#include "react-native-fast-lodash.h"

using namespace facebook;

int computeGcd(int a, int b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}

void installMath(jsi::Runtime & rt) {
  auto propId = jsi::PropNameID::forAscii(rt, "gcd");
  auto lamda = [](jsi::Runtime & rt,
    const jsi::Value & thisValue,
    const jsi::Value * args,
    size_t count
  ) -> jsi::Value {
    auto data = args -> asObject(rt);
    auto aValue = data.getProperty(rt, "a");
    auto bValue = data.getProperty(rt, "b");
    int a = aValue.asNumber();
    int b = bValue.asNumber();
    int gcd = computeGcd(a, b);
    return jsi::Value(gcd);
  };
  jsi::Function gcd =
      jsi::Function::createFromHostFunction(rt, propId, 2, lamda);
  rt.global().setProperty(rt, "jsiGcd", gcd);
}
