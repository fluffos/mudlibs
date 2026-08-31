// enforce.c
#include <std.h>
#include <tirun.h>

inherit ROOM;

/***********************************************
Sentances: 
1) 120 rounds in jail  ( 2 min )                        -- 1 --
2) 480 rounds in jail  ( 8 min )                        -- 3 --
3) 720 rounds in jail  (12 min ) [para]                  -- 5 --
4) 1020 rounds in jail (17 min ) [para]                 -- 6 --
5) All autoloading equipment is auctioned off,
   300 rounds (5 min) in jail [para]                     -- 2 --
6) 600 rounds in jail  (10 min ) [para],                 -- 4 --
   700 damage worth of a flogging
7) Five random autoloading objects are destroyed,
   all non autoloading equipment is destroyed,
   600 rounds in jail [no para], fine?                  -- 4 --
8) Beheaded in Tirun square, corpse is left there,
   along with your severed head 
9) Hanged, all equipment lost
***********************************************/

void create() {
   set_short("Entering a courtroom");
   set_properties(([
        "no attack" : 1, "no magic" : 1, "no teleport" : 1, "no gate" : 1
   ]));
}

int FilterMe(string str) {
   write("You are bound and gagged.");
  if (!wizardp(this_player()))
   return 1;
  else return 0;
}

void give_info(object tp, int sentance) {
   object *stuff;
   int i;
   switch(sentance) {
     case 1:
       "/d/nopk/tirun/jail"->add_prisoner(tp, 120);
       return;
     case 2:
       "/d/nopk/tirun/jail"->add_prisoner(tp, 480);
       break;
     case 3:
       "/d/nopk/tirun/jail"->add_prisoner(tp, 720);
       tp->set_paralyzed(720, "You have been bound and gagged.");
       break;
     case 4:
       "/d/nopk/tirun/jail"->add_prisoner(tp, 1020);
       tp->set_paralyzed(1020, "You have been bound and gagged.");
       break;
     case 5:
       message("info", "Your belongings are sold in a hasty auction to the local shops.", tp);
       stuff = all_inventory(tp);
       i = sizeof(stuff);
       while(i--) {
           if(stuff[i]->is_weapon())
             stuff[i]->move(ROOMS"wstorage");
           else if(stuff[i]->is_armour())
             stuff[i]->move(ROOMS"astorage");
           else
             stuff[i]->move(ROOMS"storage");
       }
       "/d/nopk/tirun/jail"->add_prisoner(tp, 300);
       tp->set_paralyzed(300, "You have been bound and gagged.");
       break;
     case 6:
       "/d/nopk/tirun/jail"->add_prisoner(tp, 1020);
       message("info", "You are flogged severly before being thrown in jail!", tp);
       tp->add_hp(-700);
       if(tp->query_hp() > 0)
         tp->set_paralyzed(1020, "You have been bound and gagged.");
       break;
     case 7:
       message("info", "Your belongings are sold in a hasty auction to the local shops.", tp);
       message("info", "A few of them broke in the process.", tp);
       stuff = all_inventory(tp);
       i = sizeof(stuff);
       while(i--) {
           if(random(4) == 0) {
             stuff[i]->remove();
             continue;
           }
           if(stuff[i]->is_weapon())
             stuff[i]->move(ROOMS"wstorage");
           else if(stuff[i]->is_armour())
             stuff[i]->move(ROOMS"astorage");
           else
             stuff[i]->move(ROOMS"storage");
       }
       this_player()->add_money("gold",this_player()->query_money("gold"));
       "/d/nopk/tirun/jail"->add_prisoner(tp, 600);
       tp->set_paralyzed(600, "You have been bound and gagged.");
       return;
     case 8:
       message("info", "%^RED%^"+tp->query_cap_name()+" has been sentanced to death!", users());
       message("info", "As you are led to the square, you are knelt down in front of a"
                       " large stump...", tp);
       tp->set_paralyzed(4, "You are bound and gagged.");
       call_out("do_execute", 4, tp);
       break;
     case 9:
       message("info", "%^RED%^"+tp->query_cap_name()+" has been sentanced to death!", users());
       message("info", "You are led to the square, where your death awaits you.", tp);
       tp->set_paralyzed(4, "You are bound and gagged.");
       call_out("just_die", 4, tp);
   }
}

void do_execute(object tp) {
   tp->move(ROOMS"square");
   message("info", tp->query_cap_name()+" is executed by the guards.", environment(tp));
   tp->die();
}

void just_die(object tp) {
   object *stuff;
   int i;
   tp->move(ROOMS"square");
   message("info", tp->query_cap_name()+" is executed by the guards.", environment(tp));
   stuff = all_inventory(tp);
   i = sizeof(stuff);
   while(i--) {
      stuff[i]->remove();
   }
   tp->die();
}

void init() {
 ::init();
   add_action("FilterMe", "");
}
