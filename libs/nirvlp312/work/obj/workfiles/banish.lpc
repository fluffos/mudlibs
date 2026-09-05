/*
 * Modified to update code and add logging - Rumplemintz
 */

string bb;

string short() { return "The banishment object"; }
void init() { add_action("banish","banish"); }
void long() { write ("Use 'banish <name>'\n"); }

int banish(string who) {
  int level;
  level = this_player()->query_level();
  if (level < 21) return 0;
  if (!who) {
    write("Banish who?\n");
    return 1;
  }
  if (!this_player()->valid_name(who)) return 1;
  if (restore_object("pfiles/" + who[0..0] + "/" + who)) {
    write("That name is already used.\n");
    return 1;
  }
  if (restore_object("banish/" + who)) {
    write("That name is already banished.\n");
    return 1;
  }
  bb = this_player()->query_real_name();
  if (bb == "Someone") {
    write("You must not be invisible!\n");
    return 1;
  }
  log_file("banish",
           "----------------------------------------------------" +
           capitalize((string)this_player()->query_real_name()) +
           " banished " + who + "\n" +
           "Time: " + ctime() + "\n" +
           "----------------------------------------------------\n");
  save_object("banish/" + who);
  return 1;
}

int get() {
  write("You now have the banishment object\n");
  return 1;
}

int id(string str) {
  return str == "banishment" || str == "object";
}
