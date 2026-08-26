
#include "../defs.h"
int ring;
inherit OBJECT;

void create() {
  seteuid(getuid());
  set("short", "a large bell");
  set("long", @ENDLONG
This bell is on the verge of collapsing, it is very rusty, but it
still can be rung.
ENDLONG
  );
  set("id", ({
    "bell",
    
    
  }));
  set("bulk", 50);
  set("mass", 10000);
  set_value(0);
 }
void init() {
        add_action ("ring", "ring") ;
}

int ring(string str) {


        if (!str || !id(str)) {
                notify_fail ("Ring what?\n") ;
                return 0 ;
        }
         if(str)
            {
            write("You ring the decaying bell and the citizens of the town look up at
you in wonder!\n");
            return 1;
            }

