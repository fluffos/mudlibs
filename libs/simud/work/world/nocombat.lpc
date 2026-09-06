#include <object.h>
#include <saveload.h>

//string stop_msg;
string no_msg;

string query_name() {
  return "nocombat";
}

string query_no_msg() {
  return no_msg;
}

set_no_msg(string str) {
  if (!str)
    no_msg = "But this is such a peaceful place...";
  else
    no_msg = str;
}
/* commented out -- spams every time someone enters the room, not sure how to fix
string query_stop_msg() {
  return stop_msg;
}

set_stop_msg(string str) {
  if (!str)
    stop_msg = "But this is such a peaceful place...";
  else
    stop_msg = str;
}
*/
void stopcombat() {
   object victim;

   foreach( victim : all_inventory(environment()) )
      victim->stop_combat();
}

int nocombat() {
  msg_object(this_player(), no_msg);
  return 1;
}

void init() {
   ::init();
   add_action("nocombat", "attack");
   add_action("nocombat", "kill");
   stopcombat();
}

create() {
   ::create();
   set_no_msg();
}
