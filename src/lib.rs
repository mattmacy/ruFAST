#![feature(concat_idents)]
#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));


use std::ffi::CString;

pub struct ProcessObjectPort {
    port: FASTProcessObjectPortRef,
}

impl Drop for ProcessObjectPort {
    fn drop(&mut self) {
        unsafe { FASTProcessObjectPortDelete(self.port) };
    }
}

macro_rules! impl_process_object {
    ($name:ident) => (
        pub struct $name {
            ir: concat_idents!(FAST, $name, Ref)
        }
        impl ProcessObject for $name {
            fn new() -> Self {
                unsafe { $name { ir : concat_idents!(FAST, $name, New)() } }
            }
            fn getPOR(&mut self) -> FASTProcessObjectRef {
                self.ir as FASTProcessObjectRef
            }
        }
        impl Drop for $name {
            fn drop(&mut self) {
                unsafe { FASTProcessObjectDelete(self.ir as FASTProcessObjectRef) };
            }
        }
    )
}

pub trait ProcessObject {
    fn new() -> Self;
    fn getPOR(&mut self) -> FASTProcessObjectRef;
    fn getOutputPort(&mut self) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPortId(self.getPOR(), 0)} }
    }
    fn getOutputPortId(&mut self, portid: u32) -> ProcessObjectPort {
        unsafe { ProcessObjectPort {port : FASTProcessObjectGetOutputPortId(self.getPOR(), portid)} }
    }
    fn setInputConnection(&mut self, port : &mut ProcessObjectPort) {
        unsafe { FASTProcessObjectSetInputConnection(self.getPOR(), port.port); };
    }
}

impl_process_object!(ImageFileImporter);
impl_process_object!(ImageResampler);
impl_process_object!(SurfaceExtraction);
impl_process_object!(LungSegmentation);
impl_process_object!(Dilation);
impl_process_object!(Erosion);
impl_process_object!(ImageRenderer);
impl_process_object!(MeshRenderer);
impl_process_object!(SimpleWindow);

pub trait Renderer {
    fn getIr(&mut self) -> FASTRendererRef;
}
impl Renderer for ImageRenderer {
    fn getIr(&mut self) -> FASTRendererRef {
        self.ir  as FASTRendererRef
    }
}
impl Renderer for MeshRenderer {
    fn getIr(&mut self) -> FASTRendererRef {
        self.ir as FASTRendererRef
    }
}

impl ImageFileImporter {
    pub fn setFilename(&mut self, name: &str)  {
        unsafe { FASTImageFileImporterSetFilename(self.ir, CString::new(name).unwrap().as_bytes_with_nul().as_ptr() as *const i8) };
    }
}

impl ImageResampler {
    pub fn setOutputSpacing2D(&mut self, spaceX: f32, spaceY: f32) {
        unsafe { FASTImageResamplerSetOutputSpacing2D(self.ir, spaceX, spaceY); };
    }
    pub fn setOutputSpacing3D(&mut self, spaceX: f32, spaceY: f32, spaceZ: f32) {
        unsafe { FASTImageResamplerSetOutputSpacing3D(self.ir, spaceX, spaceY, spaceZ); };
    }
}

impl SurfaceExtraction {
    pub fn setThreshold(&mut self, threshold: f32) {
        unsafe { FASTSurfaceExtractionSetThreshold(self.ir, threshold); };
    }
}

impl Dilation {
    pub fn setStructuringElementSize(&self, size: i32) {
        unsafe { FASTDilationSetStructuringElementSize(self.ir, size) };
    }
}

impl Erosion {
    pub fn setStructuringElementSize(&self, size: i32) {
        unsafe { FASTErosionSetStructuringElementSize(self.ir, size) };
    }
}

impl MeshRenderer {
    pub fn addInputConnection(&mut self, port : &mut ProcessObjectPort, color: FASTColor, opacity: f32) {
        unsafe { FASTMeshRendererAddInputConnection(self.ir, port.port, color, opacity); };
    }
}

impl SimpleWindow {
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
    /* FAST code must be called from the main thread */

}
