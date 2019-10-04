#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct type
{
    char word[50];
    char meaning[50];
    struct type *link;
};
struct type *head=NULL;
struct type *tail=NULL;
struct type *node=NULL;
struct type *ptr=NULL;

void create(char wrd[],char mng[])
{
    node=(struct type*) malloc(sizeof(struct type));
    strcpy(node->word,wrd);
    strcpy(node->meaning,mng);
    node->link=NULL;
    if(head==NULL)
    {
        head=tail=node;
    }
    else
    {
        tail->link=node;
        tail=node;
    }
}

void search()
{
    char item[50];
    printf("\n\nEnter the word for search: ");
    scanf("%s",item);
    strlwr(item);
    printf("Searching is under process");
    waiting();
    ptr=head;
    while(ptr!=NULL)
    {
        if( (strcmp(item,ptr->word))==0)
        {
            printf("\n\nThe meaning of %s is: %s\n",ptr->word,ptr->meaning);
            break;
        }
        else
        {
            ptr=ptr->link;
        }
    }
    if(ptr==NULL)
        printf("\n\nsorry!! Out of dictionary. Please Try Another...\n");

}
void insertion()
{
    int a;
    char loc[50],wordin[30],meaningin [40];
    printf("\n\ndo you want to insert in selecting position?\n\n        YES-1  NO-2_ ");
    scanf("%d",&a);
    if(a==1)
    {
        printf("\nwhere do you want to insert: ");
        scanf("%s",loc);
        strlwr(loc);
        printf("\nenter the word you want to insert: ");
        scanf("%s",wordin);
        strlwr(wordin);
        printf("enter the meaning you want to insert: ");
        scanf("%s",meaningin);
        strlwr(meaningin);
    }
    else if(a==2)
    {
        printf("\nenter the word you want to insert: ");
        scanf("%s",wordin);
        strlwr(wordin);
        printf("enter the meaning you want to insert: ");
        scanf("%s",meaningin);
        strlwr(meaningin);
        printf("\nInserting is under process");
        waiting();
        create( wordin,meaningin);
        return;
    }
    printf("\nInserting is under process");
    waiting();
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(loc,ptr->word)==0)
        {
            struct type *NEW=(struct type*) malloc(sizeof(struct type));

            strcpy(NEW->word,wordin);
            strcpy(NEW->meaning,meaningin);
            NEW->link=ptr->link;
            ptr->link=NEW;
            return;
        }
        else
        {
            ptr=ptr->link;
        }
    }
    if(ptr==NULL)
    {
        printf("\nCan't insert.location not found!!\n");
    }
}
struct type *prev=NULL;
void deletion(char y)
{
    if(y=='A'){
        head=NULL;
        printf("Please wait");
        waiting();
        return;
    }
    char item[50];
    printf("\nenter the word you  want to delete: ");
    scanf("%s",item);
    strlwr(item);
    printf("\nDeleting is under process");
    waiting();
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(item,ptr->word)==0)
        {
            if(prev!=NULL)
            {
                prev->link=ptr->link;
            }
            else
            {
                head=ptr->link;
            }
            break;
        }
        else
        {
            prev=ptr;
            ptr=ptr->link;
        }
    }
    if(ptr==NULL)
        {
            printf("\nCan't delete. word not found!!\n");
        }
}
void update()
{

    char here[50],upw[40],upm[50];
    printf("\nenter the word you  want to update: ");
    scanf("%s",here);
    strlwr(here);
    printf("\nenter the updated word: ");
    scanf("%s",upw);
    strlwr(upw);
    printf("enter the updated meaning: ");
    scanf("%s",upm);
    strlwr(upm);
    printf("\nUpdating is under process");
    waiting();
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(here,ptr->word)==0)
        {
            strcpy(ptr->word,upw);
            strcpy(ptr->meaning,upm);
            printf("\nitem found and update is completed.\n");
            return;
        }
        else
        {
            ptr=ptr->link;
        }
    }
    if(ptr==NULL)
    {
        printf("\nitem not found!\n");
    }
}
void display()
{
    ptr=head;
    if(ptr==NULL)
        printf("List is empty!\n");
    while(ptr!=NULL)
    {
        printf("%20s  -> ",ptr->word);
        printf("  %s\n",ptr->meaning);
        ptr=ptr->link;
    }
}


