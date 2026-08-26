/* The afk command for players and creators alike
 *
 * Sets a definable afk message that others will get while your, well, afk
 * if you don't actually pass a message then a generic afk one will be 
 * displayed instead.
 */


inherit COMMAND_BASE;

int cmd(string arg) {
  
  if (!arg || arg == "") {
    if (TP->query_property("afk")) {
      write("Making you present and available again.\n");
      TP->remove_property("afk");
      TP->remove_property("afk_string");
    } else {
      write("Setting your %^ORANGE%^AFK%^RESET%^ flag.\n");
      write("You will become available again the next time you enter a command.\n");
      TP->add_property("afk", 1);
    }
  } else {
    if (TP->query_property("afk")) {
      write("Setting a new %^ORANGE%^AFK%^RESET%^ message.\n");
      write("Use 'afk' with no arguments to return.\n");
      TP->add_property("afk_string", arg);
    } else {
      write("Setting your %^AFK%^ flag with '"+arg+"' afk message.\n");
      write("You will become available again the next time you enter a command.\n");
      TP->add_property("afk", 1);
      TP->add_property("afk_string", arg);
    }
  }
  return 1;
}
