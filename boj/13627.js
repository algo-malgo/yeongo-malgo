const fs = require("fs");
const readFileSyncAddress = "/dev/stdin";
// const readFileSyncAddress = "./input.txt";

const input = fs
  .readFileSync(readFileSyncAddress)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const [n, r] = input.shift().split(" ").map(Number);
const returned = input.shift().split(" ").map(Number);
const res = Array.from({ length: n }, (_, i) => i + 1).filter((v) => !returned.includes(v));
if (res.length === 0) console.log("*");
else console.log(res.join(" "));
