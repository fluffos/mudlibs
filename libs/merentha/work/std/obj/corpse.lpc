// Petrarch
// Merentha Lib 1.2.0
// corpse object

#include <std.h>

#define DECAY_TIME 10

inherit CONTAINER;

string gender, race;

void set_gender(string str) { gender=str; }
void set_race(string str) { race=str; }

void create() {
  ::create();
  set_name("corpse");
  set_id(({"corpse","remains","decaying corpse"}));
}

void decay(int i) {
  if (i) call_out("decay", DECAY_TIME, i-1);
  if (i<3 && i>1) {
   set_short("the decaying corpse of a "+race);
   set_long("This is the decaying corpse of what appears to have been a "+gender+" "+race+".");
  }
  else if (i==1) {
   set_short("the badly decaying corpse of a "+race);
   set_long("This is the badly decaying corpse of what appears to have been a "+gender+" "+race+".");
  }
  else if (!i) call_out("remove", 0);
  else {
  set_short("the corpse of a "+race);
  set_long("This is the corpse of what appears to be a "+gender+" "+race+".");
  }
}

string query_long() {
object *inv;
string str=::query_long();
int i;
  i=sizeof(inv=all_inventory(this_object()));
  if(!i)  return str;
  str+="\nOn the corpse there is:";
  while (i--) str+="\n   "+inv[i]->query_short();
  return str;
}
