function rotateImage(a: number[][]): number[][] {
    let len = a.length;
    for(let i=0; i<len; i++)
        for(let j=i; j<len; j++)
            [a[i][j], a[j][i]] = [a[j][i], a[i][j]]
        
    for(let i=0; i<len; i++){
        for(let j=0; j<Math.floor(len/2); j++){
             [a[i][j], a[i][len-j-1]] = [a[i][len-j-1], a[i][j]]
        }
    }
    return a

}