void displayTitle()
{
    system("cls");
    printf("\n\t\tA Typical Digital dictionary System\n");
    printf("\n\t\tProject Number: 5\n");
    printf("\n\t\tProject Member IDs: \n\n\t\t\t\tShaheduzzaman Shahed(152-15-523)\n\t\t\t\tKhalid Ibrahim(152-15-524)\n\t\t\t\tMd. Shimul Hosen(152-15-538)\n\t\t\t\tSK. Mahadi Hasan Jony(152-15-535)\n");
    printf("\n\t\tAbout Project: Its's a chance to show what we'v learned. We'v tried our best to make a better dictionary. Our group work was great and we satisfied with our group.\n");
    printf("\nUser MENU\n");

    printf("Press  1  to search the meaning.\n");
    printf("Press  2  to insert a word.\n");
    printf("Press  3  to delete a word.\n");
    printf("Press  4  to update a word.\n");
    printf("Press  5  to display all words.\n");
    printf("Press  6  to exit_ ");
}
void waiting()
{
    int i;
    for(i=0; i<100000000; i=i+2)
    {
        if(i%10000000==0)
        {
            printf(".");
        }
    }
}

int main()
{
    create("amazing","wonderful");
    create("angry","furious");
    create("answer","reply");
    create("question","Ask");
    create("bad","harmful");
    create("beautiful","pretty");
    create("begin ","start");
    create("big ","huge");
    create("brave ","fearless");
    create("break","smash");
    create("come","approach");
    create("cool","cold");
    create("cry ","scream");
    create("cut ","slash");
    create("dangerous ","risky");
    create("dark","sunless");
    create("decide","determine");
    create("do ","conclude");
    create("destroy","demolish");
    create("difference ","disagreement");
    create("eager","keen");
    create("end","finish");
    create("fair ","honest");
    create("fall ","drop");
    create("false","drop");
    create("famous","famed");
    create("fast","quick");
    create("fat","pudgy");
    create("funny","laughable");
    create("get","gain");
    create("go","disappear");
    create("good","suitable");
    create("happy","satisfied");
    create("hate","dislike");
    create("help","assist");
    create("hide","cover");
    create("idea","conception");
    create("important","vital");
    create("interest","keen");
    create("keep","preserve");
    create("kill","execute");
    create("lazy","idle");
    create("little","small");
    create("look","see");
    create("love","care_for");
    create("make","create");
    create("move","go");
    create("new","current");
    create("old","used");
    create("part","piece");
    create("place","area");
    create("plan","design");
    create("popular","common");
    create("put","keep");
    create("quiet","soundless");
    create("right","correct");
    create("run","rush");
    create("tell","inform");
    create("show","display");
    create("slow","unhurried");
    create("stop","pause");
    create("story","fable");
    create("strange","odd");
    create("take","hold");
    create("think","assume");
    create("trouble","distress");
    create("true","accurate");
    create("ugly","horrible");
    create("unhappy","sad");
    create("wrong","incorrect");
    create("good","well");
    create("field","open place");

    int operation;
    displayTitle();
    do
    {
        scanf("%d", &operation);
        displayTitle();
        switch(operation)
        {
        case 1:
            printf("\n\nYou have pressed 1.");
            search();
            printf("\nSearch Completed. Proceed to next operation_ ");
            break;
        case 2:
            printf("\n\nYou have pressed 2.\n");
            insertion();
            printf("\n\nInsert Completed. Proceed to next operation_ ");
            break;
        case 3:
            printf("\n\nYou have pressed 3.\nIf you want to delete all list press 'A' Or  delete a single word press 'B' :");
            char ch;
            scanf(" %c",&ch);
            deletion(ch);
            printf("\n\nDeletion Completed. Proceed to next operation_ ");
            break;
        case 4:
            printf("\n\nYou have pressed 4.\n");
            update();
            printf("\n\nUpdating Completed. Proceed to next operation_ ");
            break;
        case 5:
            printf("\n\nYou have pressed 5. Displaying is under process");
            waiting();
            printf("\n\n");
            display();
            printf("\nCompleted. Proceed to next operation_ ");
            break;
        case 6:
            printf("\n\n               THANK YOU FOR USING DIU DICTIONARY");
            waiting();
            printf("\n\n");
        }
    }
    while(operation != 6);

    return 0;
}
