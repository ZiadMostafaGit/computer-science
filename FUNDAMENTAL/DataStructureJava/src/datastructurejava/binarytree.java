/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package datastructurejava;

/**
 *
 * @author ziad
 */
public class binarytree {
    
public static class node{
    
    public int data;
    public node lift;
    public node right;
    
    public node(int val){
        data=val;
        lift=null;
        right=null;
        
    }
    
    
};
    

public static class BT{
    
    private node root;
    private int max;
    private int hight; 
    private int leafs;
    
    
    public BT(int val){
        node newnode=new node(val);
        root=newnode;
        max=0;
        hight=0;
        
    }
    
    
    public boolean is_empty(){
        return root.lift==null&&root.right==null;
    }
    
    
    node addRecursive(node current, int value) {
        if (current == null) {
            return new node(value);
        }

        if (value < current.data) {
            current.lift = addRecursive(current.lift, value);
        } else if (value > current.data) {
            current.right = addRecursive(current.right, value);
        } else {
            // value already exists
            return current;
        }

        return current;
    }
    
    
    
    
    public void postprint(node current){
        
        
        
        if(current==null){
           
            return;
        }
        postprint(current.lift);
        postprint(current.right);
        System.out.print(current.data+" ");
        
        
        
        
        
        
    }
    
    
      public node get_root()
      {
          return root;
      }
      
      public int max(node current){
          
          
          
          if(current==null)
          {
              return max;
              
          }
          if(current.data>max)
              max=current.data;
          
          max=max(current.lift);
          max=max(current.right);
          
          
          return max;
          
      }
      
      public int gethight(node current){
          
          
          if(current==null){
          
              return 0;
          }
          
         
          
            return Math.max( gethight(current.lift),gethight(current.right))+1;
        
          
          
      }
      
      public int countallnodes(node current)
      {
          if(current==null)
            {
          
                 return 0;
              
            }      
          
       int lifthight=countallnodes(current.lift);
       int righthight=countallnodes(current.right);
      
       
       return righthight+lifthight+1;
      
    }
      public int countLeafNodes(node current) {
    if (current == null) {
        return 0;
    }
    if (current.lift == null && current.right == null) {
        return 1;
    }
    return countLeafNodes(current.lift) + countLeafNodes(current.right);
}

       
      
      
    public boolean searchingtree(node current,int val) {
    if (current == null) {
        return false;
    }
    if (current.data == val ) {
        return true;
    }
    return searchingtree(current.lift,val)||     searchingtree(current.right,val);

        
    
     
}

       
    
    
    
    
    
    public  boolean is_perfect(node current){
        
        int num=countallnodes(current);
        int high=gethight(current)-1;
        if(num==Math.pow(2, high+1)-1)
        {
            return true;
        }else
        {
            return false;
        }
        
    }
       
       
      public void preprint(node current){
        
        
        
        if(current==null){
           
            return;
        }
        System.out.print(current.data+" ");
        preprint(current.lift);
        preprint(current.right);
        
        
        
        
        
        
    }
      
      
      public void infexprint(node current)
      {
        if(current==null){
           
            return;
        }
        infexprint(current.lift);
        System.out.print(current.data+" ");
        infexprint(current.right);
      
    }
      

}


    
}
