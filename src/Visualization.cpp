#include "FAST/Visualization/SimpleWindow.hpp"
#include "FAST/Visualization/ImageRenderer/ImageRenderer.hpp"
#include "FAST/Visualization/MeshRenderer/MeshRenderer.hpp"

#include "Visualization.h"
using namespace fast;

FAST_REF_IMPL(MeshRenderer)
FAST_REF_IMPL(ImageRenderer)
FAST_REF_IMPL(SimpleWindow)

struct FASTOpaqueRenderer {
	Renderer::pointer p;
};
struct FASTOpaqueProcessObjectPort {
	ProcessObjectPort p;
};

inline ProcessObjectPort unwrap(struct FASTOpaqueProcessObjectPort  *Tys) {
	return Tys->p;
}

inline Renderer::pointer unwrap(struct FASTOpaqueRenderer  *Tys) {
	return Tys->p;
}

static inline Color unwrap(enum FASTColor col) {
	switch (col) {
	case FASTRed:
		return Color::Red();
	case FASTGreen:
		return Color::Green();
	case FASTBlue:
		return Color::Blue();
	case FASTWhite:
		return Color::White();
	case FASTBlack:
		return Color::Black();
	case FASTYellow:
		return Color::Yellow();
	case FASTPurple:
		return Color::Purple();
	case FASTCyan:
		return Color::Cyan();
	default:
		abort();
	}
}

void FASTMeshRendererAddInputConnection(FASTMeshRendererRef ir, FASTProcessObjectPortRef port,  enum FASTColor color, float opacity) {
	unwrap(ir)->addInputConnection(unwrap(port), unwrap(color), opacity);
}

inline FASTPlaneRef wrap(const Plane *Tys) {
  return reinterpret_cast<FASTPlaneRef>(const_cast<Plane*>(Tys));
}

inline Plane *unwrap(const FASTPlaneRef Tys) {
	return reinterpret_cast<Plane *>(const_cast<FASTPlaneRef>(Tys));
}

FASTPlaneRef FASTPlaneSagittal() {
	return wrap(new Plane(Vector3f(1,0,0)));
}

FASTPlaneRef FASTPlaneCoronal() {
	return wrap(new Plane(Vector3f(0,1,0)));
}

FASTPlaneRef FASTPlaneAxial() {
	return wrap(new Plane(Vector3f(0,0,1)));
}
inline FASTViewRef wrap(const View *Tys) {
	return reinterpret_cast<FASTViewRef>(const_cast<View*>(Tys));
}

inline View *unwrap(FASTViewRef Tys) {
  return reinterpret_cast<View *>(Tys);
}

void FASTViewSetViewingPlane(FASTViewRef view, FASTPlaneRef plane)
{
	unwrap(view)->setViewingPlane(*unwrap(plane));
}

void  FASTSimpleWindowAddRenderer(FASTSimpleWindowRef win, FASTRendererRef ir) {
	unwrap(win)->addRenderer(unwrap(ir));
}

void FASTSimpleWindowSet2DMode(FASTSimpleWindowRef win) {
	unwrap(win)->set2DMode();
}

void FASTSimpleWindowSet3DMode(FASTSimpleWindowRef win) {
	unwrap(win)->set3DMode();
}

FASTViewRef FASTSimpleWindowGetView(FASTSimpleWindowRef win) {
	return wrap(unwrap(win)->getView());
}

void FASTSimpleWindowSetTimeout(FASTSimpleWindowRef win, unsigned int ms) {
	unwrap(win)->setTimeout(ms);
}

void FASTSimpleWindowStart(FASTSimpleWindowRef win) {
	unwrap(win)->start();
}




