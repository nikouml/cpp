#include"stdio.h"
#include"malloc.h"
//1.Ԫ�����ͣ�������ͺ�ָ������
typedef struct LNode         //����ṹ�壬
{
 int num,pwd;                 //num�����洢�˵���ţ�pwd�����洢�˵�����
 struct LNode *next;
};
struct LNode *head,*p,*pt;    //������
//2 ������ѭ����������
 
int creatLinkList(int n)      //����n����������
{
   int i;
   head=(struct LNode*)malloc(sizeof(struct LNode));   //����һ����ͷ��������
   if(!head)  {return 0;}    //�������ɹ�������0
   p=head;
   for(i=1;i<n;i++)
  {
     pt=(struct LNode*)malloc(sizeof(struct LNode));
     if(!pt)  {return 0;}
     p->next=pt;
     p=pt;
  }
    p->next=head; //����ѭ������
    pt=head;
return 0;
}
//3.�����������뺯��
 int enterPwd(int n)        //����n��������
{
   int i,j;
   printf("\n����������: \n");
    for( i=1;i<=n;i++)
    {
       scanf("%d",&j);
       pt->num=i;        //num�洢�˵����
       pt->pwd=j;         //pwd�洢�˵�����
       pt=pt->next;
    }
    pt=p;
return j;
}
 //4�������������
 int outList(int m,int n)    //����m��n���ݱ�������ֵ������
{
   int i,a;
   for(i=1;i<=n;i++)         //��һ��forѭ������ѭ������
   {
      for(a=1;a<m;a++)      //ɾ�����
      {
        pt=pt->next;
      }
      p=pt->next;
      m=p->pwd;
      printf("%d ",p->num);    //����˵����
      pt->next=p->next;
      free(p);          //�ͷŶ�̬����Ľ��ռ�
   }
   return 0;
}
 //������
int main()
{   int m,n;   //mΪ��������ֵ��nΪ����
    printf("\n����m��n���ݱ�������ֵ������;\n");
    printf("\n������ m ��n: \n");
    scanf("%d %d",&m,&n);
    creatLinkList( n);  //���ô�����������
    enterPwd( n);       //�����������뺯��
    printf("\n���ӵ���������:\n");
    outList( m,n);      //���������������
}