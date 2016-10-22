#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#define MAX 50


int initializerList(EMovie* movies, int length)
{
    int i;
        for(i=0; i<length; i++)
            movies[i].isEmpty = 1;

    return 0;
}


void addMovie(EMovie* movies,int lenght)
{
    int indice;
    char aux[500];

    indice=getFreeSpace(movies, lenght);//Busca el primer espacio libre del array.
    if(indice!=-1)//Si encuentra un espacio, permite el ingreso.
    {
        printf("Ingrese el titulo de la pelicula: ");
        gets(aux);
        strcpy(movies[indice].titulo,aux);
        printf("Ingrese el genero de la pelicula: ");
        gets(aux);
        strcpy(movies[indice].genero,aux);
        printf("Ingrese la descripcion de la pelicula: ");
        gets(aux);
        strcpy(movies[indice].descripcion,aux);
        printf("Ingrese el link de la pelicula: ");
        gets(aux);
        strcpy(movies[indice].linkImagen,aux);
        printf("Ingrese puntaje del 1 al 10: ");
        movies[indice].puntaje = getInt(0,10);//Verifica que el numero sea un entero de rango 0 a 10
        printf("Ingrese duracion en minutos: ");
        movies[indice].duracion = getInt(0,500);//Verifica que el numero sea un entero de rango 0 a 500
        system("cls");
        movies[indice].isEmpty = 0;
    }
    else//Si no encuentra un espacio avisa.
    {
        printf("No puede ingresar mas peliculas");
        getch();
    }
}


