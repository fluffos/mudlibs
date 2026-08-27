/* Retrieve a wizwar weapon. */
/* Hamlet, Feb 1996 */

#include "retrieve.h"

#define GP_COST 5

mapping items;

string help() {
  return "Comando: Reclamar\n"
         "Coste en Pg: "+GP_COST+"\n"
         "Sintaxis:    reclamar <nombre del objeto>\n"
         "Descripcion:  Esta habilidad te permite reclamar ciertos tipos\n"
         "              de objetos determinados de tu gremio cuando pierdes\n"
         "              su posesion.  Antes de reclamar un objeto\n"
         "              debes haberlo marcado como de tu propiedad.\n\n";
}

int retrieve(string str, object x) {
  object me;
  object *obs;
  int i;

  items = ITEMS;
    
  if(x)
    me = x;
  else
    me = this_player();
    
  if(!str || str == "") {
    tell_object(me,"Reclamar que?\n");
    return 1;
  }
  
  if(me->query_dead()) {
    tell_object(me,"Eres un fantasma, no puedes reclamar nada\n"
                   "Sinister sonrie.\n");
    return 1;
  }
  
  if( me->adjust_gp(-GP_COST) < 0 ) {
    tell_object(me,"Lo intentas y lo intentas, pero no puedes "
                   "canalizar la suficiente energia que te ayude\n"
                   "a reclamar tu "+str+"\n");
    return 1;
  }
  
  if(!items[str]) {
    tell_object(me,"No puedes reclamar "+str+"\n");
    return 1;
  }
  
  obs = children(items[str]);
  
  // Added check for environment below - Radix Nov 19 1996
  for(i=0;i<sizeof(obs);i++)
    if(obs[i]->query_property("OWNER") == me->query_name())
       if(environment(obs[i]) == me) continue;
       else
          break;
      
  if(i == sizeof(obs)) {
    tell_object(me,"No puedes localizar tu "+str+" en los reinos.\n");
    return 1;
  }
  
  if(environment(obs[i])) {
    if(living(environment(obs[i])))
      tell_object(environment(obs[i]),"Un "+str+" se apaga y desaparece.\n");
    else
      tell_room(environment(obs[i]),"Un "+str+" se apaga y desaparece.\n");
  }
  
  obs[i]->move(me);
  
  tell_object(me,"Tu "+str+" aparece en tus manos!\n");
  
  return 1;  
}
         
mapping tell_me_items() {
  return items;
}
