// 地狱鬼斧
#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
        set_name(HIC"地狱鬼斧"NOR, ({"magic axe", "maxe"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIC"这是一把地狱鬼斧,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",60);
        }
     init_axe(400);
        setup();
}       