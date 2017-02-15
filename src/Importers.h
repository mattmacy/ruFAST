#ifndef CFAST_IMPORTERS_H
#define CFAST_IMPORTERS_H
#ifdef __cplusplus
extern "C" {
#endif    

    typedef struct FASTOpaqueImageImporter *FASTImageImporterRef;
    FASTImageResamplerRef FASTImageImporterNew(void);
    void FASTImageImporterDelete(FASTImageImporterRef);
    void FASTImageImporterSetFilename(FASTImageImporterRef ir, char *filename);

    FASTProcessObjectPortRef FASTImageImporterGetOutputPort(FASTImageImporterRef);
#ifdef __cplusplus
}
#endif

#endif
