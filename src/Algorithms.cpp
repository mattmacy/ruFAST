#include "FAST/Algorithms/ImageResampler/ImageResampler.hpp"
#include "FAST/Algorithms/BinaryThresholding/BinaryThresholding.hpp"
#include "FAST/Algorithms/MeshToSegmentation/MeshToSegmentation.hpp"
#include "FAST/Algorithms/AirwaySegmentation/AirwaySegmentation.hpp"
#include "FAST/Algorithms/SurfaceExtraction/SurfaceExtraction.hpp"
#include "FAST/Algorithms/LungSegmentation/LungSegmentation.hpp"
#include "FAST/Algorithms/Morphology/Dilation.hpp"
#include "FAST/Algorithms/Morphology/Erosion.hpp"
#include "FAST/Algorithms/SeededRegionGrowing/SeededRegionGrowing.hpp"
#include "FAST/Algorithms/AirwaySegmentation/AirwaySegmentation.hpp"
#include "FAST/Algorithms/CenterlineExtraction/CenterlineExtraction.hpp"
#include "FAST/Algorithms/GaussianSmoothingFilter/GaussianSmoothingFilter.hpp"



#include "Algorithms.h"

using namespace fast;
FAST_REF_IMPL(ImageResampler)
FAST_REF_IMPL(LungSegmentation)
FAST_REF_IMPL(SurfaceExtraction)
FAST_REF_IMPL(Dilation)
FAST_REF_IMPL(Erosion)
FAST_REF_IMPL(SeededRegionGrowing)
FAST_REF_IMPL(AirwaySegmentation)
FAST_REF_IMPL(CenterlineExtraction)
FAST_REF_IMPL(BinaryThresholding)
FAST_REF_IMPL(GaussianSmoothingFilter)


void FASTImageResamplerSetOutputSpacing2D(FASTImageResamplerRef ir, float spacingX, float spacingY) {
	unwrap(ir)->setOutputSpacing(spacingX, spacingY);
}

void FASTImageResamplerSetOutputSpacing3D(FASTImageResamplerRef ir, float spacingX, float spacingY, float spacingZ) {
	unwrap(ir)->setOutputSpacing(spacingX, spacingY, spacingZ);
}

void FASTSurfaceExtractionSetThreshold(FASTSurfaceExtractionRef ir, float threshold) {
	unwrap(ir)->setThreshold(threshold);
}

void FASTDilationSetStructuringElementSize(FASTDilationRef ir, int size) {
	unwrap(ir)->setStructuringElementSize(size);
}

void FASTErosionSetStructuringElementSize(FASTErosionRef ir, int size) {
	unwrap(ir)->setStructuringElementSize(size);
}

void FASTSeededRegionGrowingAddSeedPoint2D(FASTSeededRegionGrowingRef ir, uint32_t x, uint32_t y) {
	unwrap(ir)->addSeedPoint(x, y);
}

void FASTSeededRegionGrowingAddSeedPoint3D(FASTSeededRegionGrowingRef ir, uint32_t x, uint32_t y, uint32_t z) {
	unwrap(ir)->addSeedPoint(x, y, z);
}

void FASTSeededRegionGrowingSetIntensityRange(FASTSeededRegionGrowingRef ir, float min, float max) {
	unwrap(ir)->setIntensityRange(min, max);
}


void FASTBinaryThresholdingSetLowerThreshold(FASTBinaryThresholdingRef ir, float threshold) {
	unwrap(ir)->setUpperThreshold(threshold);
}

void FASTBinaryThresholdingSetUpperThreshold(FASTBinaryThresholdingRef ir, float threshold) {
	unwrap(ir)->setLowerThreshold(threshold);
}

void FASTGaussianSmoothingFilterSetStandardDeviation(FASTGaussianSmoothingFilterRef ir, float stddev) {
	unwrap(ir)->setStandardDeviation(stddev);
}
void FASTGaussianSmoothingFilterSetMaskSize(FASTGaussianSmoothingFilterRef ir, uint8_t size) {
	unwrap(ir)->setMaskSize(size);
}
void FASTGaussianSmoothingFilterSetOutputType(FASTGaussianSmoothingFilterRef ir, enum FASTDataType type) {
	unwrap(ir)->setOutputType((DataType)type);
}
