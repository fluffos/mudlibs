#include <mudlib.h>
inherit ARMOR ;
void create() {
        seteuid(getuid());
        set ("id", ({ "mining helmet", "helmet" }) );
        set ("name", "helmet");
        set ("short", "Mining Helmet") ;
        set ("long", @EndText
A standard mining helmet made of iron used to protect the head.
EndText
);      
        set_armor_type("helmet");
        set_bonus(2);
        set ("value", 400);
}
