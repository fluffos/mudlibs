// wh-cloth.c thd 四代女弟子穿

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(WHT"浅灰绸衫"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一件浅灰色的绸衫。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

