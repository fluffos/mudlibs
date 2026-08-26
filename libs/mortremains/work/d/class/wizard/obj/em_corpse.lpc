// Cyanide, Dec 96. (?)
// Ressurected by Cyanide, 15 Apr 98.

#include <mudlib.h>

inherit OBJECT;

void create() {
  set ("killer", "Noone");
  set ("name", "Noone");
  set ("embalmer", "Noone");
  set ("mass", 120);
  set ("short", "@@query_short");
  set ("long", "@@query_long");
  set ("id", ({ "corpse", "remains", "body", "dead body",
   }) );
}

string query_short() {
  string str;

  str = 
   "Corpse of "+this_object()->query("name")+", embalmed by "+
   this_object()->query("embalmer");

  return str;
}

string query_long() {
  string str;

  str =
"This is the dead corpse of "+this_object()->query("name")+
" slain by "+this_object()->query("killer")+".\n"+
"It has been embalmed and preserved by "+
this_object()->query("embalmer")+".\n";
 
  return str;
}

/* EOF */
