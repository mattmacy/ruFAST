
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

pub trait ProcessObject {
    fn getOutputPort(&mut self) -> ProcessObjectPort;
    fn getOutputPortId(&mut self, portid: u32) -> ProcessObjectPort;
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort);
}

pub trait Renderer {
    fn getIr(&mut self) -> FASTRendererRef;
}

impl ImageFileImporter {
    pub fn new() -> Self {
        unsafe { ImageFileImporter { ir : FASTImageFileImporterNew() } }
    }
    pub fn setFilename(&mut self, name: &str)  {
        unsafe { FASTImageFileImporterSetFilename(self.ir, CString::new(name).unwrap().as_bytes_with_nul().as_ptr() as *const i8) };
    }
}

impl ProcessObject for ImageFileImporter{
    fn getOutputPort(&mut self) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPort(self.ir as FASTProcessObjectRef, 0)} }
    }
    fn getOutputPortId(&mut self, portid: u32) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPort(self.ir as FASTProcessObjectRef, portid)} }
    }
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTProcessObjectSetInputConnection(self.ir as FASTProcessObjectRef, port.port); };
    }
}

impl Drop for ImageFileImporter {
    fn drop(&mut self) {
        unsafe { FASTProcessObjectDelete(self.ir as FASTProcessObjectRef) };
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
        unsafe { FASTProcessObjectDelete(self.ir as FASTProcessObjectRef) };
    }
}

impl ProcessObject for ImageResampler {
    fn getOutputPort(&mut self) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPort(self.ir as FASTProcessObjectRef, 0)} }
    }
    fn getOutputPortId(&mut self, portid: u32) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPort(self.ir as FASTProcessObjectRef, portid)} }
    }
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTProcessObjectSetInputConnection(self.ir as FASTProcessObjectRef, port.port); };
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
        unsafe { FASTProcessObjectDelete(self.ir as FASTProcessObjectRef) };
    }
}

impl ProcessObject for SurfaceExtraction {
    fn getOutputPort(&mut self) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPort(self.ir as FASTProcessObjectRef, 0)} }
    }
    fn getOutputPortId(&mut self, portid: u32) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPort(self.ir as FASTProcessObjectRef, portid)} }
    }
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTProcessObjectSetInputConnection(self.ir as FASTProcessObjectRef, port.port); };
    }
}


pub struct LungSegmentation {
    ir: FASTLungSegmentationRef,
}

impl LungSegmentation {
    pub fn new() -> Self {
        unsafe { LungSegmentation { ir : FASTLungSegmentationNew() } }
    }
}

impl Drop for LungSegmentation {
    fn drop(&mut self) {
        unsafe { FASTProcessObjectDelete(self.ir as FASTProcessObjectRef) };
    }
}

impl ProcessObject for LungSegmentation {
    fn getOutputPort(&mut self) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPort(self.ir as FASTProcessObjectRef, 0)} }
    }
    fn getOutputPortId(&mut self, portid: u32) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPort(self.ir as FASTProcessObjectRef, portid)} }
    }
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTProcessObjectSetInputConnection(self.ir as FASTProcessObjectRef, port.port); };
    }
}

pub struct ImageRenderer {
    ir: FASTImageRendererRef,
}
impl ImageRenderer {
    pub fn new() -> Self {
        unsafe { ImageRenderer { ir : FASTImageRendererNew() } }
    }
}
impl Renderer for ImageRenderer {
    fn getIr(&mut self) -> FASTRendererRef {
        self.ir  as FASTRendererRef
    }
}
impl ProcessObject for ImageRenderer {
    fn getOutputPort(&mut self) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPort(self.ir as FASTProcessObjectRef, 0)} }
    }
    fn getOutputPortId(&mut self, portid: u32) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPort(self.ir as FASTProcessObjectRef, portid)} }
    }
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTProcessObjectSetInputConnection(self.ir as FASTProcessObjectRef, port.port); };
    }
}
impl Drop for ImageRenderer {
    fn drop(&mut self) {
        unsafe { FASTProcessObjectDelete(self.ir as FASTProcessObjectRef) };
    }
}

pub struct MeshRenderer {
    ir: FASTMeshRendererRef,
}
impl MeshRenderer {
    pub fn new() -> Self {
        unsafe { MeshRenderer { ir : FASTMeshRendererNew() } }
    }
    pub fn addInputConnection(&mut self, port : &mut ProcessObjectPort, color: FASTColor, opacity: f32) {
        unsafe { FASTMeshRendererAddInputConnection(self.ir, port.port, color, opacity); };
    }
}
impl ProcessObject for MeshRenderer {
    fn getOutputPort(&mut self) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPort(self.ir as FASTProcessObjectRef, 0)} }
    }
    fn getOutputPortId(&mut self, portid: u32) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPort(self.ir as FASTProcessObjectRef, portid)} }
    }
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTProcessObjectSetInputConnection(self.ir as FASTProcessObjectRef, port.port); };
    }
}
impl Renderer for MeshRenderer {
    fn getIr(&mut self) -> FASTRendererRef {
        self.ir as FASTRendererRef
    }
}
impl Drop for MeshRenderer {
    fn drop(&mut self) {
        unsafe { FASTProcessObjectDelete(self.ir as FASTProcessObjectRef) };
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
        unsafe { FASTProcessObjectDelete(self.ir as FASTProcessObjectRef) };
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
