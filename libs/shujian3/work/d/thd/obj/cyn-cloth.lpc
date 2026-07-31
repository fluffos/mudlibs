// cyn-cloth.c thd 三代女弟子穿

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(CYN"蓝绿绸衫"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一件蓝绿色的绸衫。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 20);
        }
        setup();
}


