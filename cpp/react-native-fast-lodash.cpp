#include "react-native-fast-lodash.h"
#include "JsiMath/JsiMath.h"

void install(jsi::Runtime & rt) {
  installMath(rt);
}
