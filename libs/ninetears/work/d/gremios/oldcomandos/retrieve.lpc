/* Retrieve a wizwar weapon. */
/* Hamlet, Feb 1996 */

#include "retrieve.h"

#define GP_COST 5

mapping items;

string help() {
  return "Command name: Retrieve\n"
         "GP Cost:      "+GP_COST+"\n"
         "Syntax:       retrieve <item name>\n"
         "Description:  This ability allows you to retrieve certain\n"
         "              items specific to the WizWar guild when you\n"
         "              lose possession of them.  In order to retrieve\n"
         "              an item, you must 'mark' it as your own.\n\n";
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
    tell_object(me,"Retrieve what?\n");
    return 1;
  }
  
  if(me->query_dead()) {
    tell_object(me,"You, a disembodied ghost, expect to retrieve items?\n"
                   "Grimbrand laughs.\n");
    return 1;
  }
  
  if( me->adjust_gp(-GP_COST) < 0 ) {
    tell_object(me,"You try and try, but cannot seem to concentrate "
                   "enough to channel the energies\n"
                   "necessary to retrieve your "+str+"\n");
    return 1;
  }
  
  if(!items[str]) {
    tell_object(me,"You may not retrieve a "+str+"\n");
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
    tell_object(me,"You could not locate your "+str+" in the realms.\n");
    return 1;
  }
  
  if(environment(obs[i])) {
    if(living(environment(obs[i])))
      tell_object(environment(obs[i]),"A "+str+" fades then disappears.\n");
    else
      tell_room(environment(obs[i]),"A "+str+" fades then disappears.\n");
  }
  
  obs[i]->move(me);
  
  tell_object(me,"Your "+str+" appears in your hands!\n");
  
  return 1;  
}
         
mapping tell_me_items() {
  return items;
}
