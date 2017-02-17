#ifndef CFAST_ALGORITHMS_H
#define CFAST_ALGORITHMS_H
#include "ProcessObject.h"

#ifdef __cplusplus
extern "C" {
#endif    
    typedef struct FASTOpaqueBinaryThresholding *FASTBinaryThresholdingRef;
    typedef struct FASTOpaqueMeshToSegmentation *FASTMeshToSegmentationRef;

    FAST_REF_DECL(ImageResampler);
    FAST_REF_DECL(SurfaceExtraction);
    FAST_REF_DECL(LungSegmentation);
    FAST_REF_DECL(Dilation);
    FAST_REF_DECL(Erosion);
    /*
     * ImageResampler
     */
    void FASTImageResamplerSetOutputSpacing2D(FASTImageResamplerRef ir, float spacingX, float spacingY);
    void FASTImageResamplerSetOutputSpacing3D(FASTImageResamplerRef ir, float spacingX, float spacingY, float spacingZ);
    /*
     * SurfaceExtraction
     */
    void FASTSurfaceExtractionSetThreshold(FASTSurfaceExtractionRef ir, float threshold);

    /*
     * Morphology
     */
    void FASTDilationSetStructuringElementSize(FASTDilationRef ir, int size);
    void FASTErosionSetStructuringElementSize(FASTErosionRef ir, int size);


#ifdef __cplusplus
}
#endif

#endif
