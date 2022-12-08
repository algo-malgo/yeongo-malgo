function solution(ingredient) {
    let answer = 0;
    let arr = [];
    
    function isHamburger(arr){
        return arr.join('') === '1231';
    }
    
    ingredient.forEach((x)=>{
      arr.push(x);
        if(arr.length >= 4){
            if(isHamburger(arr.slice(arr.length-4))){
                answer++;
                for(let i=0;i<4;i++){
                    arr.pop();
                }
            }
        }  
    })
    
    return answer;
}
