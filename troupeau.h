#include<gtk/gtk.h>
#ifndef OUVRIERS_H_
#define OUVRIERS_H_
typedef struct 
{char dater [20] ;
char id [20] ;
char type [20] ;
char daten [20] ;
char sexe [20] ; 
int lm ;
}troupeau;

void ajouter(troupeau o) ;
int exist(char*id) ;
void supprimer(char*id) ;
void modifier(troupeau ov, char*id );
#endif
