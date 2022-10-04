function solution(n, words) {
    var answer = [];
    
    const history = [];

    for(let i=0;i<words.length;i++){
        if(i == 0){
            history.push(words[i]);
            continue;
        }
        if(history.includes(words[i])){
            return [(i % n)+1,Math.floor(i / n)+1];
        }
        if(words[i-1].at(words[i-1].length-1) !== words[i].at(0)){
            return [(i % n)+1,Math.floor(i / n)+1];
        }
        history.push(words[i])
    }

    return [0,0];
}
