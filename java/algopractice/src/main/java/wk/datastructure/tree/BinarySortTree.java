package wk.datastructure.tree;

public class BinarySortTree {

    public static class Node {
        Node p, left, right;
        int value;
        public Node(int value) {
            this.value = value;
        }
        public boolean isLeaf() { //如果左右子树都为空的话，为叶子节点
            return left==null && right==null;
        }
    }

    Node root = null;

    /**
     * 插入方法
     * */
    void insert(Node n) {
        Node x = root;
        Node y = null;
        while(x!=null) { // 找到叶子节点 当为空时，该空位置为插入位置，y指向该位置的父节点
            y = x;
            if(n.value < x.value) {
                x = x.left;
            } else {
                x = x.right;
            }
        }
        if(y == null) { //如果树为空
            root = n;
        } else if(n.value < y.value) {
            y.left = n;
            n.p = y; //设置父节点
        } else {
            y.right = n;
            n.p = y; //设置父节点
        }
    }

    void delete(int v) {
        Node n = findByValue(v);
        if(n==null) return;
        if(n==root) {
            root = delete(n);
        } else {
            delete(n);
        }
    }

    /**
     * @return 返回删除后补位上来的节点，而不是被删除的节点。用来如果删除的root的时候，能够获取新root
     * */
    private Node delete(Node node) {
        if(node!=null) {
            if(node.isLeaf()) {
                _replace(node,null); //将node对应的位置替换为null，相当于删除node
                return null;
            } else if (node.left!=null && node.right==null) {
                _replace(node,node.left);
                return node.left;
            } else if (node.left==null && node.right!=null) {
                _replace(node,node.right);
                return node.right;
            } else if (node.left!=null && node.right!=null) {
                Node rightTree = _rotateClockwise(node.right);
                rightTree.left = node.left;
                rightTree.left.p = rightTree;
                _replace(node,rightTree);
                return rightTree;
            }
        }
        return null;
    }

    /**
     * 用于delete方法，替换node1对应的子树 为 node2对应的子树，并不改变父亲与子树的关系
     * */
    private void _replace(Node node1, Node node2) {
        if(root==node1) {
            root = node2;
            if(node2!=null) node2.p = null;
        }
        Node p = node1.p;
        if(p.left==node1) {
            p.left = node2;
            if(node2!=null) node2.p = p;
        } else if (p.right==node1) {
            p.right = node2;
            if(node2!=null) node2.p = p;
        }
    }

    /**
     * 目的：使树的根节点的左子树为空，方式通过顺时针旋转实现
     * 功能：顺时针旋转树 b为最小元素，要将b旋转为该树的根元素，这就保证该树的左子树为空
     * 先找到最小元素b
     * 将b的原右子树赋给临时变量t
     * 将b的左子树替换为a
     * 将a树的最左值（原b的位置）替换成b的原右子树t
     * 注意a的右子树不用左处理
     *       a        b
     *      : :        \
     *     b    ==>    a
     *      \         : :
     *       c       c
     */
    private Node _rotateClockwise(Node node) {
        if(node==null) return null;
        if(node.left==null) return node;
        Node minNode = _minimum(node);
        Node t = minNode.right;
        minNode.right = node;
        node.p = minNode;
        _replace(minNode, t);
        return minNode;
    }

    /**
     * 目的：使树根节点的左子树为空，方式通过逆时针旋转树实现
     * 功能：逆时针旋转树
     *      a           b
     *     : :         /
     *        b  ==>  a
     *       /       : :
     *      c           c
     * */
    private Node _rotateCounterClockwise(Node node) {
        if(node==null) return null;
        if(node.right==null) return node;
        Node maxNode = _maximum(node);
        Node t = maxNode.left;
        maxNode.left = node;
        node.p = maxNode;
        _replace(maxNode,t);
        return maxNode;
    }

    /**
     * 最小值节点
     * */
    Node minimum(){
        return _minimum(root);
    }
    private Node _minimum(Node node) {
        if(node==null) return null;
        while(node.left!=null) node = node.left;
        return node;
    }
    /**
     * 最大值节点
     * */
    Node maximum() {
        return _maximum(root);
    }
    private Node _maximum(Node node) {
        if(node==null) return null;
        while(node.right!=null) node = node.right;
        return node;
    }
    /**
     * 按顺序的后继
     *     5
     *   1/
     *    \2
     *     \3
     *  如果3有右子树，这后继是右子树的最小值
     *  因为3没有右子树，所以3的后继是5
     *  判断方式是迭代判断3往上的父节点，直到某父节点是其父节点的左子树，如1是5的左子树
     */
    Node successor(int v) {
        Node x = findByValue(v);
        return _successor(x);
    }
    private Node _successor(Node node) {
        if(node==null) return null;
        if(node.right!=null) return _minimum(node.right);
        Node p = node;
        while((p=p.p)!=null && p.p.left!=p);
        return p.p;
    }

    /**
     * 返回对应值的节点，默认返回最左面一个
     * */
    Node findByValue(int v) {
        return _findByValue(root, v);
    }
    private Node _findByValue(Node node, int v) {
        if(node==null) {
            return null;
        }
        Node leftn = _findByValue(node.left, v);
        if(leftn!=null) return leftn;
        if(v==node.value) return node;
        return _findByValue(node.right, v);

    }

    /** 树的深度 */
    public int depth() {
        return _depth(root);
    }
    private int _depth(Node node) {
        if(node==null) return 0;
        else return 1 + Math.max(_depth(node.left), _depth(node.right));
    }

    /**
     * 按照中序进行打印，二叉查找树的中序就是其排序的顺序
     * */
    public void print() {
        _print(root);
        System.out.println();
    }
    private void _print(Node node) {
        if(node!=null) {
            _print(node.left);
            System.out.print(node.value);
            _print(node.right);
        }
    }

    public void printR() {
        _printR(root);
        System.out.println();
    }
    private void _printR(Node node) {
        if(node!=null) {
            _printR(node.left);
            if(node.left!=null) {
                System.out.print(node.value+"l->"+node.left.value+" ");
            }
            if(node.right!=null) {
                System.out.print(node.value+"r->"+node.right.value+" ");
            }
            _printR(node.right);
        }
    }


    public static void main(String[] args) {

        int[] values = new int[] {2,3,1,6,5,9,7,8,4};
        BinarySortTree tree = new BinarySortTree();
        for(int v : values) {
            tree.insert(new Node(v));
        }
        System.out.println("Depth: " + tree.depth());
        tree.print();
        tree.printR();
        tree.delete(6);
        tree.print();
        tree.printR();

    }


}
