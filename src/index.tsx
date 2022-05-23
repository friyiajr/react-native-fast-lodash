import { NativeModules } from 'react-native';

NativeModules.FastLodash.install();

function ceil(num: number, precision: number = 0): number {
  return global.jsiCeil(num, precision);
}

function floor(num: number, precision: number = 0): number {
  return global.jsiFloor(num, precision);
}

function max(num: number[]): number {
  return global.jsiMax(num);
}

function min(num: number[]): number {
  return global.jsiMin(num);
}

export default {
  ceil,
  floor,
  max,
  min,
};
