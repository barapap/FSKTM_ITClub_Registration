/*	GROUP MEMBERS:
	1. Ahmad Syawal Bin Ahmad Zaini		AI210282
	2. Chia Sze Yee						AI210360
	3. Kor Wei Yan						AI210411
	4. Muhammad Ali Uzair Bin Marzele	AI210178
	5. Nur Aisyah Zayani Binti Hamid	AI210063		
	6. Nurafiqah Sherly Binti Zaini 	AI210300 		*/	

// GROUP TITLE : Club Registration System for IT Club FSKTM

#include<stdio.h>
#include<stdlib.h>
#include<string.h>	//for strcpy, strcmp etc
#include<conio.h>	//for getch etc.

struct Information{
	int no;
	char matrics[9];	
	char name[20];
	char courseCode[4];
	char icNum[13];
	int currStudyYear;
};
	typedef struct Information newInfo;

struct node{
	newInfo record;
	struct node *next;
};
	typedef struct node node;
	typedef node *nodePtr;

void mainMenu(){
	puts("----- FSKTM IT CLUB REGISTRATION SYSTEM -----\n\n"
	"\t    <<< MAIN MENU >>>\n"
	" \t(1) Insert A New Record\n" 				
	" \t(2) Remove A Record\n"					
	" \t(3) Update A Record\n" 					
	" \t(4) Find Record\n"						
	" \t(5) Display Record\n"					
	" \t(0) EXIT SYSTEM \n\n"
	"  ---  [PRESS TWICE ON SELECTION]  ---\n");
}
void insertRecord(nodePtr *headptr, newInfo rinfo){
	nodePtr newptr, prevptr, currptr;
	int registeredmember=0;
	newptr = malloc(sizeof(node));			//dynamic memory allocation
	
	if(newptr != NULL){
		newptr->record = rinfo;				//insertion of record into new node
		newptr->next = NULL;
		
		prevptr = NULL;
		currptr = *headptr;
		
		while(currptr != NULL){				//find the end of list when list is not empty
			prevptr = currptr;
			currptr = currptr->next;
		}
		
		if(prevptr == NULL){				//linking new node when list is empty
			*headptr = newptr;
		}
		else{
			prevptr->next = newptr;			//linking new node when list is not empty
		}
		
		currptr = *headptr;					//Club Status Analysis Counter
		while(currptr!=NULL){
			registeredmember += 1;
			currptr = currptr->next;
		}
		puts("____________________________________________");
		puts("\n!!! NEW MEMBER REGISTERED SUCCESSFULLY !!!\n"
		"\tWelcome to IT Club FSKTM :)");
		puts("____________________________________________");
		printf("\nCURRENT CLUB REGISTRATION STATUS\n");							//Current Club Status Analysis
		printf("   Current Registration Number\t: %d\n", rinfo.no);
		printf("   Current Registered Member\t: %d\n", registeredmember);
	}
	else{
		printf("No memory available.\n");	//dynamic memory allocation failed
	}
}

void removeRecordMenu(){
	puts("----- FSKTM IT CLUB REGISTRATION SYSTEM -----\n\n"
	"    <<< REMOVE RECORD MENU >>>\n"
	" \t(1) By Matrics Number\n"
	" \t(2) By I/C Number\n"
	" \t(0) Return to Main Menu\n\n"
	"  ---  [PRESS TWICE ON SELECTION]  ---\n");
}
void removeRecord(nodePtr *headptr, nodePtr ptr){
	nodePtr temp, prev, curr;
	if(*headptr == ptr){				//remove record when the record is first in the list
		temp = ptr;
		*headptr = ptr->next;
		free(temp);
	}
	else{								//remove record when the record is not first in the list
		prev = *headptr;
		curr = (*headptr)->next;
		while(curr!=ptr){					//finding the record to be deleted in the list
			prev = curr;
			curr = curr->next;
		}
		temp = curr;
		prev->next = curr->next;
		free(temp);
	}
	int registeredmember = 0;
	curr = *headptr;					//Club Status Analysis Counter
	while(curr!=NULL){
		registeredmember += 1;
		curr = curr->next;
	}
	puts("____________________________________________");
	printf("\nCURRENT CLUB REGISTRATION STATUS\n");							
	printf("   Current Registered Member\t: %d\n", registeredmember);
	return;	
}

