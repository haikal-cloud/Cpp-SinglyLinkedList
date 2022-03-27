#include <iostream>

using namespace std;

struct ListNode{
	float data;
	ListNode *next; 
	
};

struct SinglyLinkedList{
	ListNode *head, *tail;
	int size;
	
	void init(){
		head=tail=NULL;
		size=0;
	}
	

	int get_size(){
		return size;
	}
	
	void make_empty(){
		
		head=tail=NULL;
		size=0;
	}
	
	bool is_empty(){
		return head==NULL;
	}
//nambah kepala	
	void add_head(float x){
		ListNode *tmp = new ListNode ;
		tmp->data = x;
		tmp->next = NULL;
		if (is_empty()){
			head=tail=tmp;
		}else{
		  tmp->next = head;
		  head=tmp;
		}size++;
	}
//nambah ekor	
		void add_tail(float x){
		ListNode *tmp = new ListNode;
		tmp->data = x;
		tmp->next = NULL;
		if (is_empty()){
			head=tail=tmp;
		}else{
		  tail->next = tmp;
		  tail=tmp;
		}size++;
	}
//nambah sesudah suatu node	
	void nambah_setelah (float setelah, float x){
		ListNode *p = head;
		while (p != NULL){
			if (p->data == setelah){
			if (p == tail){
				add_tail(x);
			}else{
			ListNode *tmp = new ListNode;
			tmp->data = x;
			tmp->next = p->next;
			p->next = tmp;
			size++;
			break;
		}
			}p = p->next;
		}
	}
	
	
	//nambah sebelum suatu node	

void nambah_sebelum(float x,float y){
        ListNode *p;
        ListNode *tmp=new ListNode;

         if(head->data==y){
            tmp->data=x;
            tmp->next=head;
            head=tmp;
        }
        else{
            p=head;
            while(p!=NULL){
                    if(p->next->data==y){
                    tmp->data=x;
                    tmp->next=p->next;
                    p->next=tmp;
                    break;

                    }
                p=p->next;

            }
        }
    size ++;

    }

//hapus kepala
void hapus_kepala (){
	ListNode *p = head;
    ListNode *tmp = new ListNode;
    tmp->next = head;
    head = head->next;
    delete tmp;
}


//hapus ekor
void hapus_ekor (){
  ListNode *prev = NULL;
  ListNode *tmp = head;
   while(tmp->next!=NULL){
      prev= tmp;
      tmp=tmp->next;
   }
   delete tmp;
   prev->next= NULL;
   return;
}

//hapus suatu node
void hapus (float x){
	 ListNode *p = head;
	 while(p != NULL){
	 	if (p->next == NULL)
	 	break;
	 	if(p->next->data == x){
	 		ListNode *tmp = p->next;
	 		p->next = p->next->next;
	 		delete tmp;
	 		break;
		 }p = p->next;
	 }
}


//tampilkan node
	void print(){
		ListNode *p = head;
		while (p != NULL){
			cout << p->data << "~~ ";
			p = p->next;
		} cout << "\n \n";
	}
	
};

int main(){
   SinglyLinkedList sll;
   sll.init();
   sll.add_head(2);
   sll.print();
   sll.add_head(1);
   sll.print();
   sll.add_tail(4);
   sll.print();
   sll.nambah_setelah(2, 3); 
   sll.print();
   sll.nambah_sebelum(19, 1);
   sll.print();
   sll.nambah_setelah(3, 6.9);
   sll.print();
   sll.hapus_kepala();
   sll.print();
   sll.hapus(3);
   sll.print();
   
   sll.hapus_ekor();
   sll.print();
   
}