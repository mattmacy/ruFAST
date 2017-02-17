extern crate bindgen;
extern crate gcc;

use std::env;
use std::path::PathBuf;

fn main() {
    // Tell cargo to tell rustc to link the system bzip2
    // shared library.
    println!("cargo:rustc-link-search=native=/usr/local/fast/lib");
    println!("cargo:rustc-link-lib=FAST");
    println!("cargo:rustc-link-lib=GLEW");
    println!("cargo:rustc-link-lib=igtlutil");
    println!("cargo:rustc-link-lib=OpenIGTLink");
    println!("cargo:rustc-link-lib=Qt5Core");
    println!("cargo:rustc-link-lib=Qt5Gui");
    println!("cargo:rustc-link-lib=Qt5Widgets");

    // The bindgen::Builder is the main entry point
    // to bindgen, and lets you build up options for
    // the resulting bindings.
    let bindings = bindgen::Builder::default()
        // Do not generate unstable Rust code that
        // requires a nightly rustc and enabling
        // unstable features.
        .no_unstable_rust()
        .clang_arg("-Isrc")
        .header("src/wrapper.h")
    // Finish the builder and generate the bindings.
        .generate()
        // Unwrap the Result and panic on failure.
        .expect("Unable to generate bindings");

    // Write the bindings to the $OUT_DIR/bindings.rs file.
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
    //gcc::compile_library("libcFAST.a", &["src/Data.cpp", "src/Algorithms.cpp"]);
    gcc::Config::new()
        .file("src/Algorithms.cpp")
        .file("src/Data.cpp")
        .file("src/Importers.cpp")
        .file("src/Visualization.cpp")
        .file("src/ProcessObject.cpp")
        .include("src")
        .include("/usr/local/fast/include")
        .include("/usr/include/eigen3")
        .include("/usr/include/x86_64-linux-gnu/qt5/QtWidgets/")
        .include("/usr/include/x86_64-linux-gnu/qt5/QtCore")
        .include("/usr/include/x86_64-linux-gnu/qt5/QtGui")
        .include("/usr/include/x86_64-linux-gnu/qt5")
        .flag("-std=c++11")
        .flag("-Wno-deprecated-declarations")
        .object("/usr/local/fast/lib/libFAST.so")
        .pic(true)
        .compile("libcFAST.a");
}
