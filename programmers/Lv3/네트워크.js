function solution(n, computers) {
    let answer = 0;
    let visit = Array(n).fill(false);
    for(let i=0;i<n;i++){
        if(!visit[i]){
            dfs(i);
            answer += 1;
        }
    }
    
    function dfs(cur){
        for(let i=0;i<computers[cur].length;i++){
            let next = computers[cur][i];
            if(!visit[i] && next === 1){
                visit[i] = true;
                dfs(i);
            }
        }
    }
    return answer;
}
