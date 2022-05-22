import { NativeModules } from 'react-native';

NativeModules.FastLodash.install();

function ceil(num: number, precision: number = 0): number {
  return global.jsiCeil(num, precision);
}

function floor(num: number, precision: number = 0): number {
  return global.jsiFloor(num, precision);
}

export default {
  ceil,
  floor,
};
