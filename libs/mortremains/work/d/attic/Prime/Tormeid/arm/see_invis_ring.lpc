#include <mudlib.h>
#include "../defs.h"

inherit ARMOR ;

void create() {
  seteuid(getuid());
  set("id", ({ "strange ring", "ring" }) ) ;
 set("short", "a strange ring") ;
  set("long", @ENDLONG
This ring has strange runes and inscriptions all over it.
ENDLONG
  );
  set("mass", 25);
  set("wear_func", "blah") ;
  set("remove_func", "blah2") ;
  set("bulk", 20) ;
  set("value",3500) ;
  set_armor_type("ring");
  set("value", 3500 ) ;
  set("size", -1);
}

int blah() {
  TP->set("see_invis", 1) ;
  return 1;
}

int blah2() {
  TP->delete("see_invis") ;
  return 1;
}
