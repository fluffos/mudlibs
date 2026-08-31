
//     _psiblast.c
//     Psychic Power
//     Danovae - 12.15.2001

#include <std.h>
inherit DAEMON;
int spell();

int cmd_psiblast(string str) {
   object tp, ob;
   int attack, intelligence, skip, which, i;
   string what;
   object *inv;

   if(!spell()) {
     write("Ha ha! You are too stupid to cast this.");
     return 1;
   }

   this_player()->set_magic_round();
   tp = this_player();
   if(tp->query_ghost()) {
     notify_fail("You have no brain with which to think.\n");
     return 0;
   }

   if((string)tp->query_class() == "child") {
     notify_fail("You do not have the mental discipline to do this.\n");
     return 0;
   }

   if(tp->query_casting()) return 1;
   if((int)tp->query_mp() < 15) {
     notify_fail("You are not focused enough.\n");
     return 0;
   }

   if(!str) {
     ob = (object)tp->query_current_attacker();
     if(!ob) {
       notify_fail("Psiblast what?\n");
       return 0;
     }
   }

   else {
     ob = present(str, environment(tp));
     if(!ob) {
       sscanf(str, "%s %d", what, which);
       inv = all_inventory(environment(tp));
       for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) {
          if(inv[i]->id(what)) {
             skip++;
             if(skip == which) ob = inv[i];
          }
       }

       if(!ob) {
          notify_fail("No "+str" here...\n");
          return 0;
       }
    }
   }

   if(!living(ob)) {
     notify_fail(ob->query_cap_name()+" has no mind.\n");
     return 0;
   }

   if(ob == tp) {
     notify_fail("How do you propose to do that?\n");
     return 0;
   }

   if(ob->is_player() && !interactive(ob)) {
     notify_fail("You cannot attack link-dead players.\n");
     return 0;
   }
   attack = (int)tp->query_skill("magic attack");
   intelligence = (int)tp->query_stats("intelligence");
   attack -= intelligence;
   if(attack < 1) attack = 1;
   if(!tp->kill_ob(ob, 0)) return 1;
   write("%^MAGENTA%^You fire a burst of psychic energy.%^RESET%^");
   tell_room(environment(tp), "%^MAGENTA%^"+tp->query_cap_name()+
       "fires a burst of psychic energy at "
       +(string)ob->query_cap_name()+".%^RESET%^",
       ({ ob, tp }) );
     tell_object(ob, "%^MAGENTA"+tp->query_cap_name()+
       " fires a burst of psychic energy at you.");
/*
if (this_player()->query_level()>10)
tp->set_casting(
attack+(this_player()->query_level())/10+(this_player()->query_level()) );
 else
tp->set_casting( random(this_player()->query_level()*20/2) );
*/
   tp->set_casting(attack);
   tp->add_skill_points("magic attack", attack/20 + 2);
   tp->add_mp(-(random(15)*this_player->query_level())/2);
   return 1;
}


void help() {
   write(
     "Syntax: <psiblast [(living)]>\n"
     "Project painful thoughts... just like in the movies.\n");
}

int spell() { if (this_player()->query_class() == "mage") return 1; }

