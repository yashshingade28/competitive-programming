class SegTree {
		int leftmost, rightmost;
		int and, xor;
		long maxand = (1 << 62) - 1;
		int maxxor = 0;
		SegTree lchild, rchild;

		public SegTree(int l, int r, int a[]) {
			this.leftmost = l;
			this.rightmost = r;
			if (l == r) {
				and = a[l];
				xor = a[l];
			} else {
				int mid = (l + r) / 2;
				lchild = new SegTree(l, mid, a);
				rchild = new SegTree(mid + 1, r, a);
				recalc();
			}
		}

		public void recalc() {
			if (leftmost == rightmost)
				return;
			and = lchild.and & rchild.and;
			xor = lchild.xor ^ rchild.xor;
		}

		public long AndQuery(int l, int r) {
			if (l > rightmost || r < leftmost)
				return maxand;
			if (l <= leftmost && r >= rightmost)
				return and;
			return lchild.AndQuery(l, r) & rchild.AndQuery(l, r);
		}

		public int XorQuery(int l, int r) {
			if (l > rightmost || r < leftmost)
				return maxxor;
			if (l <= leftmost && r >= rightmost)
				return xor;
			return lchild.XorQuery(l, r) ^ rchild.XorQuery(l, r);
		}
	}