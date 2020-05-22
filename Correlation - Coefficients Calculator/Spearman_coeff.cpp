# include<bits/stdc++.h>
using namespace std;

vector<int> get_rank(int size,vector<double> arr)
{
    vector<int> rank(size);
    vector<bool> used(size);
    for(int i=0;i<size;i++)
    {
        used[i]=false;
    }
    int lowest = highest_value(size,arr);
    for(int i=1;i<=size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(used[j]==false && arr[lowest]>arr[j])
                lowest = j;
        }
        rank[lowest] = i;
        used[lowest] = true;
        lowest = highest_value(size,arr);
    }
    return rank;
}
int highest_value(int size,vector<double> arr)
{
    int highest=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>arr[highest])
            highest = i;
    }
    return highest;
}
double deviation(int size,vector<int> x_rank,vector<int> y_rank)
{
    double d;
    for(int i=0;i<size;i++)
    {
        d += pow(x_rank[i]-y_rank[i],2);
    }
    return d;
}
double spearman_coeff(int size,vector<int> x_rank,vector<int> y_rank)
{
    return 1 - ((6 * deviation(size, x_rank, y_rank)) / (size * (pow(size, 2) - 1)));
}

int main()
{
    int n;
    cin >> n;
    vector<double> x,y;
    for(int i=0;i<2*n;i++)
    {
        double val;
        cin >> val;
        if(i<n)
            x.push_back(val);
        else
            y.push_back(val);
    }
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << spearman_coeff(n,get_rank(n,x),get_rank(n,y));
    return 0;
}
