#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cmath>
using namespace std;

//char alpha[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
void fun(string& arr,string& filtered,bool cwb,bool& vert, int &rwcnt, int &rwfinal, int &colcnt, int &colfinal, int &cnt,int &rowcurrent, int &colcurrent, int size,int &colgoal,int &rowgoal);

int main(int argc,char *argv[]){
	if(argc!= 5){
		cout<<"Usage is rtc \"string\" (columns,rows) clockwise/counter-clockwise"<<endl;
		return 0;
	} else {
		//Filter string
		string Mystring=argv[1];
		cout<<Mystring<<endl;
		string filtered;
		for(int i=0;i<Mystring.length();i++){
			if(int(Mystring[i])<=90 && int(Mystring[i])>=65){
				filtered+=Mystring[i];
			}else if(int(Mystring[i])<=122 && int(Mystring[i])>=97){
				filtered+=(int(Mystring[i])-32);
			}
		}
		cout<<filtered<<endl;
		//create variables
		string col=argv[2];
		col=col.substr(1,col.length()-2);
		string rw=argv[3];
		rw=rw.substr(0,rw.length()-1);
		bool cwb=false;
		int rwcnt=0; //number of passes
		int rwfinal=atoi(rw.c_str());
		int colcnt=0; //number of horizontal passes
		int colfinal=atoi(col.c_str());
		int size=rwfinal*colfinal;
		int cnt=1;
		//char arr[size];
		string arr;
		arr.reserve(size);
		arr+=filtered[colfinal-1];
		int axes =size-filtered.length();
		cout<<filtered.length()<<size<<axes<<endl;
		if (axes!=0){
			for(int i=0;i<axes;i++){
				filtered+="X";
			}
		}
		int rowgoal=0;
		int colgoal=0;
		int rowcurrent=0;
		int colcurrent=colfinal-1;
		bool vert=false;
		cout<<filtered<<endl;
		cout<<rwfinal<<"  "<<colfinal<<"  "<<rwcnt<<"  "<<colcnt<<endl;
		cout<<rowcurrent<<"  "<<colcurrent<<endl;
		//do the program
		string cw=argv[4];
		if (cw=="clockwise"){
			cout<<"clockwise"<<endl;
			cwb=true; //clockwise
			vert=true;
		}
		fun(arr,filtered,cwb,vert,rwcnt,rwfinal,colcnt,colfinal,cnt,rowcurrent,colcurrent,size,colgoal,rowgoal);
		cout<<arr<<endl;
		return 0;
	}
}
//a function taking in the rwcnt and col cnt and a reference
void fun(string& arr,string& filtered,bool cwb,bool& vert, int &rwcnt, int &rwfinal, int &colcnt, int &colfinal, int &cnt,int &rowcurrent, int &colcurrent,int size,int &colgoal,int &rowgoal){
	//check if finished
	cout<<vert<<endl;
	if(cnt>=size){
		return;
	} else {
		if (vert==true){
			cout<<"right next to if statemnt and vert is "<<vert<<"and rwcnt%2="<<rwcnt%2<<endl;
			if(rwcnt%2==0){
				rowgoal=rwfinal-(colcnt/2)-1;
				cout<<rwfinal<<"	"<<rwcnt%2<<endl;
				rowcurrent++;
				cout<<rowcurrent<<" "<<rowgoal<<endl;
				//cout<<"Going down to  "<<rowgoal<<endl;
				//cout<<rowcurrent<<endl;
				for (rowcurrent;rowcurrent<=rowgoal;rowcurrent++){
					//cout<<(rowcurrent)*colfinal+colcurrent<<endl;
					arr+=filtered[(rowcurrent)*colfinal+colcurrent];
					cout<<arr[cnt];
					cnt++;
					cout<<"\t"<<cnt<<"/"<<size<<"	Rowgoal:	"<<rowgoal<<"	current:	"<<colcurrent<<"/"<<rowcurrent<<"	count 	:"<<colcnt<<"/"<<rwcnt<<"	vert	"<<vert<<endl;
				}
				rowcurrent--;
				//cout<<colcurrent<<"  rowcurrent:	"<<rowcurrent<<endl;
			}else{
				rowgoal=colcnt-1;
				rowcurrent--;
				cout<<"Going up to"<<rowgoal<<endl;
				for (rowcurrent;rowcurrent>=rowgoal;rowcurrent--){
					arr+=filtered[(rowcurrent)*colfinal+colcurrent];
					cout<<arr[cnt];
					cnt++;
					cout<<"\t"<<cnt<<"/"<<size<<"	Rowgoal:	"<<rowgoal<<"	current:	"<<colcurrent<<"/"<<rowcurrent<<"	count 	:"<<colcnt<<"/"<<rwcnt<<"	vert	"<<vert<<endl;
				}
				//cout<<colcurrent<<"  rowcurrent:	"<<rowcurrent<<endl;
				rowcurrent++;
			}
			rwcnt++;
			vert=false;
			//cout<<vert<<"	"<<colcnt<<"	"<<rwcnt<<endl;
			fun(arr,filtered,cwb,vert,rwcnt,rwfinal,colcnt,colfinal,cnt,rowcurrent,colcurrent,size,colgoal,rowgoal);
		}else {
			if (colcnt%2==0){
				colgoal=rwcnt/2;
				colcurrent--;
				//cout<<"<--"<<colgoal<<endl;
				for (colcurrent;colcurrent>=colgoal;colcurrent--){
					arr+=filtered[(rowcurrent)*colfinal+colcurrent];
					cout<<arr[cnt];
					cnt++;
					cout<<"\t"<<cnt<<"/"<<size<<"	colgoal:	"<<colgoal<<"	current:	"<<colcurrent<<"/"<<rowcurrent<<"	count 	:"<<colcnt<<"/"<<rwcnt<<"	vert	"<<vert<<endl;
				}
				colcurrent++;
				//cout<<colcurrent<<"  rowcurrent:	"<<rowcurrent<<endl;
			}else{
				colgoal=colfinal-rwcnt-1;
				//cout<<"-->"<<endl;
				colcurrent++;
				for (colcurrent;colcurrent<=colgoal;colcurrent++){
					arr+=filtered[(rowcurrent)*colfinal+colcurrent];
					cout<<arr[cnt];
					cnt++;
					cout<<"\t"<<cnt<<"/"<<size<<"	colgoal:	"<<colgoal<<"	current:	"<<colcurrent<<"/"<<rowcurrent<<"	count 	:"<<colcnt<<"/"<<rwcnt<<"	vert	"<<vert<<endl;
				}
				//cout<<colcurrent<<endl;
				colcurrent--;
				//cout<<"changing"<<colcurrent<<endl;
			}
		colcnt++;
		//cout<<colcnt<<endl;
		vert=true;
		//cout<<vert<<endl;//"	"<<colcnt<<"	"<<rwcnt<<endl;
		fun(arr,filtered,cwb,vert,rwcnt,rwfinal,colcnt,colfinal,cnt,rowcurrent,colcurrent,size,colgoal,rowgoal);
		}
	}
}
	//check which direction it should go
	/*if clockwise,
	*/