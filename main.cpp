#include <iostream>
#include<fstream> ///declared to use ifstream
#include<iomanip>
using namespace std;


///Declare Constant array of
const int Maximum = 20;

///Create a struct of Vehicles with members as listed below
struct Vehicles
{
    int ID[Maximum];
    string Model_Name[Maximum];
    int Engine_Cyl[Maximum];
    string Transmission[Maximum];
    string ManufDate[Maximum];
    string ShipData[Maximum];

};
///Create a struct of Options with members as listed below
struct Options
{
    Vehicles ID;
    string SeatTyp[Maximum];
    int WheelSize[Maximum];
    string Stereo[Maximum];
    string Winter_Package[Maximum];

};
///Creat a struct of Owner as listed below
struct Owner
{
    Vehicles ID;
    char flag[Maximum];   /// This stores character  of both I and D

      ///==============individuals=========
    string FirstName[Maximum];
    string lastName[Maximum];
    int AddNum[Maximum];
    string Address[Maximum];
    ///==============individuals=========


    ///========Dealers=====================

    string Zip[Maximum];
    ///========Dealers=====================
};


///Function prototypes
void initalizVehicles( ifstream& infile, Vehicles& ID, Vehicles& Model_Name, Vehicles& Engine_Cyl, Vehicles& Transmission, Vehicles& ManufDate, Vehicles& ShipData );

void initizOptions(ifstream&infile, Options& ID, Options& SeatTyp,Options& WheelSize, Options& Stereo, Options& Winter_Package);
void sortingOptions(ifstream& infile, Options& ID, Options& SeatTyp,Options& WheelSize, Options& Stereo, Options& Winter_Package);


