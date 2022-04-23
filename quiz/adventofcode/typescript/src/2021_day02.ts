import fs from 'fs';
import path from 'path';

type Command = {
  dir: string;
  unit: number;
}

type Position = {
  depth: number;
  horizontal: number;
}

export const AoC2021Day02 = (): void => {
  const file_path = path.join(__dirname, '../../2021_day02_input.txt');
  const data = fs.readFileSync(file_path).toString().split('\n');
  const cmd: Command[] = data.map(line => {
    let str = line.split(' ');
    return { dir: str[0], unit: Number(str[1]) };
  });

  const part1 = (cmd: Command[]): number => {
    let positions: Position = { depth: 0, horizontal: 0 };
    cmd.forEach(c => {
      switch (c.dir) {
        case 'forward':
          positions.horizontal += c.unit;
          break;
        case 'down':
          positions.depth += c.unit;
          break;
        case 'up':
          positions.depth -= c.unit;
          break;
      }
    });
    return positions.depth * positions.horizontal;
  }

  const part2 = (cmd: Command[]): number => {
    let aim = 0;
    let positions: Position = { depth: 0, horizontal: 0 };
    cmd.forEach(c => {
      switch (c.dir) {
        case 'forward':
          positions.horizontal += c.unit;
          positions.depth += c.unit * aim;
          break;
        case 'down':
          aim += c.unit;
          break;
        case 'up':
          aim -= c.unit;
          break;
      }
    });
    return positions.depth * positions.horizontal;
  }

  console.log("part1's answer: " + part1(cmd));
  console.log("part2's answer: " + part2(cmd));
};
