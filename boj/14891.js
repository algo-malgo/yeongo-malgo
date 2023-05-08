const fs = require("fs");
// const readFileSyncAddress = "/dev/stdin";
const readFileSyncAddress = "./input.txt";

const input = fs
  .readFileSync(readFileSyncAddress)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const arr = input.splice(0, 4).map((v) => v.split(""));
const k = +input.shift();
const rotate = input.map((v) => v.split(" ").map(Number));

rotate.forEach((v) => {
  const [num, dir] = v;
  let prev = dir;
  let next = dir;
  const rotateOp = [[num - 1, dir]];
  for (let i = num - 1; i >= 1; i--) {
    if (arr[i][6] === arr[i - 1][2]) break;
    prev = -prev;
    rotateOp.push([i - 1, prev]);
  }
  for (let i = num - 1; i < 3; i++) {
    if (arr[i][2] === arr[i + 1][6]) break;
    next = -next;
    rotateOp.push([i + 1, next]);
  }
  rotateOp.forEach((op) => {
    const [idx, dir] = op;
    rotateChain(idx, dir);
  });
});
console.log(calculateScore());

function rotateChain(idx, dir) {
  if (dir === 1) {
    const tmp = arr[idx].pop();
    arr[idx].unshift(tmp);
  } else {
    const tmp = arr[idx].shift();
    arr[idx].push(tmp);
  }
}

function calculateScore() {
  let sum = 0;
  for (let i = 0; i < 4; i++) {
    if (arr[i][0] === "1") {
      switch (i) {
        case 0:
          sum += 1;
          break;
        case 1:
          sum += 2;
          break;
        case 2:
          sum += 4;
          break;
        case 3:
          sum += 8;
          break;
      }
    }
  }
  return sum;
}
