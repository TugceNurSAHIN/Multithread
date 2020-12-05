#include <iostream>
#include <string>
#include<math.h>
#include <cstring>
#include <string.h>
#include<fstream>
#include <thread>
using namespace std;
int tasan=0;
struct thread_data {
   int  row;
   int sent;
   int que;
   int frst;
   int lst;
};

void *iftar(void *sahur){
int satir=0;
char ch;
int i=0,j=0,k=0;
struct thread_data *imsakiye;
imsakiye=(struct thread_data *) sahur;
ifstream DosyaOku("input.txt");

	if(DosyaOku.is_open()){
		while(DosyaOku.get(ch)) {
        		if (ch == '\n') {
            			satir++;}}}
string file[satir+tasan];
DosyaOku.close();
ifstream DosyaOku1("input.txt");
if(DosyaOku1.is_open()){
 while(getline(DosyaOku1,file[k])){
	//cout<<file[k];
	if(k>=satir-1) break;
k++;
}}
int counter=0;
int counter1=0;

	for(i=imsakiye->frst;i<=imsakiye->lst;i++){
			
		if(i>satir) break;
		for(j=0;j<=file[i].length();j++){	
			//cout<<file[i][j];
			if(file[i][j]=='.'||file[i][j]=='?'||file[i][j]=='!'||file[i][j]==':')
				{counter++;}    }counter1++;
				if(i>=satir)
					counter1--;
		  			    }			
imsakiye->sent=counter;
imsakiye->row=counter1;	}			 
int main() {
char ch;
int satir=0;
int htiss; //her tread için satır sayısı
int x; //thread number
int tm;
int i;
cout<<"Thread Number?\n";
cin>>x;
pthread_t threads[x];
struct thread_data td[x];
ifstream DosyaOku("input.txt");
	if(DosyaOku.is_open()){
	     while(DosyaOku.get(ch)) {
        		if (ch == '\n') {
            			satir++; }}}
	DosyaOku.close();
	if(satir%x!=0){
	tasan=satir%x;
	htiss=satir/x+1;}
	else{htiss=satir/x;}
cout<<"Total number of lines in input.txt: "<<satir<<'\n';
cout<<"Each tread should read the number of lines: "<<htiss<<'\n';

 	for( i = 1; i <=x; i++ ) {
	td[i].row=htiss;
	td[i].sent=0;
	td[i].que=i;
	td[i].frst=(i-1)*htiss;
	td[i].lst=(i)*htiss-1;
        tm = pthread_create(&threads[i], NULL, iftar, (void *)&td[i]);
        pthread_join(threads[i],NULL);
	cout<<td[i].que<<".thread for number of sentence : "<<td[i].sent<<" and number of lines: "<<td[i].row<<'\n';}
   pthread_exit(NULL);
return 0;
}