void deleteMovie(EMovie* movie,int lenght)
{
    char aux[50];
    int flag=0,i;
    char opcion;

    printf("Ingrese el titulo de la pelicula que desea borrar: ");
    fflush(stdin);
    gets(aux);
    for(i=0; i<lenght; i++)//Recorre el array de peliculas
    {
        if((strcmp(aux,movie[i].titulo)==0) && movie[i].isEmpty==0)//Si encuentra la pelicula y no esta dada de baja permite borrala.
        {
            printf("Pelicula encontrada, sus datos son:\n\n");
            showMovie(movie+i);
            printf("\nSeguro desea dar de baja S/N ?: ");
            opcion = tolower(getche());//Toma el caracter ingresado y lo conviernes a minuscula.
            if(opcion=='s')
            {
                movie[i].isEmpty=-1;//Da la baja logica
                printf("\n\n­­Registro eliminado!!\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("\n\nEl registro no fue eliminado!\n\n");
                system("pause");
                system("cls");
            }
            flag=1;
            break;
        }//Cierre del if
    }//Cierre del for
    if(flag==0)//Avisa si no la encuentra
    {
        printf("\n\nPelicula inexistente\n\n");
        system("pause");
        system("cls");
    }
}


void modifyMovie(EMovie* movie,int lenght)
{
    char aux[50];
    int flag=0,i, opcion;
    char seguir='s';
    int puntaje, duracion;

    system("cls");
    printf("Ingrese el titulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(aux);
    for(i=0; i<lenght; i++)//Recorre el array de peliculas
    {
        if((strcmp(aux,movie[i].titulo)==0) && movie[i].isEmpty==0)//Si encuentra la pelicula y no esta dada de baja permite modificarla.
        {
            printf("Datos de pelicula a ser modificados:\n\n");
            showMovie(movie+i);
            do
            {
                opcion = printMenu("\nOpciones: \n1-Genero\n2-Descripcion\n3-Puntuacion\n4-Duracion\n6-Salir\n");
                switch(opcion)
                {
                case 1:
                    printf("Ingrese el nuevo genero de la pelicula: ");
                    fflush(stdin);
                    gets(movie[i].genero);
                    break;
                case 2:
                    printf("Ingrese la nueva descripcion de la pelicula: ");
                    fflush(stdin);
                    gets(movie[i].descripcion);
                    break;
                case 3:
                    printf("Ingrese puntaje nuevo: ");
                    scanf("%d", &puntaje);
                    movie[i].puntaje=puntaje;
                    break;
                case 4:
                    printf("Ingrese nueva duracion: ");
                    scanf("%d", &duracion);
                    movie[i].duracion=duracion;
                    break;
                case 5:
                    seguir = 'n';
                    break;
                }//Cierre del Switch
            }//Cierre del do
            while(seguir == 's');
        }//Cierre del if
    }//Cierre del for

    if(flag==0)//Avisa si no la encuentra
    {
        printf("Pelicula inexistente\n\n");
        system("pause");
        system("cls");
    }
}


void createHTML(EMovie *movie, int lenght)
{
    int longi,i;
    char lineStr[100];
    char salida[50];

    printf("Ingrese el nombre del archivo de salida: ");//Pide el dato.
    fflush(stdin);
    gets(salida);//Toma el dato.
    strcat(salida,".html");
    FILE* source = fopen("index.html", "r"); // Realiza una copia del contenido de index y lo guarda en
    FILE* dest = fopen(salida, "w");         // el archivo de salida que se tomo.
    while(fgets(lineStr,100,source)!=NULL)
    {
        longi = strlen(lineStr);
        fwrite(lineStr, sizeof(char), longi, dest);
    }
    fclose(source);
    for(i=0; i<lenght; i++)//Recorre el array de peliculas.
    {
        if(movie[i].isEmpty == 0)//Ingresa si ella pelicula existe.
        {
            fwrite("<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='",sizeof(char),97,dest );
            longi = strlen(movie[i].linkImagen);
            fwrite(movie[i].linkImagen,sizeof(char),longi,dest );
            fflush(stdin);
            fwrite("' alt=''></a><h3><a href='#'>",sizeof(char),29,dest );
            longi = strlen(movie[i].titulo);
            fwrite(movie[i].titulo,sizeof(char),longi,dest );
            fwrite("</a></h3><ul><li>Genero:",sizeof(char),24,dest );
            longi = strlen(movie[i].genero);
            fwrite(movie[i].genero,sizeof(char),longi,dest );
            fwrite("</li><li>",sizeof(char),9,dest );
            fprintf(dest,"%d",movie[i].puntaje );
            fwrite("</li><li>",sizeof(char),9,dest );
            fprintf(dest,"%d",movie[i].duracion );
            fwrite("</li></ul><p>",sizeof(char),13,dest );
            longi = strlen(movie[i].descripcion);
            fwrite(movie[i].descripcion,sizeof(char),longi,dest );
            fwrite("</p></article>",sizeof(char),14,dest );
        }
    }
    fclose(dest);
    printf("\nArchivo %s creado!\n\n\n",salida);
    system("PAUSE");
    system("cls");
}


int printMenu(char *menu)//Imprime un menu con opcion para el switch
{
    int opcion;
    printf("%s",menu);
    printf("\n Eliga una opcion : ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}


void showMovie(EMovie* movie)//Lista los datos de una pelicula.
{
    printf("Titulo: %s\nGenero: %s\nDescripcion: %s\nPuntuacion: %d\nDuracion: %d\n",
           movie->titulo,
           movie->genero,
           movie->descripcion,
           movie->puntaje,
           movie->duracion);
}


int getFreeSpace(EMovie* movie, int lenght)//Obtengo un espacio libre
{
    int i;
    int indice=-1;
    for(i=0; i<lenght; i++)
    {
        if(movie[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int getInt(int minimo, int maximo)//Valida un entero y su rango
{
    int number, aux;
    fflush(stdin);
    aux=scanf("%d", &number);
    while(aux != 1 || (aux==1 && (number < minimo || number > maximo)))
    {
        if(aux==0)
        {
            fflush(stdin);
            printf("El numero ingresado posee caracteres incorrectos. Reingrese uno valido (%d-%d): ",minimo,maximo);
            aux=scanf("%d",&number);
        }
        else
        {
            fflush(stdin);
            printf("El numero ingresado esta fuera de rango. Reingrese uno valido(%d-%d): ",minimo,maximo);
            aux=scanf("%d",&number);
        }
    }
    return number;
}

