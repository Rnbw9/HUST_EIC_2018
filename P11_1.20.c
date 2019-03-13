#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float *pa,x;
    float result=0;
    int n,i;
    printf("请输入多项式的最高次幂\n");
    scanf("%d",&n);
    printf("请输入x的值\n");
    scanf("%f",&x);
    pa=(float*)malloc(n * sizeof(float));
    if(pa==NULL)
    {
        printf("分配内存空间失败，程序结束\n");
        return 0;
    }
    printf("请从零次项开始依次输入每项前的系数。\n");
    for(i=0;i<=n;i++)
    {
        printf("%d次项:",i);
        scanf("%f",&pa[i]);
    }
    result=pa[n]*x+pa[n-1];
    for(i=n-1;i>=1;i--)
    {
        result=result*x+pa[i-1];
        printf("%f  ",result);
    }
    printf("多项式结果为:%f\n",result);
    free(pa);

    return 0;
}