void initizOwner(ifstream& infile, Owner& ID,Owner& flag,Owner& FirstName,Owner& lastName,Owner& AddNum,Owner& Address,Owner& Zip);
void sotingowner(ifstream& infile, Owner& ID,Owner& flag,Owner& FirstName,Owner& lastName,Owner& AddNum,Owner& Address,Owner& Zip);
void PrintVehicles( ifstream& infile, Vehicles ID, Vehicles Model_Name, Vehicles Engine_Cyl, Vehicles Transmission, Vehicles ManufDate, Vehicles ShipData, Options SeatTyp, Options  Wheel_Size, Options Stero, Options Winter_Package,Owner Flag,Owner First_Name,Owner lastName,Owner AddNum, Owner Address, Owner Zip);
void PrintVehiclesForD(ifstream& infile, Vehicles ID, Vehicles Model_Name, Vehicles Engine_Cyl, Vehicles Transmission, Vehicles ManufDate, Vehicles ShipData, Options SeatTyp, Options  Wheel_Size, Options Stero, Options Winter_Package,Owner Flag, Owner Zip);
void PrintVehiclesForI(ifstream& infile, Vehicles ID, Vehicles Model_Name, Vehicles Engine_Cyl, Vehicles Transmission, Vehicles ManufDate, Vehicles ShipData, Options SeatTyp, Options  Wheel_Size, Options Stero, Options Winter_Package,Owner Flag,Owner First_Name,Owner lastName,Owner AddNum, Owner Address);
void PrintVehiclesWithFourCyl(ifstream& infile, Vehicles ID, Vehicles Model_Name, Vehicles Engine_Cyl, Vehicles Transmission, Vehicles ManufDate, Vehicles ShipData, Options SeatTyp, Options  Wheel_Size, Options Stero, Options Winter_Package,Owner Flag,Owner First_Name,Owner lastName,Owner AddNum, Owner Address, Owner Zip);
void PrintVehiclesWithPremStereo(ifstream& infile, Vehicles ID, Vehicles Model_Name, Vehicles Engine_Cyl, Vehicles Transmission, Vehicles ManufDate, Vehicles ShipData, Options SeatTyp, Options  Wheel_Size, Options Stero, Options Winter_Package,Owner Flag,Owner First_Name,Owner lastName,Owner AddNum, Owner Address, Owner Zip);
void PrintVehicleWithLeatherSeats(ifstream& infile, Vehicles ID, Vehicles Model_Name, Vehicles Engine_Cyl, Vehicles Transmission, Vehicles ManufDate, Vehicles ShipData, Options SeatTyp, Options  Wheel_Size, Options Stero, Options Winter_Package,Owner Flag,Owner First_Name,Owner lastName,Owner AddNum, Owner Address, Owner Zip);
int main()
{
    ///declare ifstream
    ifstream infile;

    ///Declare all variables
    Vehicles  listID,listModel_Name, listEngine_Cyl,listTransmission, listManufDate,listShipData;
    Options  list2ID, listSeat, listWheelSizp,listStereo, listWinter_Package;
    Owner  list3ID, listflag,FirstName,listlastName, listAddNum,listAddress, listZip;
    int RecieveCom;




///Open TextFile for vehicles; confirm that the file has been opened
   infile.open("vehicles.txt");
   if (infile )
   {
       cout <<"Success Opening Vehicles.txt"<<endl;
   }




   initalizVehicles(infile,listID, listModel_Name, listEngine_Cyl,  listTransmission, listManufDate, listShipData );///Function Declaration of initalizVehicles


   infile.close();///Close the text file in other to read from options textfile

   infile.open("options.txt");///Open TextFile for options


   initizOptions(infile,list2ID, listSeat, listWheelSizp,listStereo, listWinter_Package);///Function Declaration of initizOptions

   infile.close();///Close the text file in other to read from owner textfile

   infile.open("owner.txt"); ///Open TextFile for owner


    initizOwner( infile,list3ID, listflag,FirstName,listlastName, listAddNum, listAddress, listZip);///Function Declaration of initizOwner



    infile.close();/// Close file


///Print out the whole data in a function called PrintVehicles
cout<<"******************************************************************************************************************************************************"<<endl;
cout<<"******************************************************************************************************************************************************"<<endl;
sortingOptions(infile,list2ID, listSeat, listWheelSizp,listStereo, listWinter_Package);/// call the sorting alogrithm for both Options and Owners
sotingowner(infile,list3ID, listflag,FirstName,listlastName, listAddNum, listAddress, listZip);
PrintVehicles(infile,listID,listModel_Name, listEngine_Cyl,listTransmission, listManufDate,listShipData, listSeat, listWheelSizp,listStereo, listWinter_Package, listflag,FirstName,listlastName, listAddNum,listAddress, listZip);///Function Declaration of PrintVehicles
cout<<"******************************************************************************************************************************************************"<<endl;
cout<<"******************************************************************************************************************************************************\n\n"<<endl;

cout<<"0 - Print all vehicle\n1 - Print only vehicles manufactured for dealers\n2 - Print only vehicles manufactured for individuals\n3 - Print only vehicles with 4 cylinders engines\n4 - Print only vehicles with premium\n5 - Print only vehicles with leather seats\n6 - Exit:\n"<<endl;

cin >> RecieveCom;





while(RecieveCom < 7)
{
    cout <<"You Entered: "<<RecieveCom << endl<<endl;
if(RecieveCom == 0 ||RecieveCom < 6)
{


    if (RecieveCom == 0)
{
    PrintVehicles(infile,listID,listModel_Name, listEngine_Cyl,listTransmission, listManufDate,listShipData, listSeat, listWheelSizp,listStereo, listWinter_Package, listflag,FirstName,listlastName, listAddNum,listAddress, listZip);

}
  else
    if (RecieveCom ==1)
{
    PrintVehiclesForD(infile,listID,listModel_Name, listEngine_Cyl,listTransmission, listManufDate,listShipData, listSeat, listWheelSizp, listStereo, listWinter_Package,listflag,listZip);
}

else
    if (RecieveCom == 2)
{    PrintVehiclesForI(infile,listID,listModel_Name, listEngine_Cyl,listTransmission, listManufDate,listShipData, listSeat, listWheelSizp,listStereo, listWinter_Package, listflag,FirstName,listlastName, listAddNum,listAddress);

}
    else
        if (RecieveCom == 3)
    {
        PrintVehiclesWithFourCyl(infile,listID,listModel_Name, listEngine_Cyl,listTransmission, listManufDate,listShipData, listSeat, listWheelSizp,listStereo, listWinter_Package, listflag,FirstName,listlastName, listAddNum,listAddress, listZip);
    }
    else
        if (RecieveCom == 4)
    {
        PrintVehiclesWithPremStereo(infile,listID,listModel_Name, listEngine_Cyl,listTransmission, listManufDate,listShipData, listSeat, listWheelSizp,listStereo, listWinter_Package, listflag,FirstName,listlastName, listAddNum,listAddress, listZip);
    }
    else
    if(RecieveCom == 5)
    {
      PrintVehicleWithLeatherSeats(infile,listID,listModel_Name, listEngine_Cyl,listTransmission, listManufDate,listShipData, listSeat, listWheelSizp,listStereo, listWinter_Package, listflag,FirstName,listlastName, listAddNum,listAddress, listZip);
    }
}
 else
    if(RecieveCom > 5 && RecieveCom <7)
 {

    cout<<"Exiting Program PRESS ENTER" <<endl;

    return 1;
 }



   cout<<"\n\n0 - Print all vehicle\n1 - Print only vehicles manufactured for dealers\n2 - Print only vehicles manufactured for individuals\n3 - Print only vehicles with 4 cylinders engines\n4 - Print only vehicles with premium\n5 - Print only vehicles with leather seats\n6 - Exit:\n"<<endl;

   cin >> RecieveCom;


   }

return 0;
}



