#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "troupeau.h"
#include "tree.h"

void
on_gestionouvrier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{


}


void
on_ajouteri_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget  *entrydater, *entryid, *entrytype, *entrydaten, *entrylm, *entrysexe, *DATER, *ID, *TYPE, *DATEN ,*success , *fail , *p ,*p2 ,*p3; 

troupeau o ;
p=lookup_widget(button,"treeviewi1");
p3=lookup_widget(button,"treeviewi2");

entrydater=lookup_widget(button,"entrydateri");
entryid=lookup_widget(button,"entryidi");
entrytype=lookup_widget(button,"entrytypei");
entrydaten=lookup_widget(button,"entrydateni");
entrylm=lookup_widget(button,"spinbutton");
entrysexe=lookup_widget(button,"comboboxsexe");




DATER=lookup_widget(button,"dateri");
ID=lookup_widget(button,"idi");
TYPE=lookup_widget(button,"typei");
DATEN=lookup_widget(button,"dateni");
fail=lookup_widget(button,"labelexiste");
success=lookup_widget(button,"label11");



strcpy(o.dater, gtk_entry_get_text(GTK_ENTRY(entrydater)));
strcpy(o.id, gtk_entry_get_text(GTK_ENTRY(entryid)));
strcpy(o.type, gtk_entry_get_text(GTK_ENTRY(entrytype)));
strcpy(o.daten, gtk_entry_get_text(GTK_ENTRY(entrydaten)));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrysexe)));
o.lm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entrylm));


if(strcmp(o.dater,"")==0){
gtk_widget_show(DATER);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(DATER,FALSE);
gtk_widget_set_visible(success,FALSE);

}
if(strcmp(o.id,"")==0){
gtk_widget_show(ID);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(ID,FALSE);
gtk_widget_set_visible(success,FALSE);

}

if(strcmp(o.type,"")==0){
gtk_widget_show(TYPE);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(TYPE,FALSE);
gtk_widget_set_visible(success,FALSE);
}

if(strcmp(o.daten,"")==0){
gtk_widget_show(DATEN);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(DATEN,FALSE);
gtk_widget_set_visible(success,FALSE);

}
if(gtk_widget_get_visible(DATER)==FALSE && gtk_widget_get_visible(ID)==FALSE && gtk_widget_get_visible(TYPE)==FALSE && gtk_widget_get_visible(DATEN)==FALSE){
         if(exist(o.id)==1){
	gtk_widget_set_visible(success,FALSE);
	gtk_widget_show(fail);
        Affichertroupeau (p,"users.txt");
        Affichertroupeau1(p3,"users.txt");
}
       

 else {

	
         ajouter(o);

	gtk_widget_set_visible(fail,FALSE);
	gtk_widget_show(success);


	gtk_entry_set_text(GTK_ENTRY(entrydater),"");
	gtk_entry_set_text(GTK_ENTRY(entryid),"");
	gtk_entry_set_text(GTK_ENTRY(entrytype),"");
        gtk_entry_set_text(GTK_ENTRY(entrydaten),"");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(entrylm),500);


       p2=lookup_widget(button,"treeviewi1");
	Affichertroupeau(p2,"users.txt");
        Affichertroupeau1(p3,"users.txt");}
}
	
	

	
	
}


void
on_modifieri_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeviewi_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


}


void
on_supprimeri_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{



}






void
on_modifieri1_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        gchar* dater;
GtkWidget *entryid, *entrytype, *entrydaten, *entrysexe, *entrylm, *success,  *p , *p2;
troupeau ov;


success=lookup_widget(button,"succesi");



entryid=lookup_widget(button,"entryidi1");
entrytype=lookup_widget(button,"entrytypei1");
entrydaten=lookup_widget(button,"entrydateni1");
entrylm=lookup_widget(button,"spinbutton2");
entrysexe=lookup_widget(button,"comboboxsexe2");




