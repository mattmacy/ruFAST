#include "FAST/Importers/ImageImporter.hpp"
#include "FAST/Importers/ImageFileImporter.hpp"
#include "FAST/Importers/MetaImageImporter.hpp"
//#include "FAST/Importers/VTKImageImporter.hpp"
#include "FAST/Importers/VTKLineSetFileImporter.hpp"
#include "FAST/Importers/VTKMeshFileImporter.hpp"
#include "FAST/Importers/VTKPointSetFileImporter.hpp"

#include "Importers.h"
using namespace fast;

struct FASTOpaqueImageImporter {
	ImageFileImporter::pointer p;
};
struct FASTOpaqueProcessObjectPort {
	ProcessObjectPort p;
};
inline ImageFileImporter::pointer unwrap(struct FASTOpaqueImageImporter  *Tys) {
	return Tys->p;
}

inline ProcessObjectPort unwrap(struct FASTOpaqueProcessObjectPort  *Tys) {
	return Tys->p;
}

FASTImageImporterRef FASTImageImporterNew() {
	struct FASTOpaqueImageImporter *o = new FASTOpaqueImageImporter();
	o->p = ImageFileImporter::New();
	return o;
}

void FASTImageImporterDelete(FASTImageImporterRef ir) {
	delete ir;
}

void FASTImageImporterSetFilename(FASTImageImporterRef ir, const unsigned char *filename) {
	unwrap(ir)->setFilename(std::string(reinterpret_cast<const char *>(filename)));
}

FASTProcessObjectPortRef FASTImageImporterGetOutputPort(FASTImageImporterRef ir) {
	struct FASTOpaqueProcessObjectPort *o = new FASTOpaqueProcessObjectPort();
	o->p = unwrap(ir)->getOutputPort();
	return o;
}
