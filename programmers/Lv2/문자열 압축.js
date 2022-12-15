function solution(s) {
    let answer = s.length;
    for(let i=1;i<=Math.floor(s.length / 2);i++){
        let res = "";
        
        for(let j=0;j<s.length;j+=i){
            const cur = s.slice(j,j+i);
            let cnt = 1;
            while(1){
                j += i;
                const next = s.slice(j,j+i);
                if(next === cur){
                    cnt++;
                }
                else{
                    break;
                }
            }
            res += cnt >= 2 ? cnt + cur : cur;
            j -= i; // 해당 j값에서부터 시작해야 하므로 다음 for문 증가될거 여기서 감소
        }
        answer = Math.min(answer, res.length);
    }
    return answer;
}
