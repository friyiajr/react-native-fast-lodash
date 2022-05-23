#include <jsi/jsilib.h>
#include <jsi/jsi.h>

#ifndef Macros_h
#define Macros_h

/// Macro that generates the header for all JSI functions
/// @param rt a reference to the runtime environment
/// @param thisValue JavaScript this value context
/// @param args arguments from JS
/// @param count total number of arguments passed to the function
#define JSI_HOST_FUNCTION(NAME)                                           \
  jsi::Value NAME(jsi::Runtime &rt, const jsi::Value &thisValue,          \
                  const jsi::Value *args, size_t count)

#endif