void updateRecordMenu(){
	puts("----- FSKTM IT CLUB REGISTRATION SYSTEM -----\n\n"
	"\t  <<< UPDATE RECORD MENU >>>\n"
	"\n **SEARCH THE STUDENT DATA FIRST BEFORE UPDATE**\n\n"
	" \t   (1) By Matric Number\n"
	" \t   (2) By I/C Number\n"
	" \t   (0) Return to Main Menu\n\n"
	"  ---  [PRESS TWICE ON SELECTION]  ---\n");
}
void updateRecord(nodePtr *headptr, nodePtr tempPtr){
	int select;
	char matrics[9];
	char name[20];
	char courseCode[4];
	char icNum[13];
	int currStudyYear;
	
	system("cls");
	updateRecordMenu();
	printf("____________________________________________");			//To show the record to be updated
    printf("\n\t(1) Matric Number\t: %s\n", tempPtr->record.matrics);
	printf("\t(2) Full Name\t\t: %s\n", tempPtr->record.name);
	printf("\t(3) Course Code\t\t: %s\n", tempPtr->record.courseCode);
	printf("\t(4) I/C Number\t\t: %s\n", tempPtr->record.icNum);
	printf("\t(5) Current Study Year  : Year %d\n", tempPtr->record.currStudyYear);
	
	printf("\n\t Enter the Update Selection \t>> ");					//To choose which data from the record to be updated
	scanf("%d",&select);
	switch(select){
		case 1:
		    fflush(stdin);
			printf("Please enter NEW matric number \t>> ");
			gets(matrics);
			strcpy(tempPtr->record.matrics,matrics);
			break;
		case 2:
			fflush(stdin);
			printf("Please enter NEW name \t>> ");
			gets(name);
			strcpy(tempPtr->record.name,name);
			break;
		case 3:
			fflush(stdin);
			printf("Please enter NEW course code \t>> ");
			gets(courseCode);
			strcpy(tempPtr->record.courseCode,courseCode);
			break;
		case 4:
			fflush(stdin);
			printf("Please enter NEW IC number \t>> ");
			gets(icNum);
			strcpy(tempPtr->record.icNum,icNum);
			break;
		case 5:
			fflush(stdin);
			printf("Please enter NEW current study year >> ");
			scanf("%d",&currStudyYear);
			tempPtr->record.currStudyYear = currStudyYear;
			break;
		default:
			printf("\nOut of choice limit\n");
			return;
	}
	return;
}	

void findRecordMenu(){
	puts("----- FSKTM IT CLUB REGISTRATION SYSTEM -----\n\n"
	"\t  <<< FIND RECORD MENU >>>\n"
	" \t(1) By Matrics Number\n"
	" \t(2) By I/C Number\n"
	" \t(0) Return to Main Menu\n\n"
	"  ---  [PRESS TWICE ON SELECTION]  ---\n");
}
nodePtr findByMatric(nodePtr ptr, char data[9]){
	int i;
	if(ptr == NULL){											//if the list is empty
		printf("\n\n\t  {{ List is empty }}\n");
		printf("  No Club Members had been recorded yet\n");
		printf("   Unable to search for matric %s\n\n", data);
		return;
	}
	else{														//if the list is not empty
		while(ptr != NULL){
			if(strcmp(ptr->record.matrics,data)==0){
				puts("\n Student record found.\n");
				puts("\t--- STUDENT DETAILS --- ");
				printf(" Record Number\t\t: %d\n", ptr->record.no);
				printf(" Matric Number\t\t: %s\n", ptr->record.matrics);
				printf(" Full Name\t\t: %s\n", ptr->record.name);
				printf(" Course Code\t\t: %s\n", ptr->record.courseCode);
				printf(" I/C Number\t\t: %s\n", ptr->record.icNum);
				printf(" Current Study Year \t: Year %d\n", ptr->record.currStudyYear);
				return ptr;
			}
			else{
				ptr = ptr->next;
			}
		}
		puts("\n\n      Sorry, record was not found");
		printf("Club Member of Matric %s does not exist\n", data);
		//getch();
		return NULL;
	}
}
nodePtr findByIC(nodePtr ptr, char data[13]){
	int i;
	if(ptr == NULL){
		printf("\n\n\t  {{ List is empty }}\n");
		printf("  No Club Members had been recorded yet\n");
		printf("  Unable to search for IC %s\n\n", data);
		return;
	}
	else{
		while(ptr != NULL){
			if(strcmp(ptr->record.icNum, data)==0){
				puts("\nStudent record found.\n");
				puts("\t--- STUDENT DETAILS --- ");
				printf(" Record Number\t\t: %d\n", ptr->record.no);
				printf(" I/C Number\t\t: %s\n", ptr->record.icNum);
				printf(" Full Name\t\t: %s\n", ptr->record.name);
				printf(" Matric Number\t\t: %s\n", ptr->record.matrics);			
				printf(" Course Code\t\t: %s\n", ptr->record.courseCode);
				printf(" Current Study Year \t: Year %d\n", ptr->record.currStudyYear);
				return ptr;
			}
			else{
				ptr = ptr->next;
			}
		}
		puts("\n\n      Sorry, record was not found\n");
		printf("Club Member of IC %s does not exist\n", data);
		//getch();
		return NULL;
	}
}

