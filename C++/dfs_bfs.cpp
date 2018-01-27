#include <stdlib.h>
#include <stdio.h>

struct node                       /* ͼ����ṹ����     */
{
   int vertex;                    /* ����������Ϣ       */
   struct node *nextnode;         /* ָ��һ�����ָ��   */
};
typedef struct node *graph;       /* ͼ�εĽṹ����̬   */
struct node head[9];              /* ͼ�ζ�������       */
int visited[9];                   /* �����������       */

/********************�������е���Ϣ�����ڽӱ�********************/
void creategraph(int node[20][2],int num)/*numָ����ͼ�ı���*/
{
   graph newnode;                 /*ָ���½ڵ��ָ�붨��*/
   graph ptr;
   int from;                      /* �ߵ����          */
   int to;                        /* �ߵ��յ�          */
   int i;
   for ( i = 0; i < num; i++ )    /* ��ȡ������Ϣ�������ڽӱ�*/
   {
      from = node[i][0];         /*    ���ߵ����            */
      to = node[i][1];           /*   ���ߵ��յ�             */
      
   /* �����¶��� */
      newnode = ( graph ) malloc(sizeof(struct node));
      newnode->vertex = to;        /* ������������       */
      newnode->nextnode = NULL;    /* �趨ָ���ֵ       */
      ptr = &(head[from]);         /* ����λ��           */
      while ( ptr->nextnode != NULL ) /* ����������β   */
         ptr = ptr->nextnode;     /* ��һ������         */
      ptr->nextnode = newnode;    /* ����ڵ�        */
   }
}

/**********************  ͼ�����������Ѱ��********************/
void dfs(int current)
{
   graph ptr;
   visited[current] = 1;          /* ��¼�ѱ�����       */
   printf("vertex[%d]\n",current);   /* �����������ֵ     */
   ptr = head[current].nextnode;  /* ����λ��           */
   while ( ptr != NULL )          /* ����������β       */
   {
      if ( visited[ptr->vertex] == 0 )  /* ���û������ */
         dfs(ptr->vertex);              /* �ݻر������� */
      ptr = ptr->nextnode;              /* ��һ������   */
   }
}

/****************************** ������******************************/
int main()
{
   graph ptr;
   int node[19][2] = { {1, 2}, {2, 1},  /* ��������     */
                       {1, 3}, {3, 1},
                       {2, 4}, {4, 2},
                       {2, 5}, {5, 2},
                       {3, 6}, {6, 3},
                       {3, 7}, {7, 3},
                       {4, 8}, {8, 4},
                       {5, 8}, {8, 5},
                       {6, 7}, {7, 6},
					    };
   int i;
   //clrscr();
   for ( i = 1; i <= 8; i++ )      /*   ���������ʼ��  */
   {
      head[i].vertex = i;         /*    �趨����ֵ      */
      head[i].nextnode = NULL;    /*       ָ��Ϊ��     */
      visited[i] = 0;             /* �趨������ʼ��־   */
   }
   creategraph(node,19);          /*    �����ڽӱ�      */
   printf("Content of the gragh's ADlist is:\n");
   for ( i = 1; i <= 8; i++ )
   {
      printf("vertex%d ->",head[i].vertex); /* ����ֵ    */
      ptr = head[i].nextnode;             /* ����λ��   */
      while ( ptr != NULL )       /* ����������β       */
      {
         printf(" %d ",ptr->vertex);  /* ӡ����������   */
         ptr = ptr->nextnode;         /* ��һ������     */
      }
      printf("\n");               /*   ����             */
   }
   printf("\nThe end of the dfs are:\n");
   dfs(1);                        /* ��ӡ�����������   */
   printf("\n");                  /* ����               */
   puts(" Press any key to quit...");
  // getch();
}