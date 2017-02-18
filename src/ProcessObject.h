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
    void FASTProcessObjectUpdate(FASTProcessObjectRef ir);



#define FAST_REF_DECL(name)			\
    typedef struct FASTOpaque##name *FAST##name##Ref; \
    FAST##name##Ref FAST##name##New(void);

#define FAST_RENDERER_DECL(name)			\
    void FAST##name##AddInputConnection(FAST##name##Ref ir, FASTProcessObjectPortRef port)

#define FAST_RENDERER_IMPL(name)			\
    void FAST##name##AddInputConnection(FAST##name##Ref ir, FASTProcessObjectPortRef port) { \
	unwrap(ir)->addInputConnection(unwrap(port));			\
    }

#define FAST_REF_IMPL(name)					\
    struct FASTOpaque##name {					\
	name::pointer p;					\
    };								\
    inline name::pointer unwrap(struct FASTOpaque##name  *Tys) { \
	return Tys->p;							\
    }									\
    FAST##name##Ref FAST##name##New() {				\
	struct FASTOpaque##name *o = new FASTOpaque##name();	\
	o->p = name::New();					\
	return o;							\
    }									\

    
#ifdef __cplusplus
}
#endif

#endif
    
