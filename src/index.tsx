// @ts-nocheck

import { NativeModules } from 'react-native';

NativeModules.FastLodash.install()

export function gcd(values: object): number {
  return global.jsiGcd(values);
}


