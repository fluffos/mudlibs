// Chronos rewrote the zap command to be cooler.
#include <mudlib.h>
#include <logs.h>

#define CORPSE_OBJ "/obj/obj/flaming_corpse"
inherit DAEMON;

#define SYNTAX  "Syntax: fry [target]\n"

int cmd_fry(string str) {
    object target, targetenv;

    notify_fail( SYNTAX );
    if(!str || str == "")  return 0;
    str = lower_case(str);
    targetenv = environment(this_player());
    if  (!targetenv) {
        write("You are in the Void.  It doesn't work here.\n") ;
          return 1;
    }
    target = present(str, targetenv);
    if(!target) {
        write("[FRY] There is no such living object here.\n");
        return 1; }

    if(!living(target)) {
        write("[FRY] That object is not alive.\n");
        return 1; }        


    if(target->link_data("dead") || target->query_dead() ||
      target->query("dead")) {
        write("[FRY] That object is already dead.\n");
        return 1; }
   if(wizardp(target) && target->query("immortal")) {
        write("[FRY] That wizard is immortal, and cannot be killed.\n");
        return 1; }
  if (userp(target)) {
     write("[FRY] This command is not for use on players.\n") ;
     return 1; 
  }
   str = target->query("cap_name") ;
   if (str=="Alucard") {
      write("You feel that Alucard is somehow protected by someone very powerful..\n   You think better of frying him.\n") ;
     return 1;
  }
   message("combat", TPN+"'s eyes begin to glow with a brilliant red hue.\n"+
   TPN + " gestures at "+str+" violently and "+
      subjective(target->query("gender")) + " suddenly bursts into flames.\n",
    environment(TP), ({ TP }) ) ;
   write("You gesture violently at "+str+" and "+subjective(target->query("gender"))+
     " suddenly bursts into flames.\n") ;
    target->remove() ;
     target =clone_object(CORPSE_OBJ) ;
    target->move(targetenv) ;
    target->set_name(str) ;
#ifdef ZAP_LOG
    if(interactive(target))
        log_file(ZAP_LOG, (string)this_player()->query("cap_name") +
            " fried "+str+" ["+
          extract(ctime(time()), 4, 15) + "]\n");
#endif
    return 1;
}

string help() {
     return @ENDHELP

Usage: fry <target>

Another demented creation from Chronos, this command is simply a modified zap.
Note: Both "zap" and "fry" are LOGGED to prevent wizards from abusing
the commands to aid players.

See also: zap
ENDHELP
  ;
 }
