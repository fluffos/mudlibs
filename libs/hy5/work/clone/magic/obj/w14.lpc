// 龙剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(YEL"龙剑"NOR, ({"magic swordd", "mswordd"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", YEL"这是一把龙剑,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",50);
        }
     init_sword(550);
        setup();
}       