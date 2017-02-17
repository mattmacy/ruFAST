
#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));


use std::ffi::CString;

pub struct ImageFileImporter {
    ir: FASTImageFileImporterRef,
}

pub struct ProcessObjectPort {
    port: FASTProcessObjectPortRef,
}

pub trait Algorithm {
    fn getOutputPort(&mut self) -> ProcessObjectPort;
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort);
}

pub trait Renderer {
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort);
    fn getIr(&mut self) -> FASTRendererRef;
}

impl ImageFileImporter {
    pub fn new() -> Self {
        unsafe { ImageFileImporter { ir : FASTImageFileImporterNew() } }
    }
    pub fn setFilename(&mut self, name: &str)  {
        unsafe { FASTImageFileImporterSetFilename(self.ir, CString::new(name).unwrap().as_bytes_with_nul().as_ptr() as *const i8) };
    }
    pub fn getOutputPort(&mut self) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTImageFileImporterGetOutputPort(self.ir)} }
    }
}

impl Drop for ImageFileImporter {
    fn drop(&mut self) {
        unsafe { FASTImageFileImporterDelete(self.ir) };
    }
}

pub struct ImageResampler {
    ir: FASTImageResamplerRef,
}

impl ImageResampler {
    pub fn new() -> Self {
        unsafe { ImageResampler { ir : FASTImageResamplerNew() } }
    }
    pub fn setOutputSpacing2D(&mut self, spaceX: f32, spaceY: f32) {
        unsafe { FASTImageResamplerSetOutputSpacing2D(self.ir, spaceX, spaceY); };
    }
    pub fn setOutputSpacing3D(&mut self, spaceX: f32, spaceY: f32, spaceZ: f32) {
        unsafe { FASTImageResamplerSetOutputSpacing3D(self.ir, spaceX, spaceY, spaceZ); };
    }
}

impl Drop for ImageResampler {
    fn drop(&mut self) {
        unsafe { FASTImageResamplerDelete(self.ir) };
    }
}

impl Algorithm for ImageResampler {
    fn getOutputPort(&mut self) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTImageResamplerGetOutputPort(self.ir)} }
    }
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTImageResamplerSetInputConnection(self.ir, port.port); };
    }
}

pub struct SurfaceExtraction {
    ir: FASTSurfaceExtractionRef,
}

impl SurfaceExtraction {
    pub fn new() -> Self {
        unsafe { SurfaceExtraction { ir : FASTSurfaceExtractionNew() } }
    }
    pub fn setThreshold(&mut self, threshold: f32) {
        unsafe { FASTSurfaceExtractionSetThreshold(self.ir, threshold); };
    }
}

impl Drop for SurfaceExtraction {
    fn drop(&mut self) {
        unsafe { FASTSurfaceExtractionDelete(self.ir) };
    }
}

impl Algorithm for SurfaceExtraction {
    fn getOutputPort(&mut self) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTSurfaceExtractionGetOutputPort(self.ir)} }
    }
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTSurfaceExtractionSetInputConnection(self.ir, port.port); };
    }
}

pub struct ImageRenderer {
    ir: FASTRendererRef,
}
impl ImageRenderer {
    pub fn new() -> Self {
        unsafe { ImageRenderer { ir : FASTImageRendererNew() } }
    }
}
impl Renderer for ImageRenderer {
    fn getIr(&mut self) -> FASTRendererRef {
        self.ir
    }
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTRendererSetInputConnection(self.ir, port.port); };
    }
}
impl Drop for ImageRenderer {
    fn drop(&mut self) {
        unsafe { FASTRendererDelete(self.ir) };
    }
}

pub struct MeshRenderer {
    ir: FASTRendererRef,
}
impl MeshRenderer {
    pub fn new() -> Self {
        unsafe { MeshRenderer { ir : FASTMeshRendererNew() } }
    }
}
impl Renderer for MeshRenderer {
    fn getIr(&mut self) -> FASTRendererRef {
        self.ir
    }
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTRendererSetInputConnection(self.ir, port.port); };
    }
}
impl Drop for MeshRenderer {
    fn drop(&mut self) {
        unsafe { FASTRendererDelete(self.ir) };
    }
}

pub struct SimpleWindow {
    ir: FASTSimpleWindowRef,
}
impl SimpleWindow {
    pub fn new() -> Self {
        unsafe { SimpleWindow { ir : FASTSimpleWindowNew() } }
    }
    pub fn addRenderer(&mut self, renderer: &mut Renderer) {
        unsafe { FASTSimpleWindowAddRenderer(self.ir, renderer.getIr()); };
    }
    pub fn set2DMode(&mut self) {
        unsafe { FASTSimpleWindowSet2DMode(self.ir); };
    }
    pub fn setTimeout(&mut self, milliseconds: u32) {
        unsafe { FASTSimpleWindowSetTimeout(self.ir, milliseconds); };
    }
    pub fn getView(&mut self) -> View {
        unsafe { View { ir: FASTSimpleWindowGetView(self.ir) } }
    }
    pub fn start(&mut self) {
        unsafe { FASTSimpleWindowStart(self.ir); };
    }
}

impl Drop for SimpleWindow {
    fn drop(&mut self) {
        unsafe { FASTSimpleWindowDelete(self.ir) };
    }
}

pub struct View {
    ir: FASTViewRef,
}

impl View {
    pub fn setViewingPlane(&mut self, plane: Plane) {
        unsafe { FASTViewSetViewingPlane(self.ir, plane.ir) };
    }
}

pub struct Plane {
    ir: FASTPlaneRef,
}
impl Plane {
    pub fn coronal() -> Self {
        unsafe { Plane { ir: FASTPlaneCoronal() } }
    }
    pub fn sagittal() -> Self {
        unsafe { Plane { ir: FASTPlaneSagittal() } }
    }
    pub fn axial() -> Self {
        unsafe { Plane { ir: FASTPlaneAxial() } }
    }
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn surface_extraction_test() {
        let mut importer = ImageFileImporter::new();
        importer.setFilename("resources/CT/CT-Abdomen.mhd");

        let mut extraction = SurfaceExtraction::new();
        extraction.setInputConnection(&mut importer.getOutputPort());
        extraction.setThreshold(300.0);

        let mut surface_renderer = MeshRenderer::new();
        surfaceRenderer.setInputConnection(&mut extraction.getOutputPort());

        let mut window = SimpleWindow::new();
        window.addRenderer(&mut surfaceRenderer);
        window.setTimeout(5*1000);
        window.start();
    }
}
