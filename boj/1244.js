const fs = require("fs");
const readFileSyncAddress = "/dev/stdin";
// const readFileSyncAddress = "./input.txt";

const input = fs
  .readFileSync(readFileSyncAddress)
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.trim());

const n = +input.shift();
const switches = input.shift().split(" ").map(Number);
let m = +input.shift();
const arr = input.map((v) => v.split(" ").map(Number));

for (let i = 0; i < m; i++) {
  const [gender, tmp] = arr[i];
  const num = tmp - 1;

  if (gender === 1) {
    const multiple = [];
    for (let j = 1; j <= n; j++) {
      if (j % tmp === 0) multiple.push(j - 1);
    }
    toggleSwitch(multiple);
  } else {
    let start = num;
    let end = num;
    const section = [];
    for (let j = 0; j < n; j++) {
      if (num - j - 1 < 0 || num + j + 1 >= n) break;
      if (switches[num - j - 1] !== switches[num + j + 1]) break;
      if (switches[num - j - 1] === switches[num + j + 1]) {
        start = num - j - 1;
        end = num + j + 1;
      }
    }
    for (let j = start; j <= end; j++) section.push(j);
    toggleSwitch(section);
  }
}
let answer = "";
for (let i = 0; i < switches.length; i++) {
  answer += switches[i] + " ";
  if ((i + 1) % 20 === 0) {
    console.log(answer);
    answer = "";
  }
}
if (answer !== "") console.log(answer);

function toggleSwitch(arr) {
  for (let i = 0; i < arr.length; i++) {
    switches[arr[i]] = switches[arr[i]] === 0 ? 1 : 0;
  }
}
