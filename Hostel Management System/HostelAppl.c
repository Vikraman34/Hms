#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "HostelIf.h"
#include "HostelImpl.h"

void main()
{
	int sc = 0;
	int shc = 0;
	int ic = 0;
	int sno = 1;
	int yr, a, hos, dhos, count = 0, flag=0;
	char name[50], fname[50], dep[5], add[100], pno[50], mod[20], sname[50], sfname[50], dname[50], dfname[50];
	int choice, hoschoice=0;
	q1 = createqueue(q1);
	q2 = createqueue(q2);
	q3 = createqueue(q3);

	FILE *fp;

	shared = createemptylist(shared);
	single = createemptylist(single);
	inter = createemptylist(inter);
	int singlewait = 0, interwait = 0, sharewait = 0;

	printf("\nGetting information from the database...\n");

	fp = fopen("SingleHostelDetails.txt", "r");
	if(fp!=NULL)
	{
		while(!feof(fp) && sc !=2)
		{
			struct node *temp = (struct node *) malloc(sizeof(struct node));
			fread(temp, sizeof(struct node), 1, fp);
			insert(single, temp->name, temp->fathername, temp->dept, temp->address, temp->phoneno, temp->year, temp->typeofhostel, temp->mode, temp->roomno);
			sc++;
		}
	}
	fclose(fp);

	fp = fopen("SharedHostelDetails.txt", "r");
	if(fp!=NULL)
	{
		while(!feof(fp) && shc !=4)
		{
			struct node *temp = (struct node *) malloc(sizeof(struct node));
			fread(temp, sizeof(struct node), 1, fp);
			insert(shared, temp->name, temp->fathername, temp->dept, temp->address, temp->phoneno, temp->year, temp->typeofhostel, temp->mode, temp->roomno);
			shc++;
		}
	}
	fclose(fp);

	fp = fopen("InternationalHostelDetails.txt", "r");
	if(fp!=NULL)
	{
		while(!feof(fp) && ic !=2)
		{
			struct node *temp = (struct node *) malloc(sizeof(struct node));
			fread(temp, sizeof(struct node), 1, fp);
			insert(inter, temp->name, temp->fathername, temp->dept, temp->address, temp->phoneno, temp->year, temp->typeofhostel, temp->mode, temp->roomno);
			ic++;
		}
	}
	fclose(fp);

	int siCount = 0;
	int shCount = 0;
	int inCount = 0;

	fp = fopen("SingleWaitingList.txt", "r");
	if(fp!=NULL)
		while(!feof(fp))
		{
			struct queue *qTemp = (struct queue*)malloc(sizeof(struct queue));
			fread(qTemp, sizeof(struct queue), 1, fp);
			free(qTemp);
			siCount++;
		}
	fclose(fp);

	fp = fopen("SingleWaitingList.txt", "r");
	if(fp!=NULL)
	{
		int count = 0;
		while(!feof(fp) && count!=siCount-1)
		{
			count++;
			struct queue *q = (struct queue *)malloc(sizeof(struct queue));
			fread(q, sizeof(struct queue), 1, fp);
			enqueue(q1, q->stu.name, q->stu.fathername, q->stu.dept, q->stu.year, q->stu.address, q->stu.phoneno, q->stu.typeofhostel, q->stu.mode, q->stu.roomno);
			singlewait++;
		}
	}
	fclose(fp);

	fp = fopen("SharedWaitingList.txt", "r");
	if(fp!=NULL)
		while(!feof(fp))
		{
			struct queue *qTemp = (struct queue*)malloc(sizeof(struct queue));
			fread(qTemp, sizeof(struct queue), 1, fp);
			free(qTemp);
			shCount++;
		}
	fclose(fp);

	fp = fopen("SharedWaitingList.txt", "r");
	if(fp!=NULL)
	{
		int count = 0;
		while(!feof(fp) && count!=shCount-1)
		{
			count++;
			struct queue *q = (struct queue *)malloc(sizeof(struct queue));
			fread(q, sizeof(struct queue), 1, fp);
			enqueue(q2, q->stu.name, q->stu.fathername, q->stu.dept, q->stu.year, q->stu.address, q->stu.phoneno, q->stu.typeofhostel, q->stu.mode, q->stu.roomno);
			sharewait++;
		}
	}
	fclose(fp);

	fp = fopen("InternationalWaitingList.txt", "r");
	if(fp!=NULL)
		while(!feof(fp))
		{
			struct queue *qTemp = (struct queue*)malloc(sizeof(struct queue));
			fread(qTemp, sizeof(struct queue), 1, fp);
			free(qTemp);
			inCount++;
		}
	fclose(fp);

	fp = fopen("InternationalWaitingList.txt", "r");
	if(fp!=NULL)
	{
		int count = 0;
		while(!feof(fp) && count!=inCount-1)
		{
			count++;
			struct queue *q = (struct queue *)malloc(sizeof(struct queue));
			fread(q, sizeof(struct queue), 1, fp);
			enqueue(q3, q->stu.name, q->stu.fathername, q->stu.dept, q->stu.year, q->stu.address, q->stu.phoneno, q->stu.typeofhostel, q->stu.mode, q->stu.roomno);
			interwait++;
		}
	}
	fclose(fp);
	printf("\nDone!!\n");

	printf("\n-----> Hostel Management System <-----\n");

	while(1)
	{
		printf("\n------------> Operations <------------\n1. Request a Room\n2. Find a Student in the hostel\n3. Display all the Student\'s details\n4. Vacate your Room\n5. Display the Waiting Lists\n6. Write the Student\'s details to a file\n7. Write the Waiting Lists to a file\n8. Exit\nYour choice : ");
		scanf("%d", &choice);

		if(choice == 8)
		{
			struct node *temp = (struct node*) malloc(sizeof(struct node));

			if(!isEmpty(single))
			{
				fp = fopen("SingleHostelDetails.txt", "w");
				temp = single->next;
				int count = 0;
				while(temp!=NULL && count != sc)
				{
					count++;
					fwrite(temp, sizeof(struct node), 1, fp);
					temp = temp->next;
				}
				fclose(fp);
			}

			if(!isEmpty(shared))
			{
				fp = fopen("SharedHostelDetails.txt", "w");
				temp = shared->next;
				int count = 0;
				while(temp!=NULL && count != shc)
				{
					count++;
					fwrite(temp, sizeof(struct node), 1, fp);
					temp = temp->next;
				}
				fclose(fp);
			}

			if(!isEmpty(inter))
			{
				fp = fopen("InternationalHostelDetails.txt", "w");
				temp = inter->next;
				int count = 0;
				while(temp!=NULL && count != ic)
				{
					count++;
					fwrite(temp, sizeof(struct node), 1, fp);
					temp = temp->next;
				}
				fclose(fp);
			}

			struct queue *qTemp = (struct queue *)malloc(sizeof(struct queue));
			
			if(!isQEmpty(q1))
			{
				fp = fopen("SingleWaitingList.txt", "w");
				qTemp = q1->next;
				int count = 0;
				while(qTemp!=NULL && count!=singlewait)
				{
					count++;
					fwrite(qTemp, sizeof(struct queue), 1, fp);
					qTemp = qTemp->next;
				}
				fclose(fp);
			}

			if(!isQEmpty(q2))
			{
				fp = fopen("SharedWaitingList.txt", "w");
				qTemp = q2->next;
				int count = 0;
				while(qTemp!=NULL && count!=sharewait)
				{
					count++;
					fwrite(qTemp, sizeof(struct queue), 1, fp);
					qTemp = qTemp->next;
				}
				fclose(fp);
			}

			if(!isQEmpty(q3))
			{
				fp = fopen("InternationalWaitingList.txt", "w");
				qTemp = q3->next;
				int count = 0;
				while(qTemp!=NULL && count!=interwait)
				{
					count++;
					fwrite(qTemp, sizeof(struct queue), 1, fp);
					qTemp = qTemp->next;
				}
				fclose(fp);
			}

			printf("\nDataBase updated.\nThanks for using the Hostel Management System.\nHave a nice day!\n");
			break;
		}
		switch (choice)
		{
		case 1:
			printf("\nEnter your name : ");
			scanf("%s", name);
			printf("Enter your father\'s name : ");
			scanf("%s", fname);
			printf("Enter your department : ");
			scanf("%s", dep);
			printf("Enter your year of study : ");
			scanf("%d", &yr);
			printf("Enter your address : ");
			scanf(" %[^\n]s", add);
			printf("Enter your Mobile Number : ");
			scanf("%s", pno);
			printf("Enter the mode of admission (DOTE/MANGEMENT) : ");
			scanf("%s", mod);
			loop:
			printf("Which type of hostel do you want? \n1->Single\n2->Shared\n3->International\nYour Choice : ");
			scanf("%d", &hoschoice);

			switch (hoschoice)
			{
			case 1:
				sc++;
				if (sc <= 2)
				{
					single = insert(single, name, fname, dep, add, pno, yr, "Single", mod, sc);
					printf("\nRoom successfully alloted\nYour Room Number is A-%d\n", sc);
				}
				else
				{
					sc--;
					enqueue(q1, name, fname, dep, yr, add, pno, "Single", mod, sc);
					singlewait++;
				}
				
				if (singlewait > 0)
					printf("\nSorry! We currently don\'t have any vacant Single Rooms. \nCurrent Status : Waiting List #%d\n", singlewait);
				
				break;

			case 2:
				shc++;

				if(count == 2)
				{
					sno++;
					count = 0;
				}
				count++;
				if (shc <= 4)
				{
					shared = insert(shared, name, fname, dep, add, pno, yr, "Shared", mod, sno);
					printf("\nRoom successfully alloted\nYour Room Number is B-%d\n", sno);
				}
				else
				{
					shc--;
					enqueue(q2, name, fname, dep, yr, add, pno, "Shared", mod, shc);
					sharewait++;
				}

				if (sharewait > 0)
					printf("\nSorry! We currently don\'t have any vacant Shared Rooms. \nCurrent Status : Waiting List #%d\n", sharewait);
				break;

			case 3:
				ic++;

				if (ic <= 2)
				{
					inter = insert(inter, name, fname, dep, add, pno, yr, "International", mod, ic);
					printf("\nRoom successfully alloted\nYour Room Number is I-%d\n", ic);
				}
				else
				{
					ic--;
					enqueue(q3, name, fname, dep, yr, add, pno, "International", mod, ic);
					interwait++;
				}

				if (interwait > 0)
					printf("\nSorry! We currently don\'t have any vacant Rooms in the International Hostel. \nCurrent Status : Waiting List #%d\n", interwait);
				break;

			default:
				printf("\nInvalid Hostel type. Operation Terminated.\n");
				goto loop;
			}
			break;

		case 2:
			printf("\nEnter your name : ");
			scanf("%s", sname);
			printf("Enter your father\'s name : ");
			scanf("%s", sfname);
			printf("Enter the type of hostel you are in : \n1->Single\n2->Shared\n3->International\n");
			scanf("%d", &hos);
			if (hos == 1)
				a = search(single, sname, sfname);
			else if (hos == 2)
				a = search(shared, sname, sfname);
			else
				a = search(inter, sname, sfname);
			if (a == 0)
				printf("Student not found");
			break;

		case 3:
			flag = 0;
			if (sc)
			{
				printf("\n------> Single Room Hostel <------\n");
				display(single);
				printf("\n----------------------------------\n");
				flag = 1;
			}
			if (shc)
			{
				printf("\n------> Shared Room Hostel <------\n");
				display(shared);
				printf("\n----------------------------------\n");
				flag = 1;
			}
			if (ic)
			{
				printf("\n-----> International Hostel <-----\n");
				display(inter);
				printf("\n-----------------------------------\n");
				flag = 1;
			}
			if(!flag)
				printf("\nAll the rooms are empty!\n");
			break;

		case 4:
			printf("\nEnter your name : ");
			scanf("%s", dname);
			printf("Enter your father\'s name : ");
			scanf("%s", dfname);
            l:
			printf("Enter the type of hostel you are in : \n1->Single\n2->Shared\n3->International\n");
			scanf("%d", &dhos);

			int del;
			if (dhos == 1)
            {
				del = delete (single, dname, dfname);
				if(del)
					sc--;
            }
			else if (dhos == 2)
            {
				del = delete (shared, dname, dfname);
				if(del)
					shc--;
            }
			else if(dhos == 3)
            {
				del = delete (inter, dname, dfname);
				if(del)
					ic--;
            }
            else
            {
                printf("\nInvalid Hotel Type\n");
                goto l;
            }

			if (del == 0)
				printf("\nYou have not been registered in any of the hostels. \nOperation terminated.\n");
			else if (dhos == 1 && !isQEmpty(q1) && sc<=2)
			{
				q4 = dequeue(q1);
				singlewait--;
				single = insert(single, q4->name, q4->fathername, q4->dept, q4->address, q4->phoneno, q4->year, q4->typeofhostel, q4->mode, del);
				sc++;
				printf("\nWaiting List updated.\n");
			}
			else if(dhos == 2 && !isQEmpty(q2) && shc<=4)
			{
				q4 = dequeue(q2);
				sharewait--;
				shared = insert(shared, q4->name, q4->fathername, q4->dept, q4->address, q4->phoneno, q4->year, q4->typeofhostel, q4->mode, del);
				shc++;
				printf("\nWaiting List updated.\n");
			}
			else if(dhos == 3 && !isQEmpty(q3) && ic<=2)
			{
				q4 = dequeue(q3);
				interwait--;
				inter = insert(inter, q4->name, q4->fathername, q4->dept, q4->address, q4->phoneno, q4->year, q4->typeofhostel, q4->mode, del);
				ic++;
				printf("\nWaiting List updated.\n");
			}

			break;

		case 5:
			if(isQEmpty(q1) && isQEmpty(q2) && isQEmpty(q3))
				printf("\nAll the Waiting Lists are empty.\n");
			else
			{
				if(singlewait)
				{
					printf("\n------> Single Room Waiting List <-------\n");
					displayQ(q1);
					printf("\n-----------------------------------------\n");
				}
				if(sharewait)
				{
					printf("\n------> Shared Room Waiting List <-------\n");
					displayQ(q2);
					printf("\n-----------------------------------------\n");
				}
				if(interwait)
				{
					printf("\n---> International Room Waiting List <---\n");
					displayQ(q3);
					printf("\n-----------------------------------------\n");
				}
			}
			break;

        case 6:
            printf("\nEnter the name of the file : ");
            char fname1[50];
            FILE *fp1;
            scanf("%s", fname);
            fp1 = fopen(fname, "w");

            if (sc)
			{
				fprintf(fp1, "\n------> Single Room Hostel <------\n");
				writeToFile(fp1, single);
				fprintf(fp1, "\n----------------------------------\n");
			}
			if (shc)
			{
				fprintf(fp1, "\n------> Shared Room Hostel <------\n");
				writeToFile(fp1, shared);
				fprintf(fp1, "\n----------------------------------\n");
			}
			if (ic)
			{
				fprintf(fp1, "\n-----> International Hostel <-----\n");
				writeToFile(fp1, inter);
				fprintf(fp1 ,"\n-----------------------------------\n");
			}
            fclose(fp1);
			break;

		case 7:
			printf("\nEnter the name of the file : ");
            char fname2[50];
            FILE *fp2;
            scanf("%s", fname);
            fp2 = fopen(fname, "w");

			
			if(isQEmpty(q1) && isQEmpty(q2) && isQEmpty(q3))
				fprintf(fp2, "\nAll the Waiting Lists are empty.\n");
			else
			{
				if(singlewait)
				{
					fprintf(fp2, "\n---> Single Room Waiting List <---\n");
					writeWaitToFile(fp2, q1);
					fprintf(fp2, "\n----------------------------------\n");
				}
				if(sharewait)
				{
					fprintf(fp2, "\n---> Shared Room Waiting List <---\n");
					writeWaitToFile(fp2, q2);
					fprintf(fp2, "\n----------------------------------\n");
				}
				if(interwait)
				{
					fprintf(fp2, "\n---> Shared Room Waiting List <---\n");
					writeWaitToFile(fp2, q3);
					fprintf(fp2, "\n----------------------------------\n");
				}
			}
			
			fclose(fp2);
			break;


		default:
			printf("\nInvalid Choice. Enter again.\n");
		}
	}
}