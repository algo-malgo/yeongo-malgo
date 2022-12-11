function solution(n) {
    let answer = "";
    while(n > 0){
        const res = n % 3;
        answer += (res || 4).toString();
        if(n === 3)break;
        n = !res ? Math.floor(n / 3)-1 : Math.floor(n / 3);
    }
    return answer.split('').reverse().join('');
}
