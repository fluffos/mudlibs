
#include <player.h>
#include <drinks.h>

inherit COMMAND_BASE;

void my_mess(string fish, string erk);

mixed cmd(string str) {
  string who, what;
  object ob;
  if(!creatorp(TP) && !TP->query_property("echoto"))
    return notify_fail(NOT_ALLOWED);

  if(!str || str == "")
    return notify_fail("Syntax : echoto <player> <text>\n");

  if(sscanf(str, "%s %s", who, what) != 2)
    return notify_fail("Syntax : echoto <player> <text>\n");

  who = lower_case(who);
  who = (string)TP->expand_nickname(who);
  if(!creatorp(TP) && TP->adjust_sp(-ECHOTO_COST) < 0)
    return notify_fail(NO_POWER);

  ob = find_player(who);
  if(!ob)
    return notify_fail("Can't find "+who+".\n");

  if (TP->query_volume(D_ALCOHOL))
    what = TP->drunk_speech(what);
  log_file("ECHOS", ctime(time())+" "+this_player()->query_name()+" echos "+
     "to "+who+": "+what+"\n" );
  what += "%^RESET%^";
  my_mess("You echo to " + who + ": ", what);
  event(ob, "player_echo_to", what + "\n", TP);
  return 1;
}

void my_mess(string fish, string erk) {
  if(!interactive(TP)) return;
  printf("%s%-=*s\n", fish, (int)TP->query_cols()-strlen(fish), 
          TP->fix_string(erk));
} /* my_mess() */
