/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
     const answer = [];
     const visit = [...Array(candidates.length)].map(()=>0);
     candidates.sort((a,b)=>a-b);

     function recur(sum, arr, idx){
        if(sum === target){
            answer.push(arr);
            return;
        }
        for(let i=idx;i<candidates.length;i++){
            const cur = candidates[i];
            if(sum + cur > target)continue;
            recur(sum + cur, [...arr, cur], i);
        }
    }
    recur(0, [], 0);
    return answer;
};
