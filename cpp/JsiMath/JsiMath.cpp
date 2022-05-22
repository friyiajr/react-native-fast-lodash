#include <cmath>

#include "JsiMath.h"

using namespace facebook;

/// Revieves a decimal number and a precision value then rounds up to that precision
/// @param rt a reference to the runtime environment
/// @param thisValue JavaScript this value context
/// @param args arguments from JS
/// @param count total number of arguments passed to the function
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
/// @param rt a reference to the runtime environment
/// @param thisValue JavaScript this value context
/// @param args arguments from JS
/// @param count total number of arguments passed to the function
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

void installMath(jsi::Runtime & rt) {
  auto floorId = jsi::PropNameID::forAscii(rt, "floor");
  jsi::Function floor =
    jsi::Function::createFromHostFunction(rt, floorId, 1, jsiFloor);
  rt.global().setProperty(rt, "jsiFloor", floor);
  
  auto ceilId = jsi::PropNameID::forAscii(rt, "ceil");
  jsi::Function ceil =
    jsi::Function::createFromHostFunction(rt, ceilId, 1, jsiCeil);
  rt.global().setProperty(rt, "jsiCeil", ceil);
}
