#include "FAST/ProcessObject.hpp"
#include "ProcessObject.h"

using namespace fast;
struct FASTOpaqueProcessObjectPort {
	ProcessObjectPort p;
};

struct FASTOpaqueProcessObject {
	ProcessObject::pointer p;
};

inline ProcessObjectPort unwrap(struct FASTOpaqueProcessObjectPort  *Tys) {
	return Tys->p;
}

inline ProcessObject::pointer unwrap(struct FASTOpaqueProcessObject  *Tys) {
	return Tys->p;
}

FASTProcessObjectPortRef FASTProcessObjectGetOutputPortId(FASTProcessObjectRef ir, uint32_t portid) {
	struct FASTOpaqueProcessObjectPort *o = new FASTOpaqueProcessObjectPort();
	o->p = unwrap(ir)->getOutputPort(portid);
	return o;
}

void FASTProcessObjectSetInputConnection(FASTProcessObjectRef ir, FASTProcessObjectPortRef p) {
	unwrap(ir)->setInputConnection(unwrap(p));
}

void FASTProcessObjectUpdate(FASTProcessObjectRef ir) {
	unwrap(ir)->update();
}

void FASTProcessObjectDelete(FASTProcessObjectRef ir) {
	delete ir;
}

void FASTProcessObjectPortDelete(FASTProcessObjectPortRef ir) {
	delete ir;
}
