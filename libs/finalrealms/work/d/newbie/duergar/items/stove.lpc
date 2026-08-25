/* Likewise this is Hamlet's.  Perhaps worm isn't the word. */
inherit "/std/container";
#include "path.h"
nosave int x =0;
 
object pot;
object ladle;

void setup() {
  set_name("stove");
  set_long("A large wood-burning stove.\n");
  set_short("Wood-burning stove");
  set_value(0);
  set_weight(10000);
set_max_weight(10000);
  reset_get();

//  set_prevent_insert();

  if(!pot) {
    pot = clone_object(ITEMS+"pot");
    pot->move(this_object());
  }
  if(!ladle) {
    ladle = clone_object(ITEMS+"ladle");
    ladle->move(this_object());
  }
}

void init() {
  add_action("ladle_me","ladle");
  ::init();
}

void ladle_me(string what) {
  object *playerhas;
  object thestew, thebowl;
  int i, maxi;
  int hasladle = 0;
  int hasbowl = 0;

  if( what != "stew" )   return 0;

  playerhas = all_inventory(this_player());
  maxi = sizeof(playerhas);
  for(i=0;i<maxi;i++) {
    if( (string) playerhas[i]->query_name() == "ladle" )
      hasladle = 1;
    if( (string) playerhas[i]->query_name() == "bowl" ) {
      hasbowl = 1;
      thebowl = playerhas[i];
    }
  }
  
  if(!hasladle) {
    tell_object(this_player(),"Perhaps you should get the ladle first!\n");
    return ;
  }
  if(!hasbowl) {
    tell_object(this_player(),"Perhaps you should put your stew in a bowl.\n");
    return ;
  }

  if(x < 4) {
  tell_object(this_player(),"You scoop a nice serving of stew out of "
               "the pot on the stove.\n");
  tell_room(environment(this_object()),this_player()->query_cap_name() +
             " scoops a healthy portion of stew out of the pot.  "
             "Boy is smells good!\n",({this_player()}));
  thestew = clone_object(ITEMS+"stew");
  thestew->move(thebowl);
  x++;
  return ;
  }
 else
  {tell_object(this_player(),"Sorry, but you have taken the last of the "
	"stew.\n");
   tell_room(environment(this_object()),this_player()->query_cap_name() +
	" has taken the last of the stew.....what a pig.\n");
return ;
  }
}
         
