#include "/players/maledicta/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("chainmail");
set_alias("newbie_chain");
set_short("Chainmail");
set_long(
"  This is a well constructed suit of chainmail. Its links are\n"+
"made of a lightweight steel, and easily capable of withstanding\n"+
"most normal attacks. Small plates also protect the shoulders and\n"+
"upper arms.\n");
set_ac(3);
set_type("armor");  
set_weight(2);
set_value(0);
set_save_flag(0);
}

drop(silently) {
   ::drop();
    write("The chainmail crumbles as you drop it.\n");
    destruct(this_object());
    return 1;
}



