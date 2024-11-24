#include<iostream>
#include<windows.h> //gotoxy
#include<conio.h>  //getch function use krnay k liye
using namespace std;


const int maxrsc=100;
const int maxusers=50;

string aemail[3]={"areeba@gmail.com","uet@gmail.com","eman@gmail.com"};
string apassword[3]={"Areeba@123","Uet@123","Eman@123"};
string uemail[maxusers]={"fatima@gmail.com","maria@gmail.com"};
string upassword[maxusers]={"Fatima@123","Maria@123"};

string resourcename[maxrsc]={"apple macbook","sony headphones","microphone","3D printer","iron","canon camera","VR Headset","webcam","usb drive","drone","speakers","guitar","dvd player","projector","toaster","ps5","ps4","bulb","hammer","saw","drill","scissor","spanner","wrench","tester","mallet","tape measure","nut","nails","shovel","football","volleyball","basketball","cricket bat","cricket ball","paintbrush","paint","watercolor","graphite pencils","ink","easel stand","prismacolor pencil set","sketchbook","ruler","acrylics","oil paints","stapler","yarn","twine","ribbon","washi tape","canvas","yoga mat","dumbells","vernier calliper","potentiometer","lab coats","flask","safety goggles","litmus paper","test tube rack","Compound microscope","Centrifuge machine",};
string resourcetype[maxrsc]={"electronics","electronics","electronics","electronics","electronics","electronics","electronics","electronics","electronics","electronics","electronics","electronics","electronics","electronics","electronics","electronics","electronics","tools","tools","tools","tools","tools","tools","tools","tools","tools","tools","tools","tools","tools","sports equipment","sports equipment","sports equipment","sports equipment","sports equipment","art supplies","art supplies","art supplies","art supplies","art supplies","art supplies","art supplies","art supplies","art supplies","art supplies","art supplies","art supplies","art supplies","art supplies","art supplies","art supplies","art supplies","fitness equipment","fitness equipment","lab equipment","lab equipment","lab equipment","lab equipment","lab equipment","lab equipment","lab equipment"};
bool isavailable[maxrsc];

void printheader();
void gotoxy(int x, int y);
bool userregister(string email, string password,int& usercount,const int maxusers);
bool userlogin(string email,string password,int usercount);
bool adminlogin();
int selectrole();
int adminmenu();
int usermenu();
int addresource(int resourcecount);
int searchresource(int resourcecount);
int updateresource(int resourcecount);
int deleteresource(int resourcecount);
int listresource(int resourcecount);
int borrowresource(int resourcecount);
int returnresource(int resourcecount);
int calculatelength(string str);
int viewusers(string uemail[],int usercount);

