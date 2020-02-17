int lrSegmentNumber(int l, int r) {
    int total=0, base=1;

    for(int i=r; i>=l; i--){
        total += i*base;
        base*=10;
    }
    return total;

}
