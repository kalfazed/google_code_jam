#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

const char* search_engine[10] = {
    "google",
    "baidu",
    "souhu",
    "yahoo",
    "goo",
    "bing",
    "NSN",
    "B9",
    "DontASK",
    "Yeehow"
};

int main(){
    int num_of_case;
    int num_of_engine;
    int* num_of_query;
    int i,j;
    int random_query;

    FILE *f = fopen("file.txt","w");
    if (f == NULL)
    {
        fprintf(stderr, "Error to open the file\n",NULL);
        exit(1);
    }

    const char* string = "This is the test of google code jam";
    fprintf(f,"%s\n", string);

    fprintf(stderr, "Input the num of test_engine:\n",NULL);
    scanf("%d",&num_of_engine);

    fprintf(stderr, "Input the case of test:\n",NULL);
    scanf("%d",&num_of_case);
    fprintf(f,"Input\n",NULL);
    fprintf(f,"%d\n",num_of_case);

    num_of_query = (int *)malloc(num_of_case*sizeof(int));
    for(i=0; i<num_of_case; i++){
        fprintf(stderr, "Input the num of queries for case %d:\n",i+1);
        scanf("%d",&num_of_query[i]);

        fprintf(f,"%d\n",num_of_engine);
        for(j=0; j<num_of_engine; j++)
            fprintf(f, "%s\n",search_engine[j]);

        fprintf(f, "%d\n",num_of_query[i]);
        srand(time(NULL));
        for(j=0; j<num_of_query[i]; j++){
            random_query = rand() % num_of_engine;
            fprintf(f,"%s\n",search_engine[random_query]);
        }
    }

    fclose(f);
    return 0;
}


