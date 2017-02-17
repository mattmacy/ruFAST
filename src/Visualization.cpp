#include "FAST/Visualization/SimpleWindow.hpp"
#include "FAST/Visualization/ImageRenderer/ImageRenderer.hpp"
#include "FAST/Visualization/MeshRenderer/MeshRenderer.hpp"

#include "Visualization.h"
using namespace fast;

struct FASTOpaqueRenderer {
	Renderer::pointer p;
};

struct FASTOpaqueProcessObjectPort {
	ProcessObjectPort p;
};

inline Renderer::pointer unwrap(struct FASTOpaqueRenderer  *Tys) {
	return Tys->p;
}

inline ProcessObjectPort unwrap(struct FASTOpaqueProcessObjectPort  *Tys) {
	return Tys->p;
}

FASTRendererRef FASTImageRendererNew() {
	struct FASTOpaqueRenderer *o = new FASTOpaqueRenderer();
	o->p = ImageRenderer::New();
	return o;
}

FASTRendererRef FASTMeshRendererNew() {
	struct FASTOpaqueRenderer *o = new FASTOpaqueRenderer();
	o->p = MeshRenderer::New();
	return o;
}

void FASTRendererDelete(FASTRendererRef ir) {
	delete ir;
}

void FASTRendererSetInputConnection(FASTRendererRef ir, FASTProcessObjectPortRef p) {
	unwrap(ir)->setInputConnection(unwrap(p));
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

struct FASTOpaqueSimpleWindow {
	SimpleWindow::pointer p;
};

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




