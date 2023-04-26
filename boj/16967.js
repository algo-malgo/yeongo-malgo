const fs = require("fs");
const readFileSyncAddress = "/dev/stdin";
// const readFileSyncAddress = "./input.txt";

const input = fs
  .readFileSync(readFileSyncAddress)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const [H, W, X, Y] = input.shift().split(" ").map(Number);
let B = input.map((v) => v.split(" ").map(Number));
const answer = [];
for (let i = X; i < H; i++) {
  for (let j = Y; j < W; j++) {
    const origin = B[i - X][j - Y];
    B[i][j] = B[i][j] - origin;
  }
}

for (let i = 0; i < H; i++) {
  const tmp = [];
  for (let j = 0; j < W; j++) {
    tmp.push(B[i][j]);
  }
  answer.push(tmp.join(" "));
}
console.log(answer.join("\n"));
