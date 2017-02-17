#ifndef CFAST_PROCESS_OBJECT_H
#define CFAST_PROCESS_OBJECT_H
#ifdef __cplusplus
extern "C" {
#endif    

    typedef struct FASTOpaqueProcessObjectPort *FASTProcessObjectPortRef;
    typedef struct FASTOpaqueProcessObject *FASTProcessObjectRef;
    FASTProcessObjectPortRef FASTProcessObjectGetOutputPortId(FASTProcessObjectRef ir, uint32_t portid);
    void FASTProcessObjectSetInputConnection(FASTProcessObjectRef ir, FASTProcessObjectPortRef port);
    void FASTProcessObjectDelete(FASTProcessObjectRef ir);
    void FASTProcessObjectPortDelete(FASTProcessObjectPortRef ir);

    
#ifdef __cplusplus
}
#endif

#endif
    
