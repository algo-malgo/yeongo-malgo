function solution(s) {
    var answer = [];
    let cnt = 0;
    let zero = 0;
    
    while(s !== "1"){
        let pos = s.indexOf(0);
        while(pos !== -1){
            pos = s.indexOf(0,pos+1);
            zero++;
        }
        s = s.replaceAll(0,'');
        s = (s.length).toString(2);
        cnt++;
    }
    answer.push(cnt,zero);
    return answer;
}
