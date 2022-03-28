#include <bits/stdc++.h>
#include <clasp/config.h>
#include <gtk/gtk.h>
#define maxAttributes                                                          \
  10 // change this to increase max bitset size, left it at 10 so printing is
     // prettier
using namespace std;

vector<vector<string>> items; // attribute items
ifstream attributesFile("inputs/attributes.txt");
ifstream constraintsFile("inputs/constraints.txt");
ifstream penaltyFile("inputs/penalty.txt");
ifstream possibilisticFile("inputs/possibilistic.txt");
ifstream qualitativeFile("inputs/qualitative.txt");
/**
 * AI project 3
 * Francisco Romero, William Daniel Hiromoto, Nolan Boner
 * The goal of this project is to design and build a Knowledge-Based Intelligent
 * System that collects user preferences and reasons about them. Featuring an
 * easy-to-use GUI for collecting, from the user, names of attributes and their
 * values, hard constraints, and preferences. This program will also be able to
 * read inputs from a file.
 */

/*
    todo::atributes in binary

    todo::Hard constraints (H) are represented as propositional formulas in the
   Conjunc-tional Normal Form (CNF)

    todo::preferences (T ) in the preference languages of penalty logic,
   possibilistic logic, and qualitative choice logic. Formulas involved in the
   preference theories (i.e., the φ’s and the ψ’s) are of CNF as well.

    todo::Existence of feasible objects: decide whether there are feasible
   objects w.r.t H, that is, whether there are models of H that are truth
   assignments making H true.

    todo::Exemplification: generate, if possible, two random feasible objects,
   and show the preference between the two (strict preference or equivalence)
   w.r.t T .

    todo::Optimization: find an optimal object w.r.t T .

    todo::Omni-optimization: find all optimal objects w.r.t T
*/

// borrowing https://fodor.org/blog/cpp-gtk4-gui/
static void on_activate(GtkApplication *app) {
  // Create a new window
  GtkWidget *window = gtk_application_window_new(app);
  // Create a new button
  GtkWidget *button = gtk_button_new_with_label("Hello, World!");
  // When the button is clicked, close the window passed as an argument
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_close),
                           window);
  gtk_window_set_child(GTK_WINDOW(window), button);
  gtk_window_present(GTK_WINDOW(window));
}

/**
 * Feed it a list of positions and bools, it will return true if all are true,
 * else returns false;
 * @param toCheck the string to check
 * @param values first value is position, second value is
 * @return
 */
int checkAnd(bitset<maxAttributes> toCheck, vector<pair<int, int>> values) {
  for (int i = 0; i < values.size(); i++)
    if (toCheck.test(i) != values[i].second) {
      printf("Test Rejecting: %s at %d %d\n", toCheck.to_string().c_str(),
             values[i].first, values[i].second);
      return 0;
    } else
      printf("Test Accepting: %s at %d %d\n", toCheck.to_string().c_str(),
             values[i].first, values[i].second);

  return 1;
}

int checkOr(bitset<maxAttributes> toCheck,
            vector<vector<pair<int, int>>> values) {
  for (int i = 0; i < values.size(); i++)
    if (checkAnd(toCheck, values[i]))
      return 1;
  return 0;
}

/**
 * Just a function for testing the other functions
 */
void testing() {
  vector<pair<int, int>> test1;
  test1.push_back(make_pair(0, 1));
  test1.push_back(make_pair(1, 1));
  test1.push_back(make_pair(2, 1));
  test1.push_back(make_pair(3, 1));

  vector<pair<int, int>> test2;
  test2.push_back(make_pair(0, 1));
  test2.push_back(make_pair(1, 0));
  test2.push_back(make_pair(2, 0));
  test2.push_back(make_pair(3, 1));

  bitset<maxAttributes> bTest("1001");
  // checkAnd(bTest, test1);
  int orRestult = checkOr(bTest, {test1, test2});
  if (orRestult)
    cout << "Or Successful Yay!\n";
  else
    cout << "Or Failure!\n";
}

int main(int argc, char **argv) {

  testing();
  string rawInput;

  if (attributesFile.is_open())
    while (attributesFile.good()) {
      getline(attributesFile, rawInput);

      regex vowels("[^-0-9a-zA-Z]+");
      rawInput = regex_replace(rawInput, vowels, " ");

      istringstream iss(rawInput);

      string attribute, zero, one;
      iss >> attribute >> zero >> one;

      items.push_back({zero, one});
      cout << "recording: " << attribute << ' ' << zero << ' ' << one << endl;
    }
  else
    cout << "Couldnt open attributes file";
  // Create a new application
  GtkApplication *app = gtk_application_new("com.example.GtkApplication",
                                            G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
  return g_application_run(G_APPLICATION(app), argc, argv);
}
