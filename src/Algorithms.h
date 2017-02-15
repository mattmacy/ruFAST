#ifndef CFAST_ALGORITHMS_H
#define CFAST_ALGORITHMS_H
#include "ProcessObject.h"

#ifdef __cplusplus
extern "C" {
#endif    
    typedef struct FASTOpaqueImageResampler *FASTImageResamplerRef;
    typedef struct FASTOpaqueBinaryThresholding *FASTBinaryThresholdingRef;
    typedef struct FASTOpaqueMeshToSegmentation *FASTMeshToSegmentationRef;

    FASTImageResamplerRef FASTImageResamplerNew(void);
    void FASTImageResamplerDelete(FASTImageResamplerRef ir);
    void FASTImageResamplerSetOutputSpacing2D(FASTImageResamplerRef ir, float spacingX, float spacingY);
    void FASTImageResamplerSetOutputSpacing3D(FASTImageResamplerRef ir, float spacingX, float spacingY, float spacingZ);
    void FASTImageResamplerSetInputConnection(FASTImageResamplerRef ir, FASTProcessObjectPortRef port);

    FASTProcessObjectPortRef FASTImageResamplerGetOutputPort(FASTImageResamplerRef ir);

#ifdef __cplusplus
}
#endif

#endif
