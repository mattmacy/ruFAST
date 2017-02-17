#ifndef CFAST_IMPORTERS_H
#define CFAST_IMPORTERS_H
#include "ProcessObject.h"

#ifdef __cplusplus
extern "C" {
#endif    

    FAST_REF_DECL(ImageFileImporter);
    void FASTImageFileImporterSetFilename(FASTImageFileImporterRef ir, const char *filename);

#ifdef __cplusplus
}
#endif

#endif
