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
    typedef struct FASTOpaquePlane *FASTPlaneRef;
    typedef struct FASTOpaqueView *FASTViewRef;
    FAST_REF_DECL(ImageRenderer)
    FAST_REF_DECL(MeshRenderer)
    FAST_REF_DECL(SimpleWindow)
    /*
     * Renderer
     */

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

    void FASTSimpleWindowAddRenderer(FASTSimpleWindowRef win, FASTRendererRef ir);
    void FASTSimpleWindowSet2DMode(FASTSimpleWindowRef win);
    void FASTSimpleWindowSet3DMode(FASTSimpleWindowRef win);
    void FASTSimpleWindowStart(FASTSimpleWindowRef win);
    void FASTSimpleWindowSetTimeout(FASTSimpleWindowRef win, unsigned int milliseconds);
    FASTViewRef FASTSimpleWindowGetView(FASTSimpleWindowRef win);

    /*
     * MeshRenderer
     */
    void FASTMeshRendererAddInputConnection(FASTMeshRendererRef ir, FASTProcessObjectPortRef port, enum FASTColor color, float opacity);
#ifdef __cplusplus
}
#endif

#endif
