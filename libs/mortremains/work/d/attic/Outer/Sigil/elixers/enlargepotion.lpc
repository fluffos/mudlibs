

#include <mudlib.h>

inherit OBJECT;

void create() {
	set("mass", 1);
	set("id", ({ "potion", "enlargepotion" }) );
	set("short", "potion of enlarge");
	set("long", @LONG
A potion enchanted by a powerful wizard.
LONG
	);
set("value", 750);
   }

void init(){
add_action("drink", "drink");
}

int drink(string str){

object ob, spl;

if (!str){
write ("drink what?\n");
return 1;
}


seteuid(getuid());

ob = present(str, TP);

if (ob == this_object()){
if (present("#ENLARGE_OB#", TP)){
this_object()->remove();
return 1;
}
spl = clone_object("/d/class/wizard/obj/enlarge_ob");
spl->move(TP);
spl->begin_spell(10);
this_object()->remove();
return 1;
}
return 0;
}


