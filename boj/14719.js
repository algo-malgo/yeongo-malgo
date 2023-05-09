const fs = require("fs");
const readFileSyncAddress = "/dev/stdin";
// const readFileSyncAddress = "./input.txt";

const input = fs
  .readFileSync(readFileSyncAddress)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const [H, W] = input.shift().split(" ").map(Number);
const arr = input.shift().split(" ").map(Number);
const block = [...Array(H)].map(() => [...Array(W)].map(() => 0));
for (let i = 0; i < arr.length; i++) {
  for (let j = 0; j < arr[i]; j++) {
    block[j][i] = 1;
  }
}
let answer = 0;

for (let i = 0; i < H; i++) {
  for (let j = 0; j < W; j++) {
    if (block[i][j]) {
      let tmp = j + 1;
      while (tmp < W && block[i][tmp] === 0) {
        tmp++;
      }
      if (tmp === W) break;
      answer += tmp - j - 1;
      j = tmp - 1;
    }
  }
}
console.log(answer);
