


class Stack:
    
      def __init__(self,si) -> None:
            self.arr=[si]
            self.top=-1
            self.size=0
        
      def Is_empty(self):
          return self.size==0     
        
      def Add(self,val):
            self.top==1
            self.arr[self.top]=val
            
      def Gettop(self):
          return self.top
                
      def Pop(self):
          if self.is_empty():
              print("The Stack Is Empty...")
          else:
              top-=1
      
      def Pick(self):
          if self.is_empty():
                print("The Stack Is Empty...")
          else:
              return self.arr[self.top] 
      
      def PrintStack(self):
          for item in range(self.top,-1,-1):
              print(self.arr[item],end=" ")
          print("\n")       
     
      def DeleteStack(self):
           self.top=-1       
      
      
      
      
              
                