function solution(babbling) {
    let answer = 0;
    const base = ["aya", "ye", "woo", "ma"];
    babbling.forEach(x => {
        let prev = "";
        let tmp = x;
        while(1){
            base.forEach(b => {
                if(x.slice(0, b.length) === b && prev !== b){
                    x = x.replace(b,'');
                    prev = b;
                }
            });
            if(x.length === 0)break;
            if(tmp === x)break;
            tmp = x;
        }
        if(x.length === 0){
            answer += 1;
        }
    })    
    return answer;
}
