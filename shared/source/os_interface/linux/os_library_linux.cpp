/*
 * Copyright (C) 2019-2024 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/os_interface/linux/os_library_linux.h"

#include "shared/source/helpers/debug_helpers.h"
#include "shared/source/os_interface/linux/sys_calls.h"

#include <dlfcn.h>
#include <link.h>

namespace NEO {

OsLibrary *OsLibrary::loadAndCaptureError(const std::string &name, std::string *errorValue) {
    auto ptr = new (std::nothrow) Linux::OsLibrary(name, errorValue);
    if (ptr == nullptr)
        return nullptr;

    if (!ptr->isLoaded()) {
        delete ptr;
        return nullptr;
    }
    return ptr;
}

const std::string OsLibrary::createFullSystemPath(const std::string &name) {
    return name;
}

namespace Linux {

OsLibrary::OsLibrary(const std::string &name, std::string *errorValue) {
    if (name.empty()) {
        this->handle = SysCalls::dlopen(0, RTLD_LAZY);
    } else {
//#ifdef SANITIZER_BUILD
        auto dlopenFlag = RTLD_LAZY;
//#else
//        auto dlopenFlag = RTLD_LAZY | RTLD_DEEPBIND;
//        /* Background: https://github.com/intel/compute-runtime/issues/122 */
//#endif
        adjustLibraryFlags(dlopenFlag);
        this->handle = SysCalls::dlopen(name.c_str(), dlopenFlag);
        if (!this->handle && (errorValue != nullptr)) {
            errorValue->assign(dlerror());
        }
    }
}

OsLibrary::~OsLibrary() {
    if (this->handle != nullptr) {
        dlclose(this->handle);
        this->handle = nullptr;
    }
}

bool OsLibrary::isLoaded() {
    return this->handle != nullptr;
}

void *OsLibrary::getProcAddress(const std::string &procName) {
    DEBUG_BREAK_IF(this->handle == nullptr);

    return dlsym(this->handle, procName.c_str());
}

std::string OsLibrary::getFullPath() {
#ifndef __ANDROID__
    struct link_map *map = nullptr;
    int retVal = NEO::SysCalls::dlinfo(this->handle, RTLD_DI_LINKMAP, &map);
    if (retVal == 0 && map != nullptr) {
        return std::string(map->l_name);
    }
#endif
    return std::string();
}
} // namespace Linux
} // namespace NEO