///Below are the functions definitions of each prototype mentioned above

void initalizVehicles( ifstream& infile, Vehicles& ID, Vehicles& Model_Name, Vehicles& Engine_Cyl, Vehicles& Transmission, Vehicles& ManufDate, Vehicles& ShipData )
{
    ///Declare all variables
    int total;
    /// Get the first data
    infile >> total;


  ///Display the total value of vehicles
    cout <<"Total Vehicles: "<< total;
    cout <<endl<<endl<<endl;


///get Data from the Vehicles file and save it in the struct of the arrays
       for (int i = 0 ; i < 20; i++)
   {


       infile >> ID.ID[i] >> Model_Name.Model_Name[i] >> Engine_Cyl.Engine_Cyl[i] >> Transmission.Transmission[i] >> ManufDate.ManufDate[i] >> ShipData.ShipData[i];
   }
}
void initizOptions(ifstream& infile, Options& ID, Options& SeatTyp,Options& WheelSize, Options& Stereo, Options& Winter_Package)
{
    ///get Data from the options file and save it in options struct member arrays

    for(int i = 0 ; i < 20 ; i++)
    {

        infile >> ID.ID.ID[i] >> SeatTyp.SeatTyp[i] >> WheelSize.WheelSize[i] >> Stereo.Stereo[i] >> Winter_Package.Winter_Package[i];
    }
}
void sortingOptions(ifstream& infile, Options& ID, Options& SeatTyp,Options& WheelSize, Options& Stereo, Options& Winter_Package)
{


   for (int i = 0 ; i<Maximum -1; i++)
    for ( int j = i + 1; j<Maximum;++j)
     if (ID.ID.ID[i] >ID.ID.ID[j])/// check the numbers priority for lowest to highest the swap the ID values and make the corresponding compontent follow up
   {
       swap(ID.ID.ID[i],ID.ID.ID[j]);
       swap(SeatTyp.SeatTyp[i],SeatTyp.SeatTyp[j]);
       swap(WheelSize.WheelSize[i],WheelSize.WheelSize[j]);
       swap(Stereo.Stereo[i],Stereo.Stereo[j]);
       swap(Winter_Package.Winter_Package[i],Winter_Package.Winter_Package[j]);
   }



}

