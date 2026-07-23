// 银色长枪
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name(HIB"魔法长鞭"NOR, ({"magic whip", "mwhip"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIB"这是一把魔法长鞭,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",30);
        }
     init_whip(470);
        setup();
}       