int main(){

    int resourcecount=61;
    int usercount=2;
    string name,email,password;
    int updatedidx,delidx,option;

    for(int i = 0; i < maxrsc; i++){
    isavailable[i] = true;
}
    
    printheader();
    variable:
    cout << "Press any Key to Continue. ";
    getch();
    system("cls");
    int role=selectrole();
    cout << "Press enter to continue. ";
    getch();
    system("cls");

    if(role==1){
       if(adminlogin()){
    cout<<endl;
    cout << "      Login successful! Welcome, Admin!"<<endl;
    cout<<endl;
    cout << "      Press enter to continue. "<<endl;
    getch();
    system("cls");

       }
       else{
    cout << "      Login Failed.";
    cout<<endl;
    cout << "      Press enter to continue. ";
    getch();
    system("cls");

       }
    }

    else if(role==2){

        char logorsign;

        bool invalid=true;
        while(invalid){
            gotoxy(40,4);
        cout << "Do you want to login or sign up?(x for login,y for signup)  ";
        cin >> logorsign;
        if(logorsign=='x'||logorsign=='X'||logorsign=='y'||logorsign=='Y'){
             invalid=false;
        }
        else{
            gotoxy(40,6);
            cout << "Invalid choice! Enter again!"<<endl;
        }
    }
        gotoxy(40,6);
        cout << "Press Enter to Continue.      ";
        getch();
        system("cls");

    if(logorsign=='x'||logorsign=='X'){
        if(userlogin(email,password,usercount)){
    gotoxy(35,14);
    cout << "Login Successful!"<<endl;
    gotoxy(35,15);
    cout << "                    ================================================" << endl;
    gotoxy(35,16);
    cout << "                    ==                    WELCOME!                ==" << endl;
    gotoxy(35,17);
    cout << "                    ================================================" << endl;
    }
    else{
    gotoxy(35, 14);
    cout << "Login failed.Invalid email or password."<<endl;
    }
    gotoxy(35,18);
    cout <<  "Press any Key to Continue. ";
    getch();
    system("cls");
}
    else if(logorsign=='y'||logorsign=='Y'){

    if(userregister(email,password,usercount,maxusers)){
    gotoxy(35,23);
    cout << "                         User Registered Successfully!"<<endl;
    cout << "                         Please log in.";
    }
    else{
    gotoxy(35,23);
    cout << "Registration failed. Please try again."<<endl;
    }
    gotoxy(35,25);
    cout << "=============================================================================" << endl;
    gotoxy(35,26);
    cout << "                           Press any Key to Continue. ";
    gotoxy(35,27);
    cout << "=============================================================================" << endl;
    getch();
    system("cls");

    if(userlogin(email,password,usercount)){
    gotoxy(35,14);
    cout << "Login Successful!"<<endl;
    gotoxy(35,16);
    cout << "                    ================================================" << endl;
    gotoxy(35,17);
    cout << "                    ==                   WELCOME !                ==" << endl;
    gotoxy(35,18);
    cout << "                    ================================================" << endl;
    }
    else{
    gotoxy(35, 14);
    cout << "                        Login failed.Invalid email or password."<<endl;
    }
    gotoxy(35,19);
    cout << "                                Press any Key to Continue. ";
    getch();
    system("cls");
    }

}

    if(role==1){
        while(true){
        option=adminmenu();
    
        if(option==1){

             int idx=searchresource(resourcecount);

             if(idx!=-1){
                 cout << " Resource found at index "<< idx <<endl;
                 cout << " Name: "<< resourcename[idx]<<endl;
                 cout << " Type: "<< resourcetype[idx]<<endl;
                 cout << " Availability: ";
                  if(isavailable[idx]==true){
                     cout<< " Available!"<<endl;
                     }
                     else{
                        cout<<" Not available"<<endl;
                     }
                
                }
            else{
                cout << "Resource not found in the system."<<endl;
            }

            cout << "Press enter to continue. ";
            getch();
            system("cls");
        }
           else if(option==2){

                 int updatedidx= updateresource(resourcecount);

                  if(updatedidx != -1){
                    cout << " Resource Information updated! "<<endl;
                    cout << " Name: "<< resourcename[updatedidx]<<endl;
                    cout << " Type: "<< resourcetype[updatedidx]<<endl;
                    cout << " Availability: ";
                  if(isavailable[updatedidx]==true){
                     cout<< " Available!"<<endl;
                     }
                     else{
                        cout<<" Not available"<<endl;
                        }
                  }
                else{
                     cout << "Update failed or resource not found in the system."<<endl;
                  }
            cout << "Press enter to continue. ";
            getch();
            system("cls");   
        }
           else if(option==3){
        
                int oldresourcecount=resourcecount;
                resourcecount=deleteresource(resourcecount);

                  if(resourcecount<oldresourcecount){
                    cout << "Resource has been deleted! updated resource count: "<<resourcecount<<endl;
                  }
                else{
                     cout << "Deletion failed or resource not found in the system."<<endl;
                }

            cout << "Press enter to continue. ";
            getch();
            system("cls");  
             }
              else if(option==4){
                   listresource(resourcecount);
            cout << "Press enter to continue. ";
            getch();
            system("cls"); 
                            }
        else if(option==5){
            viewusers(uemail,usercount);
            cout << "Press enter to continue. ";
            getch();
            system("cls"); 
        }
        else if(option==6){
            goto variable;
             cout << "Press enter to continue. ";
            getch();
            system("cls");
            }
        else if(option==7){
                    cout<<"Exiting Admin menu";
                     break;
             }
           else{
            cout << "Invalid option, try again." << endl;}
        }
 }
    
    else if(role==2){  
        int option;
        while(true){

            option = usermenu();
            
            if(option==1){
            int count=listresource(resourcecount);
            if(count==0){
                cout << "No resources available right now. Come back later."<<endl;
                 } 
            else{
                cout << "Total resources listed: "<<count<<endl;
                }
            cout << "Press enter to continue. ";
            getch();
            system("cls");  
            } 
             if(option==2){
            resourcecount=addresource(resourcecount);
            cout << "Press enter to continue. ";
            getch();
            system("cls");
        }
            else if(option==3){
             int bridx = borrowresource(resourcecount);
             
             if(bridx<0||bridx>=resourcecount){
                cout<<"Invalid resource number."<<endl;
                } 
                
            else if(!isavailable[bridx]){
                cout<< "Sorry, this resource is already borrowed."<<endl;
                }

            else{
                isavailable[bridx]=false;
                cout<<"You have successfully borrowed the resource: "<<resourcename[bridx]<<endl;
                  }
            cout << "Press enter to continue. ";
            getch();
            system("cls");  
            } 
            else if(option==4){
                int rtnidx = returnresource(resourcecount);
                
                if(rtnidx==-1){
                    cout << "Either the resource doesn't exist or it's already available."<<endl;
                     } 

                else{
               isavailable[rtnidx] =true;

               cout << "Resource '"<<resourcename[rtnidx] << "' has been successfully returned!"<<endl;
               cout << "Thanks for using our app! Come back for more!"<<endl;
                }

            cout << "Press enter to continue. ";
            getch();
            system("cls");  
            }

            else if(option==5){
                cout << "Exiting User Menu."<<endl;
                break;
            } 
             else if(option==6){
                goto variable;
            cout << "Press enter to continue. ";
            getch();
            system("cls");
            }
            else{
                cout << "Invalid option, try again."<<endl;
            }
        }
    } 

    else{
        cout << "Invalid role selected. Exiting program." << endl;
    }


   return 0;
}


