#include <std.h>
inherit ROOM;

void create_towers();

void create() {
 ::create();
   set_short("Within the tower of all evils");
   set_long("This is Ferny's test place.");
   set_exits(([ "out" : "/wizards/inferno/workroom" ]));
   create_towers();
}

void create_towers() {
   object o;
   "/wizards/inferno/tracker"->clean_tower();
   o = new("/wizards/inferno/troom");
   o->add_exit( file_name(this_object()), "down");
   o->set_tower(2);
   this_object()->add_exit(file_name(o), "up");
   "/wizards/inferno/tracker"->add_tower(o);
   o->create_tower();
}
