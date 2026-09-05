// xuan-cloth.c
//

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("护法袈裟", ({ "jia sha", "cloth" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 50);
                set("wear_msg","$N拿出一件$n披在身上。\n");
                set("remove_msg","$N把$n从身上脱了下来。\n");
        }
        setup();
}

