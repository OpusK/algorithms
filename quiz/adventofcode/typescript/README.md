# [Advent of Code](https://adventofcode.com/) using Typescript

## Setup environment
- For Node.js
  ```bash
  npm init -y                         # for package.json
  npm install typescript --save-dev   # for typescript
  npm install @types/node --save-dev  # for node.d.ts
  npx tsc --init --rootDir src --outDir lib --esModuleInterop --resolveJsonModule --lib es6,dom --module commonjs     # for tsconfig.json
  ```

- For live compilation + running
  ```bash
  npm install ts-node --save-dev  # for live compilation
  npm install nodemon --save-dev  # for watching changes 
  ```
  - Add npm scripts to package.json
    ```bash
    "scripts": {
      "start": "npm run build:live",
      "build": "tsc -p .",
      "build:live": "nodemon --watch src --ext ts,txt --exec \"ts-node\" src/index.ts"
    },
    ```
- Run & Enjoy
  ```bash
  npm run start
  ```
