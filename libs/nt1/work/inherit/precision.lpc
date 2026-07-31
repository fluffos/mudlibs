//Created by Super at 2002.
//These functions will be used to extend the limit of intergets.
#define MX 20

private int max(int a,int b)
{
        if(a>b) return a;
        else return b;
}

private int min(int a,int b)
{
        if(a<b) return a;
        else return b;
}

//convert a normal integer to a array.
int *convert(int a)
{
        string b;
        int *returns,size;
        b = sprintf("%d",a);
        size = sizeof(b)-1;
        returns = allocate(MX);
        for(int i=size;i>=0;i--)
                returns[size-i] += b[i] - 48;
        
        return returns;
}

private int *carry(int *a)
{
        int *result;
        result = allocate(sizeof(a)+1);
        for(int i=0;i<sizeof(a);i++)
        {
                result [i] += a[i];
                result [i+1] = result[i] / 10;
                result [i] = result[i] % 10;
        }
        return result;
}

//same as a+b           
int *addd(int *a, int *b)
{
        int *ab,maxn;
        maxn = max(sizeof(a),sizeof(b));
        ab = allocate(MX);
        for(int i=0;i<MX;i++)
                ab[i] = a[i] + b[i];
        return carry(ab);
}

//same as a-b
int *sub(int *a,int *b)
{
        int *ab,maxn;
        maxn = max(sizeof(a),sizeof(b));
        ab = allocate(MX);
        for(int i=0;i<maxn;i++)
        {
                if(a[i]<b[i])
                {
                        a[i]+=10;
                        a[i+1]-=1;
                }
                ab[i] = a[i] - b[i];
        }
        return carry(ab);
}

//same as a>b ,return 0 or 1
int bigger(int *a,int *b)
{
        for(int i = MX;i>=0;i--)
                if(a[i]>b[i]) return 1;
        return 0;
}

//same as a<b , return 0 or 1
int smaller(int *a,int *b)
{
        for(int i=MX;i>=0;i--)
                if(a[i]<b[i]) return 1;
        return 0;
}

//same as a == b,return 0 or 1
int same(int *a,int *b)
{
        for(int i=0;i<MX;i++)
                if(a[i]!=b[i]) return 0;
        return 1;
}

//same as a!= b return 0 or 1
int not(int *a,int *b)
{
        for(int i=0;i<MX;i++)
                if(a[i]==b[i]) return 0;
        return 1;
}
string process(int*);

//same as a*b
int *mul(int *a,int *b)
{
        int *ab,*temp;
        ab = allocate(MX);
        for(int i=0;i<MX;i++)
        {
                temp = 0;
                temp = allocate(2*MX);
                for(int j=0;j<MX;j++)
                        temp[i+j] = a[i]*b[j];
                ab = addd(ab,carry(temp));
        }
        return carry(ab);
}

//process a int array to string
string process(int *a)
{
        int size,n;
        string b;
        size = sizeof(a)-1;
        b = "";
        for(int i = size;i>=0;i--)
        {
                if(a[i]>0) 
                        n = 1;
                if(n) b+=sprintf("%d",a[i]);
        }
        return b;
}

