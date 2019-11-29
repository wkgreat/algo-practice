package wk.datastructure.tree;
/**
 * 二叉树节点
 * */
public class BiTree {

    BiTree left;
    BiTree right;
    char value;

    public BiTree getLeft() {
        return left;
    }

    public void setLeft(BiTree left) {
        this.left = left;
    }

    public BiTree getRight() {
        return right;
    }

    public void setRight(BiTree right) {
        this.right = right;
    }

    public char getValue() {
        return value;
    }

    public void setValue(char value) {
        this.value = value;
    }

    /**
     * 前序遍历
     * */
    public static void preOrder(BiTree tree) {
        if(tree==null) {
            return;
        }
        System.out.print(tree.getValue());
        preOrder(tree.left);
        preOrder(tree.right);
    }
    /**
     * 中序遍历
     * */
    public static void midOrder(BiTree tree) {
        if(tree==null) {
            return;
        }
        midOrder(tree.left);
        System.out.print(tree.getValue());
        midOrder(tree.right);
    }
    /**
     * 后序遍历
     * */
    public static void backOrder(BiTree tree) {
        if(tree==null) {
            return;
        }
        backOrder(tree.left);
        backOrder(tree.right);
        System.out.print(tree.getValue());
    }

    /**
     * 根据前序和中序生成二叉树
     * */
    public static BiTree parseTreeFromPreAndMid(String pres, String mids) {
        BiTree tree = new BiTree();
        if(pres==null || pres.length()==0) {
            return null;
        }
        if(pres.length()==1) {
            tree.setValue(pres.charAt(0));
            return tree;
        }
        char c = pres.charAt(0);
        tree.setValue(pres.charAt(0));
        int i = mids.indexOf(c);
        int leftlen = i;
        int rightlen = mids.length()-i-1;
        if(leftlen<=0) {
            tree.setLeft(null);
        } else {
            String newpre = pres.substring(1,1+leftlen);
            String newmid = mids.substring(0,i);
            tree.setLeft(parseTreeFromPreAndMid(newpre,newmid));
        }
        if(rightlen<=0) {
            tree.setRight(null);
        } else {
            String newpre = pres.substring(1+leftlen,pres.length());
            String newmid = mids.substring(i+1,mids.length());
            tree.setRight(parseTreeFromPreAndMid(newpre,newmid));
        }
        return tree;
    }

    public static void main(String[] args) {
        String s1 = "ABDECFG";
        String s2 = "DBEAFCG";
        BiTree tree = parseTreeFromPreAndMid(s1,s2);
        backOrder(tree);
    }

}
