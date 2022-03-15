#include <iostream>
#include <gtk/gtk.h>
using namespace std;

/**
 * AI project 3
 * Francisco Romero, William Daniel Hiromoto, Nolan Boner
 * The goal of this project is to design and build a Knowledge-Based Intelligent System that collects user preferences and reasons about them.
 * Featuring an easy-to-use GUI for collecting, from the user, names of attributes and their values, hard constraints, and preferences.
 * This program will also be able to read inputs from a file.
 */

/*
    todo::atributes in binary

    todo::Hard constraints (H) are represented as propositional formulas in the Conjunc-tional Normal Form (CNF)

    todo::preferences (T ) in the preference languages of penalty logic, possibilistic logic, and qualitative choice logic.
        Formulas involved in the preference theories (i.e., the φ’s and the ψ’s) are of CNF as well.

    todo::Existence of feasible objects: decide whether there are feasible objects w.r.t H,
        that is, whether there are models of H that are truth assignments making H true.

    todo::Exemplification: generate, if possible, two random feasible objects, and show the
        preference between the two (strict preference or equivalence) w.r.t T .

    todo::Optimization: find an optimal object w.r.t T .

    todo::Omni-optimization: find all optimal objects w.r.t T
*/

// borrowing https://fodor.org/blog/cpp-gtk4-gui/
static void on_activate (GtkApplication *app) {
    // Create a new window
    GtkWidget *window = gtk_application_window_new (app);
    // Create a new button
    GtkWidget *button = gtk_button_new_with_label ("Hello, World!");
    // When the button is clicked, close the window passed as an argument
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_close), window);
    gtk_window_set_child (GTK_WINDOW (window), button);
    gtk_window_present (GTK_WINDOW (window));
}

int main(int argc, char **argv) {
    // Create a new application
    cout << "reeee" << endl;
    GtkApplication *app = gtk_application_new ("com.example.GtkApplication",
                                               G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (on_activate), NULL);
    return g_application_run (G_APPLICATION (app), argc, argv);
}

