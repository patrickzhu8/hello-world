#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>
using namespace std;

class pat_string:public string{
	public:
		int GetInt(string str){
			int n =0;
			stringstream os;
			os << str;
			os >> n;
			return n;
		}
		string GetString(int n){
			string s;
			stringstream os;
			os << n;
			os >> s;
			return s;
		}
		string GetTrim(string str){
			str.erase(0,str.find_first_not_of(" "));
			str.erase(str.find_last_not_of(" ")+1);
			return str;
		}
		
		vector<string> GetChar(string str){
			vector<string> v;
			string strResult="";
			istringstream istr(str);
			while(! istr.eof()){
			    istr >> strResult;
				v.push_back(strResult);
			}
			return v;
		}
		
		vector<string> GetChar(string str,char ch){
			vector<string> v;
			string strResult="";
			istringstream istr(str);
			while(! istr.eof()){
			    getline(istr,strResult,ch); //TBD:How to chang to any kind char
				v.push_back(strResult);
			}
			return v;
		}
		vector<string> GetCharby(string str){
			vector<string> v;
			string strResult="";
			istringstream istr(str);
			while(! istr.eof()){
			    getline(istr,strResult,','); //TBD:How to chang to any kind char
				v.push_back(strResult);
			}
			return v;
		}
};
vector<string> vstr;

void display(string str){
	cout << str << endl;
}
int main(int argc,char *argv[]){
	pat_string str;
	int n = str.GetInt("123");
	string s1 = str.GetString(456);
	string s2 = str.GetTrim(" hello ");
	int i = 0;
	cout <<"The string '123' convert to integer is:"<< n << endl;
	cout <<"The integer 456 convert to string is:" << s1 << endl;
	cout <<"The string ' hello ' erase spaceis:" << s2 <<endl;
	//cout << str.GetChar("hello patrick and cissy")<< endl;
	vstr = str.GetChar("hello patrick and cissy");
	for(i=0;i< vstr.size();i++){
		cout<<vstr[i] << endl;
	}
	//test GetChar
	cout << "test GetChar(string,','\n" << endl;
	vstr = str.GetChar("hello,patrick,and,cissy",',');
	for(i=0;i< vstr.size();i++){     //TBD how to use algorithm to show vector element
		cout<<vstr[i] << endl;
	}
	/*
	vstr = str.GetCharby("hello,patrick,and,cissy");
	for(i=0;i< vstr.size();i++){     //TBD how to use algorithm to show vector element
		cout<<vstr[i] << endl;
	}
	*/
	//for_each(vstr.begin(),vstr.end(),display);
	for_each(vstr.begin(),vstr.end(),ptr_fun(display));
	cout << "**************" << endl;
	//ostream_iterator<string> myout(cout,"\t");
	//for_each(vstr.begin(),vstr.end(),ptr_fun(*myout));
	return 0;
}
