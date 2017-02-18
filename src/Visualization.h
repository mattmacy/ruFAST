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
    FAST_REF_DECL(PointRenderer)
    FAST_REF_DECL(LineRenderer)
    FAST_REF_DECL(SliceRenderer)
    FAST_REF_DECL(SegmentationRenderer)
    FAST_REF_DECL(TextRenderer)
    FAST_REF_DECL(BoundingBoxRenderer)
    FAST_REF_DECL(VolumeRenderer)

    FAST_REF_DECL(SimpleWindow)
    /*
     * Renderer
     */
    FAST_RENDERER_DECL(ImageRenderer);
    FAST_RENDERER_DECL(MeshRenderer);
    FAST_RENDERER_DECL(PointRenderer);
    FAST_RENDERER_DECL(LineRenderer);
    FAST_RENDERER_DECL(SliceRenderer);
    FAST_RENDERER_DECL(SegmentationRenderer);
    FAST_RENDERER_DECL(TextRenderer);
    FAST_RENDERER_DECL(BoundingBoxRenderer);
    FAST_RENDERER_DECL(VolumeRenderer);

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
     * Renderer specific functions
     */
    void FASTMeshRendererAddInputConnectionExt(FASTMeshRendererRef ir, FASTProcessObjectPortRef port, enum FASTColor color, float opacity);
    void FASTLineRendererAddInputConnectionExt(FASTLineRendererRef ir, FASTProcessObjectPortRef port, enum FASTColor color, float width);
    void FASTSegmentationRendererSetFillArea(FASTSegmentationRendererRef ir, int fill);
#ifdef __cplusplus
}
#endif

#endif