void displayMenu(){							
	puts("----- FSKTM IT CLUB REGISTRATION SYSTEM -----\n\n"
	"\t  <<< DISPLAY RECORD MENU >>>\n"
	" \t(1) All Record\n"
	" \t(2) Group By Course\n"
	" \t(0) Return to Main Menu\n\n"
	"  ---  [PRESS TWICE ON SELECTION]  ---\n");
}
void displayAll(nodePtr ptr){
	if(ptr == NULL){
		printf("\nThe list is empty");
	}
	while(ptr != NULL){
		printf("\nRECORD NUMBER %d\n", ptr->record.no);
		printf("\t Matric Number\t    : %s\n",ptr->record.matrics);
		printf("\t Student Name \t    : %s\n",ptr->record.name);
		printf("\t Course Code\t    : %s\n",ptr->record.courseCode);
		printf("\t I/C Number\t    : %s\n",ptr->record.icNum);
		printf("\t Current Study Year : %d\n\n",ptr->record.currStudyYear);
		ptr = ptr->next;
	}	
	getch();	
}
void displayByCourse(nodePtr ptr, char course[4]){
    int counter;
    if(ptr == NULL){
        printf("The list is empty");
     }
    while(ptr != NULL){
            if(strcmp(ptr->record.courseCode,course) == 0){
            printf("\nRECORD NUMBER %d\n", ptr->record.no);
            printf("\n\t Matric Number\t    : %s\n",ptr->record.matrics);
            printf("\t Student Name \t    : %s\n",ptr->record.name);
            printf("\t I/C Number\t    : %s\n",ptr->record.icNum);
            printf("\t Current Study Year : %d\n\n",ptr->record.currStudyYear);
            counter++;
            }
            ptr = ptr->next;
    }
    if(counter == 0){
        printf("\nNo club member is in %s.", course);
    }
    getch();
}

