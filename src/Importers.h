#ifndef CFAST_IMPORTERS_H
#define CFAST_IMPORTERS_H
#include "ProcessObject.h"

#ifdef __cplusplus
extern "C" {
#endif    

    typedef struct FASTOpaqueImageFileImporter *FASTImageFileImporterRef;
    FASTImageFileImporterRef FASTImageFileImporterNew(void);
    void FASTImageFileImporterSetFilename(FASTImageFileImporterRef ir, const char *filename);

#ifdef __cplusplus
}
#endif

#endif
