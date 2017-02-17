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

inline ImageFileImporter::pointer unwrap(struct FASTOpaqueImageFileImporter  *Tys) {
	return Tys->p;
}

FASTImageFileImporterRef FASTImageFileImporterNew() {
	struct FASTOpaqueImageFileImporter *o = new FASTOpaqueImageFileImporter();
	o->p = ImageFileImporter::New();
	return o;
}

void FASTImageFileImporterSetFilename(FASTImageFileImporterRef ir, const char *filename) {
	unwrap(ir)->setFilename(std::string(reinterpret_cast<const char *>(filename)));
}
