#ifndef CFAST_VISUALIZATION_H
#define CFAST_VISUALIZATION_H
#include "ProcessObject.h"

#ifdef __cplusplus
extern "C" {
#endif    
    typedef struct FASTOpaqueRenderer *FASTRendererRef;
    typedef struct FASTOpaquePlane *FASTPlaneRef;
    typedef struct FASTOpaqueView *FASTViewRef;
    typedef struct FASTOpaqueSimpleWindow *FASTSimpleWindowRef;
    /*
     * Renderer
     */
    FASTRendererRef FASTImageRendererNew(void);
    void FASTRendererDelete(FASTRendererRef ir);
    void FASTRendererSetInputConnection(FASTRendererRef ir, FASTProcessObjectPortRef port);

    /*
     * Plane
     */
    FASTPlaneRef FASTPlaneCoronal(void);
    FASTPlaneRef FASTPlaneSagittal(void);
    FASTPlaneRef FASTPlaneAxial(void);

    /*
     * View
     */
    void FASTViewSetViewingPlane(FASTViewRef view, FASTPlaneRef plane);

    /*
     * SimpleWindow
     */
    FASTSimpleWindowRef FASTSimpleWindowNew(void);
    void FASTSimpleWindowDelete(FASTSimpleWindowRef win);

    void FASTSimpleWindowAddRenderer(FASTSimpleWindowRef win, FASTRendererRef ir);
    void FASTSimpleWindowSet2DMode(FASTSimpleWindowRef win);
    void FASTSimpleWindowSet3DMode(FASTSimpleWindowRef win);
    void FASTSimpleWindowStart(FASTSimpleWindowRef win);
    void FASTSimpleWindowSetTimeout(FASTSimpleWindowRef win, unsigned int milliseconds);
    FASTViewRef FASTSimpleWindowGetView(FASTSimpleWindowRef win);

    /*
     * MeshRenderer
     */
    FASTRendererRef FASTMeshRendererNew(void);

#ifdef __cplusplus
}
#endif

#endif
