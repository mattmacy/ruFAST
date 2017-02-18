#ifndef CFAST_ALGORITHMS_H
#define CFAST_ALGORITHMS_H
#include "ProcessObject.h"
#include "Data.h"
#ifdef __cplusplus
extern "C" {
#endif    
    typedef struct FASTOpaqueMeshToSegmentation *FASTMeshToSegmentationRef;

    FAST_REF_DECL(ImageResampler);
    FAST_REF_DECL(SurfaceExtraction);
    FAST_REF_DECL(LungSegmentation);
    FAST_REF_DECL(Dilation);
    FAST_REF_DECL(Erosion);
    FAST_REF_DECL(SeededRegionGrowing)
    FAST_REF_DECL(AirwaySegmentation)
    FAST_REF_DECL(CenterlineExtraction)
    FAST_REF_DECL(BinaryThresholding)
    FAST_REF_DECL(GaussianSmoothingFilter)
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

    void FASTSeededRegionGrowingAddSeedPoint2D(FASTSeededRegionGrowingRef ir, uint32_t x, uint32_t y);
    void FASTSeededRegionGrowingAddSeedPoint3D(FASTSeededRegionGrowingRef ir, uint32_t x, uint32_t y, uint32_t z);
    void FASTSeededRegionGrowingSetIntensityRange(FASTSeededRegionGrowingRef ir, float min, float max);


    void FASTBinaryThresholdingSetLowerThreshold(FASTBinaryThresholdingRef ir, float threshold);
    void FASTBinaryThresholdingSetUpperThreshold(FASTBinaryThresholdingRef ir, float threshold);

    void FASTGaussianSmoothingFilterSetStandardDeviation(FASTGaussianSmoothingFilterRef ir, float stddev);
    void FASTGaussianSmoothingFilterSetMaskSize(FASTGaussianSmoothingFilterRef ir, uint8_t size);
    void FASTGaussianSmoothingFilterSetOutputType(FASTGaussianSmoothingFilterRef ir, enum FASTDataType type);
#ifdef __cplusplus
}
#endif

#endif
