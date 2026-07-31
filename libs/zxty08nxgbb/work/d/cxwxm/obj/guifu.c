//marry 8.13
#include <weapon.h>

#include <ansi.h>

inherit AXE;

void create()
{
        set_name(HIR"鬼斧"NOR, ({ "guifu","axe" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 1000);
                set("material", "blacksteel");
                set("long", "别看它尺寸巨大、其貌不扬，但却是痴心妄想门开山始祖用上古\n"
"玄铁铸成的鬼斧。\n");
                set("wield_msg", "$N从背后拔出一柄亮晃晃$n握在手中　\n");
                set("unequip_msg", "$N将手中的$n插在背后。　\n");
        }
//marry 8.13
{       set("no_get",1);
        set("no_drop",1);
        set("no_give",1);
}

        init_axe(900);
        setup();
}

