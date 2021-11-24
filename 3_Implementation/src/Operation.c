#include<stdio.h>
#include<string.h>

#define ESC27
#define F1 59
#define F2 60

void signup(void);
void login(void);

struct{
    char password[20];
    char username[20];
}s;

FILE *fp;
void main()
{
    int ch;
    while(1)
    {
        clrscr();
        gotoxy(20,5);
        printf("---------------Larsen & Tubro---------------");
        gotoxy(28,7);
        printf("-----Welcome to L&T Technology Services-----");
        gotoxy(28,9);
        printf("Press F1 For Login");
        goto(28,11);
        printf("Press F2 For Signup");
        goto(28,13);
        printf("Press ESC For Exit");
        goto(28,15);
        printf("------------*_*_*_*_*_*_*_*----------");
        getch();
        ch = getch();
        switch (ch)
        {
        case F1:
            clrscr();
            gotoxy(10,14);
            for(int i=0;i<40;i++)
            {
                printf("_");
                delay(40);
            }
        login();
        break;
        case F2:
            clrscr();
            gotoxy(10,14);
            for(int i=0;i<40;i++)
            {
                printf("_");
                delay(40);
            }
        signup();
        break;
        case ESC:
            exit(0);
            break;
        }
    }/* While */
    getch();
        
    
}

void login()
{
    int c;
    char username[20];
    char pass[20];
    char chkp;

    clrscr();
    gotoxy(23,5);
    printf("---------------Login---------------");
    gotoxy(23,7);

    fp=fopen("record.bin","rb");

    printf("Enter UserName        :");
    gets(username);
    gotoxy(23,9);
    printf("Enter Password       :");

    for(int i=0;c=getch()!=13;i++)
    {
        pass[i]=c;
        printf("*");
    }
    pass[i]="\0";

    while (!feof(fp))
    {
        fread(&s,sizeof(s),1,fp);

        chku=strcmp(username,s.username);
        chkp=strcmp(pass,s.password);

        if(chku==0&&chkp!=0)
        {
            printf("Invalid Password........");
            break;
        }
        else if(chku!=0&&chkp==0)
        {
            printf("\n\tInvalid Username........");
            break;
        }
        else if(chku==0&&chkp==0)
        {
            clrscr();
            gotoxy(20,10);
            printf("-----Hello %s Welcome Here-----",s.username);
            break;
        }

    }
    
    getch();

}

void signup();
{
    char c;
    fp=fopen("record.bin","ab");
    clrscr();
    gotoxy(23,5);
    printf("---------------SignUp---------------");
    gotoxy(23,7);
    printf("Set UserName      : ");
    gets(s.username);

    gotoxy(23,9);
    printf("Set Password       :  ");
        for(i=0;c=getche()!=13;i++)
        {
            s.password[i]=c;
        }
    gotoxy(23,11);
    printf("Press Enter to continue...........");
        if(getch()==13)
        {
            fwrite(&s,sizeof(s),1,fp);
            gotoxy(23,13);
            cprintf("\n Information Saved.....");
        
        }
        else
        retrun;
    fclose(fp);

    getch();
}

