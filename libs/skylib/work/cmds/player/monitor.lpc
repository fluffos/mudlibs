inherit COMMAND_BASE;

mixed cmd(string str) {
  int monitor;

  monitor = TP->query_monitor();
  
  if (!str) {
    if (!monitor)
      str = "off";
    else
      str = "on";
  }
  if (str == "on")
    monitor = 1;
  else if (str == "off")
    monitor = 0;

  if (monitor)
    write("Your hit point monitor is on.\n");
  else
    write("Your hit point monitor is off.\n");
  
  TP->set_monitor(monitor);
  return 1;
} /* cmd() */

mixed *query_patterns() {
   return ({ "", (: cmd(0) :),
             "{on|off}", (: cmd($4[0]) :) });
} /* query_patterns() */
