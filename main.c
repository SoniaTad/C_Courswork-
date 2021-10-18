#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE*fp;

typedef struct movie 
{
    char title[30];
    int year;
    char lead_actor[30];
    char lead_actress[30];
    char director[30] ;
    char producer[30];
    char Plot[300];
} movie;
typedef struct nodes
 {
    struct nodes* prev;
    movie movie;
    char title[30];
    int year;
    char lead_actor[30];
    char lead_actress[30];
    char director[30] ;
    char producer[30];
    char Plot[300];
    struct nodes* next;
 }NODE;

struct nodes* new_node;
struct nodes* last;
struct nodes *head;
struct nodes *temp2;
struct nodes*node_to_delete;
struct nodes*current_node;

void create()
{
    char title[30];
    int year;
    char lead_actor[30];
    char lead_actress[30];
    char director[30];
    char producer [30];
    char plot[300];

   //allocating memory
    new_node = (struct nodes*)malloc(sizeof(struct nodes));

    printf("Enter title: ");
    scanf(" %[^\n]s",title);
    printf("%s\n", title);

    printf ("Enter year: ");
    scanf("%d",&year);
    printf("%d\n",year);

    printf("Add lead actor: ");
    scanf(" %[^\n]s",lead_actor);
    printf("%s\n", lead_actor);

    printf("Add a lead_actress: ");
    scanf(" %[^\n]s",lead_actress);
    printf("%s\n",lead_actress);

    printf("Add the director: ");
    scanf(" %[^\n]s",director);
    printf("%s\n",director);

    printf("Add the producer: ");
    scanf(" %[^\n]s",producer);
    printf("%s\n",producer);

    printf("Add the plot of the movie: ");
    scanf(" %[^\n]s",plot);
    printf(" %s\n",plot);
   
    new_node->prev=NULL;
    new_node->next= NULL;

    strcpy(new_node->movie.title, title);
    new_node->movie.year =year ;
    strcpy(new_node->movie.lead_actor, lead_actor);
    strcpy(new_node->movie.lead_actress, lead_actress);
    strcpy(new_node->movie.director , director);
    strcpy(new_node ->movie.producer , producer);
    strcpy(new_node->movie.Plot , plot);

};
void insert()
{
    // If DLL is empty
    if (head == NULL) {
        create();
        head = new_node;
        last = new_node;
        head=last;
    }

    // Else create a new node and
    // update the links
    else {
        create();
        last->next = new_node;
        new_node->prev = last;
        last = new_node;
        new_node=last;
    }
}
void  display() {
  fp=fopen("Movies.txt","w+");

    if (head == NULL) 
    {
        printf("the  list is empty\n");
    }
    else
     {

        printf(" the movie list is:\n");

        
        for  (temp2=head; (temp2!= NULL); (temp2 = temp2->next))
        {
            printf("movie\n{.title=%s\n,.year=%d\n,.Lead_actor=%s\n,.Lead_actress=%s\n,.Director=%s\n,.Producer=%s\n,.plot=%s\n",temp2->movie.title,temp2->movie.year,temp2->movie.lead_actor ,temp2->movie.lead_actress,temp2->movie.director,temp2->movie.producer,temp2->movie.Plot);
        }

        for  (temp2=head; (temp2!= NULL); (temp2 = temp2->next)) 
        {
            fprintf(fp,"movie\n{.title=%s\n,.year=%d\n,.Lead_actor=%s\n,.Lead_actress=%s\n,.Director=%s\n,.Producer=%s\n,.plot=%s\n",temp2->movie.title,temp2->movie.year,temp2->movie.lead_actor ,temp2->movie.lead_actress,temp2->movie.director,temp2->movie.producer,temp2->movie.Plot);
            printf("***********************************\n");

        }
        fclose(fp);
    }
}


void delete_end_node()
{

    struct nodes * node_to_delete;

    if(last==NULL)
   {
        printf("the list is empty\n ");
    }
    else
   {
        node_to_delete=last;
        last->prev->next=NULL;
        last=last->prev;
        free(node_to_delete);
    }
}

void deletebeg()
{
    struct nodes* current_node;

    current_node = head;

    if (current_node == NULL) 
    {
        printf("list is empty\n");

    }
    if (current_node->next == NULL) 
    {

        free(current_node);
        head = NULL;
    }
    else 
    {
        head = head->next;
        head->prev = NULL;
        free(current_node);
    }
}





