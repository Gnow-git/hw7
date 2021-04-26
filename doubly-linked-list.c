/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
/* �ʿ��� ������� �߰� if necessary */


typedef struct Node {			// ���߿��Ḯ��Ʈ ����ü ����
	int key;					// ����Ʈ�� ������ �ʵ� key ����
	struct Node* llink;			// ���߿��Ḯ��Ʈ�� ���ʳ��� �����ϴ� ������
	struct Node* rlink;			// ���߿��Ḯ��Ʈ�� ������ ���� �����ϴ� ������
} listNode;



typedef struct Head {			// ����Ʈ ������ ��Ÿ���� first ��带 ����ü�� ����
	struct Node* first;
}headNode;

/* �Լ� ����Ʈ */

/* note: initialize�� ���������͸� �Ű������� ����
         singly-linked-list�� initialize�� �������� ���� �Ұ� */
int initialize(headNode** h);	// ����Ʈ ���� �� �ʱ�ȭ�ϴ� �Լ�

/* note: freeList�� �̱������͸� �Ű������� ����
        - initialize�� �� �ٸ��� ���� �Ұ�
        - ���������͸� �Ű������� �޾Ƶ� ������ �� ���� �� */
int freeList(headNode* h);		// ����Ʈ �Ҵ��� �����ϴ� �Լ�

int insertNode(headNode* h, int key);	// �����ϴ� ��ġ�� ��� �����ϴ� �Լ�
int insertLast(headNode* h, int key);	// ������ ��ġ�� ��带 �����ϴ� �Լ�
int insertFirst(headNode* h, int key);	// ù��° ��ġ�� ��带 �����ϴ� �Լ�
int deleteNode(headNode* h, int key);	// ���ϴ� ����� ���� �����ϴ� �Լ�
int deleteLast(headNode* h);			// ������ ��ġ�� ��带 �����ϴ� �Լ�
int deleteFirst(headNode* h);			// ù��° ��ġ�� ��带 �����ϴ� �Լ�
int invertList(headNode* h);			// ����� ��ġ�� ������Ű�� �Լ�

void printList(headNode* h);			// ��带 �����ִ� �Լ�


int main()
{
	char command;
	int key;
	headNode* headnode=NULL;
		printf("\t[-----[�� �� ��]  [2017038100]-----]\n");
	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}


