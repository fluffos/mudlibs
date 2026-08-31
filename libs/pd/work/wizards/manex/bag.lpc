#include <std.h>
inherit "std/storage/";

int mytake(string str);
int myput(string str);
int move_all();

void init() {
 ::init();
   add_action("myput", "put");
   add_action("mytake", "take");
   add_action("mytake", "get");
}

void create() {
 ::create();
   set_name("magic bag");
   set_id( ({ "magic bag"}) );
   set_short("a magic bag");
   set_long("this magic bag will expand to fit anything and everyting "
            "you ever wanted.");
   set_mass(100+(int)query_encumbrance()/10);
   set_value(2343+random(100));
   set_max_encumbrance(1000+random(250)+random (175));
   set_prevent_put("I don't think you really want this in there!");
}

int move_all() {
int i,j;
object *things;
i = sizeof(things = all_inventory(this_object()));
if (i==O) return notify_fail("thre is nothing in there.\n");
for(j=O;j<i;j++) mytake(things[j]->query_name()+" from bag");
return 1;
}

int myput(string str) {
int i;
string obj;
object ob;
if(!str) return 0;
if(i=sscanf(str, "%s in bag", obj) != 1) return notify_fail("Maybe try put <object> in bag.\n");
if(!(ob = present(obj, this_player()))) return notify fail("You need that thing first man.\n");
if(ob->query_mass() + query_encumbrance() > query_max_encumbrance()) return notify_fail("You got too much stuff already.\n");
if(ob->query_prevent_put()) return notify_fail(ob->query_prevent_put());
write("You put "+ob->query_name()+" in the magic bag");
say((string)this_player()->query_cap_name()+" puts "+ob->query_name()+" in the bag.");
ob->move(this_object());
set_mass(50+(int)query_encumbrance()/10);
this_player()->add_encumbrance(ob->query_mass()/10);
return 1;
}

int mytake(string str) {
int i;
string obj;
object ob;
if (!str) return 0;
if(i=sscanf(str, "%s from bag", obj) != 1) return notify_fail("Uhh, try get <object> from bag.\n");
if(obj=="all") { move_all(); return 1; }
if(!(ob = present(obj, this_object()))) return notify_fail("That isnt in the bag.\n");
if(ob->query_mass()/9 + query_name()+" from the bag.");
say((string)this_player()->query_cap_name()+" gets "+ob->query_name()+" from the bag.");
ob->move(this_player());
set_mass(50(int)query_encumbrance()/10;
this_player()->add_encumbrance(-(ob->query_mass()/10));
return 1;
}