bool userregister(string email, string password,int& usercount,const int maxusers){  

    bool isvalidemail=false,isvalidpass=false;

     if(usercount>=maxusers) {
        cout << "User limit reached! Cannot register more users."<<endl;
        return 0;
    }


        gotoxy(35, 5);
        cout << "=============================================================================" << endl;
        
        gotoxy(35, 6);
        cout << "==                   R    E    G    I    S    T    E    R                  ==" << endl;
        
        gotoxy(35, 7);
        cout << "==                             N    O    W    !                            ==" << endl;
 
        gotoxy(35, 8);
        cout << "=============================================================================" << endl;
    
    
    while(!isvalidemail){
        
    gotoxy(35, 10);
    cout << "Enter your email(must contain @)[Enter 'q' to exit]: ";
    getline(cin,email);

    if(email=="q"||email=="Q"){
    gotoxy(35, 12);
    cout << "Exiting registration.Goodbye!"<<endl;
    exit(0);
    }

    bool isemptyemail=true;
    for(int i=0; email[i] != '\0'; i++){
    if(email[i]!=' '){
        isemptyemail=false;
        break;
    }
}
    if(isemptyemail){
            gotoxy(35, 12);
            cout << "Email cannot be empty." << endl;
            continue;
        }

    bool hasat=false;
    int idx=-1;
    int countofat=0;

    for(int em=0;email[em]!='\0';em++){
        if(email[em]=='@'){
            hasat=true;
            idx=em;
            countofat++;
        }
    }
    if(!hasat||countofat>1||idx==0||email[idx+1]=='\0'){
        gotoxy(35,12);
        cout<<"Invalid email format.Missing or misplaced '@' or multiple '@' "<<endl;
        gotoxy(35,10);
        cout << "                                                                                           ";
       continue;
     }

    bool isemmatch = false;
    for(int x=0;x<usercount;x++){
        if(aemail[x]==email){
         isemmatch = true;
         break;
        }
    }
   
    if(isemmatch){
        gotoxy(35,12);
        cout<<"Email already registered.                                          ";
        gotoxy(35,10);
        cout << "                                                                                                      ";
        continue;
    }

    isvalidemail=true;
    gotoxy(35, 12);
    cout << "                                                                                                 ";
}

    while(!isvalidpass){
     gotoxy(35, 17);
     cout <<  "Create a secure password (Password must contain at"<<endl;
     gotoxy(35, 18);
     cout <<  "least one uppercase letter, one lowercase letter,"<<endl;
     gotoxy(35, 19);
     cout <<  "one digit,one special character and must "<<endl;
     gotoxy(35, 20);
     cout <<  "be 6 characters long):  [Enter 'q' to exit]";
     getline(cin, password);

    if(password=="q"||password=="Q"){
    gotoxy(35, 22);
    cout << "Exiting login.Goodbye!"<<endl;
    exit(0);
    }

    bool isemptypass=true;
    for(int i=0;password[i]!='\0';i++){
     if(password[i]!=' '){
        isemptypass=false;
        break;
    }
}
    if(isemptypass){
            gotoxy(35, 22);
            cout << "Error: Password cannot be empty." << endl;
            gotoxy(35, 20);
            cout << "                                                                                         ";
            continue; 
        }

    int passlength=0;
    bool hasupper=false, haslower=false, hasdigit=false, hasspecial=false;

    while(password[passlength]!= '\0'){
        if(password[passlength] >= 'A' && password[passlength] <= 'Z'){
            hasupper = true;}
        if(password[passlength] >= 'a' && password[passlength] <= 'z'){
            haslower = true;}
        if(password[passlength] >= '0' && password[passlength] <= '9'){
            hasdigit = true;}
        if((password[passlength] == '!' || password[passlength] == '@' || password[passlength] == '#' || password[passlength] == '$' ||
             password[passlength] == '%' || password[passlength] == '^' || password[passlength] == '&' || password[passlength] == '*' ||
             password[passlength] == '(' || password[passlength] == ')' || password[passlength] == '-' || password[passlength] == '_')){
            hasspecial = true;
        }
        passlength++;
    }

    if(passlength<6){
        gotoxy(35,22);
        cout << "Password must be atleast 6 characters long.Please try again."<<endl;
        gotoxy(35,20);
        cout << "                                                                                               ";
        continue;
    }

    if(!hasupper||!haslower||!hasdigit ||!hasspecial){
        gotoxy(35,22);
        cout << "Password requirements not met.Please enter a valid password." << endl;
        gotoxy(35,20);
        cout << "                                                                                                        ";
        continue;
    }
    
    isvalidpass=true;
    gotoxy(35, 22);
    cout << "                                                                                               ";
      
}

    uemail[usercount] = email;
    upassword[usercount] = password;
    usercount++;

    return true;
}
bool userlogin(string email,string password,int usercount){

    bool isvalidemail=false,isvalidpass=false;
    string logemail,logpassword;

    while(!isvalidemail){

     gotoxy(35, 5);
        cout << "=============================================================================" << endl;
        
    gotoxy(35, 6);
        cout << "==                       L      O      G      I      N                     ==" << endl;
        
    gotoxy(35, 7);
        cout << "==                           N      O      W      !                        ==" << endl;
 
    gotoxy(35, 8);
        cout << "=============================================================================" << endl;

    gotoxy(35, 10);
    cout << "Enter your email(must contain @)[Enter 'q' to exit]: ";
    getline(cin,logemail);

    if(logemail=="q"||logemail=="Q"){
    gotoxy(35, 12);
    cout << "Exiting login.Goodbye!"<<endl;
    exit(0);
    }

    bool isemptyemail=true;
    for(int i=0; logemail[i] != '\0'; i++){
    if(logemail[i]!=' '){
        isemptyemail=false;
        break;
    }
}
    if(isemptyemail){
            gotoxy(35, 12);
            cout << "Error: Email cannot be empty." << endl;
            continue;
        }

    bool hasat=false;
    int idx=-1;
    int countofat=0;

    for(int em=0;logemail[em]!='\0';em++){
        if(logemail[em]=='@'){
            hasat=true;
            idx=em;
            countofat++;
        }
    }
    if(!hasat||countofat>1||idx==0||logemail[idx+1]=='\0'){
        gotoxy(35,12);
        cout<<"Invalid email format.Missing or misplaced '@' or multiple '@' "<<endl;
        gotoxy(35,10);
        cout << "                                                                                 ";
        continue;
     }

    bool isemmatch = false;
    for(int x=0;x<usercount;x++){
        if(uemail[x]==logemail){
         isemmatch = true;
         break;
        }
    }

    if(!isemmatch){
        gotoxy(35,12);
        cout << "Email not registered.Please enter valid email or sign up first!"<<endl;
         gotoxy(35,10);
        cout << "                                                                                                      ";
        continue;
    }

    isvalidemail=true;
    gotoxy(35,12);
    cout << "                                                                                                           ";
}

    while(!isvalidpass){

    gotoxy(35, 13);
    cout<<"Enter your password: [Enter 'q' to exit] ";
    getline(cin,logpassword);

    if(logpassword=="q"||logpassword=="Q"){
    gotoxy(35, 14);
    cout << "Exiting login.Goodbye!"<<endl;
    exit(0);
    }

    bool isemptypass=true;
    for(int i=0;logpassword[i]!='\0';i++){
     if(logpassword[i]!=' '){
        isemptypass=false;
        break;
    }
}
    if(isemptypass){
            gotoxy(35, 14);
            cout << "Error: Password cannot be empty." << endl;
            gotoxy(35, 13);
            cout << "                                                                                         ";
            continue; 
        }

     bool ispassmatch = false;
        for(int i=0;i<usercount;i++){
            if((uemail[i]==logemail)&&(upassword[i]==logpassword)){
               ispassmatch = true;
               break;
            }
        }

     if(!ispassmatch){
        gotoxy(35,14);
        cout<<"Incorrect password. Please try again."<<endl;
        gotoxy(35,13);
        cout << "                                                      ";
        continue;
    }
    isvalidpass = true;
    gotoxy(35, 14);
    cout << "                                                                                   ";
    }
 return true;
}
bool adminlogin(){
    
    string logemail,logpassword;
    bool isvalidemail=false,isvalidpass=false;
    while(!isvalidemail)
    {

     gotoxy(35, 5);
        cout << "=============================================================================" << endl;
        
    gotoxy(35, 6);
        cout << "==                       L      O      G      I      N                     ==" << endl;
        
    gotoxy(35, 7);
        cout << "==                           N      O      W      !                        ==" << endl;
 
    gotoxy(35, 8);
        cout << "=============================================================================" << endl;



    gotoxy(35, 10);
    cout << "Enter your email(must contain @)[Enter 'q' to exit]: ";
    getline(cin,logemail);

    if(logemail=="q"||logemail=="Q"){
    gotoxy(35, 12);
    cout << "Exiting login.Goodbye!"<<endl;
    exit(0);
    }

    bool isemptyemail=true;
    for(int i=0; logemail[i] != '\0'; i++){
    if(logemail[i]!=' '){
        isemptyemail=false;
        break;
    }
}
    if(isemptyemail){
            gotoxy(35, 12);
            cout << "Error: Email cannot be empty." << endl;
            continue;
        }

    bool hasat=false;
    int idx=-1;
    int countofat=0;

    for(int em=0;logemail[em]!='\0';em++){
        if(logemail[em]=='@'){
            hasat=true;
            idx=em;
            countofat++;
        }
    }
    if(!hasat||countofat>1||idx==0||logemail[idx+1]=='\0'){
        gotoxy(35,12);
        cout<<"Invalid email format.Missing or misplaced '@' or multiple '@' "<<endl;
        gotoxy(35,10);
        cout << "                                                                                           ";
       continue;
     }

    bool isemmatch = false;
    for(int x=0;x<3;x++){
        if(aemail[x]==logemail){
         isemmatch = true;
         break;
        }
    }
   
    if(!isemmatch){
        gotoxy(35,12);
        cout<<"Incorrect email. Please try again.";
        gotoxy(35,10);
        cout << "                                                                                                      ";
        continue;
    }

    isvalidemail=true;
    gotoxy(35, 12);
    cout << "                                                                                                 ";
}

    while(!isvalidpass){

    gotoxy(35, 13);
    cout<<"Enter your password: [Enter 'q' to exit] ";
    getline(cin,logpassword);

    if(logpassword=="q"||logpassword=="Q"){
    gotoxy(35, 14);
    cout << "Exiting login.Goodbye!"<<endl;
    exit(0);
    }

    
    bool isemptypass=true;
    for(int i=0;logpassword[i]!='\0';i++){
     if(logpassword[i]!=' '){
        isemptypass=false;
        break;
    }
}
    if(isemptypass){
            gotoxy(35, 14);
            cout << "Error: Password cannot be empty." << endl;
            gotoxy(35, 13);
            cout << "                                                                                         ";
            continue; 
        }


    bool ispassmatch = false;
        for(int i=0;i<3; i++){
            if((aemail[i]==logemail)&&(apassword[i]==logpassword)){
               ispassmatch = true;
               break;
            }
        }
    if(!ispassmatch){
        gotoxy(35,14);
        cout<<"Incorrect password. Please try again."<<endl;
        gotoxy(35,13);
        cout << "                                                                                                  ";
        continue;
    }
    isvalidpass=true;
    gotoxy(35, 14);
    cout << "                                                                                                          ";
}
 return true;

}
int selectrole(){
        gotoxy(35, 5);
        cout << "=============================================================================" << endl;
        
        gotoxy(35, 6);
        cout << "==                       R       O       L       E                         ==" << endl;
         
        gotoxy(35, 7);
        cout << "==               S    E    L    E    C    T    I    O    N                 ==" << endl;
 
        gotoxy(35, 8);
        cout << "=============================================================================" << endl;

    int role;
    gotoxy(35, 10);
    cout << "                         Select your role!" <<endl;
    gotoxy(35, 11);
    cout << "                         1. Admin" <<endl;
    gotoxy(35, 12);
    cout << "                         2. User"  <<endl;
    gotoxy(35, 13);
    cout << "                         Enter choice(1 or 2): ";
    gotoxy(35, 14);
    cin  >> role;
    while(role<1||role>2){
        cout<<"                       Invalid role.Enter again.";
        cin >> role;
    }
    return role;
    }

