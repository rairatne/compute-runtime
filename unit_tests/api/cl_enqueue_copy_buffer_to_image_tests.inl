/*
 * Copyright (C) 2017-2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "runtime/command_queue/command_queue.h"
#include "runtime/helpers/surface_formats.h"
#include "unit_tests/fixtures/buffer_fixture.h"

#include "cl_api_tests.h"

using namespace OCLRT;

typedef api_tests clEnqueueCopyBufferToImageTests;

namespace ULT {

struct clEnqueueCopyBufferToImageTests : public api_fixture,
                                         public ::testing::Test {
    void SetUp() override {
        api_fixture::SetUp();

        // clang-format off
        imageFormat.image_channel_order     = CL_YUYV_INTEL;
        imageFormat.image_channel_data_type = CL_UNORM_INT8;

        imageDesc.image_type        = CL_MEM_OBJECT_IMAGE2D;
        imageDesc.image_width       = 32;
        imageDesc.image_height      = 32;
        imageDesc.image_depth       = 1;
        imageDesc.image_array_size  = 1;
        imageDesc.image_row_pitch   = 0;
        imageDesc.image_slice_pitch = 0;
        imageDesc.num_mip_levels    = 0;
        imageDesc.num_samples       = 0;
        imageDesc.mem_object        = nullptr;
        // clang-format on
    }

    void TearDown() override {
        api_fixture::TearDown();
    }

    cl_image_format imageFormat;
    cl_image_desc imageDesc;
};

TEST_F(clEnqueueCopyBufferToImageTests, GivenInvalidCmdQueueWhenCopyingBufferToImageThenInvalidCommandQueueErrorIsReturned) {
    size_t dstOrigin[] = {0, 0, 0};
    size_t region[] = {10, 10, 0};

    auto retVal = clEnqueueCopyBufferToImage(
        nullptr, //commandQueue
        nullptr, //srcBuffer
        nullptr, //dstBuffer
        0u,      //src_offset
        dstOrigin,
        region,
        0, //numEventsInWaitList
        nullptr,
        nullptr);

    EXPECT_EQ(CL_INVALID_COMMAND_QUEUE, retVal);
}

TEST_F(clEnqueueCopyBufferToImageTests, GivenInvalidSrcBufferWhenCopyingBufferToImageThenInvalidMemObjectErrorIsReturned) {
    size_t dstOrigin[] = {0, 0, 0};
    size_t region[] = {10, 10, 0};

    auto retVal = clEnqueueCopyBufferToImage(
        pCommandQueue,
        nullptr, //srcBuffer
        nullptr, //dstBuffer
        0u,      //src_offset
        dstOrigin,
        region,
        0, //numEventsInWaitList
        nullptr,
        nullptr);

    EXPECT_EQ(CL_INVALID_MEM_OBJECT, retVal);
}

TEST_F(clEnqueueCopyBufferToImageTests, GivenValidParametersWhenCopyingBufferToImageThenSuccessIsReturned) {

    imageFormat.image_channel_order = CL_RGBA;
    auto dstImage = clCreateImage(
        pContext,
        CL_MEM_READ_WRITE,
        &imageFormat,
        &imageDesc,
        nullptr,
        &retVal);
    ASSERT_EQ(CL_SUCCESS, retVal);
    EXPECT_NE(nullptr, dstImage);
    auto srcBuffer = std::unique_ptr<Buffer>(BufferHelper<BufferUseHostPtr<>>::create(pContext));
    size_t dstOrigin[] = {0, 0, 0};
    size_t region[] = {10, 10, 1};

    auto retVal = clEnqueueCopyBufferToImage(
        pCommandQueue,
        srcBuffer.get(),
        dstImage,
        0u, //src_offset
        dstOrigin,
        region,
        0, //numEventsInWaitList
        nullptr,
        nullptr);

    EXPECT_EQ(CL_SUCCESS, retVal);
    retVal = clReleaseMemObject(dstImage);
    EXPECT_EQ(CL_SUCCESS, retVal);
}

typedef clEnqueueCopyBufferToImageTests clEnqueueCopyBufferToImageYUV;

TEST_F(clEnqueueCopyBufferToImageYUV, GivenValidYuvDstImageWhenCopyingBufferToImageThenSuccessIsReturned) {
    auto srcBuffer = std::unique_ptr<Buffer>(BufferHelper<BufferUseHostPtr<>>::create(pContext));
    auto dstImage = clCreateImage(
        pContext,
        CL_MEM_READ_ONLY,
        &imageFormat,
        &imageDesc,
        nullptr,
        &retVal);
    ASSERT_EQ(CL_SUCCESS, retVal);
    EXPECT_NE(nullptr, dstImage);
    const size_t origin[] = {2, 2, 0};
    const size_t region[] = {2, 2, 1};
    auto retVal = clEnqueueCopyBufferToImage(
        pCommandQueue,
        srcBuffer.get(),
        dstImage,
        0,
        origin,
        region,
        0,
        nullptr,
        nullptr);

    EXPECT_EQ(CL_SUCCESS, retVal);
    retVal = clReleaseMemObject(dstImage);
    EXPECT_EQ(CL_SUCCESS, retVal);
}

TEST_F(clEnqueueCopyBufferToImageYUV, GivenInvalidOriginAndYuvDstImageWhenCopyingBufferToImageThenInvalidValueErrorIsReturned) {
    auto srcBuffer = std::unique_ptr<Buffer>(BufferHelper<BufferUseHostPtr<>>::create(pContext));
    auto dstImage = clCreateImage(
        pContext,
        CL_MEM_READ_ONLY,
        &imageFormat,
        &imageDesc,
        nullptr,
        &retVal);
    ASSERT_EQ(CL_SUCCESS, retVal);
    EXPECT_NE(nullptr, dstImage);
    const size_t origin[] = {1, 2, 0};
    const size_t region[] = {2, 2, 0};
    auto retVal = clEnqueueCopyBufferToImage(
        pCommandQueue,
        srcBuffer.get(),
        dstImage,
        0,
        origin,
        region,
        0,
        nullptr,
        nullptr);

    EXPECT_EQ(CL_INVALID_VALUE, retVal);
    retVal = clReleaseMemObject(dstImage);
    EXPECT_EQ(CL_SUCCESS, retVal);
}

TEST_F(clEnqueueCopyBufferToImageYUV, GivenInvalidRegionAndValidYuvDstImageWhenCopyingBufferToImageThenInvalidValueErrorIsReturned) {
    auto srcBuffer = std::unique_ptr<Buffer>(BufferHelper<BufferUseHostPtr<>>::create(pContext));
    auto dstImage = clCreateImage(
        pContext,
        CL_MEM_READ_ONLY,
        &imageFormat,
        &imageDesc,
        nullptr,
        &retVal);
    ASSERT_EQ(CL_SUCCESS, retVal);
    EXPECT_NE(nullptr, dstImage);
    const size_t origin[] = {2, 2, 0};
    const size_t region[] = {1, 2, 0};
    auto retVal = clEnqueueCopyBufferToImage(
        pCommandQueue,
        srcBuffer.get(),
        dstImage,
        0,
        origin,
        region,
        0,
        nullptr,
        nullptr);

    EXPECT_EQ(CL_INVALID_VALUE, retVal);
    retVal = clReleaseMemObject(dstImage);
    EXPECT_EQ(CL_SUCCESS, retVal);
}
} // namespace ULT
