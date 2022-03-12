#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t!=0)
    {
        int i,n,m,j;
        scanf("%d %d",&n,&m);
        char a[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                scanf(" %c",&a[i][j]); //For acceptinng 2d char array without the endign newline
        }
        int ans=0,temp=0,flag=1; // flag denotes whether previous char was black/white
        // For largest continuous blacks in rows
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]=='#')
                {
                    temp++;
                    if(temp>ans)
                        ans=temp;
                }
                if(a[i][j]=='.')
                    temp=0;
            }
            temp=0;
        }
        int ans_cols=0;
        temp=0;
        // For largest continuous blacks in cols
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[j][i]=='#')
                {
                    temp++;
                    if(temp>ans_cols)
                        ans_cols=temp;
                }
                if(a[j][i]=='.')
                    temp=0;
            }
            temp=0;
        }
        if(ans>=ans_cols)
            printf("%d\n", ans);
        if(ans_cols>ans)
            printf("%d\n",ans_cols);
        t--;
    }
}