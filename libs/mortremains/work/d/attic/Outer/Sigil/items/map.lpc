//ilz

#include <mudlib.h>

inherit OBJECT;

void create() {
	set("id", ({ "map", "sigil map" }) );
	set("short", "a map of sigil");
	set("long", @LONG
              *-* *-*-* *-*
              | |   |   |
  *-*-* * *-* 8-* *-*-8 *-* 2 * *-*-* * * * *
    |   |   | |     |   |   | |   |   | | | |
0-*-*-*-*-*-*-*-*-*-1-*-*-*-*-*-*-*-*-*-*-*-*-0
    |   | |   |     |   | | | |   | |   |   |
  *-*-* 8 *-* *-* *-*-* 3 4 5 6 9-* * *-*-* *
    |     |   |     |                 | | |
    *   7-*-*-*-* *-*-*               *-*-*
          |                           | | |
          *                           *-*-*
1-center of town  2-gymnasium     3-fighter's guild
4-thieve's guild  5-mage's guild  6-priest's guild
7-armory          8-pub           9-post office
LONG
	);
        set("name", "map");
  }
void init() {
  object ob = environment(this_object());
  if (!living(ob))
    call_out("remove", 1);
}

void remove() {
  object ob = environment(this_object());
  if (ob) 
    tell_room(environment(this_object()), 
    "The newbie item crumbles to dust and blows away.\n");
  ::remove();
}