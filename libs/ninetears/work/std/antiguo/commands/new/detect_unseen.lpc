/* Detect unseen, by Shauri 1-11-96 */

#include "/d/gremios/comandos/tweaks.h"

#define DETECT_UNSEEN_COST	2
#define DETECT_UNSEEN_BONUS     10

int detect_unseen(string str, object obj) {
   object player; 
   object *things;
   int i,done=0;

   if(!str || str!="oculto")
   {
      notify_fail("Encontrar que?\n");
      return 0;
   }

   if(player) player = obj;
   else player = this_player();

   if(sizeof(player->query_attacker_list())) {
      tell_object(player,"No puedes hacer esto en medio de una lucha!\n");
      return 1;
   }
   if(player->query_gp()<=1) {
     tell_object(player,"No tienes suficientes puntos de gremio.\n");
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
                    "Te percatas que "+(string)things[i]->query_cap_name()+" esta "
                    "oculto aqui!\n");
                  done=1;
               } else {
                 tell_object(things[i],
                  "Notas que "+player->query_cap_name()+" esta intentando detectarte.\n");
                 write(
                  "Intentas encontrar algo oculto por la zona pero desistes.\n");
                  tell_room(environment(player),
                     player->query_cap_name()+" busca algo oculto por la zona.\n",({player,things[i]}));
                  event(environment(this_player()), "player_search");
                  return 1;
               }
            }
         }
      }
   if(!done) {
     write(
      "Intentas encontrar algo oculto por la zona pero fallas.\n");
   }
   return 1;
}

string help() {
   return 
     "Sintaxis: encontrar oculto\n\nIntentaras encontrar algo oculto por el lugar "
     "donde tu estas buscando. Este comando sirve para detectar objetos y personas "
     "escondidas por la zona.\n";
     }
