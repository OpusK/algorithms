import fs from 'fs';
import path from 'path';

export const AoC2021Day01 = (): void => {
  const file_path = path.join(__dirname, '../../2021_day01_input.txt');
  const data = fs.readFileSync(file_path).toString()
    .split('\n').map(Number);

  const part1 = (input: number[]): number => {
    return input.reduce((larger_cnt, curr, idx, arr) => {
      // no previous measurement
      if (idx > 0 && curr > arr[idx - 1]) {
        larger_cnt++;
      }
      return larger_cnt;
    }, 0);
  }

  const part2 = (input: number[]): number => {
    return input.reduce((larger_cnt, curr, idx, arr) => {
      // slide window with 3 elements
      if (idx < arr.length - 3 && curr < arr[idx + 3]) {
        larger_cnt++;
      }
      return larger_cnt;
    }, 0);
  }

  console.log("part1's answer: " + part1(data));
  console.log("part2's answer: " + part2(data));
};
