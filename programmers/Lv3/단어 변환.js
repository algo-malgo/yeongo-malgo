function solution(begin, target, words) {
    let answer = 987654321;
    let visit = Array(words.length).fill(false);
    if(!words.includes(target))return 0;
    search(begin,0);
    
    function search(cur,cnt){
        if(cur === target){
            answer = Math.min(answer,cnt);
            return;
        }
        for(let i=0;i<words.length;i++){
            const word = words[i];
            if(visit[i])continue;
            
            const diff = cur.split('').filter((x,idx) => x !== word[idx]).length;
            if(diff > 1)continue;
            
            if(diff === 1 && !visit[i]){
                visit[i] = true;
                search(word,cnt+1);
                visit[i] = false;
            }
        }
    }
    return answer;
}