int main(){
	nodePtr head = NULL;
	newInfo readinfo;
	char courseCodeValid[5][4] = {"BIT", "BIP", "BIW", "BIS", "BIM"};
	int recordcount = 0; 
	char matricsearch[9], ICsearch[13];
	while(1){
		char matricsearch[9], ICsearch[13], course[4];
		char choice='\0',choice2='\0';
		int i=0, j=0, result=3;
		nodePtr temp=NULL;
		mainMenu();
		getch();
		choice = getch();
		switch(choice){
			case '1':
				recordcount++;
				readinfo.no = recordcount;
				printf("____________________________________________\n");
				printf("\n--- Please enter the NEW MEMBER's details ---\n\n");
				printf("Matrix Number\t   : ");
				scanf("%[^\n]s",&readinfo.matrics);
				fflush(stdin);
				printf("Student Name\t   : ");
				scanf("%[^\n]s",&readinfo.name);
				printf("Course code\t   : ");
				scanf("%s",&readinfo.courseCode);
				for(i=0; i<5; i++){
					if(strcmp(readinfo.courseCode,courseCodeValid[i]) == 0){
						printf("I/C Number\t   : ");
						scanf("%s",&readinfo.icNum);
						printf("Current study year : ");
						scanf("%d",&readinfo.currStudyYear);
						if(readinfo.currStudyYear > 0 && readinfo.currStudyYear <5){
							fflush(stdin);
							insertRecord(&head,readinfo);
							break;
						}
						else{
							puts("\n Invalid Study Year\n"
							" Record is not inserted");
							recordcount--;
							break;
						}
					}
					if(i==4){
						if(strcmp(readinfo.courseCode,courseCodeValid[i]) != 0){
							printf("\n  Sorry, Registration Failed");
							printf("\nCourse Code must be under FSKTM");
							recordcount--;
							break;
						}	
					}
				}
				break;
				
			case '2':           
				do{
					fflush(stdin);
					system("cls");
					removeRecordMenu();
					getch();
					choice2 = getch();
					printf("____________________________________________\n");
					switch(choice2){
						case '1':
							printf("\n Club Member's Matric to Remove Record >> ");
							gets(matricsearch);
							printf("____________________________________________");
							temp = findByMatric(head, matricsearch);
							getch();
							break;
						case '2':	
							printf("\nClub Member's I/C to Remove Record >>  ");
							gets(ICsearch);
							printf("____________________________________________");
							temp = findByIC(head, ICsearch);
							getch();
							break;
						case '0':
							printf("\n      Returning Back to Main Menu...\n");
							printf("----- [Press Anything to Proceed] -----\n");
							getch();
							break;
						default:
							puts("\n\t\t!! ERROR !!\n"
							"\tPlease choose again from the menu.\n"
							"\t  Enter 0 to Return to Main Menu");
							getch();
							break;
					}
					if(temp != NULL && (choice2 == '1' || choice2 == '2')){
						printf(" \n---[PRESS ENTER TWICE TO PROCEED DELETION]---\n");
						getch();
						removeRecord(&head, temp);
						break;
					}
				}while(choice2 != '0');
				break;
			case '3':
				do{
					fflush(stdin);
					system("cls");
					updateRecordMenu();
					getch();
					choice2 = getch();
					printf("____________________________________________");
					switch(choice2){
						case '1':
							printf("\nMatric Number of Member to be Updated : ");
							gets(matricsearch);
							printf("____________________________________________");
							temp = findByMatric(head, matricsearch);
							break;
						case '2':
							printf("\nIC Number of Member to be Updated : ");
							gets(ICsearch);
							printf("____________________________________________");
							temp = findByIC(head, ICsearch);
							break;
						case '0':
							printf("\n      Returning Back to Main Menu...\n");
							printf("----- [Press Anything to Proceed] -----\n");
							break;
						default:
							puts("\n\t\t!! ERROR !!\n"
							"\tPlease choose again from the menu.\n"
							"\t  Enter 0 to Return to Main Menu");
							getch();
							break;
					}
					if(temp != NULL && (choice2 == '1' || choice2 == '2')){
						getch();
						printf(" \n---[PRESS ENTER TWICE TO PROCEED UPDATE]---\n");
						updateRecord(&head, temp);
				    }
				    fflush(stdin);
				}while(choice2 != '0');
				break;
			case '4':
				do{
					fflush(stdin);
					system("cls");
					findRecordMenu();
					getch();
					choice2 = getch();
					printf("____________________________________________\n");
					switch(choice2){
						case '1':
							printf("Matric Number to be searched : ");
							gets(matricsearch);
							findByMatric(head, matricsearch);
							getch();
							break;
						case '2':
							printf("IC Number to be searched : ");
							gets(ICsearch);
							findByIC(head, ICsearch);
							getch();
							break;
						case '0':
							printf("\n      Returning Back to Main Menu...\n");
							printf("----- [Press Anything to Proceed] -----\n");
							break;
						default:
							puts("\t\t !! ERROR !!\n"
							"\t Please choose again from the menu.\n"
							"\t  Enter 0 to Return to Main Menu");
							getch();
							break;
					}
				}while(choice2 != '0');
				break;
			case '5':
				do{
					fflush(stdin);
					system("cls");
					displayMenu();
					getch();
					choice2 = getch();
					printf("____________________________________________");
					switch(choice2){
						case '1':
							displayAll(head);
							break;
						case '2':
							printf("\n\tPlease enter the course code: ");
						    scanf("%s",&course);
						    for(i=0; i<6; i++){
								if(strcmp(course,courseCodeValid[i]) == 0){
									displayByCourse(head,course);
									break;
								}
								if(i==5){
									if(strcmp(course,courseCodeValid[i]) != 0){
										printf("\nSorry, Invalid Course Code");
										printf("\nCourse Code must be under FSKTM");
										break;
									}	
								}
							}
						case '0':
							printf("\n      Returning Back to Main Menu...\n");
							printf("----- [Press Anything to Proceed] -----\n");
							break;
						default:
							puts("\n\t\t !! ERROR !!\n"
							"\t Please choose again from the menu.\n"
							"\t  Enter 0 to Return to Main Menu");
							getch();
							break;
					}
				}while(choice2 != '0');
				break;
			case '0':
				puts("Thank you for using this service\n"
				"Goodbye!");
				exit(0);
			default:
				puts("\t\t!! ERROR !!\n"
				"\tPlease choose again from the menu.\n"
				"\tEnter 0 to Exit");
				break;
		}
	fflush(stdin);
	getch();
	system("cls");
	}
}

