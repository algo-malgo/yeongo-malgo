function sherlockAndAnagrams(s) {
    const arr = getString(s);
    const obj = {};
    arr.forEach(v => {
        obj[v] = (obj[v] || 0) + 1;
    })
    let answer = 0;
    Object.values(obj).forEach(value => {
        const res = getCount(value)
        answer += res;
    })
    return answer;
}
function getString(s){
    const tmp = [];
    for(let i=0;i<s.length;i++){
        for(let j=i+1;j<=s.length;j++){
            const res = s.slice(i, j).split('').sort().join('')
            tmp.push(res);
        }
    }
    return tmp;
}
function getCount(c){
    const a = c * (c-1);
    return Math.floor(a / 2);
}
