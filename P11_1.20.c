#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float *pa,x;
    float result=0;
    int n,i;
    printf("���������ʽ����ߴ���\n");
    scanf("%d",&n);
    printf("������x��ֵ\n");
    scanf("%f",&x);
    pa=(float*)malloc(n * sizeof(float));
    if(pa==NULL)
    {
        printf("�����ڴ�ռ�ʧ�ܣ��������\n");
        return 0;
    }
    printf("�������ʼ��������ÿ��ǰ��ϵ����\n");
    for(i=0;i<=n;i++)
    {
        printf("%d����:",i);
        scanf("%f",&pa[i]);
    }
    result=pa[n]*x+pa[n-1];
    for(i=n-1;i>=1;i--)
    {
        result=result*x+pa[i-1];
        printf("%f  ",result);
    }
    printf("����ʽ���Ϊ:%f\n",result);
    free(pa);

    return 0;
}
