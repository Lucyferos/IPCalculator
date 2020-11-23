#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

int ile(int rozmiar, string *tabl, string szukana)
{
int x,wynik=0;
for(x=0;x<=rozmiar-1; x++)
if (tabl[x]==szukana)
wynik++;
return wynik;
}

int BinaryToDecimal(int n) {
   int decimalNumber = 0;
   int base = 1;
   int temp = n;
   while (temp) {
      int lastDigit = temp % 10;
      temp = temp/10;
      decimalNumber += lastDigit*base;
      base = base*2;
   }
   return decimalNumber;
}

int StringtoInt(string x){
	int x1;
	stringstream geek(x);
    geek>>x1;
    return x1;
}


string Network2(string a1, string a2, string a3, string a4){
	int x1,x2,x3,x4;
x1= StringtoInt(a1);
x2= StringtoInt(a2);
x3= StringtoInt(a3);
x4= StringtoInt(a4);


stringstream s1;
s1 << BinaryToDecimal(x1);
string stra1 = s1.str();

stringstream s2;
s2 << BinaryToDecimal(x2);
string strb = s2.str();

stringstream s3;
s3 << BinaryToDecimal(x3);
string strc = s3.str();

stringstream s4;
s4 << BinaryToDecimal(x4);
string strd = s4.str();

string final2 =stra1 +"."+strb+"."+strc+"."+strd;
return final2;
}


string Network(int iloscBitow, string ip){
	string network, test="0";
	network= ip.substr(0,iloscBitow);
	int a =32-iloscBitow;
	for(int i=0;i<a-1; i++){
		test=test+"0";
	}
	network += test;
	string a1,b,c,d;
	a1 = network.substr(0,8);
	b = network.substr(8,8);
	c = network.substr(16,8);
	d = network.substr(24,8);

	string final1 = a1+"."+b+"."+c+"."+d;

	string final3 = final1 + Network2(a1,b,c,d);
	return final3;
}

string BroadCast(int iloscBitow, string ip){
	string network, test="1";
	network= ip.substr(0,iloscBitow);
	int a =32-iloscBitow;
	for(int i=0;i<a-1; i++){
		test=test+"1";
	}
	network += test;
	string a1,b,c,d;
	a1 = network.substr(0,8);
	b = network.substr(8,8);
	c = network.substr(16,8);
	d = network.substr(24,8);

	string final1 = a1+"."+b+"."+c+"."+d;

	string final3 = final1 + Network2(a1,b,c,d);
	return final3;
}


int main(int argc, char** argv) {
	int a1,a2,a3,a4;
	 string ip;
	 cout<<"Enter Ip: ";
	 cin>>ip;
     istringstream iss(ip);
     vector<string> SeperatedValue1;
     string SeperatedValue;
   while (getline(iss, SeperatedValue, '.')) {
    if (!SeperatedValue.empty())
        SeperatedValue1.push_back(SeperatedValue);
    }
    
     a1 = StringtoInt(SeperatedValue1[0]);
      a2 = StringtoInt(SeperatedValue1[1]);
      a3 = StringtoInt(SeperatedValue1[2]);
      a4 = StringtoInt(SeperatedValue1[3]);

    int b1,b2,b3,b4;
    bitset<8> bin_a(a1);
    bitset<8> bin_b(a2);
    bitset<8> bin_c(a3);
    bitset<8> bin_d(a4);
    cout << "IP binary:"<<bin_a<<"."<<bin_b<<"."<<bin_c<<"."<<bin_d<<endl;
    string IPString1 = bin_a.to_string(); string IPString2 = bin_b.to_string();
    string IPString3 = bin_c.to_string(); string IPString4 = bin_d.to_string();
    string ipString = IPString1+IPString2+IPString3+IPString4;

   string maska;
   cout<<"Enter Subnet: ";
   cin>>maska;
   
  const char *maskaArr= maska.c_str();	 
	 sscanf(maskaArr, "%d.%d.%d.%d", &b1, &b2, &b3, &b4);
	 
	     
    bitset<8> bin_a6(b1);
    bitset<8> bin_b6(b2);
    bitset<8> bin_c2(b3);
    bitset<8> bin_d2(b4);
    cout << "Subnet binary:"<<bin_a6<<"."<<bin_b6<<"."<<bin_c2<<"."<<bin_d2<<endl;
    string maskaString1 = bin_a6.to_string(); string maskaString2 = bin_b6.to_string();
    string maskaString3 = bin_c2.to_string(); string maskaString4 = bin_d2.to_string();
    string maskastring = maskaString1+maskaString2+maskaString3+maskaString4;
     
    
   
    int wielkosc= maskastring.length()-1;
    string tab[wielkosc];


    for(int i=0;i<wielkosc+1;i++){
	   tab[i]= maskastring.at(i);

	}


	//wyznaczanie ilosci hostów
    int maskaSkrocona= ile(wielkosc+1, tab, "1");
    int z1 = 32-maskaSkrocona;
    cout<<"Hosts: "<<pow(2, z1)-2<<endl;


    //wyznacznie klasy:
   string mojstring = bin_a.to_string();
   string klasa = mojstring.substr(0,2);

   if(klasa=="00"|| klasa=="01"){
   	cout<<"Class:A"<<endl;
   //	maska = "255.0.0.0";
   }
   else if(klasa=="10"){
   	cout<<"Class:B"<<endl;
   //	maska = "255.255.0.0";
   }
   else if(klasa=="11"){
   	cout<<"Class:C"<<endl;
  // 	maska = "255.255.255.0";
   }
   cout<<"Subnet:"<<maska<<endl;
//    iptobinary(a1,a2,a3,a4);


	//wyznaczanie sieci
     string network= Network(maskaSkrocona, ipString);
     string network2 = network.substr(0,35);
    cout<<"Network Binary:"<<network2;
    cout<<endl;


    //siec decymalnie
    string network1 = network.substr(35,network.length());
    cout<<"Network:"<<network1;
    cout<<endl;
    
    //wyznaczanie broadcast binarnie
    string broadcast = BroadCast(maskaSkrocona, ipString);
    string broadcast2 = broadcast.substr(0,35);
    cout<<"Broadcast:"<<broadcast2<<endl;
    
    //broadcast decymalnie
    string broadcast1 = broadcast.substr(35,broadcast.length());
    cout<<"Broadcast:"<<broadcast1;


    getch();
	return 0;
}

