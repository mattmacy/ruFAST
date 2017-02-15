#include "FAST/Data/BoundingBox.hpp"
#include "FAST/Data/Camera.hpp"
#include "FAST/Data/Color.hpp"
#include "FAST/Data/DataObject.hpp"
#include "FAST/Data/DataTypes.hpp"
#include "FAST/Data/DynamicData.hpp"
#include "FAST/Data/Image.hpp"
#include "FAST/Data/LineSet.hpp"
#include "FAST/Data/Mesh.hpp"
#include "FAST/Data/MeshVertex.hpp"
#include "FAST/Data/PointSet.hpp"
#include "FAST/Data/Segmentation.hpp"
#include "FAST/Data/SimpleDataObject.hpp"
#include "FAST/Data/SpatialDataObject.hpp"

#include "Data.h"

using namespace fast;
struct FASTOpaqueImage {
	Image::pointer p;
};

inline Image::pointer unwrap(struct FASTOpaqueImage  *Tys) {
	return Tys->p;
}

FASTImageRef FASTImageNew() {
	struct FASTOpaqueImage *o = new FASTOpaqueImage();
	o->p = Image::New();
	return o;
}

void FASTImageDelete(FASTImageRef ir) {
	delete ir;
}

void FASTImageCreate(FASTImageRef Image, uint32_t width, uint32_t height,
	uint32_t depth, FASTDataType type, uint32_t nrOfComponents, const void *data)
{
	unwrap(Image)->create(width, height, depth, (DataType)type, nrOfComponents, data);
}

void FASTImageSetSpacing(FASTImageRef Image, float x, float y, float z)
{
	unwrap(Image)->setSpacing(x, y, z);
}
