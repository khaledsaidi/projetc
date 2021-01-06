#include <gtk/gtk.h>


void
on_ajouteri_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifieri_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewi_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supprimeri_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_gestionouvrier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifieri1_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitter_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimeri1_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercheri_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_Brebi_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_vache_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_taureau_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_okka_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_mouton_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_okkaka_clicked                      (GtkButton       *button,
                                        gpointer         user_data);
