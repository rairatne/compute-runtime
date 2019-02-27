/*
 * Copyright (C) 2017-2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once

#include "runtime/os_interface/windows/wddm/wddm.h"

#include "engine_node.h"

namespace OCLRT {

class WddmEngineMapper {
  public:
    static GPUNODE_ORDINAL engineNodeMap(EngineType engineType);
};

} // namespace OCLRT