int adminmenu(){
    int option;
        
        gotoxy(35, 5);
        cout << "               ===========================================================" << endl;
        gotoxy(35, 6);
        cout << "               ==  A  D  M  I  N     M  E  N  U     O  P  T  I  O  N  S ==" << endl;
        gotoxy(35, 7);
        cout << "               ===========================================================" << endl;
        gotoxy(35, 8);
        cout << "Admin Menu:"<<endl;
        gotoxy(35, 10);
        cout << "1. Search Resource."<<endl;
        gotoxy(35, 11);
        cout << "2. Update Resource."<<endl;
        gotoxy(35, 12);
        cout << "3. Delete Resource."<<endl;
        gotoxy(35, 13);
        cout << "4. List Resource."<<endl;
        gotoxy(35, 14);
        cout << "5. View users."<<endl;
        gotoxy(35, 15);
        cout << "6. Go back to Role selection."<<endl;
        gotoxy(35, 16);
        cout << "7. Exit."<<endl;
        gotoxy(35, 17);
        cout << "Choose option:";
        cin >> option;
        
    
    return option; 
      
    
}

int usermenu() {
    int option;

        gotoxy(35, 5);
        cout << "               ===========================================================" << endl;
        gotoxy(35, 6);
        cout << "               ==   U  S  E  R     M  E  N  U     O  P  T  I  O  N  S   ==" << endl;
        gotoxy(35, 7);
        cout << "               ===========================================================" << endl;
        gotoxy(35, 8);
        cout << "User Menu:"<<endl;
        gotoxy(35, 9);
        cout << "1. List Resource."<<endl;
        gotoxy(35, 10);
        cout << "2. Add Resource."<<endl;
        gotoxy(35, 11);
        cout << "3. Borrow Resource."<<endl;
        gotoxy(35, 12);
        cout << "4. Return Resource."<<endl;
        gotoxy(35, 13);
        cout << "5. Exit."<<endl;
        gotoxy(35, 14);
        cout << "6. Go back to Role selection."<<endl;
        gotoxy(35, 15);
        cout << "Choose option:"<<endl;
        cin >> option;
        
        return option;
}
int addresource(int resourcecount){

    string newname,newtype;

     if(resourcecount>=maxrsc){
    cout<< "Resource capacity reached. Cannot add more resources."<<endl;
        return resourcecount;
     }

     cin.ignore(); //pichlay cin say leftover \n (newline) ko ignore krta

     cout<< " Enter the name of the resource: "<<endl;
     getline(cin,newname);
    
     cout<< " Enter the type of the resource(i-e; electronics,art supplies,tools etc): "<<endl;
     getline(cin,newtype);

     
      for(int i=0; i<resourcecount; i++){
        if((resourcename[i]==newname)&&(resourcetype[i]==newtype)){
            cout << "Resource already exists in the system." << endl;
            return resourcecount; 
        }
    }
     resourcename[resourcecount] = newname;
     resourcetype[resourcecount] = newtype;
     isavailable[resourcecount]=true;

     resourcecount++;

    cout << "Resource added successfully!" << endl;

     return resourcecount;
}

