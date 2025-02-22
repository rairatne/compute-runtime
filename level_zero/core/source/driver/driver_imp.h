/*
 * Copyright (C) 2020-2024 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once

#include "level_zero/core/source/driver/driver.h"

#include <atomic>
#include <mutex>
#include <string>

namespace L0 {

class DriverImp : public Driver {
  public:
    ze_result_t driverInit(ze_init_flags_t flags) override;

    void initialize(ze_result_t *result) override;
    unsigned int getPid() const override {
        return pid;
    }
    ze_result_t initGtpin() override;

    enum class GtPinInitializationStatus {
        notNeeded,
        pending,
        inProgress,
        error
    };

  protected:
    uint32_t pid = 0;
    std::once_flag initDriverOnce;
    static ze_result_t initStatus;
    std::atomic<GtPinInitializationStatus> gtPinInitializationStatus{GtPinInitializationStatus::notNeeded};
    std::recursive_mutex gtpinInitMtx;
};

struct L0EnvVariables {
    std::string affinityMask;
    uint32_t programDebugging;
    bool metrics;
    bool pin;
    bool sysman;
    bool pciIdDeviceOrder;
    bool fp64Emulation;
    std::string deviceHierarchyMode;
};

} // namespace L0
