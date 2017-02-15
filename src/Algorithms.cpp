#include "FAST/Algorithms/ImageResampler/ImageResampler.hpp"
#include "FAST/Algorithms/BinaryThresholding/BinaryThresholding.hpp"
#include "FAST/Algorithms/MeshToSegmentation/MeshToSegmentation.hpp"
#include "FAST/Algorithms/AirwaySegmentation/AirwaySegmentation.hpp"
#include "FAST/Algorithms/SurfaceExtraction/SurfaceExtraction.hpp"

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

void FASTImageResamplerDelete(FASTImageResamplerRef ir) {
	delete ir;
}

void FASTImageResamplerSetOutputSpacing2D(FASTImageResamplerRef ir, float spacingX, float spacingY) {
	unwrap(ir)->setOutputSpacing(spacingX, spacingY);
}

void FASTImageResamplerSetOutputSpacing3D(FASTImageResamplerRef ir, float spacingX, float spacingY, float spacingZ) {
	unwrap(ir)->setOutputSpacing(spacingX, spacingY, spacingZ);
}