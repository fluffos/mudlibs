

#include <mudlib.h>

inherit OBJECT;

void create() {
	set("mass", 1);
	set("id", ({ "potion", "hastepotion" }) );
	set("short", "potion of haste");
	set("long", @LONG
A potion enchanted by a powerful wizard.
LONG
	);
set("value", 5000);
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

spl = clone_object("/d/class/wizard/obj/haste_ob");
spl->move(TP);
spl->begin_spell(TP, 10);
write("You speed up immeasurably.\n");
this_object()->remove();
return 1;
}
return 0;
}


