function solution(p) {
    var answer = '';
    
    function isCorrect(str){
        let cnt = 0;
        for(let i=0;i<str.length;i++){
            if(str[i] === '(')cnt++;
            else cnt--;
            if(cnt < 0)return false;
        }
        return true;
    }
    
    function recur(w,u,v){
        if(w === "")return "";
        
        let cnt = 0;
        for(let i=0;i<w.length;i++){
            if(w[i] === '(')cnt++;
            else cnt--;
            if(cnt === 0){
                u = w.slice(0,i+1);
                v = w.slice(i+1);
                break;
            }
        }
        if(isCorrect(u)){
            return u + recur(v,"","");
        }else{
            let str = '(' + recur(v,"","") + ')';
            u = u.slice(1,u.length-1);
            for(let el of u){
                if(el === '(')str += ')';
                else str += '(';
            }
            return str;
        }
    }
    
    answer = recur(p,"","");
    
    return answer;
}
