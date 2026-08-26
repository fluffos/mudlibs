// Petrarch
// Merentha Lib 1.0
// <dumpallobj>

varargs int command(string obj) {
object ob;
string *list;

  message("command", "Dumping all objects into /log/dumpallobj.out", this_player());
  rm("/log/dumpallobj.out");
  dumpallobj("/log/dumpallobj.out");
  message("command", "Dumping complete!", this_player());

  return 1;
}

string help() {
return "Syntax: dumpallobj\n\nDumps stats on all ojbects currently in the game into /log/dumpallobj.out";
}
