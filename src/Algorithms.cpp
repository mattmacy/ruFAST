#include "FAST/Algorithms/ImageResampler/ImageResampler.hpp"
#include "FAST/Algorithms/BinaryThresholding/BinaryThresholding.hpp"
#include "FAST/Algorithms/MeshToSegmentation/MeshToSegmentation.hpp"
#include "FAST/Algorithms/AirwaySegmentation/AirwaySegmentation.hpp"
#include "FAST/Algorithms/SurfaceExtraction/SurfaceExtraction.hpp"

#include "Algorithms.h"

using namespace fast;
struct FASTOpaqueProcessObjectPort {
	ProcessObjectPort p;
};

inline ProcessObjectPort unwrap(struct FASTOpaqueProcessObjectPort  *Tys) {
	return Tys->p;
}


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

void FASTImageResamplerSetInputConnection(FASTImageResamplerRef ir, FASTProcessObjectPortRef p) {
	unwrap(ir)->setInputConnection(unwrap(p));
}

FASTProcessObjectPortRef FASTImageResamplerGetOutputPort(FASTImageResamplerRef ir) {
	struct FASTOpaqueProcessObjectPort *o = new FASTOpaqueProcessObjectPort();
	o->p = unwrap(ir)->getOutputPort();
	return o;
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

void FASTSurfaceExtractionDelete(FASTSurfaceExtractionRef ir) {
	delete ir;
}

void FASTSurfaceExtractionSetThreshold(FASTSurfaceExtractionRef ir, float threshold) {
	unwrap(ir)->setThreshold(threshold);
}

void FASTSurfaceExtractionSetInputConnection(FASTSurfaceExtractionRef ir, FASTProcessObjectPortRef p) {
	unwrap(ir)->setInputConnection(unwrap(p));
}

FASTProcessObjectPortRef FASTSurfaceExtractionGetOutputPort(FASTSurfaceExtractionRef ir) {
	struct FASTOpaqueProcessObjectPort *o = new FASTOpaqueProcessObjectPort();
	o->p = unwrap(ir)->getOutputPort();
	return o;
}
