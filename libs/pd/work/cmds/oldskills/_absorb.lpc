//   /bin/user/_absorb.c
//   Written by Forlock for the Nightmare mudlib
//   Modified by Wraith so a player cant attack themselves
 
#include <std.h>
#include <common_fun.h> 
inherit DAEMON;
int spell(); 
int cmd_absorb (string str) {
   object ob;
   int damage;
 
   if (!spell()) {
      write("What?\n");
      return 1;
   }
   if((string)TP->QSC!="kataan" &&
      (string)TP->QSC!="necromancer") {
      notify_fail("The demons laugh at you as you attempt to use a spell of "+
                  "darkness.\n");
      return 0;
   }  

   if(!str) {
      ob = (object)TP->query_current_attacker();
      if(!ob) {
         notify_fail("Absorb from what?\n");
         return 0;
   }
}

   else ob = present(str, ENV(TP));
   if(!ob) ob = parse_objects(ENV(TP), str);
   if(!ob || !living(ob)) {
      notify_fail("Look again.\n");
      return 0;
   }

   if (TP->query_disable())
      return notify_fail("You are busy.\n");
   if(ENV(TP)->QPP("no magic")) {
      notify_fail("A magic force prevents your use of magic here.\n");
      return 0;
   }
        if (ob==this_player())
        {
            write("Its impossible to absorb yourself!");
            return 1;
        }

    if((int)TP->QA > -200 ) {
        notify_fail("The demons howl with displeasure at you.\n");
        return 0;
    }
   if((int)TP->query_mp() < 30) {
      notify_fail("Too low on magic power.\n");
      return 0;
   }
   if(TP->query_ghost()) {
      notify_fail("Your voice is hollow.\n");
      return 0;
   }
   if(TP->query_casting()) return 1;
    if(!this_player()->kill_ob(ob, 0)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   if(ENV(TP)->QPP("no attack")) {
      notify_fail("A magic force prevents you from casting your spell.\n");
      return 0;
   }
   write("You absorb some health from "+(string)ob->QCN+" and feel stronger.");
   tell_room(ENV(TP), TP->QCN+" suddenly looks stronger.", ({ob, TP}));
   damage = TP->QSK("magic attack")/3;
   damage += TP->QST("wisdom")/2;
   damage -= ob->QSK("magic defense")/5;
   damage -= ob->QST("wisdom")/4;
    if(!this_player()->kill_ob(ob)) {
        write(ob->quey_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   TP->set_disable();
   TP->set_magic_round(1);
   TP->set_casting(damage + random(TP->query_level()));
   TP->add_hp(damage);
   TP->add_alignment(-10);
   TP->add_mp(-(damage/7));
   TP->add_skill_points("magic attack", random(damage/20));
   tell_object(ob,TP->QCN+" drains away a portion of your life force!");
   return 1;
}
 
void help() {
    write("Syntax: <absorb [enemy]>\n\n"
        "With this spell, you drain the strength of your enemies\n"
        "and increase your own.\n"
    );
}
int spell() {
   if (!TP) return 0;
   if (TP->query_level() < 3) return 0;
   if (TP->QSC != "kataan" &&
       TP->QSC != "necromancer") return 0;
   if ((int)TP->QA > -200 ) return 0;
   return 1;
}
