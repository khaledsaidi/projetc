#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "troupeau.h"
 


void ajouter(troupeau o)
{
FILE *f=NULL;

f=fopen("users.txt","a+");

if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %d\n",o.dater,o.id,o.type,o.daten,o.sexe,o.lm);
fclose(f);
}


else 
{printf("\n Erreur : Non trouvé");}

}






void supprimer(char*id){
FILE*f=NULL;
FILE*f1=NULL;
troupeau o ;
f=fopen("users.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f,"%s %s %s %s %s %d\n",o.dater ,o.id ,o.type ,o.daten ,o.sexe ,&o.lm)!=EOF){
if(strcmp(id,o.id)!=0) 
fprintf(f1,"%s %s %s %s %s %d\n",o.dater ,o.id ,o.type ,o.daten ,o.sexe ,o.lm);
}
fclose(f);
fclose(f1);
remove("users.txt");
rename("ancien.txt","users.txt");
}






void modifier(troupeau ov, char*dater ){
FILE*f=fopen("users.txt","r");
FILE*f1=fopen("ancieni.txt","w+");
troupeau o;
while(fscanf(f,"%s %s %s %s %s %d\n",o.dater ,o.id ,o.type ,o.daten ,o.sexe ,&o.lm)!=EOF)
{
if(strcmp(o.dater,dater)==0)
{
fprintf(f1,"%s %s %s %s %s %d\n",dater,ov.id,ov.type,ov.daten,ov.sexe,ov.lm);
}
else{
fprintf(f1,"%s %s %s %s %s %d\n",o.dater ,o.id ,o.type ,o.daten ,o.sexe ,o.lm);
}
}
fclose(f);
fclose(f1);
remove("users.txt");
rename("ancieni.txt","users.txt");
}


int exist(char*id){
FILE*f=NULL;
troupeau o;
f=fopen("users.txt","r");
while(fscanf(f,"%s %s %s %s %s %d\n",o.dater,o.id,o.type,o.daten,o.sexe,&o.lm)!=EOF)
{
	if(strcmp(o.id,id)==0)
	return 1;
}
fclose(f);
return 0;
}








