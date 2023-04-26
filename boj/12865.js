const fs = require("fs");
const readFileSyncAddress = "/dev/stdin";
// const readFileSyncAddress = "./input.txt";

const input = fs
  .readFileSync(readFileSyncAddress)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const [n, k] = input.shift().split(" ").map(Number);
const arr = [[0, 0], ...input.map((v) => v.split(" ").map(Number))];
const dp = [...Array(n + 1)].map(() => [...Array(k + 1)].map(() => 0));

for (let i = 1; i <= n; i++) {
  const [w, v] = arr[i];
  for (let j = 1; j <= k; j++) {
    if (j < w) {
      dp[i][j] = dp[i - 1][j];
    } else {
      dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - w] + v);
    }
  }
}
console.log(dp[n][k]);
