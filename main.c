#include <stdio.h>
#include <stdlib.h>
#include <string.h> // se tiver tempo tirar essa lib pois so é usada no nome do arquivoa até o momento

void display_menu(){
    printf("==Escolha uma opcao ==\n\n");
    printf("1. Criar Json\n");
    printf("2. Visualizar Jsons\n");
    printf("3. Atualizar Json\n");
    printf("4. Remover Json\n");
}

char * setPath(char * fileName){
    char filePath[] = "files/";
    fileName = strcat(filePath, fileName);
    return fileName;
}

void create_file(){
    char filename[50];
    FILE *fptr;
    scanf("%s", filename);
    
    fptr = fopen(filename,"w");
        
    char * field = (char *) malloc(1000*sizeof(char));
    char * value =  (char *) malloc(1000*sizeof(char));
    char * result =  (char *) malloc(1000*sizeof(char));
    char * data = malloc(1);

    while(1){
    
    printf("if u want to stop type: no\n");
    printf("field: ");
    scanf("%s", field);
    if(strcmp(field, "no") == 0){
        break;
    }
    printf("value: ");
    scanf("%s", value);

    result = strcat(field, ":");
    result = strcat(result, value);

    realloc(data, strlen(data) + strlen(result));
    data = strcat(data,result);
    }
    fputs(data, fptr);
}

int handle_options(){
    int option;
    scanf("%d", &option);
    switch(option){
        case 1:
        create_file();
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        default:
        return 1;
    }
    return 0;
}

void initial_menu(){

    display_menu();

    while(handle_options()){
        printf("Invalid choice");
        handle_options();
    }
}

int main(void){
  
    initial_menu();

}

