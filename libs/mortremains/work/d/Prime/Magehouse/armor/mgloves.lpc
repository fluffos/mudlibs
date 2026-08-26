#include <mudlib.h>
inherit ARMOR ;
void create() {
        seteuid(getuid());
        set ("id", ({ "gloves", "mining gloves" }) );
        set ("name", "gloves");
        set ("short", "Mining Gloves") ;
        set ("long", @EndText
These tough leather gloves are used to protect the gnome's hands from
falling rocks or other debris.
EndText
);      
        set_armor_type("gloves");
        set_bonus(2);
        set ("value", 200);
}
