#include<iostream>
#include<iomanip>
using namespace std;

//a) inputData() : This function will input and return through parameter the customer ID,
//weight of fabric, customer status(either-R(Regular) or W(New) and additional service
//number.
void inputData(int &cID,float &wFabric,char &cStatus,char &aService)
{
	cout<<"\nEnter Customer ID : ";
	cin>>cID;
	cout<<"\nEnter Customer Status(R-regular,W-new) : ";
	cin>>cStatus;
	cout<<"\nEnter Weight of Fabric : ";
	cin>>wFabric;
	cout<<"\nAdditional Service :";
	cout<<"\na)	No additional service";
	cout<<"\nb)	Fabric collection service only - extra charge RM 3.00";
	cout<<"\nc)	Fabric delivery service only - extra charge RM 3.00";
	cout<<"\nd)	Fabric collection and delivery service - extra charge RM 6.00";
	cout<<"\nAdditional Service No? ";
	cin>>aService;	
}

//b) calcBasicCharge() : This function will calculate and return the basic charge based on
//the weight and customer status receive through parameter
int calcBasicChange(float weight,float &basicCharge)
{
	if (weight<4)
		basicCharge=weight*2;
	else
		basicCharge=8+(weight-4)*1.5;
			
	return basicCharge;
}

//c) calcAddService() : This function will determine the additional service charge based
//on the additional service number received through parameter. This function will return the
//additional service charge through parameter
float calcAddService(char addService,char status,float bCharge,float &tCharge)
{
	if (addService=='a'||addService=='A')
		tCharge=bCharge;
	else if (addService=='b'||addService=='B'||addService=='c'||addService=='C')
		tCharge=bCharge+3;
	else if (addService=='d'||addService=='D')
		tCharge=bCharge+6;
			
	if (status=='r'||status=='R')
		tCharge-=1;
	else if (status=='w'||status=='W')
		tCharge=tCharge;
	
	return tCharge;
}

//d) displayReceipt() : This function will receive the customer ID, weight of fabric,
//additional service number and total charge for each customer. It will display the individual
//receipt for each customer
void displayReceipt(int id,float weight,char service,float tCharge)
{
	cout<<"\nRotan Tunggal Fabric Folding Service";
	cout<<"\n----------------------------------------------------------"<<endl;
	cout<<"\nCustomer ID : "<<id;
	cout<<"\nFabric Weight : "<<weight;
	if (service=='a'||service=='A')
		cout<<"\nAdditional Service : a) No additional service";
	else if (service=='b'||service=='B')
		cout<<"\nAddional Service : b) Fabric collection service only - extra charge RM 3.00";
	else if (service=='c'||service=='C')
		cout<<"\nAdditional Service : c) Fabric delivery service only - extra charge RM 3.00";
	else if (service=='d'||service=='D')
		cout<<"\nAdditional Service : d) Fabric collection and delivery service - extra charge RM 6.00";
	cout<<"\nTotal Payment : RM "<<fixed<<setprecision(2)<<tCharge<<endl;
	cout<<"\n***THANK YOU***";
	cout<<"\n----------------------------------------------------------";
}

//e) main() : This function will call the function in a-d and display customer ID,
//weight of fabric, additional service entered by user and total charge in 2 decimal places
//The number of customers is determined by each loops
//The summation value of sum of total charge is also determined by each loops
//This function will stop when user enter "n"
int main()
{
	char customerStatus,additionalService,answer='y'; 
	int customerID,customer=0;
	float weightFabric,basicCharge,totalCharge,sumTotalCharge;
	while(answer=='y')
	{
		inputData(customerID,weightFabric,customerStatus,additionalService);
		calcBasicChange(weightFabric,basicCharge);
		calcAddService(additionalService,customerStatus,basicCharge,totalCharge);
		displayReceipt(customerID,weightFabric,additionalService,totalCharge);
		cout<<"\nMore customer(y-yes,n-no) : ";
		cin>>answer;
		customer++;
		sumTotalCharge+=totalCharge;
	}
	cout<<"\nCount of Customer : "<<customer;
	cout<<"\nTotal Collection : RM "<<sumTotalCharge<<endl;
	return 0;
}