void initizOwner(ifstream& infile, Owner& ID,Owner& flag,Owner& FirstName,Owner& lastName, Owner& AddNum, Owner& Address,Owner& Zip)
{

     ///get Data from the owner file and save it in owner struct member arrays
    for(int i = 0 ; i < 20 ; i++)
    {

        ///Save the ID and owner type(I or D), then specify where to save the rest Data if I or if D

  infile >> ID.ID.ID[i] >> flag.flag[i];


        if (flag.flag[i] == 'I')
       {




          infile >> FirstName.FirstName[i] >> lastName.lastName[i] >> AddNum.AddNum[i] ;

          getline(infile, Address.Address[i]);///this get both characters an white spaces



       }

       else
        if (flag.flag[i] == 'D')
       {
           infile >> Zip.Zip[i];

       }
    }
}
void sotingowner(ifstream& infile, Owner& ID,Owner& flag,Owner& FirstName,Owner& lastName,Owner& AddNum,Owner& Address,Owner& Zip)
{
    for (int i = 0 ; i<Maximum -1; i++)
    for ( int j = i + 1; j<Maximum;++j)
     if (ID.ID.ID[i] >ID.ID.ID[j]) /// check the numbers priority for lowest to highest the swap the ID values and make the corresponding compontent follow up
   {
       swap(ID.ID.ID[i],ID.ID.ID[j]);
       swap(flag.flag[i],flag.flag[j]);
       swap(FirstName.FirstName[i],FirstName.FirstName[j]);
       swap(lastName.lastName[i],lastName.lastName[j]);
       swap(AddNum.AddNum[i],AddNum.AddNum[j]);
       swap(Address.Address[i],Address.Address[j]);
       swap(Zip.Zip[i],Zip.Zip[j]);
   }

}

void PrintVehicles( ifstream& infile, Vehicles ID, Vehicles Model_Name, Vehicles Engine_Cyl, Vehicles Transmission, Vehicles ManufDate, Vehicles ShipData, Options SeatTyp, Options  Wheel_Size, Options Stero, Options Winter_Package,Owner Flag,Owner First_Name,Owner lastName,Owner AddNum,Owner Address, Owner Zip)
{
    ///Prints out the saved data
     for (int i = 0 ; i < 20; i++)
   {

       cout <<fixed << left<<setw(3)<<ID.ID[i] <<left<< setw(10)<< Model_Name.Model_Name[i]<<left <<setw(3)<< Engine_Cyl.Engine_Cyl[i]<<left<<setw(5)<< Transmission.Transmission[i]<< left<<setw(12)<< ManufDate.ManufDate[i]<< left<<setw(12)<<  ShipData.ShipData[i]<<left<< setw(10)<< SeatTyp.SeatTyp[i]<<left<< setw(5)<< Wheel_Size.WheelSize[i]<<left<<setw(10)<< Stero.Stereo[i]<<left<<setw(5)<< Winter_Package.Winter_Package[i]<<left<<setw(3)<<Flag.flag[i];

///specify what to print when program encounters either an I or D character
      if (Flag.flag[i] == 'I')
      {
          cout <<left<<setw(8)<<First_Name.FirstName[i]<<left<<setw(9)<< lastName.lastName[i]<<left<<setw(5)<<AddNum.AddNum[i]<<" "<< Address.Address[i] <<endl;

      }
      else if(Flag.flag[i]=='D')
      {
          cout<<left<<setw(8)<<Zip.Zip[i]<<endl;
      }

   }


}

