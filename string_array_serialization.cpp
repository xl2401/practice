#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string serialize(vector<string> S)
{
    string final = "";
    for(int i=0; i<S.size(); i++)
    {
        for(int j=0; j<S[i].length(); j++)
        {
            if(S[i][j]==',')
            {
                S[i].insert(j,"\\");
                j++;
            }
            else if(S[i][j]=='\\')
            {
                S[i].insert(j,"\\");
                j++;
            }
        }
        final = final + S[i] + ",";
    }
    return final;
}
vector<string> deserialize(string s)
{
    vector<string> final;
    int i = 0;
    string temp = "";
    while(i<s.length())
    {
        if(s[i]=='\\')
        {
            temp += s[i+1];
            i = i+2;
            continue;
        }
        if(s[i]==',')
        {
            final.push_back(temp);
            temp.clear();
        }
        else
        {
            temp += s[i];
        }
        i++;
    }
    return final;
}
int main()
{
    string n1 = "a&?(|),,";
    string n2= ",afwe,";
    vector<string> S;
    S.push_back(n1);
    S.push_back(n2);
    cout<<serialize(S)<<endl;
    vector<string> m = deserialize(serialize(S));
    for(int i = 0; i<m.size(); i++)
    {
        cout<<m[i]<<endl;
    }
}
