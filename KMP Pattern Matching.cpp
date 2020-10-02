#include<bits/stdc++.h>

using namespace std;

int op=0,ed=0;

vector<int> makelps(string pattern)  								//ABABCABAB
{
	int n=pattern.size();
	vector<int> lps(n,0);

	int i=0,j=1;

	while(j<n)
	{
		if(pattern[i]==pattern[j])
		{
			lps[j]=lps[i]+1;
			i++;
			j++;
		}
		else
			j++;
	}

	return lps;
}

bool kmp(string str,string pattern)									//ABABDABACDABABCABAB  -- string
{																	//ABABCABAB 		   -- pattern
	vector<int> lps=makelps(pattern);

	int i=0,j=0;

	while(i<str.size())
	{
		if(str[i]==pattern[j])
		{
			if(j==pattern.size()-1)
			{
				//ed=i+1;
				//op=ed-pattern.size()+1;
				return true;
			}

			i++;
			j++;
		}
		else
		{
			j=lps[j];
			i++;
		}
	}

	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string str,pattern;
	cin>>str>>pattern;

	if(kmp(str,pattern))
		cout<<"yes from "<<op<<" to "<<ed;
	else
		cout<<"no";

	return 0;
}
