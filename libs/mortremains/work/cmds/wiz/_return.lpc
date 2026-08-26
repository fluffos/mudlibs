// (??-??-96) Idea stolen and implemented by Chronos@ADF
//            This command returns players to their previous location
//            or if given no argument, will return you to your previous.
// (04-05-98) Updated to prevent wizards from pushing each other around.

#include <mudlib.h>

inherit DAEMON ;

int cmd_return(string str) {
  object victim ;
  string file ;
  if (!str) {
  file = TP->query("last_location") ;
  if (!file) {
    write("You have no previous location to transport to.\n") ;
    return 1;
  }
  else TP->move_player(file) ;
  return 1;
  }
  victim = present(str, environment(TP)) ;
  if (!victim) {
    write("Can't find "+str+".\n") ;
    return 1;
  }
  if (!userp(victim)) {
    write("You can't return that.\n") ;
   return 1;
  }
  if (wizardp(victim)) {
   write("You cannot force other wizards to do stuff like that.\n") ;
   return 1;
  }
  file = victim->query("last_location") ;
  if (!file) {
   write(capitalize(str)+" has no previous location to transport to.\n") ;
  return 1; 
  }
  write("You send "+capitalize(str)+
  " to "+victim->query_possessive()+" previous location.\n") ;
  say(TPN+" returns you to where you last were.\n") ;
  TP->move_player(file) ;
  return 1;
}


string help() {
  return @ENDLONG
Usage: return [player]

You can return yourself or a player to their respective previous 
location with this command.
ENDLONG
;
}
