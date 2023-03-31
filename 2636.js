const fs = require("fs");
const readFileSyncAddress = "/dev/stdin";

const input = fs
  .readFileSync(readFileSyncAddress)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const [n, m] = input.shift().split(" ").map(Number);
let arr = input.map((v) => v.split(" ").map(Number));
const dx = [-1, 1, 0, 0];
const dy = [0, 0, -1, 1];

let day = 0;
let cnt = 0;

while (1) {
  if (isAllMelt()) break;
  cnt = bfs();
  day++;
}
console.log(`${day}\n${cnt}`);

function bfs() {
  const q = [[0, 0]];
  const visit = [...Array(n)].map(() => [...Array(m)].map(() => 0));
  visit[0][0] = 1;
  const cheezeToMelt = [];

  while (q.length) {
    const [x, y] = q.shift();
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visit[nx][ny]) {
        if (arr[nx][ny] === 0) {
          q.push([nx, ny]);
        } else {
          cheezeToMelt.push([nx, ny]);
        }
        visit[nx][ny] = 1;
      }
    }
  }
  cheezeToMelt.forEach(([x, y]) => {
    arr[x][y] = 0;
  });
  return cheezeToMelt.length;
}

function isAllMelt() {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (arr[i][j] === 1) return false;
    }
  }
  return true;
}
