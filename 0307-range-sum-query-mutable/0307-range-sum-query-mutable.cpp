class NumArray {
private : 
    vector<int> segTree;
    int n;
    void buildSegTree(int st,int end,int idx,vector<int>& nums,vector<int>& segTree)
    {
        int mid = st+(end-st)/2;
        if(st == end)
        {
            segTree[idx] = nums[st];
            return;
        }
        buildSegTree(st,mid,2*idx+1,nums,segTree);
        buildSegTree(mid+1,end,2*idx+2,nums,segTree);
        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }
    void updateSegTree(int st,int end,int idx,int updateIdx,int updateVal,vector<int>& segTree)
    {
        int mid = st+(end-st)/2;
        if(st == end)
        {
            segTree[idx] = updateVal;
            return ;
        }
        if(mid >= updateIdx)
            updateSegTree(st,mid,2*idx+1,updateIdx,updateVal,segTree);
        else 
            updateSegTree(mid+1,end,2*idx+2,updateIdx,updateVal,segTree);
        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }
    int queryRange(int st,int end,int idx,int l,int r,vector<int>& segTree)
    {
        if(st > r || end < l) return 0;
        if(st >= l && end <= r) return segTree[idx];
        int mid = st+(end-st)/2;
        return queryRange(st,mid,2*idx+1,l,r,segTree) + 
                queryRange(mid+1,end,2*idx+2,l,r,segTree);
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n);
        buildSegTree(0, n - 1, 0, nums, segTree);
    }
    
    void update(int index, int val) {
       updateSegTree(0, n-1, 0, index, val, segTree);
    }
    
    int sumRange(int left, int right) {
        return queryRange(0, n-1, 0, left, right, segTree);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */