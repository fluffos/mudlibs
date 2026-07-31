// hammer.c
#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
        set_name(HIG"战斧"NOR, ({"fu", "axe"}));
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
"这是把沉重的大斧，有八尺多长，锋利无比．\n");
                set("value", 5000);
                set("material", "iron");
                set("wield_msg",
"$N拿出一把$n握在手中，眼前闪过一道寒光．\n");
                set("unwield_msg", "$N放下手中的$n。\n");
		set("no_sell",1);
                set("weapon_prop/courage", 20);
        }

        init_axe(70);
        setup();
}

