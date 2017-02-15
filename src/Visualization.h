#ifndef CFAST_VISUALIZATION_H
#define CFAST_VISUALIZATION_H
#include "ProcessObject.h"

#ifdef __cplusplus
extern "C" {
#endif    

    /*
     * ImageRenderer
     */
    typedef struct FASTOpaqueImageRenderer *FASTImageRendererRef;
    FASTImageRendererRef FASTImageRendererNew(void);
    void FASTImageRendererDelete(FASTImageRendererRef ir);
    void FASTImageRendererAddInputConnection(FASTImageRendererRef ir, FASTProcessObjectPortRef port);

    /*
     * Plane
     */
    typedef struct FASTOpaquePlane *FASTPlaneRef;
    FASTPlaneRef FastPlaneCoronal(void);
    FASTPlaneRef FastPlaneSagittal(void);
    FASTPlaneRef FastPlaneAxial(void);

    /*
     * View
     */
    typedef struct FASTOpaqueView *FASTViewRef;
    void FASTViewDelete(FASTViewRef view);
    void FASTViewSetViewingPlane(FASTViewRef view, FASTPlaneRef plane);

    /*
     * SimpleWindow
     */
    typedef struct FASTOpaqueSimpleWindow *FASTSimpleWindowRef;
    FASTSimpleWindowRef FASTSimpleWindowNew(void);
    void FASTSimpleWindowDelete(FASTSimpleWindowRef win);

    void FASTSimpleWindowAddRenderer(FASTSimpleWindowRef win, FASTImageRendererRef ir);
    void FASTSimpleWindowSet2DMode(FASTSimpleWindowRef win);
    void FASTSimpleWindowSet3DMode(FASTSimpleWindowRef win);
    FASTViewRef FASTSimpleWindowGetView(FASTSimpleWindowRef win);
    void FASTSimpleWindowSetTimeout(FASTSimpleWindowRef win, unsigned int milliseconds);
#ifdef __cplusplus
}
#endif

#endif
