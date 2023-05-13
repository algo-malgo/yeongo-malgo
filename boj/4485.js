const fs = require("fs");
const readFileSyncAddress = "/dev/stdin";
// const readFileSyncAddress = "./input.txt";

const input = fs
  .readFileSync(readFileSyncAddress)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const dx = [-1, 0, 1, 0];
const dy = [0, -1, 0, 1];
let idx = 1;

while (1) {
  const n = +input.shift();
  if (n === 0) break;
  let arr = input.splice(0, n).map((v) => v.split(" ").map(Number));

  const visit = [...Array(n)].map(() => [...Array(n)].map(() => 987654321));
  const q = [[0, 0]];
  visit[0][0] = arr[0][0];
  while (q.length) {
    const [x, y] = q.shift();
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
        if (visit[nx][ny] > visit[x][y] + arr[nx][ny]) {
          visit[nx][ny] = visit[x][y] + arr[nx][ny];
          q.push([nx, ny]);
        }
      }
    }
  }
  console.log(`Problem ${idx++}: ${visit[n - 1][n - 1]}`);
}
