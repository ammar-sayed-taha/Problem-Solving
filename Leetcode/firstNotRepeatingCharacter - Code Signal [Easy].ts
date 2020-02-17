function firstNotRepeatingCharacter(s: string): string {
    let visited :any= {}
    
    for(let i=0; i<s.length; i++){
        if(visited[s[i]])
            visited[s[i]][1]++;
        else visited[s[i]] = [i, 1];
    }

    let minIndex = -1;
    for(let i in visited)
        if(visited[i][1] == 1)
            if(minIndex > visited[i][0] || minIndex == -1)
                 minIndex = visited[i][0];
        
           

    if(minIndex == -1) return '_'
    return s[minIndex]


}
