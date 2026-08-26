

#include <mudlib.h>

inherit OBJECT;

void create() {
	set("mass", 1);
	set("id", ({ "potion", "strengthpotion" }) );
	set("short", "potion of strength");
	set("long", @LONG
A potion enchanted by a powerful wizard.
LONG
	);
 set("value", 500); 
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
if (present("#STRENGTH_OB#", TP)){
this_object()->remove();
return 1;
}
spl = clone_object("/d/class/wizard/obj/strength_ob");
spl->move(TP);
spl->begin_spell(TP);
this_object()->remove();
return 1;
}
return 0;
}


