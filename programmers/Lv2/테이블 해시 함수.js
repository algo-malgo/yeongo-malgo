function solution(data, col, row_begin, row_end) {
    data.sort((a,b)=>{
        if(a[col-1] === b[col-1])return b[0] - a[0];
        return a[col-1] - b[col-1];
    })
    let res = [];
    for(let i=row_begin-1;i<row_end;i++){
        let tmp = 0;
        const tuple = data[i];
        tuple.forEach(v => {
            tmp += v % (i+1);
        });
        res.push(tmp)
    }
    const answer = res.reduce((acc,cur)=>acc ^ cur, 0);
    return answer;
}
