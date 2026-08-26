
#include <player.h>
#include <drinks.h>

inherit COMMAND_BASE;

void my_mess(string fish, string erk);

mixed cmd(string str) {
  if(!creatorp(TP) && !TP->query_property("echo"))
    return notify_fail(NOT_ALLOWED);
  
  if (!str || str == "")
    return notify_fail("Syntax : echo <text>\n");

  if (!creatorp(TP) && TP->adjust_sp(-ECHO_COST) < 0)
    return notify_fail(NO_POWER);
  
  if (TP->query_volume(D_ALCOHOL))
    str = TP->drunk_speech(str);
  log_file("ECHOS", ctime(time())+" "+this_player()->query_name()+" echos: "+
     str+"\n");
  str += "%^RESET%^";
  my_mess("You echo: ", str);
  TP->comm_event(environment(TP), "player_echo", str + "\n");
  return 1;
}

void my_mess(string fish, string erk) {
  if(!interactive(TP)) return;
  printf("%s%-=*s\n", fish, (int)TP->query_cols()-strlen(fish), 
          TP->fix_string(erk));
} /* my_mess() */
