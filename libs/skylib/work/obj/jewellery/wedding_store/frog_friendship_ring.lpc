inherit "/obj/armour";
#include <move_failures.h>
void setup(){
 set_name("ring");
 set_short("silver and green frog friendship ring");
 add_adjective(({"silver", "and", "green", "frog", "friendship"}));
 set_long("Laughing frogs are fashioned from silver and outlined in "
   "bright green enamel.  They leap and dance in bold relief on this "
   "heavy silver ring.  Each frog has two tiny emerald eyes.\n");
 set_type("ring");
 set_value(12000);
 add_property("no recycling", 1);
}
int set_worn_by(object who){
 set_value(0);
 return ::set_worn_by(who);
}