// -를 기준으로 분리한다.

const fs = require("fs");
const readFileSyncAddress = "/dev/stdin";
// const readFileSyncAddress = "./input.txt";

const input = fs
  .readFileSync(readFileSyncAddress)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const str = input.shift();
const arr = str.split("-");
let answer = 0;
for (let i = 0; i < arr.length; i++) {
  const tmp = arr[i].split("+").map(Number);
  const res = tmp.reduce((acc, cur) => (acc += cur), 0);
  if (i === 0) answer += res;
  else answer -= res;
}
console.log(answer);
