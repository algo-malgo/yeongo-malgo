const fs = require("fs");
const readFileSyncAddress = "/dev/stdin";
// const readFileSyncAddress = "./input.txt";

const input = fs
  .readFileSync(readFileSyncAddress)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const n = parseInt(input.shift());
const arr = input.map((v) => v.split("").map(Number));
const answer = [];

function recur(s, x, y) {
  let sum = 0;
  for (let i = 0; i < s; i++) {
    for (let j = 0; j < s; j++) {
      sum += arr[y + i][x + j];
    }
  }
  if (sum === 0) answer.push(0);
  else if (sum === s * s) answer.push(1);
  else {
    s /= 2;
    answer.push("(");
    recur(s, x, y);
    recur(s, x + s, y);
    recur(s, x, y + s);
    recur(s, x + s, y + s);
    answer.push(")");
  }
}
recur(n, 0, 0);
console.log(answer.join(""));