strcpy(ov.id, gtk_entry_get_text(GTK_ENTRY(entryid)));
strcpy(ov.type, gtk_entry_get_text(GTK_ENTRY(entrytype)));
strcpy(ov.daten, gtk_entry_get_text(GTK_ENTRY(entrydaten)));
ov.lm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entrylm));
strcpy(ov.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrysexe)));

         p2=lookup_widget(button,"treeviewi2");
	p=lookup_widget(button,"treeviewi1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		
                gtk_tree_model_get (model,&iter,0,&dater,-1);
                modifier(ov, dater );

		Affichertroupeau(p,"users.txt");
                Affichertroupeau1(p2,"users.txt");
		

		
		gtk_widget_show(success);

		gtk_entry_set_text(GTK_ENTRY(entryid),"");
		gtk_entry_set_text(GTK_ENTRY(entrytype),"");
		gtk_entry_set_text(GTK_ENTRY(entrydaten),"");
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(entrylm),500);
		
		}
	
}


void
on_quitter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimeri1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p1  , *p2;
        gchar* id;

        p1=lookup_widget(button,"treeviewi1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p1));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);

          supprimer(id);
          p2=lookup_widget(button,"treeviewi2");
          Affichertroupeau1(p2,"users.txt");
        }

}


void
on_chercheri_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelid;
GtkWidget *nbResultat;
GtkWidget *message;
char id[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(button,"entryidi2");
labelid=lookup_widget(button,"labelidi");
p1=lookup_widget(button,"treeviewi2");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry)));

if(strcmp(id,"")==0){
  gtk_widget_show (labelid);b=0;
}else{
b=1;
gtk_widget_hide (labelid);}

if(b==0){return;}else{

nb=Cherchertroupeau(p1,"users.txt",id);

sprintf(chnb,"%d",nb);
nbResultat=lookup_widget(button,"nbi");
message=lookup_widget(button,"messageresi");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);

}
}
int x;



void
on_mouton_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{x = 1;}
}
void
on_Brebi_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{x = 2;}
}

void
on_taureau_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{x = 3;}
}


void
on_vache_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{x = 4;}
}

void
on_okka_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* output;
troupeau o;

int nb,nv,nm,nt;
nm=0;
nb=0;
nv=0;
nt=0;

FILE *f;
f=fopen ("users.txt","r+");

while(fscanf(f,"%s %s %s %s %s %d\n",o.dater,o.id,o.type,o.daten,o.sexe,&o.lm)!=EOF)


{
if (strcmp(o.type,"mouton")==0)
nm++;


else if (strcmp(o.type,"brebi")==0)
nb++;

else if (strcmp(o.type,"taureau")==0)
nt++;


else if (strcmp(o.type,"vache")==0)
nv++;
}

fclose(f);



int ff;
 if (x == 1)
ff = nm;
else if (x == 2)
ff = nb;
else if (x == 3)
ff = nt;
else if (x == 4)
ff = nv;

char textee[30];
sprintf(textee,"%d",ff);
output = lookup_widget(button, "nombret");
gtk_label_set_text(GTK_LABEL(output), textee);
}




void
on_okkaka_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* output;
troupeau o;
int somme1 = 0;
int somme2 = 0;
FILE *f;
f=fopen ("users.txt","r+");

while(fscanf(f,"%s %s %s %s %s %d\n",o.dater,o.id,o.type,o.daten,o.sexe,&o.lm)!=EOF)


{
if (strcmp(o.type,"brebi")==0)
somme1 += o.lm; 
else if (strcmp(o.type,"vache")==0)
somme2 += o.lm; 
}

fclose(f);
int sommee;
if (x == 1)
sommee = 0;
else if (x == 2)
sommee = somme1;
else if (x == 3)
sommee = 0;
else if (x == 4)
sommee = somme2;
char textee1[30];
sprintf(textee1,"%d",sommee);
output = lookup_widget(button, "label58");
gtk_label_set_text(GTK_LABEL(output), textee1);

}

