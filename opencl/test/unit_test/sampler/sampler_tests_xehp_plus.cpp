/*
 * Copyright (C) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/debug_settings/debug_settings_manager.h"
#include "shared/test/common/helpers/debug_manager_state_restore.h"
#include "shared/test/unit_test/utilities/base_object_utils.h"

#include "opencl/source/sampler/sampler.h"
#include "opencl/test/unit_test/fixtures/cl_device_fixture.h"
#include "opencl/test/unit_test/mocks/mock_context.h"
#include "test.h"

#include <memory>

using namespace NEO;

using XeHPPlusSamplerTest = Test<ClDeviceFixture>;

HWCMDTEST_F(IGFX_XE_HP_CORE, XeHPPlusSamplerTest, GivenDefaultThenLowQualityFilterIsDisabled) {
    using SAMPLER_STATE = typename FamilyType::SAMPLER_STATE;
    auto state = FamilyType::cmdInitSamplerState;
    EXPECT_EQ(SAMPLER_STATE::LOW_QUALITY_FILTER_DISABLE, state.getLowQualityFilter());
}
