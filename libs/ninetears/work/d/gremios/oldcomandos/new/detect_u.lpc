/* Detect unseen, by Shauri 1-11-96 */

#include "/d/gremios/comandos/tweaks.h"

#define DETECT_UNSEEN_COST	2
#define DETECT_UNSEEN_BONUS     10

int detect_unseen(string str, object obj) {
   object player; 
   object *things;
   int i,done=0;

   if(!str || str!="unseen")
   {
      return 0;
   }

   if(player) player = obj;
   else player = this_player();

   if(sizeof(player->query_attacker_list())) {
      tell_object(player,"You cannot do it in the middle of a fight!\n");
      return 1;
   }
   if(player->query_gp()<=1) {
     tell_object(player,"Not enough guild points.\n");
     return 1;
   }
   
   player->adjust_gp(-DETECT_UNSEEN_COST);
 
   things=all_inventory(environment(player));
   if(!(int)environment(player)->query_property("noguild")) 
   if(!(player->query_property("dead")))
      for(i=0; i < sizeof(things); i++) {
         if(!things[i]->query_invis()) { 
            if ((int)things[i]->query_hide_shadow() && things[i]->query_name() != player->query_name()) {
               if(things[i]->query_level()+(int)things[i]->query_int() < (int)player->query_level()+random(DETECT_UNSEEN_BONUS)+(int)player->query_int()) {
                  tell_object(player,
                    "You notice "+(string)things[i]->query_cap_name()+" is "
                    "hide here!\n");
                  done=1;
               } else {
                 tell_object(things[i],
                  "You notice "+player->query_cap_name()+" is trying detect you.\n");
                 write(
                  "You try detect unseen around the place but you fail.\n");
                  tell_room(environment(player),
                     player->query_cap_name()+" detects unseen around the room.\n",({player,things[i]}));
                  event(environment(this_player()), "player_search");
                  return 1;
               }
            }
         }
      }
   if(!done) {
     write(
      "You detect unseen around the room but don't find anybody hide.\n");
   }
   return 1;
}

string help() {
   return 
     "Syntax: detect unseen\n\nAdd one. You try detect unseen in the place "
     "where u are looking for any hide guy and bla bla ...\n"
     "See also: hide, sneak\n";
}
