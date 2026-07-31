// cloth5.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIC "绣花丝绸宫服" NOR, ({ "xiuhua fu", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件绣花丝绸宫服。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("wear_msg","$N拿出一件$n穿在身上。\n");
                set("remove_msg","$N把$n从身上脱了下来。\n");
        }
        setup(); 
}
