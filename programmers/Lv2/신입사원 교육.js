class MinHeap{
    constructor(){
        this.heap = [];
    }
    swap(a,b){
        const tmp = this.heap[a];
        this.heap[a] = this.heap[b];
        this.heap[b] = tmp;
    }
    insert(value){
        this.heap.push(value)
        this.heapifyUp();
    }
    heapifyUp(){
        let currentIndex = this.heap.length - 1;
        while(currentIndex > 0){
            const parentIndex = Math.floor((currentIndex - 1) / 2);
            if(this.heap[parentIndex] <= this.heap[currentIndex])break;
            this.swap(parentIndex, currentIndex);
            currentIndex = parentIndex;
        }
    }
    poll(){
        if(this.heap.length === 1)return this.heap.pop();
        const minValue = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.heapifyDown(0);
        return minValue;
    }
    heapifyDown(index){
        const left = 2 * index + 1;
        const right = 2 * index + 2;
        const length = this.heap.length;
        let smallestIndex = index;
        if(left < length && this.heap[left] < this.heap[smallestIndex]){
            smallestIndex = left;
        }
        if(right < length && this.heap[right] < this.heap[smallestIndex]){
            smallestIndex = right;
        }
        if(smallestIndex !== index){
            this.swap(index, smallestIndex);
            this.heapifyDown(smallestIndex)
        }
    }
}
function solution(ability, number) {
    let answer = ability.reduce((acc,cur)=>acc+=cur,0);
    const heap = new MinHeap();
    ability.forEach(v => heap.insert(v))
    for(let i=0;i<number;i++){
        const a = heap.poll();
        const b = heap.poll();
        answer += a + b;
        heap.insert(a + b);
        heap.insert(a + b);
    }
    return answer;
}