int searchresource(int resourcecount){

    string searchname;

    cin.ignore();

    cout << " Enter the name of the resource to search for: ";
    getline(cin,searchname);
    
    for(int i=0;i<resourcecount;i++){
         if(searchname==resourcename[i]){
             return i;
        }
    }
  return -1;  
}

int updateresource(int resourcecount){
  
    string updatersc;
      cin.ignore();

    cout << "Enter the name of the resource you want to update: ";
    getline(cin,updatersc);

    for(int i=0;i<resourcecount;i++){
        if(updatersc==resourcename[i]){
            cout<<"Resource "<<updatersc<<" found!"<<endl;

            int updateoption;

            while(true){
            cout<< "What would you like to update?" <<endl;
            cout<< "1. Update Resource Name" <<endl;
            cout<< "2. Update Resource Type" <<endl;
            cout<< "3. Update Availability" <<endl;
            cout<< "4. Exit update menu"    <<endl;
            cout<< "Enter your choice (1-4): ";
            cin >> updateoption;
        
            if(updateoption==1){
                cin.ignore();
                cout<<"Enter the new name for the resource:";
                getline(cin,resourcename[i]);
                cout<<"Resource name updated to '"<<resourcename[i]<<"'."<<endl;
                }

            else if(updateoption==2){
                cin.ignore();
                cout<<"Enter the new type for the resource:";
                getline(cin,resourcetype[i]);
                cout<<"Resource type updated to '"<<resourcetype[i]<<"'."<<endl;
            }
            
            else if(updateoption==3){
            cout<< "Current Availability: ";

            if(isavailable[i]==true){
                cout<< " Available!"<<endl;
            }
            else{
                cout<<" Not available"<<endl;
            }
            char avoption;
            cout<<"Do you want to update availability option?(Y for available,N for not available)";
            cin >> avoption;

            if(avoption=='y'||avoption=='Y'){
                isavailable[i]=true;
                cout<<"Resource updated to available."<<endl;
                }
            else if(avoption=='n'||avoption=='N'){
                isavailable[i]=false;
                cout<<"Resource updated to not available."<<endl;
                }

            else{
                cout<<"Invalid input.Update canceled."<<endl;
            }
        }
            else if(updateoption==4){
                cout << "Exiting update menu."<<endl;
                break; 
             } 
            else{
                cout<<"Invalid Option!"<<endl;
            }
         }    
        return i;
    }
}
    cout << "Resource not found in the system." << endl;
    return -1;

}

