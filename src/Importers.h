#ifndef CFAST_IMPORTERS_H
#define CFAST_IMPORTERS_H
#include "ProcessObject.h"

#ifdef __cplusplus
extern "C" {
#endif    

    typedef struct FASTOpaqueImageImporter *FASTImageImporterRef;
    FASTImageImporterRef FASTImageImporterNew(void);
    void FASTImageImporterDelete(FASTImageImporterRef);
    void FASTImageImporterSetFilename(FASTImageImporterRef ir, const unsigned char *filename);

    FASTProcessObjectPortRef FASTImageImporterGetOutputPort(FASTImageImporterRef);
#ifdef __cplusplus
}
#endif

#endif
