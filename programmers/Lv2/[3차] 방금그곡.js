function solution(m, musicinfos) {
    var answer = '';
    function replaceToLowerCase(match){
        return match[0].toLowerCase();
    }
    m = m.replace(/.#/gi,replaceToLowerCase);
    
    let result = [];
    
    musicinfos.forEach((musicinfo)=>{
        musicinfo = musicinfo.replace(/.#/gi,replaceToLowerCase);
        
        const [start,end,title,info] = musicinfo.split(',');
        const [h1,m1] = (start.split(':'));
        const [h2,m2] = (end.split(':'));
        const playTime = (h2-h1)*60+(m2-m1); 
        const playInfo = playTime > info.length ? info.repeat(Math.floor(playTime / info.length)) + info.slice(0, playTime % info.length) : info.slice(0, playTime);
        if(playInfo.indexOf(m) !== -1){
            result = [...result, {playTime, title}];
        }
    });
    if(!result.length)return "(None)";
    if(result.length > 1){
        result = result.sort((a,b)=>{
            return b.playTime - a.playTime;
        });
    }
    return result[0].title;
}
