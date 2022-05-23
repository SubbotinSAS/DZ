#include <iostream>
#include <fstream>
#include <stdio.h>
#include<cstring>
//#include <windows.h>
#include <string>

using namespace std;

/*struct writer{
	int n = 0;
	string preline;
	string postline;

	void wrtie(const string &s){
     char ss[s.length()];
	   for (int i = 0; i < s.length(); i++) {
		  ss[i]=s[i];
	   }
	   if(n==0 && strchr(ss,';')-ss>-1){
		 n=1;
	   }
	   if(n==0 && strchr(ss,'(')-ss>-1){
		 n=1;
	   }
       if(n==0 && strchr(ss,'{')-ss>-1){
		 n=1;
	   }
	}

	void write(const string &s, int &nn,ofstream &out){
	   char ss[s.length()];
	   for (int i = 0; i < s.length(); i++) {
		  ss[i]=s[i];
	   }
	   if(nn==2){nn=0;}
	   if(nn==3){nn=0;}
	   if(nn==0 && strchr(ss,'(')-ss>-1 && strchr(ss,')')-ss<0){
	   nn = 1;
	   }
	   if(nn==0 && strchr(ss,'(')-ss>-1 && strchr(ss,')')-ss>-1){
	   nn = 3;
	   }
	   if(nn==1 && strchr(ss,')')-ss<0){
	   preline+=s;
	   }
	   if(nn==1 && strchr(ss,')')-ss>-1){
	   preline+=s;
	   nn=2;
	   out<<preline<<endl;
	   preline.erase();
	   }
	   if(nn==0 && n==0){out<<s<<endl;}
	   if(nn==3){out<<s<<endl;}
	}
	void wtire(const string &s,int &nn,ofstream &out){
		for(int i = 0;i<s.length();i++){
		if(nn==0 && n==1){
		 postline+=s[i];
		 if(s[i]==';'){
		 out<<postline<<endl;
		 postline.erase();
		 }
		 if(s[i]=='{'){
		 out<<postline<<endl;
		 postline.erase();
		 }
		  if(s[i]=='}'){
		 out<<postline<<endl;
		 postline.erase();
		 }
		}
		}
	}
};*/

int main(void){
	string line;
	string lline;
	string llline;
	int nn = 0;
  int tt = 0;
	int t = 0;
	int tc = 0;
	//writer wr;
	ifstream in("C:/1/Lab2/1.txt");
	ofstream out("C:/1/Lab2/2.txt", ios_base::out);
	if (in.is_open() && out.is_open()) {
		while(getline(in, line)){
		  lline+=line;
		}
		for(int i = 0;i<lline.length();i++){
		  llline+=lline[i];
		  if(nn==0 && lline[i]=='>'){
		    out<<llline<<endl;
		    llline.erase();
		  }
		  if(lline[i]==';' || lline[i]=='(' || lline[i]=='{'){
		    nn=1;
		  }
		  if(nn==1 && lline[i]=='('){
		    t = 1;
		  }
		  if(nn==1 && lline[i]=='{'){
		    for(int y = 0;y<tc;y++){
			    out<<"    ";
		    }
		    out<<llline<<endl;
		    llline.erase();
		    tc = tc+1;
		  }
		  if(nn==1 && lline[i]==';' && t==0 && tt==0){
		    for(int y = 0;y<tc;y++){
			    out<<"    ";
		    }
		    out<<llline<<endl;
		    llline.erase();
		  }
      if(nn==1 && lline[i]==';' && t==0 && tt==1){
		    for(int y = 0;y<tc;y++){
			    out<<"    ";
		    }
        tc = tc-1;
        tt = 0;
		    out<<llline<<endl;
		    llline.erase();
		  }
		  if(nn==1 && lline[i]==')'){
        while(lline[i+1]==' '){
          lline.erase(i+1,1);
        }
		    t = 0;
		  }
		  if(nn==1 && lline[i]==')' && lline[i+1]!=';' && lline[i+1]!='{'){
		    for(int y = 0;y<tc;y++){
			    out<<"    ";
		    }
		    out<<llline<<endl;
		    llline.erase();
        tt=1;
        tc=tc+1;
		  }
		  if(nn==1 && lline[i]=='}'){
		    tc=tc-1;
		    for(int y = 0;y<tc;y++){
			    out<<"    ";
		    }
		    out<<llline<<endl;
		    llline.erase();
		  }
    }
	}
	else
	cout<<"Error!"<<endl;

	//Sleep(100000);
	in.close();
	//out.close();
	return 0;
}
