#include<stdio.h>
#include<string.h>//to use string data smoothly
///this is a struct
struct shop{
    int id;
    int item;
    int total;
    int a[10];
    int choose;

}add;
int rice=60,oil=90,ice=15,choco=5,bis=20;//setting price
char name[10][50]={"Rice","Oil","Ice-cream","Chocolate","Biscuit"};///2D Array
 int r=0,oi=0,ic=0,cho=0,bi=0;//value initialization
void insert_data();//function 2 prototype
void show_data();//function 3 prototype
void del_data();//function 4 prototype
void finish();//function 5 prototype

int main(){ ///main function
while(1){//to run loop again and again
again:
    printf("\n\t\t\t\tSHOP Management System\n");
    printf("\n 1.Buy Product\n 2.Show Reciept\n 3.Delete Record\n Enter:");
    scanf("%d",&add.choose);//to perform project work as user choice
    ///Nested
    if(add.choose==1){//when user choose option 1
        insert_data();//Calling function 1
    }else if(add.choose==2){
         show_data();//Calling function 2
    }else if(add.choose==3){
        del_data();//Calling function 3
    }else{//when option is out of range it will run.
        printf("\nInvalid!\n");
        goto again;//to go back to again(line 23)
    }

}
    return 0;//end of main function
}
void insert_data(){///function 2 to insert data
    system("cls");//clears older data for a cleared new screen
    FILE *file;//to Declare FILE named 'file' using file pointer
    file=fopen("sinja.txt","a");//to open a text FILE  Which is able to append
    int i;
    add.item=5;//we took 5 items
    printf("\n\t\t\tBuy Product\n\n");
    printf("\t---------------------------------------\n");
    printf("\t|    Product        | price(kg/pieces)|\n");
    printf("\t---------------------------------------\n");
    printf("\t|         Rice        |    %d         |\n",rice);
    printf("\t|         Oil         |    %d         |\n",oil);
    printf("\t|       ice-cream     |    %d         |\n",ice);
    printf("\t|       Chocolate     |    %d          |\n", choco);
    printf("\t|         biscuit     |    %d         |\n",bis);
    printf("\t---------------------------------------\n");

    printf("Enter your id:");
    scanf("%d",&add.id);//to take an identity from user using id number
    printf("Please Enter (kg/price):\n");
    for(i=0;i<add.item;i++){ ///for loop
        printf("%s : ",name[i]);//print all char items sequentially
        getchar();//to avoid conflict between int and string data
        scanf("%d",&add.a[i]);//to take quantity of specific items
    }
/*calculation part to find out cost*/
    r=r+60*add.a[0];
    oi=oi+90*add.a[1];
    ic=ic+15*add.a[2];
    cho=cho+5*add.a[3];
    bi=bi+20*add.a[4];
    add.total=r+oi+ic+cho+bi;
    fprintf(file,"%d\t%d\t%d\t%d\t%d\t%d\t%d\n",add.id,r,oi,ic,cho,bi,add.total);
    fclose(file);//to close FILE named 'file'
    printf("save successfully\n");
    finish();//Calling finish Function

}

void show_data(){///function 3 to view receipt
    system("cls");
    FILE *view;//new file declaration
    view=fopen("sinja.txt","r");//to open "view" FILE which is only readable
    printf("\n\t\t\tShow Receipt\n\n");
    while(fscanf(view,"%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&add.id,&r,&oi,&ic,&cho,&bi,&add.total)!=EOF){

    printf("\t-----------------------------------------------------\n");
    printf("\t| Product         | kg/pics |        price           |\n");
    printf("\t-----------------------------------------------------\n");
    printf("\t|   %s           |   %d    |           %d          | \n",name[0],r/60,r);
    printf("\t|    %s           |   %d    |           %d          | \n",name[1],oi/90,oi);
    printf("\t|   %s      |   %d    |           %d           | \n",name[2],ic/15,ic);
    printf("\t|   %s      |   %d    |           %d           | \n",name[3],cho/5,cho);
    printf("\t|   %s        |   %d    |           %d          | \n",name[4],bi/20,bi);
    printf("\t-----------------------------------------------------\n");
    printf("\t|    Total                  |           %d          | \n",add.total);
    printf("\t-----------------------------------------------------\n");

    }
    fclose(view);//to close FILE

}
void del_data(){///function 4 to delete any receipt
    system("cls");
    FILE *NEW,*old;
    old=fopen("sinja.txt","r");//open previous created readable text file through 'old' file
    NEW=fopen("new.txt","w");//to open writable new text File
    printf("\n\t\t\tDelete Receipt\n\n");
    int id;
    int count=0;
    printf("Enter for remove id:");
    scanf("%d",&id);

    ///Nested loop
    while(fscanf(old,"%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&add.id,&r,&oi,&ic,&cho,&bi,&add.total)!=EOF){
        if(id!=add.id){
            fprintf(NEW,"%d\t%d\t%d\t%d\t%d\t%d\t%d\n",add.id,r,oi,ic,cho,bi,add.total);
        }else{
            count++;//to skip matched id's data or delete data
            printf("\n\nRecord delete Successfully !\n");

        }
    }
    fclose(old);
    fclose(NEW);
    remove("sinja.txt");//to remove the old text file
    rename("new.txt","sinja.txt");//to rename newly created text file as old one
    finish();//Calling function finish

}
void finish(){ ///function 5 to appreciate user

        printf("\n\n\t\tThank you\n");
}
