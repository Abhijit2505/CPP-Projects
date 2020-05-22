# include<bits/stdc++.h>
using namespace std;

void fill_array1(double a[],int size)
{
    for(int i=0;i<size;i++)
    {
        cin >> a[i];
    }
}
void fill_array2(double b[],int size)
{
    for(int i=0;i<size;i++)
    {
        cin >> b[i];
    }
}
double mean(double a[],int size)
{
    double sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=a[i];
    }
    return sum/size;
}
double std_dev(double a[],int size)
{
    double sum1=0,sum2=0,m,v,sd;
    for(int i=0;i<size;i++)
    {
        sum1+=a[i];
    }
    m = sum1/size;
    for(int j=0;j<size;j++)
    {
        sum2+=pow((a[j]-m),2);
    }
    v = sum2/size;
    sd = sqrt(v);
    return sd;
}
double rank_coefficient(double mean1,double mean2,double sd1,double sd2,double a[],double b[],int size)
{
    double p=0,rank_coeff;
    for(int i=0;i<size;i++)
    {
        p+=(a[i]-mean1)*(b[i]-mean2);
    }
    rank_coeff = p/(size*sd1*sd2);
    return rank_coeff;
}

int main()
{
    int n;
    cin >> n;
    double a[n],b[n],mean1,mean2,sd1,sd2,rc;
    fill_array1(a,n);
    fill_array2(b,n);
    mean1 = mean(a,n);
    mean2 = mean(b,n);
    sd1 = std_dev(a,n);
    sd2 = std_dev(b,n);
    rc = rank_coefficient(mean1,mean2,sd1,sd2,a,b,n);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << rc << endl;
    return 0;
}
