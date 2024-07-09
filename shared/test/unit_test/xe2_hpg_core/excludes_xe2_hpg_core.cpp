/*
 * Copyright (C) 2024 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/test/common/test_macros/hw_test_base.h"

HWTEST_EXCLUDE_PRODUCT(ProductHelperTest, givenProductHelperWhenAskedIfBlitterForImagesIsSupportedThenFalseIsReturned, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(CommandEncodeStatesTest, givenOverrideSlmTotalSizeDebugVariableWhenDispatchingKernelThenSharedMemorySizeIsSetCorrectly, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(ImageSurfaceStateTests, givenGmmWhenSetAuxParamsForCCSThenAuxiliarySurfaceModeIsSet, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(WalkerPartitionTests, givenMiAtomicWhenItIsProgrammedThenAllFieldsAreSetCorrectly, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(WalkerPartitionTests, givenProgramBatchBufferStartCommandWhenItIsCalledThenCommandIsProgrammedCorrectly, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GfxCoreHelperTest, whenAdjustPreemptionSurfaceSizeIsCalledThenCsrSizeDoesntChange, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GfxCoreHelperTest, whenSetSipKernelDataIsCalledThenSipKernelDataDoesntChange, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GfxCoreHelperTest, givenDefaultGfxCoreHelperHwWhenMinimalSIMDSizeIsQueriedThen8IsReturned, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GfxCoreHelperTest, givenGfxCoreHelperWhenAskingForTimestampPacketAlignmentThenReturnFourCachelines, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GfxCoreHelperTest, whenSetCompressedFlagThenProperFlagSet, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GfxCoreHelperTest, whenIsSipKernelAsHexadecimalArrayPreferredIsCalledThenReturnFalse, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GfxCoreHelperTest, givenNumGrfAndSimdSizeWhenAdjustingMaxWorkGroupSizeThenAlwaysReturnDeviceDefault, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(PipeControlHelperTests, givenGfxCoreHelperwhenAskingForDcFlushThenReturnTrue, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(XeHPAndLaterPreemptionTests, whenProgramStateSipIsCalledThenStateSipCmdIsNotAddedToStream, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(XeHPAndLaterPreemptionTests, WhenProgrammingPreemptionThenExpectLoadRegisterCommandRemapFlagEnabled, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(BlitTests, givenXyCopyBltCommandWhenAppendBlitCommandsMemCopyIsCalledThenNothingChanged, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(ProductHelperTest, givenProductHelperWhenIsGlobalFenceInCommandStreamRequiredThenFalseIsReturned, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(MemoryManagerGetAlloctionDataTests, givenCommandBufferAllocationTypeWhenGetAllocationDataIsCalledThenSystemMemoryIsRequested, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(MidThreadPreemptionTests, givenKernelWithRayTracingWhenGettingPreemptionFlagsThenMidThreadPreemptionIsNotDisabled, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(ProductHelperTest, givenProductHelperWhenAskedIfPatIndexProgrammingSupportedThenReturnFalse, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GmmCompressionTests, givenAllValidInputsWhenQueryingThenSetAppropriateFlags, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GmmCompressionTests, givenNotAllowedCompressionAndEnabledDebugFlagWhenQueryingThenSetAppropriateFlags, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GmmCompressionTests, whenConstructedWithPreferCompressionFlagThenApplyAuxFlags, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GmmCompressionTests, givenDisabledE2ECAndEnabledDebugFlagWhenApplyingForBuffersThenSetValidFlags, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GmmCompressionTests, givenEnabledAndPreferredE2ECWhenApplyingForBuffersThenSetValidFlags, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(CommandEncodeSemaphore, givenIndirectModeSetWhenProgrammingSemaphoreThenSetIndirectBit_IsAtLeastXeHpCore, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(ProductHelperTest, givenBooleanUncachedWhenCallOverridePatIndexThenProperPatIndexIsReturned, IGFX_XE2_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(GfxCoreHelperTest, whenEncodeAdditionalTimestampOffsetsThenNothingEncoded, IGFX_XE2_HPG_CORE);
