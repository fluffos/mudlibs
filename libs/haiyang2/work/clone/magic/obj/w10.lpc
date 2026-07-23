// 地狱鬼斧
#include <ansi.h>
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name(HIG"美津浓求棒"NOR, ({"magic clubc", "mclubc"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIG"这是一把美津浓求棒,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",40);
        }
     init_club(480);
        setup();
}       