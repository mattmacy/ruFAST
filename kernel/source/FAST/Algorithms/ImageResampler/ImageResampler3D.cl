__constant sampler_t sampler = CLK_NORMALIZED_COORDS_FALSE | CLK_ADDRESS_CLAMP | CLK_FILTER_LINEAR;

float readImageAsFloat3D(__read_only image3d_t image, sampler_t sampler, float4 position) {
    int dataType = get_image_channel_data_type(image);
    if(dataType == CLK_FLOAT || dataType == CLK_SNORM_INT16 || dataType == CLK_UNORM_INT16) {
        return read_imagef(image, sampler, position).x;
    } else if(dataType == CLK_SIGNED_INT16 || dataType == CLK_SIGNED_INT8) {
        return (float)read_imagei(image, sampler, position).x;
    } else {
        return (float)read_imageui(image, sampler, position).x;
    }
}

__kernel void resample3D(
        __read_only image3d_t input,
        __global OUTPUT_TYPE* output,
        __private float scaleX,
        __private float scaleY,
        __private float scaleZ
) {
    const int4 outputPosition = {get_global_id(0), get_global_id(1), get_global_id(2), 0};
    const int3 size = {get_global_size(0), get_global_size(1), get_global_size(2)};
    float4 inputPosition = {outputPosition.x*(1.0f/scaleX), outputPosition.y*(1.0f/scaleY), outputPosition.z*(1.0f/scaleZ), 0};

    output[outputPosition.x + outputPosition.y*size.x + outputPosition.z*size.x*size.y] = readImageAsFloat3D(input, sampler, inputPosition);
}