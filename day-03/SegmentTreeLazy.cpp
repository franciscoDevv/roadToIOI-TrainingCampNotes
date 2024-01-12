struct SEG{
    ll tree[4*mxN], lz[4*mxN];
    void init(){
        memset(tree, 0, sizeof(tree));
    }
    void app(int i, ll x, int l2, int r2){
        tree[i]+=x*(r2-l2+1); 
        lz[i]+=x;
    }
    void psh(int i, int l2, int m2, int r2){
        app(2*i, lz[i], l2, m2);
        app(2*i+1, lz[i], m2+1, r2);
        lz[i] = 0;
    }
    void merge(int i){
        tree[i] = tree[2*i]+tree[2*i+1]; 
    }
    void build(int l, int r, int i){
        if(l == r){
            tree[i] = a[l];
            return;
        }
        int m = (l+r)/2; 
        build(l, m, 2*i); 
        build(m+1, r, 2*i+1);
        merge(i);
    }
    void upd(int l1, int r1, int l2, int r2, int i, ll val){
        if(l2 > r1 || r2 < l1) return; 
        if(l1 <= l2 && r2 <= r1){
            app(i, val, l2, r2);
            return; 
        }
        int m2 = (l2+r2)/2; 
        psh(i, l2, m2, r2);
        upd(l1, r1, l2, m2, 2*i, val); 
        upd(l1, r1, m2+1, r2, 2*i+1, val);
        merge(i); 
    }
    ll qry(int l1, int r1, int l2, int r2, int i){
        if(l2 > r1 || r2 < l1) return 0; 
        if(l1 <= l2 && r2 <= r1){
            return tree[i];
        }
        int m2 = (l2+r2)/2; 
        psh(i, l2, m2, r2);
        return qry(l1, r1, l2, m2, 2*i) + qry(l1, r1, m2+1, r2, 2*i+1);
    }
    ll search(int l1, int r1, int i, ll val){
        if(l1 == r1){
            return a[l1];
        }
        int m1 = (l1+r1)/2;
        psh(i, l1, m1, r1);
        if(tree[2*i]>=val){
            return search(l1, m1, 2*i, val);
        }
        return search(m1+1, r1, 2*i+1, val-tree[2*i]);
    }
}seg;