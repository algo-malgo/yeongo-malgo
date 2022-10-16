function solution(skill, skill_trees) {
    let answer = 0;
    skill_trees.forEach(x => {
        let sk = skill;
        let flag = true;
        
        x.split('').forEach(el => {
            if(sk.length && sk[0] === el){
                sk = sk.slice(1);
            }else if(sk.includes(el)){
                flag = false;
            }
        });
        if(!sk.length ||  (sk.length && flag)){
            answer++;
        }
    })
    return answer;
}
