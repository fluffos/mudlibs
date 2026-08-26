#include "../pr.h"
inherit PRIEST_SPELL;
void create(){
 sphere = ({ "necromantic" });
 level = 5;
 reversible = 1;
 }
int main(string str)
 {
   if(!str) str = tp->query("name");
   trg = present(str, environment(this_player()));
   if(!trg)
   {
      return (int) notify_fail("There is no one here by that name.\n");
    }
    tell_tp(sprintf("You cast cure light wounds on %s.\n",
                  (trg == tp) ? "yourself" : trg->query("cap_name")));

    tell_targ(sprintf("%s cast cure light wounds on you.\n", tp->query("name")));
    room_msg(sprintf("%s casts cure light wounds on %s.\n",
       tp->query("cap_name"), (trg == tp) ? hirself(trg) : trg->query("cap_name")));
     
     //
     //OTHER CODE WILL GO HERE
     //
     return 1;
   
  }
 
 int reverse(string str)
 {
   if(!str) str = tp->query("name");
   trg = present(str, environment(this_player()));
   if(!trg)
   {
     trg = tp->query_current_attacker();
     if(!trg)
     {
      return (int) notify_fail("There is no one here by that name.\n");
     }
    }
    tell_tp(sprintf("You cast cause light wounds on %s.\n",
                  (trg == tp) ? "yourself" : trg->query("cap_name")));

    tell_targ(sprintf("%s cast cause light wounds on you.\n", tp->query("name")));
    room_msg(sprintf("%s casts cause light wounds on %s.\n",
       tp->query("cap_name"), (trg == tp) ? hirself(trg) : trg->query("cap_name")));
     
    //
     //OTHER CODE WILL GO HERE
     //
     return 1;
   

  }
