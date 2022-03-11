#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
struct admin{
	int id;
	int noleave;
	char todate[20];
	char fromdate[20];
	char ename[20];
	char design[20];
	char reason[50];
	char leavetype[20];
}ad;
struct emply{
	int id;
	int pass;
	char name[20];
	char fname[20];
	int age;
	char per[30];
	char gender[10];
	char dob[20];
	char occu[30];
	char bank[30];
	int accn;
	int phn1,phn2;
	int cnic1,cnic2,cnic3;
	char acctype[20];
	char address[50];
	char email[30];
	int leaves;
	int checkin;
	int checkout;
	int hours;
	char lapprov[40];
}emp;
void mainlayout();
void emplayout();
void attend();
void checkin(int ciid);
void checkout(int coid);
void login();
void ilogin();
void clogin(int cid);
void empl(int eid);
void empdetail(int emid);
void payslip(int pid);
void paygen(int pyid,int pr,int hrs);
void leave(int lid);
void ldetails();
void adminlayout();
void eentry();
void esearch();
void aempdetail(int aeid);
void update(int uid);
void ereport();
void dailyemps();
void contemp();
void peremp();
void deleterec();
int avlp(int p);
int avlid(int avid);
void main()
{
	fflush(stdin);
	mainlayout();
	getch();
}
void mainlayout()
{
	int choice,p;
	system("cls");
	printf("*******************WELCOME TO EMPLOYEE MANAGEMENT SYSTEM********************");
	printf("\n\n\n\nPLEASE SELECT USER TYPE FROM THE FOLLOWING OPTIONS");
	printf("\n\n1 : EMPLOYEE");
	printf("\n\n2 : ADMINISTRATOR");
	printf("\n\n3 : QUIT");
	printf("\n\n\n\n\n\n\n\nPLEASE INPUT YOUR CHOICE: ");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice){
		case 1:
		    emplayout();
		    break; 
		case 2:
			system("cls");
			printf("\n\n\n\n\t\tPLEASE ENTER PASSWORD: ");
			scanf("%d",&p);
			if(p==12345){
				adminlayout();
			}else{
				printf("\n\n\t\tINCORRECT PASSWORD");
				getch();
				mainlayout();
			}
			break;
		case 3:
		    printf("\n\n\n................THANK YOU FOR USING JBHT EMPLOYEE SYSTEM....................");
			exit(1);
			break;		
	}
}
void emplayout()
{
	int emchoice;
	system("cls");
	printf("\n\n\n1 : ATTENDENCE");
	printf("\n\n2 : LOGIN");
	printf("\n\n3 : BACK");
	printf("\n\n\n\n\nPLEASE CHOOSE DESIRED OPTION: ");
	scanf("%d",&emchoice);
	fflush(stdin);
	switch(emchoice){
	    case 1: 
		    attend();
	        break;
   	    case 2:
		    login();
	        break;
	    case 3:
		    mainlayout();
	        break;    
    }
}
void login()
{
	int nom,pas,avlps,avli;
    system("cls");
    fflush(stdin);
	printf("\nPLEASE ENTER ID: ");
	scanf("%d",&nom);
	printf("\nPLEASE ENTER PASSWORD: ");
	scanf("%d",&pas);
	avlps=avlp(pas);
	avli=avlid(nom);
	if(avlps==0 || avli==0){
	    ilogin();
	}else{
	    clogin(nom);
    }
}
void ilogin()
{
	int ichoice;
	system("cls");
	printf("\n\nINCORRECT ID OR PASSWORD PLEASE CONTACT ADMINISTRATION STAFF FOR ANY QUERY");
	printf("\n\n\n1 : BACK");
	printf("\n\n2 : MAIN MENU");
	printf("\n\n\n\n\nPLEASE CHOOSE DESIRED OPTION: ");
	scanf("%d",&ichoice);
	fflush(stdin);
	switch(ichoice){
	    case 1: 
		    login();
	        break;
   	    case 2:
		    mainlayout();
	        break;
    }
}
void clogin(int cid)
{
	int cchoice;
	system("cls");
	printf("\n\n\n************WELCOME TO YOUR ACCOUNT*************");
	printf("\n\n\n1 : VIEW DETAILS");
	printf("\n\n2 : VIEW PAYSLIP");
	printf("\n\n3 : LEAVE SANCTION");
	printf("\n\n4 : LOGOUT");
	printf("\n\n\n\n\nPLEASE CHOOSE DESIRED OPTION: ");
	scanf("%d",&cchoice);
	fflush(stdin);
	switch(cchoice){
	    case 1: 
		    empdetail(cid);
	        break;
   	    case 2:
   	        payslip(cid);
	        break;
	    case 3: 
		    leave(cid);
	        break;
   	    case 4:
		    mainlayout();
	        break;    
    }
}
void adminlayout()
{
	int achoice;
	system("cls");
	printf("\n\n\n************WELCOME TO ADMINISTRATION PORTAL*************");
	printf("\n\n\n1 : ENTER NEW EMPLOYEE");
	printf("\n\n2 : SEARCH FOR EMPLOYEE");
	printf("\n\n3 : EMPLOYEE REPORT");
	printf("\n\n4 : DELETE RECORD");
	printf("\n\n5 : LEAVE REQUESTS");
	printf("\n\n6 : BACK");
	printf("\n\n\n\n\nPLEASE CHOOSE DESIRED OPTION: ");
	scanf("%d",&achoice);
	fflush(stdin);
	switch(achoice){
	    case 1: 
		    eentry();
	        break;
   	    case 2:
   	    	esearch();
	        break;
	    case 3: 
		    ereport();
	        break;
	    case 4:
		    deleterec();
	        break;
		case 5:
		    ldetails();
	        break;	      
   	    case 6:
		    mainlayout();
	        break;    
    }
}
void esearch()
{
	int n,echoice;
	system("cls");
	printf("ENTER EMPLOYEE ID : ");
	scanf("%d",&n);
	if(avlid(n)==1){
		empl(n);
	}else{
		system("cls");
		printf("\n\n\n\nTHE FOLLOWING EMPLOYEE IS NOT PRESENT IN THE DATA BASE.");
		printf("\n\n\n\n\t\t\t\t1 : BACK");
		scanf("%d",&echoice);
		if(echoice==1){
		    adminlayout();
		}
	}
}
void eentry()
{
	int cchoice,etype,dep;
	system("cls");
	FILE*fp;
	fp=fopen("record.txt","a");
	printf("\n\t\tPLEASE ENTER REQUIRED DATA FOR EMPLOYEE ACCOUNT");
    printf("\nENTER EMPLOYEE ID: ");
    scanf("%d",&emp.id);
    fflush(stdin);
	printf("\nENTER NAME: ");
	gets(emp.name);
	printf("\nENTER FATHER NAME: ");
	gets(emp.fname);
	do{
	    printf("\nENTER AGE: ");
        scanf("%d",&emp.age);
        if(emp.age<1){
	        printf("\nPLEASE ENTER VALID AGE");
		}
	}while(emp.age<1);
    printf("\nCHOOSE EMPLOYEE DEPARTMENT: ");
	printf("\n\n\t1 : ACCOUNTANT ");
	printf("\n\n\t2 : MANAGER");
   	printf("\n\n\t3 : ENGINEER");
	printf("\n\nCHOICE : ");
	scanf("%d",&dep);
	switch(dep){
		case 1:
			strcpy(emp.occu,"accountant");
			break;
		case 2:
			strcpy(emp.occu,"manager");
			break;
		case 3:
		    strcpy(emp.occu,"engineer");
			break;	
    }
    fflush(stdin);
	printf("\nENTER GENDER : ");
	gets(emp.gender);
	printf("\nENTER EMPLOYEE DATE OF BIRTH (dd-mm-yyyy): ");
	gets(emp.dob);
	printf("\nENTER EMPLOYEE ADDRESS: ");
	gets(emp.address);
	printf("\nENTER EMAIL ADDRESS: ");
	gets(emp.email);
	printf("\nENTER PROFESSSIONAL QUALIFICATION: ");
	gets(emp.per);
	printf("\nENTER BANK ADDRESS: ");
	gets(emp.bank);
	printf("\nENTER ACCOUNT NUMBER: ");
	scanf("%d",&emp.accn);
	printf("\n\nENTER PHONE NUMBER xxxx-xxxxxxx: ");
    scanf("%d-%d",&emp.phn1,&emp.phn2);
	printf("\n\nENTER CNIC NUMBER xxxxx-xxxxxxx-x: ");
	scanf("%d-%d-%d",&emp.cnic1,&emp.cnic2,&emp.cnic3);
	fflush(stdin);
	printf("\nCHOOSE EMPLOYEE TYPE: ");
	printf("\n\n\t1 : DAILY BASIS ");
	printf("\n\n\t2 : PERMENANT");
   	printf("\n\n\t3 : CONTRACT");
   	printf("\n\nCHOICE : ");
	scanf("%d",&etype);
	switch(etype){
		case 1:
			strcpy(emp.acctype,"daily basis");
			break;
		case 2:
			strcpy(emp.acctype,"permenant");
			break;
		case 3:
		    strcpy(emp.acctype,"contract");
			break;	
    }
    system("cls");
	printf("\n\n\n\n\t\tPLEASE INPUT PASSWORD TO SECURE YOUR ACCOUNT: ");
	scanf("%d",&emp.pass);
	system("cls");
	printf("\n\nTHE EMPLOYEE %d ACCOUNT HAS BEEN CREATED THANK YOU FOR YOUR COOPERATION",emp.id);
	fwrite(&emp,sizeof(struct emply),1,fp);
    fclose(fp);
    printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&cchoice);
    fflush(stdin);
    if(cchoice==1){
    	empl(emp.id);
	}
}
void empl(int eid)
{
	int achoice;
	system("cls");
	printf("\n\n\n************EMPLOYEE %d *************",eid);
	printf("\n\n\n1 : VIEW DETAILS");
	printf("\n\n2 : UPDATE PROFILE");
	printf("\n\n3 : LOGOUT");
	printf("\n\n\n\n\nPLEASE CHOOSE DESIRED OPTION: ");
	scanf("%d",&achoice);
	fflush(stdin);
	switch(achoice){
	    case 1: 
		    aempdetail(eid);
	        break;
	    case 2: 
		    update(eid);
	        break;
   	    case 3:
		    adminlayout();
	        break;  
    }
}
int avlid(int avid)
{
	FILE*fp;
	fp=fopen("record.txt","r");
	while(!feof(fp)){
		fread(&emp,sizeof(struct emply),1,fp);
		if(avid==emp.id){
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}
int avlp(int p)
{
	FILE*fp;
	fp=fopen("record.txt","r");
	while(!feof(fp)){
		fread(&emp,sizeof(struct emply),1,fp);
		if(p==emp.pass){
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}
void empdetail(int emid)
{
	FILE*fp;
	system("cls");
	int s,dchoice;
	fp=fopen("record.txt","r");
	
    while (fread(&emp, sizeof(struct emply), 1, fp))
        {
        s = emp.id;
        if (s == emid){
            printf("\nEMPLOYEE ID: %d",emp.id);
            printf("\n\n\nNAME: ");
            puts(emp.name);
            printf("\n\nFATHER NAME: ");
            puts(emp.fname);
            printf("\n\nGENDER: ");
            puts(emp.gender);
            printf("\n\nPHONE NUMBER: 0%d-%d",emp.phn1,emp.phn2);
            printf("\n\nCNIC NUMBER: %d-%d-%d",emp.cnic1,emp.cnic2,emp.cnic3);
            printf("\n\nACCOUNT TYPE: ");
            puts(emp.acctype);
            printf("\n\nDEPARTMENT: ");
            puts(emp.occu);
            printf("\n\nDATE OF BIRTH: ");
            puts(emp.dob);
            printf("\n\nADDRESS: ");
            puts(emp.address);
            printf("\n\nEMAIL ADDRESS: ");
            puts(emp.email);
            printf("\n\nNUMBER OF LEAVES: %d",emp.leaves);
            printf("\n\nLEAVE APPROVAL: ");
            puts(emp.lapprov);
            printf("\n\ncheck in : %d",emp.checkin);
            printf("\n\nhours  : %d",emp.hours);
            fclose(fp);
        }
    }
    printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&dchoice);
    fflush(stdin);
    if(dchoice==1){
    	clogin(emid);
	}
}
void checkin(int ciid)
{
	FILE *fpt;
    FILE *fp;
    int t;
    fp = fopen("record.txt", "r");
    fpt = fopen("tempFile", "w");
    while (fread(&emp, sizeof(struct emply), 1, fp)){
        t = emp.id;
        if (t != ciid){
            fwrite(&emp, sizeof(struct emply), 1, fpt);
        }else{ 
            time_t in = time(NULL);
            struct tm *ltm = localtime(&in);
            emp.checkin=ltm->tm_hour;
            fwrite(&emp, sizeof(struct emply), 1, fpt);
		} 
    }
    fclose(fp);
    fclose(fpt);
    fp = fopen("record.txt", "w");
    fpt = fopen("tempFile", "r");
    while (fread(&emp, sizeof(struct emply), 1, fpt)){
        fwrite(&emp, sizeof(struct emply), 1, fp);
    }
    fclose(fp);
    fclose(fpt);
    printf("\n\n CHECK IN SUCCESSFUL");
    getch();
    emplayout();
}
void checkout(int coid)
{
	FILE *fpt;
    FILE *fp;
    int t;
    fp = fopen("record.txt", "r");
    fpt = fopen("tempFile", "w");
    while (fread(&emp, sizeof(struct emply), 1, fp)){
        t = emp.id;
        if (t != coid){
            fwrite(&emp, sizeof(struct emply), 1, fpt);
        }else{          
		    time_t out = time(NULL);
            struct tm *ltm = localtime(&out);
            emp.checkout=ltm->tm_hour;
            if(emp.checkout<=emp.checkin){
            	emp.checkout=emp.checkout+12;
			}
            emp.hours=(emp.hours)+(emp.checkout-emp.checkin);
            fwrite(&emp, sizeof(struct emply), 1, fpt);
		} 
    }
    fclose(fp);
    fclose(fpt);
    fp = fopen("record.txt", "w");
    fpt = fopen("tempFile", "r");
    while (fread(&emp, sizeof(struct emply), 1, fpt)){
        fwrite(&emp, sizeof(struct emply), 1, fp);
    }
    fclose(fp);
    fclose(fpt);
    printf("\n\n CHECK OUT SUCCESSFUL");
    getch();
    emplayout();
}
void attend()
{
	system("cls");
	int no,avli,avlpa,pa,x,y;
	printf("\nPLEASE ENTER ID: ");
	scanf("%d",&no);
	printf("\nPLEASE ENTER PASSWORD: ");
	scanf("%d",&pa);
	system("cls");
	avli=avlid(no);	
	avlpa=avlp(pa);
	if(avli==0 || avlpa==0){
		printf("\nINCORRECT ID OR PASSWORD");
		printf("\n\n1 : BACK ");
		scanf("%d",&y);
		if(y==1){
		    attend();
		}
	}else{
		printf("\n\n1 : CHECK IN");
		printf("\n\n2 : CHECK OUT");
		printf("\n\nPLEASE ENTER YOUR CHOICE: ");
		scanf("%d",&x);
		fflush(stdin);
	    switch(x){
	        case 1: 
		        checkin(no);
	            break;
   	        case 2:
		        checkout(no);
	            break;  
        }
    }
}
void ereport()
{
	int erchoice;
	system("cls");
	printf("\n\n\nREPORT TYPE");
	printf("\n\n1 : DAILY BASIS EMPLOYEES");
	printf("\n\n2 : PERMENANT EMPLOYEES");
	printf("\n\n3 : CONTRACT EMPLOYEES");
	printf("\n\n4 : BACK");
	printf("\n\n\n\n\nPLEASE CHOOSE DESIRED OPTION: ");
	scanf("%d",&erchoice);
	fflush(stdin);
	switch(erchoice){
	    case 1: 
		    dailyemps();
	        break;
   	    case 2:
		    peremp();
	        break; 
		case 3: 
		    contemp();
	        break;
   	    case 4:
		    adminlayout();
	        break; 
    }
}
void dailyemps()
{
	FILE*fp;
	char s[30];
	int dchoice;
	fp=fopen("record.txt","r");
	system("cls");
    while(fread(&emp, sizeof(struct emply), 1, fp)){
        strcpy(s,emp.acctype);
        if (strcmp("daily basis",s)== 0){
            printf("\n\nEMPLOYEE ID: %d",emp.id);
            printf("\n\n\nNAME: ");
            puts(emp.name);
            printf("\n\nPHONE NUMBER: 0%d-%d",emp.phn1,emp.phn2);
            printf("\n\nEMPLOYEE TYPE: ");
            puts(emp.acctype);
            printf("\n\nDEPARTMENT: ");
            puts(emp.occu);        
            printf("\n\nNUMBER OF LEAVES: %d",emp.leaves);
            printf("\n--------------------------------------------------------------\n");
        }
    }
	fclose(fp); 
    printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&dchoice);
    fflush(stdin);
    if(dchoice==1){
    	ereport();
	}
}
void peremp()
{
	FILE*fp;
	char s[30];
	int dchoice;
	fp=fopen("record.txt","r");
	system("cls");
    while(fread(&emp, sizeof(struct emply), 1, fp)){
        strcpy(s,emp.acctype);
        if (strcmp("permenant",s)== 0){
            printf("\n\nEMPLOYEE ID: %d",emp.id);
            printf("\n\n\nNAME: ");
            puts(emp.name);
            printf("\n\nPHONE NUMBER: 0%d-%d",emp.phn1,emp.phn2);
            printf("\n\nEMPLOYEE TYPE: ");
            puts(emp.acctype);
            printf("\n\nDEPARTMENT: ");
            puts(emp.occu);        
            printf("\n\nNUMBER OF LEAVES: %d",emp.leaves);
            printf("\n--------------------------------------------------------------\n");
        }
    }
	fclose(fp); 
    printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&dchoice);
    fflush(stdin);
    if(dchoice==1){
    	ereport();
	}
}
void contemp()
{
	FILE*fp;
	char s[30];
	int dchoice;
	fp=fopen("record.txt","r");
	system("cls");
    while(fread(&emp, sizeof(struct emply), 1, fp)){
        strcpy(s,emp.acctype);
        if (strcmp("contract",s)== 0){
            printf("\n\nEMPLOYEE ID: %d",emp.id);
            printf("\n\n\nNAME: ");
            puts(emp.name);
            printf("\n\nPHONE NUMBER: 0%d-%d",emp.phn1,emp.phn2);
            printf("\n\nEMPLOYEE TYPE: ");
            puts(emp.acctype);
            printf("\n\nDEPARTMENT: ");
            puts(emp.occu);        
            printf("\n\nNUMBER OF LEAVES: %d",emp.leaves);
            printf("\n--------------------------------------------------------------\n");
        }
    }
	fclose(fp); 
    printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&dchoice);
    fflush(stdin);
    if(dchoice==1){
    	ereport();
	}
}
void update(int uid)
{
	FILE *fpt;
    FILE *fpo;
    int s,uchoice,uc;
    fpo = fopen("record.txt", "r");
    fpt = fopen("tempFile", "w");
    while (fread(&emp, sizeof(struct emply), 1, fpo)){
        s = emp.id;
        if (s != uid){
            fwrite(&emp, sizeof(struct emply), 1, fpt);
        }else{
        	system("cls");
            printf("\n\n1 : UPDATE NAME");
	        printf("\n\n2 : UPDATE PHONE NUMBER");
	        printf("\n\n3 : UPDATE CNIC NUMBER");
	        printf("\n\n4 : UPDATE ADDRESS");
            printf("\n\n5 : UPDATE EMAIL ADDRESS");
            printf("\n\n6 : UPDATE DEPARTMENT NAME");
            printf("\n\n7 : UPDATE BANK ADDRESS");
            printf("\n\n8 : UPDATE BANK ACCOUNT NUMBER");
            printf("\n\n9 : UPDATE EMPLOYEE TYPE");
            printf("\n\n\n\nPLEASE CHOOSE DESIRED OPTION: ");
            scanf("%d",&uchoice);
            fflush(stdin);
            switch(uchoice){
    	        case 1:
    		        printf("\nENTER NAME: ");
    		        gets(emp.name);
    		        break;
    	        case 2:
				    printf("\nENTER PHONE NUMBER xxxx-xxxxxxx: ");
                    scanf("%d-%d",&emp.phn1,&emp.phn2);
                    break;
	            case 3:    
			        printf("\nENTER CNIC NUMBER xxxxx-xxxxxxx-x: ");
	                scanf("%d-%d-%d",&emp.cnic1,&emp.cnic2,&emp.cnic3);
	                break;
	            case 4:
	                printf("\nENTER ADDRESS: ");
					gets(emp.address); 
					break;
				case 5:
				    printf("\nENTER EMAIL ADDRESS: ");
					gets(emp.email);
					break;
		    	case 6:
				    printf("\nENTER POSITION TITLE: ");
					gets(emp.occu);
					break;				
	            case 7:
				    printf("\nENTER BANK ADDRESS: ");
					gets(emp.bank);
					break;
				case 8:
				    printf("\nENTER BANK ACCOUNT NUMBER: ");
					scanf("%d",&emp.accn);
					break;
				case 9:
				    printf("\nENTER EMPLOYEE TYPE: ");
					gets(emp.acctype);
					break;				
				}
            fwrite(&emp, sizeof(struct emply), 1, fpt);
		} 
    }
    fclose(fpo);
    fclose(fpt);
    fpo = fopen("record.txt", "w");
    fpt = fopen("tempFile", "r");
    while (fread(&emp, sizeof(struct emply), 1, fpt)){
        fwrite(&emp, sizeof(struct emply), 1, fpo);
    }
    fclose(fpo);
    fclose(fpt);
    printf("\n\n\n\n\nACCOUNT DETAILS UPDATED SUCCESSFULLY UPDATED");
    printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&uc);
    if(uc==1){
    	empl(uid);
	}    
}
void deleterec()
{
	FILE*fp;
    FILE*fpt;
    int num, s,dchoice;
    system("cls");
    printf("\n\nENTER EMPLOYEE ID NUMBER YOU WANT TO DELETE: ");
    scanf("%d", &num);
    if (avlid(num) == 0){
        printf("\n\nACCOUNT IS NOT PRESENT");
        getch();
        adminlayout();
	}else{
		printf("\n\nARE YOU SURE YOU WANT TO DELETE THIS ACCOUNT");
		printf("\n\n\n\n\n1: YES\t\t\t\t2: NO");
		scanf("%d",&dchoice);
		fflush(stdin);
		switch(dchoice){
			case 1:
			    fp = fopen("record.txt", "r");
                fpt = fopen("tempfile", "w");
                while (fread(&emp, sizeof(struct emply), 1, fp)){
                    s = emp.accn;
                    if (s != num){
                        fwrite(&emp, sizeof(struct emply), 1, fpt);
                    }
                    fclose(fp);
                    fclose(fpt);
                    fp = fopen("record.txt", "w");
                    fpt = fopen("tempfile", "r");
                    while (fread(&emp, sizeof(struct emply), 1, fpt)){
                        fwrite(&emp, sizeof(struct emply), 1, fp);
                    }
                    fclose(fp);
                    fclose(fpt);
					system("cls");
					printf("\n\n\n\t\tACCOUNT DELETED\n");
                    getch();
                    adminlayout();
                }               	
                break;
            case 2:
            	adminlayout();
            	break;
        }
    }
}
void aempdetail(int aeid)
{
	FILE*fp;
	system("cls");
	int s,dchoice;
	fp=fopen("record.txt","r");
    while (fread(&emp, sizeof(struct emply), 1, fp))
        {
        s = emp.id;
        if (s == aeid){
            printf("\nEMPLOYEE ID: %d",emp.id);
            printf("\n\n\nNAME: ");
            puts(emp.name);
            printf("\n\nFATHER NAME: ");
            puts(emp.fname);
            printf("\n\nGENDER: ");
            puts(emp.gender);
            printf("\n\nPHONE NUMBER: 0%d-%d",emp.phn1,emp.phn2);
            printf("\n\nCNIC NUMBER: %d-%d-%d",emp.cnic1,emp.cnic2,emp.cnic3);
            printf("\n\nACCOUNT TYPE: ");
            puts(emp.acctype);
            printf("\n\nDEPARTMENT: ");
            puts(emp.occu);
            printf("\n\nDATE OF BIRTH: ");
            puts(emp.dob);
            printf("\n\nADDRESS: ");
            puts(emp.address);
            printf("\n\nEMAIL ADDRESS: ");
            puts(emp.email);
            printf("\n\nNUMBER OF LEAVES: %d",emp.leaves);
            fclose(fp);
        }
    }
    printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&dchoice);
    fflush(stdin);
    if(dchoice==1){
    	empl(aeid);
	}
}
void payslip(int pid)
{
	FILE*fp;
	int t;
	char s[20],a[20];
	system("cls");
	fp=fopen("record.txt","r");
    while (fread(&emp, sizeof(struct emply), 1, fp))
        {
        t = emp.id;
        if (t == pid){
        	
            strcpy(s,emp.acctype);
            strcpy(a,emp.occu);
            fclose(fp);
        }
    }
	if(strcmp(s,"daily basis")==0){			
	    if(strcmp(a,"engineer")==0){
	    	if(emp.hours>=8){
	    		paygen(pid,100,8);
			}else{
				printf("\n\n\t\tTOTAL HOURS ELIGIBILITY NOT FULFILLED");
				getch();
				clogin(pid);
			}
	    }
	}else if(strcmp(s,"permenant")==0){
		if(emp.hours>=208){
		    if(strcmp(a,"manager")==0){
			    paygen(pid,200,208);
	        }else if(strcmp(a,"accountant")==0){
			    paygen(pid,80,208);
		    }else if(strcmp(a,"engineer")==0){
			    paygen(pid,100,208);
		    }
		}else{
			printf("\n\n\t\tTOTAL HOURS ELIGIBILITY NOT FULFILLED");
			getch();
			clogin(pid);
		}
	}else if(strcmp(s,"contract")==0){
		if(emp.hours>=208){
	        if(strcmp(a,"accountant")==0){
			    paygen(pid,80,208);
		    }else if(strcmp(a,"engineer")==0){
			    paygen(pid,100,208);
		    }
		}else{
			printf("\n\n\t\tTOTAL HOURS ELIGIBILITY NOT FULFILLED");
			getch();
			clogin(pid);
		}
	}
}
void paygen(int pyid,int pr,int hrs)
{
	FILE*fp;
	system("cls");
	int t,ot,td,x;
	fp=fopen("record.txt","r");
    while (fread(&emp, sizeof(struct emply), 1, fp))
        {
        t = emp.id;
        if (t == pyid){
        	printf("\n-----------------------------------PAYSLIP--------------------------------------");
        	printf("\n\nEMPLOYEE ID: %d",emp.id);
        	printf("\n\nEMPLOYEE NAME: ");
        	puts(emp.name);
        	printf("\n\nBANK ADDRESS: ");
        	puts(emp.bank);
        	printf("\n\nDEPARTMENT: ");
        	puts(emp.occu);
        	printf("\n\nTOTAL HOURS WORKED: %d",emp.hours);
        	printf("\n\nTOTAL CASUAL LEAVES: %d",emp.leaves);
        	printf("\n\nOVERTIME HOURS: %d",emp.hours-hrs);
        	printf("\n\nBASIC PAY:           \t\t\t%d",8*emp.hours*pr);
        	printf("\n\nMECICAL ALLOWANCE:   \t\t\t1000");
        	printf("\n\nHOUSE ALLOWANCE:     \t\t\t500");
        	printf("\n\nCONVEYENCE ALLOWANCE:\t\t\t200");
        	printf("\n\nFOOD ALLOWANCE:      \t\t\t400");
        	ot=(emp.hours-hrs)*(pr/2);
        	printf("\n\nOVERTIME ALLOWANCE:  \t\t\t%d",ot);
        	printf("\n\nTOTAL EARNINGS:      \t\t\t%d",(8*emp.hours*pr)+2100+ot);
        	printf("\n\nLOSS OF PAY:         \t\t\t%d",emp.leaves*8*pr);
        	printf("\n--------------------------------------------------------------------------------");
        	td=((8*emp.hours*pr)+2100+ot)-(emp.leaves*8*pr);
        	printf("\nNET PAY:             \t\t\t%d",td);
            fclose(fp);
        }
    }
    printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&x);
    fflush(stdin);
    if(x==1){
    	clogin(pyid);
	}
}
void leave(int lid)
{
	int cchoice,etype;
	system("cls");
	FILE*fp;
	fp=fopen("admin.txt","a");
	printf("\n\t\tPLEASE ENTER REQUIRED DATA FOR LEAVE");
    printf("\nENTER EMPLOYEE ID: ");
    scanf("%d",&ad.id);
    fflush(stdin);
	printf("\nENTER NAME: ");
	gets(ad.ename);
    printf("\nENTER DEPARTMENT NAME: ");
	gets(ad.design);
	printf("\nCHOOSE LEAVE TYPE: ");
	printf("\n\n\t1 : SICK LEAVE ");
	printf("\n\n\t2 : VACATION");
    printf("\n\n\t3 : PERSONAL LEAVE");
    printf("\n\n\t4 : UNPAID LEAVE");
    printf("\n\nCHOICE : ");
	scanf("%d",&etype);
	switch(etype){
		case 1:
			strcpy(ad.leavetype,"sick leave");
			break;
		case 2:
			strcpy(ad.leavetype,"vacation");
			break;
		case 3:
		    strcpy(ad.leavetype,"personal leave");
			break;	
		case 4:
		    strcpy(ad.leavetype,"unpaid leave");
			break;	
    }
    fflush(stdin);
    printf("\nDATES REQUESTED");
    printf("\tfrom: ");
	gets(ad.fromdate);
	printf("\nto: ");
	gets(ad.todate);
	printf("\nPLEASE MENTION YOUR REASON: ");
	gets(ad.reason);
	printf("\nENTER LEAVE DAYS: ");
    scanf("%d",&ad.noleave);
	printf("\n\n\tLEAVE FORM SUBMITTED SUCCESSFULLY");
	fwrite(&ad,sizeof(struct admin),1,fp);
    fclose(fp);
    printf("\n\n\t\t\t\t1 : BACK ");
    scanf("%d",&cchoice);
    fflush(stdin);
    if(cchoice==1){
    	clogin(lid);
	}
}
void ldetails()
{
	FILE*fp;
	system("cls");
	int s,dchoice,id;
	char x;
	fp=fopen("admin.txt","r");
	if(fp==NULL){
		printf("NO LEAVE FORM");
		getch();
		adminlayout();
	}else{
        while(fread(&ad, sizeof(struct admin), 1, fp)){
            printf("\n\nEMPLOYEE ID: %d",ad.id);
            printf("\n\n\nNAME: ");
            puts(ad.ename);
            printf("\n\nDEPARTMENT: ");
            puts(ad.design);
            printf("\n\nEMPLOYEE TYPE: ");
            puts(ad.leavetype);
            printf("\n\nDATE REQUESTED:\t from: %s\t\t to: %s",ad.fromdate,ad.todate);
            printf("\n\nREASON: ");
            puts(ad.reason);
            printf("\n\nNUMBER OF LEAVES: %d",ad.noleave);
            printf("\n--------------------------------------------------------------\n");
        }
    }
	fclose(fp);
	printf("\n");
	do{
		printf("\n\nENTER ID: ");
		scanf("%d",&id);
		FILE *fpt;
        FILE *fp,*fp1;
        int t;
        fp = fopen("admin.txt", "r");
        fpt = fopen("record.txt", "w");
        while (fread(&ad, sizeof(struct admin), 1, fp)){
            t = ad.id;
            if (t != id){
                fwrite(&emp, sizeof(struct emply), 1, fpt);
            }else{  
                emp.leaves=emp.leaves+ad.noleave;
                strcpy(emp.lapprov,"congratulations leave approved");
                fwrite(&emp, sizeof(struct emply), 1, fpt);
		    } 
        }
        fclose(fp);
        fclose(fpt);
        fp = fopen("admin.txt", "r");
        fp1 = fopen("tempfile", "w");
        while (fread(&ad, sizeof(struct admin), 1, fp)){
            t = ad.id;
            if (t != id){
            fwrite(&ad, sizeof(struct admin), 1, fp1);
            }
            fclose(fp);
            fclose(fp1);
            fp = fopen("admin.txt", "w");
            fpt = fopen("tempfile", "r");
            while (fread(&ad, sizeof(struct admin), 1, fp1)){
                fwrite(&ad, sizeof(struct admin), 1, fp);
            }
            fclose(fp);
            fclose(fp1);
        }          
        printf("DO YOU WANT TO APPROVE MORE LEAVES <y/n>: ");
        scanf(" %c",&x);
	}while(x=='y');
    adminlayout();
}

