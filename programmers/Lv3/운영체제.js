function solution(program) {
    program.sort((a,b)=>a[1]-b[1])
    const answer = [...Array(11)].map(()=>0);
    let time = 0;
    let j = 0;
    const heap = new MinHeap();
    while(j < program.length || !heap.empty()){
        if(j < program.length && program[j][1] <= time){
            heap.insert(program[j++])
            continue;
        }
        if(!heap.empty()){
            const [prior, start, end] = heap.poll();
            answer[prior] += time - start;
            time += end;
        }else{
            time = program[j][1];
        }
    }
    answer[0] = time;
    return answer;
}
class MinHeap{
    constructor(){
        this.heap = [];
    }
    empty(){
        return this.heap.length === 0;
    }
    swap(a, b){
        const tmp = this.heap[a]
        this.heap[a] = this.heap[b]
        this.heap[b] = tmp;
    }
    insert(value){
        this.heap.push(value)
        this.heapifyUp();
    }
    heapifyUp(){
        let cur = this.heap.length - 1;
        while(cur > 0){
            const parent = Math.floor((cur-1)/2)
            if(this.heap[parent][0] <= this.heap[cur][0])break;
            this.swap(parent, cur);
            cur = parent;
        }
    }
    poll(){
        if(this.heap.length === 1)return this.heap.pop();
        const min = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.heapifyDown(0);
        return min;
    }
    heapifyDown(pos){
        const left = 2 * pos + 1
        const right = 2 * pos + 2
        let cur = pos;
        const length = this.heap.length;
        if(left < length){
            if(this.heap[left][0] === this.heap[cur][0] && this.heap[left][1] < this.heap[cur][1])cur = left;
            else if(this.heap[left][0] < this.heap[cur][0])cur = left;
        }
        if(right < length){
            if(this.heap[right][0] === this.heap[cur][0] && this.heap[right][1] < this.heap[cur][1])cur = right;
            else if(this.heap[right][0] < this.heap[cur][0])cur = right;
        }
        if(pos !== cur){
            this.swap(pos, cur);
            this.heapifyDown(cur);
        }
    }
}
