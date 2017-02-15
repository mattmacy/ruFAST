#include "FAST/Visualization/SimpleWindow.hpp"
#include "FAST/Visualization/ImageRenderer/ImageRenderer.hpp"

#include "Visualization.h"
using namespace fast;

struct FASTOpaqueImageRenderer {
	ImageRenderer::pointer p;
};

struct FASTOpaqueProcessObjectPort {
	ProcessObjectPort p;
};

inline ImageRenderer::pointer unwrap(struct FASTOpaqueImageRenderer  *Tys) {
	return Tys->p;
}

inline ProcessObjectPort unwrap(struct FASTOpaqueProcessObjectPort  *Tys) {
	return Tys->p;
}

FASTImageRendererRef FASTImageRendererNew() {
	struct FASTOpaqueImageRenderer *o = new FASTOpaqueImageRenderer();
	o->p = ImageRenderer::New();
	return o;
}

void FASTImageRendererDelete(FASTImageRendererRef ir) {
	delete ir;
}

void FASTImageRendererAddInputConnection(FASTImageRendererRef ir, FASTProcessObjectPortRef p) {
	unwrap(ir)->addInputConnection(unwrap(p));
}

inline FASTPlaneRef wrap(const Plane *Tys) {
  return reinterpret_cast<FASTPlaneRef>(const_cast<Plane*>(Tys));
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

struct FASTOpaqueSimpleWindow {
	SimpleWindow::pointer p;
};

inline FASTViewRef wrap(const View *Tys) {
	return reinterpret_cast<FASTViewRef>(const_cast<View*>(Tys));
}

inline View *unwrap(FASTViewRef Tys) {
  return reinterpret_cast<View *>(Tys);
}

inline SimpleWindow::pointer unwrap(struct FASTOpaqueSimpleWindow  *Tys) {
	return Tys->p;
}

FASTSimpleWindowRef FASTSimpleWindowNew() {
	struct FASTOpaqueSimpleWindow *o = new FASTOpaqueSimpleWindow();
	o->p = SimpleWindow::New();
	return o;
}

void FASTSimpleWindowDelete(FASTSimpleWindowRef win) {
	delete win;
}

void  FASTSimpleWindowAddRenderer(FASTSimpleWindowRef win, FASTImageRendererRef ir) {
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

void FASTSimpleWindowDelete(FASTViewRef view) {
	delete unwrap(view);
}
