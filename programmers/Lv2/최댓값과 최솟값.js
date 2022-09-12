function solution(s) {
    var answer = '';
    const arr = s.split(' ');
    arr.sort((a,b)=>a-b);
    answer = arr[0] + " " + arr.at(-1);
    return answer;
}
