function solution(progresses, speeds) {
    let answer = [];
    let st = [];
    progresses = progresses
        .map((progress,idx) => Math.ceil((100 - progress) / speeds[idx]))
        .forEach((progress) => {
        if(!st.length || st[0] >= progress){
            st.push(progress);
        }
        if(st[0] < progress){
            answer.push(st.length);
            st = [progress];
        }
    });
    answer.push(st.length);
    return answer;
}
