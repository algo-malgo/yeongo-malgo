function solution(priorities, location) {
    var answer = 0;
    let pq = [];
    let q = [];
    priorities.forEach((priority,idx)=>{
        pq.push(priority);
        q.push({priority, idx});
    });
    pq = pq.sort((a,b)=>b-a);
    while(q.length !== 0){
        const {priority, idx} = q[0];
        q.shift();
        
        if(priority === pq[0]){
            pq.shift();
            answer++;
            if(idx === location)return answer;
        }else{
            q.push({priority,idx});
        }
    }
    return answer;
}
