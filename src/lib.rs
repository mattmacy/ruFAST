
#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

pub struct ImageImporter {
    ir: FASTImageImporterRef,
}

pub struct ProcessObjectPort {
    port: FASTProcessObjectPortRef,
}

impl ImageImporter {
    pub fn new() -> Self {
        unsafe { ImageImporter { ir : FASTImageImporterNew() } }
    }
    pub fn setFilename(&mut self, name: &str) {
        unsafe { FASTImageImporterSetFilename(self.ir, name.as_ptr()); };
    }
    pub fn getOutputPort(&mut self) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTImageImporterGetOutputPort(self.ir)} }
    }
}

impl Drop for ImageImporter {
    fn drop(&mut self) {
        unsafe { FASTImageImporterDelete(self.ir) };
    }
}

pub struct ImageResampler {
    ir: FASTImageResamplerRef,
}

impl ImageResampler {
    pub fn new() -> Self {
        unsafe { ImageResampler { ir : FASTImageResamplerNew() } }
    }
    pub fn getOutputPort(&mut self) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTImageResamplerGetOutputPort(self.ir)} }
    }
    pub fn setOutputSpacing2D(&mut self, spaceX: f32, spaceY: f32) {
        unsafe { FASTImageResamplerSetOutputSpacing2D(self.ir, spaceX, spaceY); };
    }
    pub fn setOutputSpacing3D(&mut self, spaceX: f32, spaceY: f32, spaceZ: f32) {
        unsafe { FASTImageResamplerSetOutputSpacing3D(self.ir, spaceX, spaceY, spaceZ); };
    }
    pub fn setInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTImageResamplerSetInputConnection(self.ir, port.port); };
    }
}

impl Drop for ImageResampler {
    fn drop(&mut self) {
        unsafe { FASTImageResamplerDelete(self.ir) };
    }
}


pub struct ImageRenderer {
    ir: FASTImageRendererRef,
}

impl ImageRenderer {
    pub fn new() -> Self {
        unsafe { ImageRenderer { ir : FASTImageRendererNew() } }
    }
    pub fn addInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTImageRendererAddInputConnection(self.ir, port.port); };
    }
}

impl Drop for ImageRenderer {
    fn drop(&mut self) {
        unsafe { FASTImageRendererDelete(self.ir) };
    }
}


pub struct SimpleWindow {
    ir: FASTSimpleWindowRef,
}

impl SimpleWindow {
    pub fn new() -> Self {
        unsafe { SimpleWindow { ir : FASTSimpleWindowNew() } }
    }
    pub fn addRenderer(&mut self, renderer: ImageRenderer) {
        unsafe { FASTSimpleWindowAddRenderer(self.ir, renderer.ir); };
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
    fn image_resampler_test() {
        let mut importer = ImageImporter::new();
        importer.setFilename("resources/CT/CT-Abdomen.mhd");

        let mut resampler = ImageResampler::new();
        resampler.setOutputSpacing3D(1.0, 1.0, 1.0);
        resampler.setInputConnection(&mut importer.getOutputPort());

        let mut renderer = ImageRenderer::new();
        renderer.addInputConnection(&mut resampler.getOutputPort());

        let mut window = SimpleWindow::new();
        window.addRenderer(renderer);
        window.set2DMode();
        window.getView().setViewingPlane(Plane::coronal());
        window.setTimeout(500);
        window.start();
        println!("finished test!");
    }
}
