#include "nodes_LLoLL.h"
#include "cnPtrQueue.h"
#include <iostream>
using namespace std;

namespace CS3358_FA2024_A5P2
{
	
   // if (head == 0) return
   // create queue q of CNode*
   // while (head != 0)
   //    if (head->data != 0)
   //       q.push(head->data)
   //    head = head->link;
   // while ( ! q.empty() )
   //    cursor = q.front()
   //    q.pop()
   //    display cursor->data
   //    if ( cursor->link != 0 )
   //       q.push( cursor->link )

   // do breadth-first (level) traversal and print data
   void ShowAll_BF(PNode* pListHead, ostream& outs)
   {
      if(pListHead == 0) return;

      cnPtrQueue queue;
      while(pListHead)
      {
         if(pListHead->data)
         {
            queue.push(pListHead->data);
         }
         pListHead = pListHead->link;
      }
      while(!queue.empty())
      {
         CNode* cursor = queue.front();
         queue.pop();
         outs << cursor->data << "  ";
         if(cursor->link)
         {
            queue.push(cursor->link);
         }
      }
   }
   
   void Destroy_cList(CNode*& cListHead)
   {
      int count = 0;
      CNode* cNodePtr = cListHead;
      while (cListHead != 0)
      {
         cListHead = cListHead->link;
         delete cNodePtr;
         cNodePtr = cListHead;
         ++count;
      }
      cout << "Dynamic memory for " << count << " CNodes freed"
           << endl;
   }

   void Destroy_pList(PNode*& pListHead)
   {
      int count = 0;
      PNode* pNodePtr = pListHead;
      while (pListHead != 0)
      {
         pListHead = pListHead->link;
         Destroy_cList(pNodePtr->data);
         delete pNodePtr;
         pNodePtr = pListHead;
         ++count;
      }
      cout << "Dynamic memory for " << count << " PNodes freed"
           << endl;
   }

   // do depth-first traversal and print data
   void ShowAll_DF(PNode* pListHead, ostream& outs)
   {
      while (pListHead != 0)
      {
         CNode* cListHead = pListHead->data;
         while (cListHead != 0)
         {
            outs << cListHead->data << "  ";
            cListHead = cListHead->link;
         }
         pListHead = pListHead->link;
      }
   }
}
