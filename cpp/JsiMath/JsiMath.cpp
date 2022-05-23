#include <cmath>
#include <float.h>

#include "JsiMath.h"

using namespace facebook;

/// Revieves a decimal number and a precision value then rounds up to that precision
JSI_HOST_FUNCTION(jsiCeil) {
  auto numberToRound = args[0].asNumber();
  
  // Default to 0 decimal places if no precision value
  // is specified
  auto base = count > 1 ? args[1].asNumber() : 0;
  
  // Use powers of 10 to increase to a larger value that can
  // be rounded more easily.
  // For example:
  //    5.124 * 100  = 512.4
  //    ceil(512.4)  = 513
  //    512 / 100    = 5.13
  auto denominator = pow(10, base);
  auto result = ceil(numberToRound * denominator) / denominator;
  return jsi::Value(result);
};

/// Revieves a decimal number and a precision value then rounds down to that precision
JSI_HOST_FUNCTION(jsiFloor) {
  auto numberToRound = args[0].asNumber();
  
  // Default to 0 decimal places if no precision value
  // is specified
  auto base = count > 1 ? args[1].asNumber() : 0;
  
  // Use powers of 10 to increase to a larger value that can
  // be rounded more easily.
  // For example:
  //    5.124 * 100  = 512.4
  //    floor(512.4) = 512
  //    512 / 100    = 5.12
  auto denominator = pow(10, base);
  auto result = floor(numberToRound * denominator) / denominator;
  return jsi::Value(result);
};

/// Revieves an array of numbers and returns the max
JSI_HOST_FUNCTION(jsiMax) {
  auto rawArray = args[0].asObject(rt);
  auto array = rawArray.asArray(rt);
  
  auto rawLength = rawArray.getProperty(rt, "length");
  auto length = rawLength.asNumber();
  
  if(length == 0) {
    return jsi::Value(nullptr);
  }
  
  auto max = DBL_MIN;
  
  for(auto i = 0; i < length; i++) {
    auto currentVal = array.getValueAtIndex(rt, i).asNumber();
    if(currentVal > max) {
      max = currentVal;
    }
  }
  
  return jsi::Value(max);
}

/// Revieves an array of numbers and returns the min
JSI_HOST_FUNCTION(jsiMin) {
  auto rawArray = args[0].asObject(rt);
  auto values = rawArray.asArray(rt);
  auto length = rawArray.getProperty(rt, "length");
  
  if(length.asNumber() == 0) {
    return jsi::Value(nullptr);
  }
  
  auto min = DBL_MAX;
  
  for(auto i = 0; i < length.asNumber(); i++) {
    auto currentVal = values.getValueAtIndex(rt, i).asNumber();
    if(currentVal < min) {
      min = currentVal;
    }
  }
  
  return jsi::Value(min);
}

void installMath(jsi::Runtime & rt) {
  auto floorId = jsi::PropNameID::forAscii(rt, "floor");
  jsi::Function floor =
    jsi::Function::createFromHostFunction(rt, floorId, 1, jsiFloor);
  rt.global().setProperty(rt, "jsiFloor", floor);
  
  auto ceilId = jsi::PropNameID::forAscii(rt, "ceil");
  jsi::Function ceil =
    jsi::Function::createFromHostFunction(rt, ceilId, 1, jsiCeil);
  rt.global().setProperty(rt, "jsiCeil", ceil);
  
  auto maxId = jsi::PropNameID::forAscii(rt, "max");
  jsi::Function max =
    jsi::Function::createFromHostFunction(rt, maxId, 1, jsiMax);
  rt.global().setProperty(rt, "jsiMax", max);
  
  auto minId = jsi::PropNameID::forAscii(rt, "min");
  jsi::Function min =
    jsi::Function::createFromHostFunction(rt, minId, 1, jsiMin);
  rt.global().setProperty(rt, "jsiMin", min);
}
