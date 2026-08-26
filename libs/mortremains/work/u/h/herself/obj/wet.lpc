
#include <mudlib.h>

inherit OBJECT ;

void create() {
    set("id" , ({"wet" , "wetness"}) );
    set("short" , "");
    set("long" , wrap(""));
    set("extra_look" , (capitalize(subjective(TP->query("gender"))))+
      " is all wet.\n");
    set("invisible" , 2);
    set("mass" , 1);
    set("bulk", 1);
    set("value" , 0);
}