void del_spc_node(int npos)
{
    struct nodes*current_node;

    int node_ctr;

    current_node=head;

  for ((node_ctr=1); (node_ctr<npos)&&(current_node!=NULL); node_ctr++)
    {
        current_node=current_node->next;
    }
    if (npos==1)
    {
        deletebeg();
    }
    else if(current_node==last)
    {
        delete_end_node();
    }
    else if (current_node!=NULL)
    {
        current_node->prev->next=current_node->next;
        current_node->next->prev=current_node->prev;
        free(current_node);
    }
    else {
        printf("invalid node  postion entered\n");
    }
}
void search()
 {
    int year;

    printf("enter the year of the movie:");
    scanf(" %d",&year);

    for (current_node=head; (current_node!=NULL); (current_node=current_node->next))
    {
        if  (current_node->movie.year==year) 
        {
            printf("movie found\n");

            printf("movie\n{.title=%s\n,.year=%d\n,.Lead_actor=%s\n,.Lead_actress=%s\n,.Director=%s\n,.Producer=%s\n,.plot=%s\n",current_node->movie.title,current_node->movie.year,current_node->movie.lead_actor ,current_node->movie.lead_actress,current_node->movie.director,current_node->movie.producer,current_node->movie.Plot);
        }
        else if (current_node->movie.year!=year) 
        {
            printf("this is a movie from a  diffrent year\n");
        }
    }
    int c;
    printf("would you like to save the search?(0|1)?");
    scanf(" %d",&c);

    if(c==1)
     {
        FILE*FP;
        FP=fopen("filtred_search.txt","w+");

        for (current_node=head; (current_node!=NULL); (current_node=current_node->next))
         {
            if(current_node->movie.year==year)
             {
                printf("movie\n{.title=%s\n,.year=%d\n,.Lead_actor=%s\n,.Lead_actress=%s\n,.Director=%s\n,.Producer=%s\n,.plot=%s\n",current_node->movie.title,current_node->movie.year,current_node->movie.lead_actor ,current_node->movie.lead_actress,current_node->movie.director,current_node->movie.producer,current_node->movie.Plot);
            }
        }
        for (current_node=head; (current_node!=NULL); (current_node=current_node->next))
         {
            if(current_node->movie.year==year) 
            {
                fprintf(FP ,"movie\n{.title=%s\n,.year=%d\n,.Lead_actor=%s\n,.Lead_actress=%s\n,.Director=%s\n,.Producer=%s\n,.plot=%s\n",current_node->movie.title,current_node->movie.year,current_node->movie.lead_actor ,current_node->movie.lead_actress,current_node->movie.director,current_node->movie.producer,current_node->movie.Plot);
            }
        }

        fclose(FP);
    }
    else if(c==0)
   {
        printf("search not saved\n");
    }


}

    

int main(void) 
{
    FILE *fp = fopen("Movies.txt", "w+");

    if (!fp)
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    int choice;
    int i;

    printf ("welcome to the main menu\n");
    printf("**********************\n");
    printf("please select one of those\n ");
    printf("1.list of my movies\n");
    printf("2.Add a new  movie to the list\n ");
    printf("3.Delete an existent movie from the list\n");
    printf("4.Search movie by year\n ");
    printf("5.EXIT \n");
    printf("**********************\n");

    do
   {
        printf("enter your choice:");
        scanf(" %d",&choice);
        switch(choice)
        {
        case(1): {
            printf("the movie list is \n");
            printf(" the number of movies is 5\n");

            for (i = 1; i < 6; i++) {
                insert();
            }
            display();

            for  (temp2=head; (temp2!= NULL); (temp2 = temp2->next))
             {

                fscanf(fp ,"movie{.title=%s\n,.year=%d\n,.Lead_actor=%s\n,.Lead_actress=%s\n,.Director=%s\n,.Producer=%s\n,.plot=%s\n", temp2->movie.title, 
                 &temp2->movie.year,temp2->movie.lead_actor ,temp2->movie.lead_actress,temp2->movie.director,temp2->movie.producer,temp2->movie.Plot);
            }
            for  (temp2=head; (temp2!= NULL); (temp2 = temp2->next))
            {
                printf("movie\n{.title=%s\n,.year=%d\n,.Lead_actor=%s\n,.Lead_actress=%s\n,.Director=%s\n,.Producer=%s\n,.plot=%s\n",temp2->movie.title,temp2->movie.year,temp2->movie.lead_actor ,temp2->movie.lead_actress,temp2->movie.director,temp2->movie.producer,temp2->movie.Plot);
            }

            break;
        }
       case(2): 
       {
            printf("adding a movie to the list\n");

            insert();
            display();

            for  (temp2=head; (temp2!= NULL); (temp2 = temp2->next))
             {
                fscanf(fp ,"movie{.title=%s\n,.year=%d\n,.Lead_actor=%s\n,.Lead_actress=%s\n,.Director=%s\n,.Producer=%s\n,.plot=%s\n",temp2->movie.title,
                 &temp2->movie.year,temp2->movie.lead_actor ,temp2->movie.lead_actress,temp2->movie.director,temp2->movie.producer,temp2->movie.Plot);
            }
            for  (temp2=head; (temp2!= NULL); (temp2 = temp2->next))
            {
                printf("movie\n{.title=%s\n,.year=%d\n,.Lead_actor=%s\n,.Lead_actress=%s\n,.Director=%s\n,.Producer=%s\n,.plot=%s\n",temp2->movie.title,temp2->movie.year,temp2->movie.lead_actor ,temp2->movie.lead_actress,temp2->movie.director,temp2->movie.producer,temp2->movie.Plot);
            }

            break;
        }
       case(3): {
            
            printf("which movie would you like to delete:");
            int npos=i;
            
            scanf("%d",&npos);
            printf("Movie in position %d\n",npos);

            del_spc_node( npos);
            display();
            
            for  (temp2=head; (temp2!= NULL); (temp2 = temp2->next))
             {
                fscanf(fp ,"movie{.title=%s\n,.year=%d\n,.Lead_actor=%s\n,.Lead_actress=%s\n,.Director=%s\n,.Producer=%s\n,.plot=%s\n", temp2->movie.title,   
                &temp2->movie.year,temp2->movie.lead_actor ,temp2->movie.lead_actress,temp2->movie.director,temp2->movie.producer,temp2->movie.Plot);
            }
            for  (temp2=head; (temp2!= NULL); (temp2 = temp2->next))
            {
                printf("movie\n{.title=%s\n,.year=%d\n,.Lead_actor=%s\n,.Lead_actress=%s\n,.Director=%s\n,.Producer=%s\n,.plot=%s\n",temp2->movie.title,temp2->movie.year,temp2->movie.lead_actor ,temp2->movie.lead_actress,temp2->movie.director,temp2->movie.producer,temp2->movie.Plot);
            }

          
            fclose(fp);

            break;
        }
       case(4): {

          search();

            break;
        }
       case(5):
         {
            exit(0);

            break;
         }

        }
    }

    while((choice>=1)&&(choice<6));

    printf("error\n");

    return 0;
}


