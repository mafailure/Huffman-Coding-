#include<bits/stdc++.h>
using namespace std; 
class Node
{
	public: char data; int freq; Node * left,*right; 
	Node(char data,int freq)
	{
		this->data=data; 
		this->freq=freq; 
		left=right=0; 
	}
	bool operator< (Node other)
	{
		 return freq<other.freq; 
	}
};
class pq
{
	private:vector<Node*> a;
	bool comp(Node * x,Node * y)
	{
		return *x<*y; 
	}
	public: pq()
	{
		a.push_back(NULL); 
	}
	void heapify()
	{
		int cur=a.size()-1;
		while(cur!=1)
		{
			int par=cur/2; 
			if((*a[par])<(*a[cur]))break; 
			else swap(a[par],a[cur]),cur=par; 
		}
		
	}
	public: void push(Node * cur)
	{
		   a.push_back(cur); 
		   heapify();  
	}
	public: void pop()
	{
		swap(a[1],a.back()); 
		a.pop_back(); 
		int cur=1; 
		while(1)
		{
			int largest=cur; 
			if(2*cur<a.size()&&!(*a[cur]<*a[2*cur]))largest=2*cur; 
			if(2*cur+1<a.size()&&!(*a[largest]<*a[2*cur+1]))largest=2*cur+1; 
			if(largest==cur)return ; 
			swap(a[cur],a[largest]); 
			cur=largest; 
		}
	}
	public:Node * top()
	{
		return a[1]; 
	}
	public: int size()
	{
		return a.size()-1; 
	}
	
};
pq TREENODES ; 
vector<string> val(26); 
void traverse(Node * root,string s)
{
	if(root->data>='a'&&root->data<='z')val[root->data-'a']=s; 
	if(root->left)traverse(root->left,s+'0'); 
	if(root->right)traverse(root->right,s+'1'); 
}
signed main()
{
		int n;
		cin>>n;
		vector<char>chars(n); vector<int> freq(n); 
		for(int i=0;i<n;i++)cin>>chars[i]>>freq[i]; 	  
		for(int i=0;i<n;i++)TREENODES.push(new Node(chars[i],freq[i]));
		while(TREENODES.size()>1)
		{
			 Node * a=TREENODES.top(); 
			 TREENODES.pop(); 
			 Node * b=TREENODES.top(); 
			 TREENODES.pop(); 
			 Node * par=new Node('\n',a->freq+b->freq); 
			 par->left=a; par->right=b;
			 TREENODES.push(par);  
		}
		traverse(TREENODES.top(),"");
		for(int i=0;i<n;i++)
		{
			cout<<chars[i]<<" "<<val[chars[i]-'a']<<endl; 
		}
		
}