int deleteresource(int resourcecount){

    bool found=false;
    string delrsc;

      cin.ignore();

    cout << "Enter the name of the resource to delete: ";
    getline(cin,delrsc);

    for(int i=0;i<resourcecount;i++){
        if(delrsc==resourcename[i]){
            found=true;
            for(int j=i;j<resourcecount-1;j++){
                resourcename[j]=resourcename[j+1];
                resourcetype[j]=resourcetype[j+1];
                isavailable[j]=isavailable[j+1];
            }
            resourcecount--;
            cout << "Resource " << delrsc << " deleted successfully."<<endl;
            return resourcecount;
        }
   }
   if(!found){
    cout << "Resource not found." << endl;
    }
return resourcecount;  
}
int calculatelength(string str){
    int length = 0;
    while (str[length] != '\0'){
        length++;
    }
    return length;
}
int listresource(int resourcecount){

   if(resourcecount>0){
    cout << "Listing all resources "<<endl;

cout<<"Sr No.  Resource name          Resource type            Availability"<<endl; 

        int maxname = 0;
        int maxtype = 0;

        for(int i=0;i<resourcecount; i++){
            int namelength = calculatelength(resourcename[i]);
            int typelength = calculatelength(resourcetype[i]);
            if(namelength > maxname){
                maxname = namelength;
            }
            if(typelength > maxtype){
                maxtype = typelength;
            }
        }

        for(int i = 0; i < resourcecount; i++){
         
            cout << (i + 1);
            cout << "\t";
            cout << resourcename[i];
            int namelength = calculatelength(resourcename[i]);
            for(int j=namelength; j<maxname;j++) {
                cout << " "; 
            }
            cout << "\t";
            cout << resourcetype[i];
            int typelength = calculatelength(resourcetype[i]);
            for(int j = typelength; j<maxtype; j++){
                cout << " ";
            }
            
   cout << "\t";
        
         if(isavailable[i]){
        cout << "Available" << endl;
            }
     else{
        cout << "Not Available" << endl;
        }
    }
}
else{
    cout << "No resources available." << endl;
    }

return resourcecount; 
}
int borrowresource(int resourcecount){
     
    int choice;
    bool rscav=false;

   cout<<"Sr No.  Resource name          Resource type            Availability"<<endl; 

        int maxname = 0;
        int maxtype = 0;

        for(int i=0;i<resourcecount; i++){
            int namelength = calculatelength(resourcename[i]);
            int typelength = calculatelength(resourcetype[i]);
            if(namelength > maxname){
                maxname = namelength;
            }
            if(typelength > maxtype){
                maxtype = typelength;
            }
        }

        for(int i = 0; i < resourcecount; i++){
         
            cout << (i + 1);
            cout << "\t";
            cout << resourcename[i];
            int namelength = calculatelength(resourcename[i]);
            for(int j=namelength; j<maxname;j++) {
                cout << " "; 
            }
            cout << "\t";
            cout << resourcetype[i];
            int typelength = calculatelength(resourcetype[i]);
            for(int j = typelength; j<maxtype; j++){
                cout << " ";
            }
         cout << "\tAvailable" << endl;
         rscav=true;
        }
    

if(!rscav){
    cout <<"No available resources at the moment. Please check back later."<<endl;
    return -1; 
    }

    cout<<"Enter the number of resource you want to borrow:";
    cin>>choice;

    return choice-1;
}

