int firstDuplicate(std::vector<int> a) {
    unordered_set<int> count;

    int len = a.size();
    for(int i=0; i<len; i++){
        if(count.find(a[i]) == count.end()) count.insert(a[i]);
        else return a[i];
    }
    return -1;
}
