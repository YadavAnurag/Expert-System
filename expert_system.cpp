#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
using namespace std;
class Data{
public:
char pattern[20];
char name[30];
};

	void welcome_screen(void);
    void personal_info(void);
    void good_bye(void);
    void proceed(void);
	void putData(void);
	void update_database(void);
    void checkValue(void);
    void user_symptoms_match(Data&);
    
	void user_symptoms_input(Data &dGet){
	ifstream file;
	char arr[100];
	int i=0;
	file.open("questions.txt");
	while(i<14){
		file.getline((char *) arr, 99);
		cout<<arr<<"\n";
		cin>> dGet.pattern[i];
		i++;
	}
	
}
string user_name;

//             **************** starting of main()****************
int main(){
	Data d, dGet;
	welcome_screen();
	while(1){
	printf("\n\n");
	printf("\n1.Do You Want to find your Disease ??");
	printf("\n2.Do you Want to update your Disease database ??");
	printf("\n3.Exit\n");
	int a;
	cin>>a;
	if(a==1){
	personal_info();
	cout<<"Please keep patience and help us to identify ur problem\n";
	user_symptoms_input(dGet);
	user_symptoms_match(dGet);
	}
	if(a==2){
	personal_info();
	update_database();
	}
	if(a==3)
	good_bye();
}
	return 0;
}

//            ***************** end of main() *****************
                                 //*************functions definitions**************  

 //                            ************ definition of welcome screen end****************								 
void welcome_screen(void){
	
printf("\n\n\n\n\n");
printf("************* W E L C O M E *************\n");
printf("*************  E X P E R T S Y S T E M ************\n");
printf("\n\n\n***************Done By Me*****************\n");
printf("*****************************************************\n");
printf("*****************************************************\n");
}
//                          ************** definition of horizontal_stars()***************
/*void clss::horizontal_stars(void){
printf("\t\t\t***************************************************************\n");
printf("\t\t\t***************************************************************\n");
}*/
                 //******  personal info function*******
void personal_info(){	
printf("\n\n");
printf("            P E R S O N A L info\n");
printf("N A M E     :");
cin>>user_name;
}


  // *************** exit function definition ****************
void good_bye(){

printf("\n\n");
printf("************************ GOOD BYE ************************\n");
printf("**********************************************************\n");
printf("**********************************************************\n");
exit(1);
}

//    ***************  definition of update_database() *******************
void  update_database(){
	fstream fileValue;
	Data d, dGet;
	int flag=0;
	fileValue.open("value.dat", ios::in);  // Couldn't recover the correct arguments for file opening methods
	user_symptoms_input(dGet);
	while(fileValue){
		fileValue.read((char *)&d, sizeof(d));
		if(!strcmp(d.pattern,dGet.pattern)){
			flag=1;
		}
	}
	fileValue.close();
	if(flag==1){
		cout<<"\nSorry We already have a value for it.\n";
		return;
	}
	else if(flag==0){
		fstream nfileValue("value.dat", ios::app);
		cout<<"\nEnter the name of this disease:\n";
		cin>>dGet.name;
		nfileValue.write((char *)&dGet, sizeof(dGet));
		cout<<"Data Updated successfully.\n";
		cout<<"Thankyou "<< user_name << " for your kind support\n";
		nfileValue.close();
		return;
    }

}


//   ******************* definition of user_syptoms_match()**************
void  user_symptoms_match(Data &dGet){
	fstream fileValue;
	Data d;
	int flag=0;
	fileValue.open("value.dat");  //Could not recover the correct arguments for file Opening 
		while(fileValue){
		fileValue.read((char *)&d, sizeof(d));
		if(!strcmp(d.pattern,dGet.pattern)){
			flag=1;
			strcpy(dGet.name, d.name);
			break;
		}
	}
	if(flag == 1){
		cout<<" \nDr.Anurag has indentified the disease and it is \n";
		cout<<dGet.name;
		cout<<" We wish "<< user_name<<" to get well soon\n";
		fileValue.close();
		return;
	}
	else if(flag == 0){
		cout<<"\nSorry but database doesn't got the update for this symptoms\n";
		cout<<"Please help us to improve our services by updating our record\n";
		fileValue.close();
		return;
	}
}
