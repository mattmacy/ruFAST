#ifndef CFAST_DATA_H
#define CFAST_DATA_H

#include "ProcessObject.h"

enum FASTDataType {
    TYPE_FLOAT,
    TYPE_UINT8,
    TYPE_INT8,
    TYPE_UINT16,
    TYPE_INT16,
    TYPE_UNORM_INT16, // Unsigned normalized 16 bit integer. A 16 bit int interpreted as a float between 0 and 1.
    TYPE_SNORM_INT16 // Signed normalized 16 bit integer. A 16 bit int interpreted as a float between -1 and 1.
};


#ifdef __cplusplus
extern "C" {
#endif
    FAST_REF_DECL(Image);
    void FASTImageCreate(FASTImageRef Image, uint32_t width, uint32_t height,
	uint32_t depth, enum FASTDataType data_type, uint32_t nrOfComponents, const void *data);
    void FASTImageSetSpacing(FASTImageRef Image, float x, float y, float z);
    

#ifdef __cplusplus
}
#endif

#endif
