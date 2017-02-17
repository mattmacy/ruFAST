#include "FAST/Importers/ImageImporter.hpp"
#include "FAST/Importers/ImageFileImporter.hpp"
#include "FAST/Importers/MetaImageImporter.hpp"
//#include "FAST/Importers/VTKImageImporter.hpp"
#include "FAST/Importers/VTKLineSetFileImporter.hpp"
#include "FAST/Importers/VTKMeshFileImporter.hpp"
#include "FAST/Importers/VTKPointSetFileImporter.hpp"

#include "Importers.h"
using namespace fast;

struct FASTOpaqueImageFileImporter {
	ImageFileImporter::pointer p;
};
struct FASTOpaqueProcessObjectPort {
	ProcessObjectPort p;
};
inline ImageFileImporter::pointer unwrap(struct FASTOpaqueImageFileImporter  *Tys) {
	return Tys->p;
}

inline ProcessObjectPort unwrap(struct FASTOpaqueProcessObjectPort  *Tys) {
	return Tys->p;
}

FASTImageFileImporterRef FASTImageFileImporterNew() {
	struct FASTOpaqueImageFileImporter *o = new FASTOpaqueImageFileImporter();
	o->p = ImageFileImporter::New();
	return o;
}

void FASTImageFileImporterDelete(FASTImageFileImporterRef ir) {
	delete ir;
}

void FASTImageFileImporterSetFilename(FASTImageFileImporterRef ir, const char *filename) {
	unwrap(ir)->setFilename(std::string(reinterpret_cast<const char *>(filename)));
}

FASTProcessObjectPortRef FASTImageFileImporterGetOutputPort(FASTImageFileImporterRef ir) {
	struct FASTOpaqueProcessObjectPort *o = new FASTOpaqueProcessObjectPort();
	o->p = unwrap(ir)->getOutputPort();
	return o;
}
