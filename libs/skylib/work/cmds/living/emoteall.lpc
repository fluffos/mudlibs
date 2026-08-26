
#include <player.h>
#include <drinks.h>

inherit COMMAND_BASE;

#define BEEP sprintf("%c",7)

void my_mess(string fish, string erk);

mixed cmd(string str) {
  if(!creatorp(TP) && !TP->query_property("emoteall"))
    return notify_fail(NOT_ALLOWED);

  if(!str || str == "")
    return notify_fail("Syntax : emoteall <string>\n");

  if(!creatorp(TP) &&
     TP->adjust_sp(-EMOTEALL_COST*((strlen(str)/10)+1)+100) < 0)
    return notify_fail(NO_POWER);

  str = replace(str, BEEP, "");
  if (TP->query_volume(D_ALCOHOL))
    str = TP->drunk_speech(str);
  log_file("ECHOS", ctime(time())+" "+TP->query_name()+" emotes "+
           "to all: "+str+"\n");
  str += "%^RESET%^";
  my_mess("You emoteall : ", TP->query_cap_name()+" " + str);
  TP->comm_event(users(), "player_emote_all", TP->query_cap_name() + " " + str + "\n");
  return 1;
}

void my_mess(string fish, string erk) {
  if(!interactive(TP)) return;
  printf("%s%-=*s\n", fish, (int)TP->query_cols()-strlen(fish), 
          TP->fix_string(erk));
} /* my_mess() */
