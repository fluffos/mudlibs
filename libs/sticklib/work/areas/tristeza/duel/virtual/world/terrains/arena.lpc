
/*******************************************************
 NAME:    arena.c

 PURPOSE: Duel arena room.

 AUTHOR:  Tron
 *******************************************************/

#include <virtual_room.h>

#include <areas.h>

#define	DUELD	AREA_DUEL_ARENA "dueld"


nomask status
query_no_teleport() { return 1; }

nomask status
query_duel_arena() { return 1; }

object
query_dead_object() {  return this_object(); }

status
object_died(object dead, object killer) {
string winner;
int x;

     if(!dead) return 0;
     
   if(dead->query_npc()) return 0;
     tell_object(dead, "You grin out of pain and bitter defeat.\n");
   /*
     if(killer)
       if(killer != dead) killer->add_exp((int)dead->query_level()/2 * 200);
       dead->add_exp(-((x = (int)dead->query_ep()/10) > 450000 ? 450000 : x));
*/
   if(killer && killer != dead) {
      DUELD->add_dueld_kill((string)killer->query_real_name(),
             (int)dead->query_level());
   }
     if(DUELD->dueld_deadobj(dead)) {
         winner = (string)DUELD->query_dueld_winner();
         if(winner) DUELD->dueld_end(winner);
     }
  return 1;
}
     
    
nomask private string *
do_desc() {
string *s;

    s = ({ "You are wandering around the duel arena. "+
           "The arena is surrounded by round stone walls, that "+
           "rise high above your reach. The ground is mixed rubble "+
           "and sand. This is a perfect place for a little fight.",
           "You stand in well kept arena with stone walls around it. "+
           "Occasional dust clouds drift around the duel arena carried "+
           "by the circling bursts of wind." });

    return s;
}

void
create_virtual() { 
  
  set_light_level(1);
  set_outdoors(WD_OUTDOORS);
 
  short_desc="Duel Arena";
 
  add_virtual_exit("north", 0, -1);
  add_virtual_exit("south", 0, 1);
  add_virtual_exit("east", 1, 0);
  add_virtual_exit("west", -1, 0);
  add_virtual_exit("northeast", 1, -1);
  add_virtual_exit("northwest", -1, -1);
  add_virtual_exit("southeast", 1, 1);
  add_virtual_exit("southwest", -1, 1);

  set_hb(1);

  set_effects(({"The wind howls around the round duel arena.\n",
                "Small dust clouds rise from the sandy ground when"+
                " you move.\n"}), 5);

  set_random_desc(do_desc());  
}

void
init_virtual() {


  if(!DUELD->query_dueld_dueling()) {
     write("There is no duel going on...Zzzzzzp.\n");
	this_player()->move_player("X", AREA_DUEL_ARENA "duel_off");
     return;
   }
  add_action("remove_gladiator", "kickout");
  add_action("duelstatus", "duelstat");
  add_action("quit", "quit");
  add_action("find_gladiator", "find");
    add_action("endduel", "endduel");
}


status
endduel() {
string winner;

   if(winner = (string)DUELD->query_dueld_winner()) {
       DUELD->dueld_end(winner);
     }
   else write("You can't end the duel now!\n");

   return 1;
}
status
quit() {

   write("You can't quit in the middle of the duel!!!\n");
   return 1;
}

status
duelstatus() {

  DUELD->query_dueld_status();
  return 1;
}

status
remove_gladiator(string s) {
object plr;
string winner;

   if(!s) {
      notify_fail("kickout who?\n");
      return 0;
   }
   
   s = lower_case(s);

   if(!(plr = find_player(s))) {
      notify_fail("No such player.\n");
      return 0;
    }
   if(interactive(plr) && plr->query_duel_arena()) {
      notify_fail("But this person is not currently escaping the battle.\n");
      return 0;
   }
   if(DUELD->dueld_deadobj(plr)) {
       write("You banish the filthy coward from the duel.\n");
        
       winner = (string) DUELD->query_dueld_winner();
       if(winner) DUELD->dueld_end(winner);
   }
   else {
      notify_fail("That person is not in this duel.\n");
      return 0;
   }

 return 1;
}

 
status
find_gladiator(string s) {
object ob;
string dir, dist;
 
   if(!s) return duelstatus();
 
   ob = find_player(s);
 
   if(!ob) {
      notify_fail("Where, who?\n");
      return 0;
   }
   
   if(environment(ob)->query_duel_arena()) {
      int *crd1;
      int *crd2;
      int *crd3;
      int x, y, corner;
 
      int len;
 
      crd1 = (int *)environment(ob)->query_coordinates();
      crd2 = (int *)environment(this_player())->query_coordinates();
      crd3 = ({0, 0});
 
      crd3[0] = crd2[0] - crd1[0];
      crd3[1] = crd2[1] - crd1[1];
 
      len = (x = crd3[0] * crd3[0]) + (y = crd3[1] * crd3[1]);
      if(len == 0) {
          this_player()->tell_me(capitalize(s)+" is right HERE!");
          return 1;
      }
      if(x && y)
      if(x >= len/2 && y >= len/2) corner = 1;
 
      dir = ""; dist = "";
      if(corner) {
         if(crd3[1] < 0) dir = "south";
         else dir = "north";
         if(crd3[0] > 0) dir += "west";
         else dir += "east";
      }
      else {
         if(!x && y) {
           if(crd3[1] < 0) dir = "south";
           else dir = "north";
         }
         else if(x && !y) {
           if(crd3[0] > 0) dir = "west";
           else dir = "east";
         }
         else {
            if(x > y) {
               if(crd3[0] < 0) dir = "east";
               else dir = "west";
            }
            else {
               if(crd3[1] > 0) dir = "north";
               else dir = "south";
            }
         }
      }
 
      switch(len) {
 
        case 1..2: dist = " right next to you ";
                   break;
        case 3..6: dist = " near you ";
                   break;
        case 7..14: dist = " rather near you ";
                   break;
        case 15..30: dist = " rather far away from you ";
                   break;
        case 31..62: dist = " far away from you ";
                   break;
        default: dist = " very far away from you ";
      }
 
      this_player()->tell_me(capitalize(s) + " is"+dist+"to "+dir);
      return 1;
  } else notify_fail(capitalize(s) + " is not in the duel.\n");

  return 0;
}
