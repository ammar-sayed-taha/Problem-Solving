
class Solution {
public:
    int firstBadVersion(int n) {
         int l=1, r=n, bad=0, m;
        while(r>=l){
            m = l+ ((r-l)/2);  // (l+r)/2; // l+((r-l)/2);
            // cout<<m<<"\n";
            if(isBadVersion(m)) {
                bad = m;
                r = m-1;
            }else l = m+1; 
        }
        return bad == 0 ? n : bad; // if bad still zero then bad version is last one
    }
};
