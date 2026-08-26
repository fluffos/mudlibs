#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id( ({"sign","wooden sign"}) );
    set_name("wooden sign");
    set_short("A large wooden sign");
    set_weight(1000000);
    set_property("no animate", 1);
    set_long("The sign seems to be an advertisement and reads:\n\n%^BOLD%^%^BLUE%^Ferries depart from the Shadow docks regularly. You will find our docks nearby in the wharf district in the southeastern quarter of the city.%^RESET%^\n\n%^ORANGE%^There are rumors of rewards for those young adventurers brave enough to venture to the isle of Deku.\n\n%^GREEN%^The more experienced may wish to stop off at Laerad and perhaps even venture into the city of Asgard and beyond there.%^RESET%^\n\n%^BOLD%^For those having achieved some riches and success, visit Shadow docks or the affiliates in Torm or on various islands to rent or purchase a boat. You will need one to visit the more secluded and dangerous islands so save up your gold so you can own your own.");
    set_value(0);
}

void init(){
   ::init();
   add_action("read_sign","read");
}

int read_sign(string str){
   if(str != "sign") return 0;
   TP->force_me("look sign");
   return 1;
}

