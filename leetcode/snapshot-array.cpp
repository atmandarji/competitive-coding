// https://leetcode.com/problems/snapshot-array/
class SnapshotArray {
public:
    vector<map<int,int> > ssa;
    int ssno;
    SnapshotArray(int length) {
        ssno=0;
        vector<map<int,int> > sv(length);
        for(int i=0;i<length;i++){
            sv[i][0]=0;
        }
        ssa=sv;
    }
    
    void set(int index, int val) {
        ssa[index][ssno]=val;
    }
    
    int snap() {
        ssno++;
        return ssno-1;
    }
    
    int get(int index, int snap_id) {
        map<int,int>::iterator it=ssa[index].upper_bound(snap_id);
        if(it != ssa[index].begin())
            it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */