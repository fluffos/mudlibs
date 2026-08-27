/* Detect unseen, by Shauri 1-11-96 */

// Mmmm, modificar para que NOTIFIKE de sigiladores, no sea como un
// buscar, y que sea permanente mientras estemos en la room

#include "/d/gremios/comandos/tweaks.h"

#define DETECT_UNSEEN_COST	2
#define DETECT_UNSEEN_BONUS     10

int detect_unseen(string str, object obj) {
   object player; 
   object *things;
   int i,done=0;

   /*if(!str || str!="unseen")
   {
      return 0;
   }*/

   if(player) player = obj;
   else player = this_player();

   if(sizeof(player->query_attacker_list())) {
      tell_object(player,"No puedes vigilar en mitad de una pelea!\n");
      return 1;
   }
   if(player->query_gp()<=1) {
     tell_object(player,"Estas demasiado cansado para vigilar.\n");
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
                    "Notas que "+(string)things[i]->query_cap_name()+
                    "esta escondido aqui!\n");
                  done=1;
               } else {
                 tell_object(things[i],
                  "Notas que "+player->query_cap_name()+" intenta detectarte.\n");
                 write(
                  "Vigilas la zona pero no detectas a nadie.\n");
                  tell_room(environment(player),
                     player->query_cap_name()+" vigila todos los rincones de la zona.\n",({player,things[i]}));
                  event(environment(this_player()), "player_search");
                  return 1;
               }
            }
         }
      }
   if(!done) {
     write(
      "Vigilas la zona pero no encuentras a nadie oculto.\n");
   }
   return 1;
}

string help() {
   return 
     "Sintaxis: vigilar\n\nAdd one. You try detect unseen in the place "
     "where u are looking for any hide guy and bla bla ...\n"
     "See also: hide, sneak\n";
}
