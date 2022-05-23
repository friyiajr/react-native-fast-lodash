import { NativeModules } from 'react-native';

NativeModules.FastLodash.install();

/**
 * Calculates the ceiling of a number to a given precision
 * @param num value you want to compute the ceiling of
 * @param precision value you want to round to
 * @returns number
 */
function ceil(num: number, precision: number = 0): number {
  return global.jsiCeil(num, precision);
}

/**
 * Calculates the floor of a number to a given precision
 * @param num value you want to compute the ceiling of
 * @param precision value you want to round to
 * @returns number
 */
function floor(num: number, precision: number = 0): number {
  return global.jsiFloor(num, precision);
}

/**
 * Calculates the max value in an array of values
 * @param nums the numbers to calculate the max for
 * @returns number
 */
function max(nums: number[]): number {
  return global.jsiMax(nums);
}

/**
 * Calculates the min value in an array of values
 * @param nums the numbers to calculate the min for
 * @returns number
 */
function min(nums: number[]): number {
  return global.jsiMin(nums);
}

export default {
  ceil,
  floor,
  max,
  min,
};
