#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "troupeau.h"
#include "tree.h"

GtkListStore *adstore;
GtkTreeViewColumn *adcolumn;
GtkCellRenderer *cellad;
FILE *f;
int i ,j ;
void Affichertroupeau(GtkWidget* treeview1,char*l)
{

troupeau o;


        
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT);

        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %d\n",o.dater,o.id,o.type,o.daten,o.sexe,&o.lm)!=EOF)
        {GtkTreeIter pIter;


         gtk_list_store_append(adstore, &pIter);

         gtk_list_store_set(adstore, &pIter,
                            0,o.dater,
                            1,o.id,
                            2,o.type,
                            3,o.daten,
                            4,o.sexe,
                            5,o.lm,
                            -1);}
        fclose(f);


if(i==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Date de Registrement",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);



	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Identifiant",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Type",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Date de Naissance",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("sexe",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Litre/mois",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}





void Affichertroupeau1(GtkWidget* treeview1,char*l)
{

troupeau o;



        adstore = gtk_list_store_new(5,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                      G_TYPE_INT);

        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %d\n",o.dater,o.id,o.type,o.daten,o.sexe,&o.lm)!=EOF)
        {GtkTreeIter pIter;
	

         gtk_list_store_append(adstore, &pIter);

         gtk_list_store_set(adstore, &pIter,
                             0,o.dater,
                            1,o.id,
                            2,o.type,
                            3,o.daten,
                            4,o.sexe,
                            5,o.lm,
                            -1);}
        fclose(f);



if(j==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Date de Registrement",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);



	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Identifiant",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Type",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Date de Naissance",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("sexe",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

      

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Litre/mois",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);



	j++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}



int Cherchertroupeau(GtkWidget* treeview1,char*l,char*id)
{

troupeau o ;
int nb=0;


        adstore = gtk_list_store_new(5,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT);

        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %d\n",o.dater,o.id,o.type,o.daten,o.sexe,&o.lm)!=EOF)
        {
	if( strcmp(id,o.id)==0){ nb++;
	GtkTreeIter pIter;

         gtk_list_store_append(adstore, &pIter);

         gtk_list_store_set(adstore, &pIter,
                            0,o.dater,
                            1,o.id,
                            2,o.type,
                            3,o.daten,
                            4,o.sexe,
                            5,o.lm
                            -1);}
}
        fclose(f);


if(j==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Date de Registrement",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);



	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Identifiant",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Type",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Date de Naissance",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Sexe",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Litre/mois",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);



	j++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}















