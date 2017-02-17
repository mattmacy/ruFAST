#ifndef CFAST_VISUALIZATION_H
#define CFAST_VISUALIZATION_H
#include "ProcessObject.h"

#ifdef __cplusplus
extern "C" {
#endif    
    enum FASTColor {
	FASTRed,
	FASTGreen,
	FASTBlue,
	FASTBlack,
	FASTWhite,
	FASTYellow,
	FASTPurple,
	FASTCyan,
    };
    typedef struct FASTOpaqueRenderer *FASTRendererRef;
    typedef struct FASTOpaqueImageRenderer *FASTImageRendererRef;
    typedef struct FASTOpaqueMeshRenderer *FASTMeshRendererRef;
    typedef struct FASTOpaquePlane *FASTPlaneRef;
    typedef struct FASTOpaqueView *FASTViewRef;
    typedef struct FASTOpaqueSimpleWindow *FASTSimpleWindowRef;
    /*
     * Renderer
     */
    FASTImageRendererRef FASTImageRendererNew(void);

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

    void FASTSimpleWindowAddRenderer(FASTSimpleWindowRef win, FASTRendererRef ir);
    void FASTSimpleWindowSet2DMode(FASTSimpleWindowRef win);
    void FASTSimpleWindowSet3DMode(FASTSimpleWindowRef win);
    void FASTSimpleWindowStart(FASTSimpleWindowRef win);
    void FASTSimpleWindowSetTimeout(FASTSimpleWindowRef win, unsigned int milliseconds);
    FASTViewRef FASTSimpleWindowGetView(FASTSimpleWindowRef win);

    /*
     * MeshRenderer
     */
    FASTMeshRendererRef FASTMeshRendererNew(void);
    void FASTMeshRendererAddInputConnection(FASTMeshRendererRef ir, FASTProcessObjectPortRef port, enum FASTColor color, float opacity);
#ifdef __cplusplus
}
#endif

#endif
