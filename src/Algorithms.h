#ifndef CFAST_ALGORITHMS_H
#define CFAST_ALGORITHMS_H
#include "ProcessObject.h"

#ifdef __cplusplus
extern "C" {
#endif    
    typedef struct FASTOpaqueImageResampler *FASTImageResamplerRef;
    typedef struct FASTOpaqueBinaryThresholding *FASTBinaryThresholdingRef;
    typedef struct FASTOpaqueMeshToSegmentation *FASTMeshToSegmentationRef;
    typedef struct FASTOpaqueSurfaceExtraction *FASTSurfaceExtractionRef;
    typedef struct FASTOpaqueLungSegmentation *FASTLungSegmentationRef;
    typedef struct FASTOpaqueDilation *FASTDilationRef;
    typedef struct FASTOpaqueErosion *FASTErosionRef;

    /*
     * ImageResampler
     */
    FASTImageResamplerRef FASTImageResamplerNew(void);
    void FASTImageResamplerSetOutputSpacing2D(FASTImageResamplerRef ir, float spacingX, float spacingY);
    void FASTImageResamplerSetOutputSpacing3D(FASTImageResamplerRef ir, float spacingX, float spacingY, float spacingZ);
    /*
     * SurfaceExtraction
     */
    FASTSurfaceExtractionRef FASTSurfaceExtractionNew(void);
    void FASTSurfaceExtractionSetThreshold(FASTSurfaceExtractionRef ir, float threshold);

    FASTLungSegmentationRef FASTLungSegmentationNew(void);
    /*
     * Morphology
     */
    FASTDilationRef FASTDilationNew(void);
    void FASTDilationSetStructuringElementSize(FASTDilationRef ir, int size);
    FASTErosionRef FASTErosionNew(void);
    void FASTErosionSetStructuringElementSize(FASTErosionRef ir, int size);
#ifdef __cplusplus
}
#endif

#endif
