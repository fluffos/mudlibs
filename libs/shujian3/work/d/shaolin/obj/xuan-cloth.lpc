// xuan-cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIR "护法袈裟" NOR, ({ "jia sha", "cloth" }) );
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件精心编织的红色护法袈裟。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 50);
                set("wear_msg","$N拿出一件$n披在身上。\n");
                set("remove_msg","$N把$n从身上脱了下来。\n");
        }
        setup();
}

