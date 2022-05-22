import { NativeModules } from 'react-native';

NativeModules.FastLodash.install();

declare global {
  function jsiGcd(values: object): number;
}

export function gcd(values: object): number {
  return global.jsiGcd(values);
}
