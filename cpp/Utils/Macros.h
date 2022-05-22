#ifndef Macros_h
#define Macros_h

#define JSI_HOST_FUNCTION(NAME)                                           \
  jsi::Value NAME(jsi::Runtime &rt, const jsi::Value &thisValue,          \
                  const jsi::Value *args, size_t count)

#endif

