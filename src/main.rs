#[warn(non_snake_case)] 
extern crate ruFAST;
use ruFAST::*;


fn image_resampler_test() {
    let mut importer = ImageFileImporter::new();
    importer.setFilename("resources/CT/CT-Abdomen.mhd");

    let mut resampler = ImageResampler::new();
    resampler.setOutputSpacing3D(1.0, 1.0, 1.0);
    resampler.setInputConnection(&mut importer.getOutputPort());

    let mut renderer = ImageRenderer::new();
    renderer.setInputConnection(&mut resampler.getOutputPort());

    let mut window = SimpleWindow::new();
    window.addRenderer(&mut renderer);
    window.set2DMode();
    window.getView().setViewingPlane(Plane::coronal());
    window.setTimeout(500);
    window.start();
}

fn surface_extraction_test() {
    let mut importer = ImageFileImporter::new();
    importer.setFilename("resources/CT/CT-Abdomen.mhd");

    let mut extraction = SurfaceExtraction::new();
    extraction.setInputConnection(&mut importer.getOutputPort());
    extraction.setThreshold(300.0);

    let mut surface_renderer = MeshRenderer::new();
    surface_renderer.setInputConnection(&mut extraction.getOutputPort());

    let mut window = SimpleWindow::new();
    window.addRenderer(&mut surface_renderer);
    window.setTimeout(5*1000);
    window.start();
}
fn main() {
    image_resampler_test();
    surface_extraction_test();
}
