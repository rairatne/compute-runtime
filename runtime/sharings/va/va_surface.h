/*
 * Copyright (C) 2017-2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "runtime/mem_obj/image.h"
#include "runtime/sharings/va/va_sharing.h"

namespace OCLRT {
class Context;
class Image;

class VASurface : VASharing {
  public:
    static Image *createSharedVaSurface(Context *context, VASharingFunctions *sharingFunctions,
                                        cl_mem_flags flags, VASurfaceID *surface, cl_uint plane,
                                        cl_int *errcodeRet);

    void synchronizeObject(UpdateData &updateData) override;

    void getMemObjectInfo(size_t &paramValueSize, void *&paramValue) override;

  protected:
    VASurface(VASharingFunctions *sharingFunctions, VAImageID imageId,
              cl_uint plane, VASurfaceID *surfaceId, bool interopUserSync)
        : VASharing(sharingFunctions, imageId), plane(plane), surfaceId(surfaceId), interopUserSync(interopUserSync){};

    cl_uint plane;
    VASurfaceID *surfaceId;
    bool interopUserSync;
};
} // namespace OCLRT