void PrintVehiclesForD(ifstream& infile, Vehicles ID, Vehicles Model_Name, Vehicles Engine_Cyl, Vehicles Transmission, Vehicles ManufDate, Vehicles ShipData, Options SeatTyp, Options  Wheel_Size, Options Stero, Options Winter_Package,Owner Flag, Owner Zip)
{


///prints out Only dealers vehicles
      for (int i = 0 ; i < 20; i++)
   {
       if(Flag.flag[i]=='D')
     {
       cout <<fixed << left<<setw(3)<<ID.ID[i] <<left<< setw(10)<< Model_Name.Model_Name[i]<<left <<setw(3)<< Engine_Cyl.Engine_Cyl[i]<<left<<setw(5)<< Transmission.Transmission[i]<< left<<setw(12)<< ManufDate.ManufDate[i]<< left<<setw(12)<<  ShipData.ShipData[i]<<left<< setw(10)<< SeatTyp.SeatTyp[i]<<left<< setw(5)<< Wheel_Size.WheelSize[i]<<left<<setw(10)<< Stero.Stereo[i]<<left<<setw(5)<< Winter_Package.Winter_Package[i]<<left<<setw(3)<<Flag.flag[i];



          cout<<left<<setw(8)<<Zip.Zip[i]<<endl;

   }
     }
}
void PrintVehiclesForI(ifstream& infile, Vehicles ID, Vehicles Model_Name, Vehicles Engine_Cyl, Vehicles Transmission, Vehicles ManufDate, Vehicles ShipData, Options SeatTyp, Options  Wheel_Size, Options Stero, Options Winter_Package,Owner Flag,Owner First_Name,Owner lastName,Owner AddNum, Owner Address)
{
    ///prints out Only individual vehicles
     for (int i = 0 ; i < 20; i++)
     {
     if (Flag.flag[i] == 'I')
      {
        cout <<fixed << left<<setw(3)<<ID.ID[i] <<left<< setw(10)<< Model_Name.Model_Name[i]<<left <<setw(3)<< Engine_Cyl.Engine_Cyl[i]<<left<<setw(5)<< Transmission.Transmission[i]<< left<<setw(12)<< ManufDate.ManufDate[i]<< left<<setw(12)<<  ShipData.ShipData[i]<<left<< setw(10)<< SeatTyp.SeatTyp[i]<<left<< setw(5)<< Wheel_Size.WheelSize[i]<<left<<setw(10)<< Stero.Stereo[i]<<left<<setw(5)<< Winter_Package.Winter_Package[i]<<left<<setw(3)<<Flag.flag[i];


          cout <<left<<setw(8)<<First_Name.FirstName[i]<<left<<setw(10)<< lastName.lastName[i]<<left<<setw(5)<<AddNum.AddNum[i]<<left<<setw(42) << Address.Address[i] <<endl;
      }
     }

}
void PrintVehiclesWithFourCyl(ifstream& infile, Vehicles ID, Vehicles Model_Name, Vehicles Engine_Cyl, Vehicles Transmission, Vehicles ManufDate, Vehicles ShipData, Options SeatTyp, Options  Wheel_Size, Options Stero, Options Winter_Package,Owner Flag,Owner First_Name,Owner lastName,Owner AddNum, Owner Address, Owner Zip)
{
    ///Prints out vehicles only with four cyl engine
     for (int i = 0 ; i < 20; i++)
   {
      if(Engine_Cyl.Engine_Cyl[i] == 4)
        {
       cout <<fixed << left<<setw(3)<<ID.ID[i] <<left<< setw(10)<< Model_Name.Model_Name[i]<<left <<setw(3)<< Engine_Cyl.Engine_Cyl[i]<<left<<setw(5)<< Transmission.Transmission[i]<< left<<setw(12)<< ManufDate.ManufDate[i]<< left<<setw(12)<<  ShipData.ShipData[i]<<left<< setw(10)<< SeatTyp.SeatTyp[i]<<left<< setw(5)<< Wheel_Size.WheelSize[i]<<left<<setw(10)<< Stero.Stereo[i]<<left<<setw(5)<< Winter_Package.Winter_Package[i]<<left<<setw(3)<<Flag.flag[i];

      if (Flag.flag[i] == 'I')
      {
          cout <<left<<setw(8)<<First_Name.FirstName[i]<<left<<setw(10)<< lastName.lastName[i]<<left<<setw(5)<<AddNum.AddNum[i]<<left<<setw(42) << Address.Address[i] <<endl;
      }
      else if(Flag.flag[i]=='D')
      {
          cout<<left<<setw(8)<<Zip.Zip[i]<<endl;
      }
    }
   }

}
void PrintVehiclesWithPremStereo(ifstream& infile, Vehicles ID, Vehicles Model_Name, Vehicles Engine_Cyl, Vehicles Transmission, Vehicles ManufDate, Vehicles ShipData, Options SeatTyp, Options  Wheel_Size, Options Stero, Options Winter_Package,Owner Flag,Owner First_Name,Owner lastName,Owner AddNum, Owner Address, Owner Zip)
{
    ///Print all vehicles with only premium stereo
    for (int i = 0 ; i < 20; i++)
   {
      if(Stero.Stereo[i] == "Premium")
        {
       cout <<fixed << left<<setw(3)<<ID.ID[i] <<left<< setw(10)<< Model_Name.Model_Name[i]<<left <<setw(3)<< Engine_Cyl.Engine_Cyl[i]<<left<<setw(5)<< Transmission.Transmission[i]<< left<<setw(12)<< ManufDate.ManufDate[i]<< left<<setw(12)<<  ShipData.ShipData[i]<<left<< setw(10)<< SeatTyp.SeatTyp[i]<<left<< setw(5)<< Wheel_Size.WheelSize[i]<<left<<setw(10)<< Stero.Stereo[i]<<left<<setw(5)<< Winter_Package.Winter_Package[i]<<left<<setw(3)<<Flag.flag[i];

      if (Flag.flag[i] == 'I')
      {
          cout <<left<<setw(8)<<First_Name.FirstName[i]<<left<<setw(10)<< lastName.lastName[i]<<left<<setw(5)<<AddNum.AddNum[i]<<left<<setw(42) << Address.Address[i] <<endl;
      }
      else if(Flag.flag[i]=='D')
      {
          cout<<left<<setw(8)<<Zip.Zip[i]<<endl;
      }
    }
   }
}
void PrintVehicleWithLeatherSeats(ifstream& infile, Vehicles ID, Vehicles Model_Name, Vehicles Engine_Cyl, Vehicles Transmission, Vehicles ManufDate, Vehicles ShipData, Options SeatTyp, Options  Wheel_Size, Options Stero, Options Winter_Package,Owner Flag,Owner First_Name,Owner lastName,Owner AddNum, Owner Address, Owner Zip)
{
    ///print all vehicles with only leather seats
       for (int i = 0 ; i < 20; i++)
   {
      if(SeatTyp.SeatTyp[i] == "Leather")
        {
       cout <<fixed << left<<setw(3)<<ID.ID[i] <<left<< setw(10)<< Model_Name.Model_Name[i]<<left <<setw(3)<< Engine_Cyl.Engine_Cyl[i]<<left<<setw(5)<< Transmission.Transmission[i]<< left<<setw(12)<< ManufDate.ManufDate[i]<< left<<setw(12)<<  ShipData.ShipData[i]<<left<< setw(10)<< SeatTyp.SeatTyp[i]<<left<< setw(5)<< Wheel_Size.WheelSize[i]<<left<<setw(10)<< Stero.Stereo[i]<<left<<setw(5)<< Winter_Package.Winter_Package[i]<<left<<setw(3)<<Flag.flag[i];

      if (Flag.flag[i] == 'I')
      {
          cout <<left<<setw(8)<<First_Name.FirstName[i]<<left<<setw(10)<< lastName.lastName[i]<<left<<setw(5)<<AddNum.AddNum[i]<<left<<setw(42) << Address.Address[i] <<endl;
      }
      else if(Flag.flag[i]=='D')
      {
          cout<<left<<setw(8)<<Zip.Zip[i]<<endl;
      }
    }
   }
}
