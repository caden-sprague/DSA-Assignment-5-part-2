#include "cnPtrQueue.h"
#include <cassert>
#include "nodes_LLoLL.h"  // for CNode
using namespace std;

namespace CS3358_FA2024_A5P2
{
   // typedef std::size_t size_type;

   cnPtrQueue::cnPtrQueue(): numItems(0)
   { }

   bool cnPtrQueue::empty() const
   {
      return numItems == 0;
   }
   
   cnPtrQueue::size_type cnPtrQueue::size() const     // returns # of items in queue
   {
      return numItems;
   } 

   CNode* cnPtrQueue::front()
   {
      if(outStack.size() == 0)
      {
         while(!inStack.empty())
         {
            outStack.push(inStack.top());
            inStack.pop();
         }
      }
      return outStack.top();
   }

   void cnPtrQueue::push(CNode* cnPtr)
   {
      inStack.push(cnPtr);
      numItems++;
   }

   void cnPtrQueue::pop()
   {
      if(outStack.size() == 0)
      {
         while(!inStack.empty())
         {
            outStack.push(inStack.top());
            inStack.pop();
         }
      }
      outStack.pop();
      numItems--;
   }
}
