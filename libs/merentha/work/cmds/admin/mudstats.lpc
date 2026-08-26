// Petrarch
// Merentha Lib 1.0
// <mudstats>

varargs int command(string val) {
  message("command", mud_status(val?1:0), this_player());
  rm("/log/mudstats.out");
  write_file("/log/mudstats.out","\n"+mud_status(0)+"\n"+mud_status(1)+"\n");
  return 1;
}

string help() {
return "Syntax: mudstats [arg]\n\nDisplays status information about the MUD.  If you include the optional arg a more detailed report is given.  The report is also writen to /log/mudstats.out";
}