int returnresource(int resourcecount){

    string returnrsc;

    cin.ignore();

    cout << "Enter the name of the resource you want to return."<<endl;
    getline(cin,returnrsc);

    for(int i=0;i<resourcecount;i++){
        if(resourcename[i]==returnrsc&& !isavailable[i]){
           return i;
        }
    }
   return -1;
}

int viewusers(string uemail[],int usercount){
    if(usercount==0){
        cout << "No users registered yet."<<endl;
        return 0;
    }

cout<<"                           List of registered user emails."<<endl;
cout<<"                       ---------------------------------------"<<endl;
cout<<"                          Sr No.           User Email         "<<endl;
cout<<"                       ---------------------------------------"<<endl;
for(int i=0;i<usercount;i++){
cout<<"                       "<<(i+1)<<"\t\t"<<uemail[i]<<"\t\t"<<endl;
cout<<"                       ---------------------------------------"<<endl;
}
return usercount;
}
void printheader()
{   
    system("Color B0"); 
    cout<<endl;
    cout<<endl;
    cout << "                                              ======================================================================================" << endl;
    cout << "                                                                                                                                    " << endl;
    cout << "                                                                #######   ##      ##   #######   ########   ########                " << endl;
    cout << "                                                               ##     ##  ##      ##  ##     ##  ##     ##  ##                      " << endl;
    cout << "                                                               ##         ##      ##  ##     ##  ##     ##  ##                      " << endl;
    cout << "                                                               #########  ##########  #########  ########   ########                " << endl;
    cout << "                                                                      ##  ##      ##  ##     ##  ##     ##  ##                      " << endl;
    cout << "                                                               ##     ##  ##      ##  ##     ##  ##     ##  ##                      " << endl;
    cout << "                                                                #######   ##      ##  ##     ##  ##     ##  ########                " << endl;
    cout << "                                                                                                                                    " << endl;
    cout << "                                                          #######    ########   ##      ##  ########  ########   ########           " << endl;
    cout << "                                                         ##     ##   ##     ##  ##      ##  ##        ##     ##  ##                 " << endl;
    cout << "                                                         ##          ##     ##  ##      ##  ##        ##     ##  ##                 " << endl;
    cout << "                                                         #########   ########   ##########  ########  ########   ########           " << endl;
    cout << "                                                                ##   ##         ##      ##  ##        ##     ##  ##                 " << endl;
    cout << "                                                         ##     ##   ##         ##      ##  ##        ##     ##  ##                 " << endl;
    cout << "                                                          #######    ##         ##      ##  ########  ##     ##  ########           " << endl;
    cout << "                                                                                                                                    " << endl;
    cout << "                                              ======================================================================================" << endl;
    cout << endl;
    cout << "                                                                                        WELCOME!                                    " << endl;
    cout << endl;
    cout << "                                                                      Your Trusted Business Application for Sharing                 " << endl;
    cout << "                                                                                 Resources Seamlessly.                              " << endl;
    cout << endl;
    cout << "                                              ======================================================================================" << endl;

}

void gotoxy(int x, int y)
{
COORD coordinates;
coordinates.X = x;
coordinates.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
