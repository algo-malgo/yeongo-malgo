function solution(today, terms, privacies) {
    const answer = [];
    const deadline = new Date(today);
    const termObj = {};
    terms.forEach(term => {
        const [a,b] = term.split(' ');
        termObj[a] = Number(b);
    });
    privacies.forEach((el,idx)=>{
        const [date, term] = el.split(' ');
        const pdate = new Date(date);
        pdate.setMonth(pdate.getMonth() + termObj[term]);
        if(pdate <= deadline)answer.push(idx+1);
    });
    
    return answer;
}