int initialize(headNode** h) {			// ����Ʈ�� �ʱ�ȭ�ϴ� �Լ� (�ι����� �����Ͱ� �ֱ⶧���� ���� �����ͷ� ���� �޴´�.)
	if(*h != NULL)
      freeList(*h);

   /* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
   *h = (headNode*)malloc(sizeof(headNode));		// ��� ��� �Ҵ�
   (*h)->first = NULL;             					// ���� ����Ʈ �̹Ƿ� NULL�� ����
	return 1;
}

int freeList(headNode* h){
	listNode* p = h->first;          // ��� p�� ��� �� first ����

   listNode* prev = NULL;           // prev��� ��忡 NULL ����
   while(p != NULL) {               // ��� P�� NULL�� �ƴҶ����� �ݺ�
      prev = p;                     
      p = p->rlink;
      free(prev);                   // prev ��忡 �Ҵ�� �޸� ��ȯ
   }
   free(h);                 
	return 0;
}


void printList(headNode* h) {		// list�� �����ִ� �Լ�
	int i = 0;
	listNode* p;					// listnode p ����

	printf("\n---PRINT\n");

	if(h == NULL) {					// ��� ��尡 ������ �Ʒ��� printf�� ���
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;					// ���۳�带 p�� ����

	while(p != NULL) {				// p�� ���� ������ ����Ʈ ��ȣ�� ����Ʈ ������ �� �ⷫ
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}




/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {	// ������ ��ġ�� ��带 �߰��ϴ� �Լ�
   listNode* node = (listNode*)malloc(sizeof(listNode));   // �ű� ��� ���� �� node�� ������ ������ �޸𸮿� �Ҵ� �޾� node�� ����.
   listNode* lastNode;         // ��� ����� ������ ��� ����.
   node -> key = key;         // node �ʵ忡 key�� ����
   node ->rlink = NULL;         // key ���� �� ���� ����Ű�� ��尡 ���⶧���� NULL �Ҵ�

   if(h -> first == NULL ){   // NULL�� ���
      h -> first = node;      // ���۳�尡 node�� ����Ŵ
      return 0;            // ����
   }
 // ������ ��带 ã�� �ݺ���
   lastNode = h -> first;      // ��� ����� h ���� ���� first�� ���� ���� ���� �̵�   
   while(lastNode -> rlink != NULL ){      // lastnode�� NULL�� �ƴҶ����� �ݺ�
      lastNode = lastNode -> rlink;      // ������ ��ũ ���� ã�´�.
   }
   lastNode -> rlink = node;         // �ش� ���� ������ ���� ���� �̵�
}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {			// ������ ��ġ�� ��带 �����ϴ� �Լ�
   listNode* frontnode;                // ������ ����
   listNode* delLastnode;              // �����ϰ��ϴ� ���� ����Ű�� ��� ����
   if(h -> first == NULL)
   {   // ������ ��尡 ���� ��� ����
      printf("������ ������ ��尡 �����ϴ�.\n");
      return 0;
   } 

   else if(h -> first -> rlink == NULL){         // ����Ʈ�� ��尡 1���϶�
      freeList(h);                  // �Ҵ� �޸� ����
      h -> first = NULL;               // head�� first�� NULL�� ����
      return 0;                     // ����
   }
   else{                           // 2�� �̻��� ��尡 ���� ���
      frontnode = h -> first;               // ������ delLastnode ���� frontnode�� ù��° ���� ���� 
      delLastnode = h -> first -> rlink;      // ������ ��带 �ι�° ���� ����
      while(delLastnode -> rlink != NULL){      // ������ ��尡 NULL�� �ƴҶ����� 
         frontnode = delLastnode;         // frontnode�� delLastnode�� �ڷ� �̵�
         delLastnode = delLastnode -> rlink;
      }
      free(delLastnode);                  // ������ ��� �߽߰� ������ ��� �޸� ��ȯ
      frontnode -> rlink = NULL;            // frontnode�� delLastnode�� ����Ű�� ��ũ NULL ����
   }	

	return 0;
}



/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {			// ó����ġ�� ��带 �߰��ϴ� �Լ�
   listNode* node = (listNode*)malloc(sizeof(listNode));      // ���� �޸� �Ҵ��Ͽ� node ����
   node->key = key;      // node�� ������ �ʵ忡 �Էµ� ������ ����

   node->rlink = h->first;   // node�� linke�� h�� first ����
   h->first = node;         // ���۳��� node�� ����

	return 0;
}

/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {			//ó�� ��ġ�� ��带 �����ϴ� �Լ�
   listNode* trail;
   if(h -> first == NULL)
   {   // ������ ��尡 ���� ��� ����
      printf("������ ������ ��尡 �����ϴ�.\n");
      return 0;
   } 

   else if(h -> first -> rlink == NULL){         // ����Ʈ�� ��尡 1���϶�
      freeList(h);                  // �Ҵ� �޸� ����
      h -> first = NULL;               // ���۳�带 NULL�� ����
      return 0;                     // ����
   }
   else{                 
   trail = h -> first;              // trail�� ���۳�忡 ����
   h -> first = trail ->rlink;       // ���۳�带 trail�� ���� rlink�� ����
   
   }
	return 0;
}



/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h) {			// ����Ʈ�� ��带 �������� �ٲٴ� �Լ�
	  listNode* one;                   // ��� one, two, three ����
      listNode* two;
      listNode* three;

      one = h -> first;                // one �����͸� ù��° ��忡 ����
      two = NULL;
      three = NULL;

      while (one != NULL){             // one�� ���� NULL�� �ƴҵ��� �ݺ�
         three = two;                  // three�� two�� ����Ű�� ��忡 ����
         two = one;                    // two ��带 one�� ����Ű�� ��忡 ����
         one = one -> rlink;            // one ��带 ���� ���� �̵�
         two -> rlink = three;          // two ����� rlink�� three�� ����
      }
      h -> first = two;                // ���� ��带 two�� ����
	return 0;
}



/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode));	//node��� ����Ʈ ��� �Ҵ�
	listNode* find = h->first;								// ã�����ϴ� 
	node->key = key;
	if(h->first == NULL)
	{
		printf("����� �����Ͱ� �����ϴ�.\n");
		node->rlink = NULL;
		node->llink = NULL;
		return 0;
		
	}else{
		while(find->rlink!=NULL){
			if(find->rlink->key > node->key)
			{
				node->rlink = find->rlink;		//node�� rlink�� find�� rlink�� ����
				find->rlink->llink = node;		//find�� rlink�� link�� node�� ����
				node->llink = find;				//node�� llink�� find�� ����
				find->rlink = node;				//find�� rlink�� node�� ����
				return 0;
			}
			find = find->rlink;					//find�� ���� �ܰ踦 Ž��
		}
		insertLast(h, key);						//ū ���� ������ �������� ��� �߰�
	}
	
	
	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {
  listNode *find = h -> first;                  // find ��尡 first�� ����Ų��
  listNode *frontfind = NULL;                          // ���� ��ų ���
  if(h->first->rlink == NULL)                    // head�� ù ������ Ž�� ����
  {
     printf("����� �����Ͱ� �����ϴ� !\n");
  }
  else{
     while(find->rlink!=NULL){                    // find�� link�� NULL�� �ɶ����� ����.
        if (find-> rlink-> key == key)            // �Է��� key ���� ���� ����� ���� �ִٸ�
        {
           frontfind = find ->rlink;              // ã�����ϴ� ���� frontfind�� ����Ų��.
           find -> rlink = find ->rlink->rlink;     // �����ϰ����ϴ� ����� �翷�� �̾��ش�.
           free(frontfind);                      // ��� ��带 ������Ų��.
           return 0;
        }
        find = find -> rlink;                      // ã�� ���� ������ ���� �����ͷ� �Ѿ��.
     }
     if (find == NULL) printf("ã�� �����Ͱ� �����ϴ�\n");
  }
  return 1;
}



