
package javaproject;
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
    
    
    public BT(int val){
        node newnode=new node(val);
        root=newnode;
        max=0;
        hight=0;
        
    }
    
    
    public boolean is_empty(){
        return root.lift==null&&root.right==null;
    }
    
    public void add(int data)
    {
            node newnode=new node(data);

                node temp=root;
                while(true)
                {
                    
                    if(newnode.data>=temp.data)
                    {
                        if(temp.right!=null) 
                            temp=temp.right;
                        
                        else
                        {
                            temp.right=newnode;
                            return;
                        }
                        
                    }
                    
                    else if(newnode.data<temp.data)
                    {
                        if(temp.lift!=null)
                            temp=temp.lift;
                        else{
                            
                            temp.lift=newnode;
                            return;
                        }
                    
                    }
                    
                }
       
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
          
         
          
          int lifthight=gethight(current.lift);
          int righthight=gethight(current.right);
          
          return Math.max(lifthight, righthight)+1;
          
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
      
       public int countleafnodes(node current)
      {
         if(current==null)
            {
          
                 return 0;
              
            }      
          
       int lifthight=countleafnodes(current.lift);
       int righthight=countleafnodes(current.right);
      
       
       return righthight+lifthight+1;
      
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