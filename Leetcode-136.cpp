#include <iostream>
using namespace std;
int main()
{
    int n,val,ans=0;
    cout<<"Enter the length of array: ";
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        cin>>val;
        vec.push_back(val);
    }
    for(int i=0;i<n;i++){
        ans=vec[i]^vec[i+1];
        
    }
    
    cout<<ans;;

    return 0;
}
