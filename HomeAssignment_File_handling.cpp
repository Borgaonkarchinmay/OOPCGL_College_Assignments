#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class employee{
	// Declare info of employee privately
	
	char name[30];
	int age, empID;
	
	public:
		
		// This function will get the employee details from console
		void readData(void){
			
			cout<<"\nEnter name of employee: ";
			cin>>name;
			cout<<"Enter age of employee: ";
			cin>>age;
			cout<<"Enter employee ID of employee: ";
			cin>>empID;
			cout<<endl;
		}
		
		
		// This function will display the employee details on the console
		void writeData(void){
			
			cout<<endl;
			cout<<"Required data of employee: "<<endl;
			cout<<"Name:\t"<<name<<"  Age:\t"<<age<<"  empID:\t"<<empID<<endl;
		}
		
		
		// This function searches for data of given employee name 
		void search(employee (& EMP)[4], char tar_nam[30]){ // Accept the array of objects by reference and name of target employee
			
		ifstream fin;
		fin.open("DataBase.txt");
		int flag = 0;
		fin.seekg(0); // Set get pointer to the begining of the file
		
		for(int i = 0; i < 4; i++){
			
			fin.read((char*) &EMP[i], sizeof(EMP[i])); // Read the data of using object from the file
			
			if(strcmp(EMP[i].name, tar_nam) == 0){
				EMP[i].writeData();
				flag = 1;
				break; 
			}
				
			if(i == (3) && flag == 0){
				cout<<"Employee details not found!! "<<endl;
			}
		}
			
		fin.close();
	}
			
};
	
	
	
// Driver Code	
int main(){

	
	employee emp[4]; // Declare array of objects
	employee tempEmp;
	char tarName[30]; // tarName will store the Name of employee to be searched
	
	
	

	ofstream fout;
	fout.open("DataBase.txt");
	
	for(int i = 0; i < 4; i++){
	
		emp[i].readData(); // Read employee of each employee 
		fout.write((char*)& emp[i], sizeof(emp[i])); // Write the data of each employee in file (binary form) one by one
	}
	
	fout.close();
	



	
	ifstream fin;
	fin.open("DataBase.txt");
	
	fin.seekg(0); // To read the file set the get pointer to the begining of the file
	
	for(int i = 0; i < 4; i++){
		
	fin.read((char*) & emp[i], sizeof(emp[i])); // Read the data of employee from the file
	emp[i].writeData(); // Display the data of employee on console
	}
	
	fin.close();

	
	
	
	
	
	// Ask for name of employee to be searched 
	cout<<"\nEnter employee to be searched"<<endl;
	cin>>tarName;
	tempEmp.search(emp, tarName); // search for the employee in the DataBase
	
	return 0;
}

/*
........
OUTPUT:

Enter age of employee: 11
Enter employee ID of employee: 21118


Enter name of employee: Rahul
Enter age of employee: 22
Enter employee ID of employee: 21119


Required data of employee:
Name:   Chinmay  Age:   19  empID:      21114

Required data of employee:
Name:   Sakshi  Age:    21  empID:      11121

Required data of employee:
Name:   Shrey  Age:     11  empID:      21118

Required data of employee:
Name:   Rahul  Age:     22  empID:      21119

Enter employee to be searched
Rahul

Required data of employee:
Name:   Rahul  Age:     22  empID:      21119

--------------------------------
Process exited after 77.71 seconds with return value 0
Press any key to continue . . .

*/

