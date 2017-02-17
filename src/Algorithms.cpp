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
struct FASTOpaqueImageResampler {
	ImageResampler::pointer p;
};

inline ImageResampler::pointer unwrap(struct FASTOpaqueImageResampler  *Tys) {
	return Tys->p;
}

FASTImageResamplerRef FASTImageResamplerNew() {
	struct FASTOpaqueImageResampler *o = new FASTOpaqueImageResampler();
	o->p = ImageResampler::New();
	return o;
}

void FASTImageResamplerSetOutputSpacing2D(FASTImageResamplerRef ir, float spacingX, float spacingY) {
	unwrap(ir)->setOutputSpacing(spacingX, spacingY);
}

void FASTImageResamplerSetOutputSpacing3D(FASTImageResamplerRef ir, float spacingX, float spacingY, float spacingZ) {
	unwrap(ir)->setOutputSpacing(spacingX, spacingY, spacingZ);
}

struct FASTOpaqueSurfaceExtraction {
	SurfaceExtraction::pointer p;
};

inline SurfaceExtraction::pointer unwrap(struct FASTOpaqueSurfaceExtraction  *Tys) {
	return Tys->p;
}

FASTSurfaceExtractionRef FASTSurfaceExtractionNew() {
	struct FASTOpaqueSurfaceExtraction *o = new FASTOpaqueSurfaceExtraction();
	o->p = SurfaceExtraction::New();
	return o;
}

void FASTSurfaceExtractionSetThreshold(FASTSurfaceExtractionRef ir, float threshold) {
	unwrap(ir)->setThreshold(threshold);
}

struct FASTOpaqueLungSegmentation {
	LungSegmentation::pointer p;
};

FASTLungSegmentationRef FASTLungSegmentationNew() {
	struct FASTOpaqueLungSegmentation *o = new FASTOpaqueLungSegmentation();
	o->p = LungSegmentation::New();
	return o;
}

struct FASTOpaqueDilation {
	Dilation::pointer p;
};

FASTDilationRef FASTDilationNew() {
	struct FASTOpaqueDilation *o = new FASTOpaqueDilation();
	o->p = Dilation::New();
	return o;
}
void FASTDilationSetStructuringElementSize(FASTDilationRef ir, int size) {
	ir->p->setStructuringElementSize(size);
}

struct FASTOpaqueErosion {
	Erosion::pointer p;
};

FASTErosionRef FASTErosionNew() {
	struct FASTOpaqueErosion *o = new FASTOpaqueErosion();
	o->p = Erosion::New();
	return o;
}
void FASTErosionSetStructuringElementSize(FASTErosionRef ir, int size) {
	ir->p->setStructuringElementSize(size);
}
