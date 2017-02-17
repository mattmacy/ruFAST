#include "FAST/Algorithms/ImageResampler/ImageResampler.hpp"
#include "FAST/Algorithms/BinaryThresholding/BinaryThresholding.hpp"
#include "FAST/Algorithms/MeshToSegmentation/MeshToSegmentation.hpp"
#include "FAST/Algorithms/AirwaySegmentation/AirwaySegmentation.hpp"
#include "FAST/Algorithms/SurfaceExtraction/SurfaceExtraction.hpp"
#include "FAST/Algorithms/LungSegmentation/LungSegmentation.hpp"
#include "FAST/Algorithms/Morphology/Dilation.hpp"
#include "FAST/Algorithms/Morphology/Erosion.hpp"

#include "Algorithms.h"

using namespace fast;
FAST_REF_IMPL(ImageResampler)
FAST_REF_IMPL(LungSegmentation)
FAST_REF_IMPL(SurfaceExtraction)
FAST_REF_IMPL(Dilation)
FAST_REF_IMPL(Erosion)


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
	ir->p->setStructuringElementSize(size);
}

void FASTErosionSetStructuringElementSize(FASTErosionRef ir, int size) {
	ir->p->setStructuringElementSize(size);
}
