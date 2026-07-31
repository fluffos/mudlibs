// 龙骑士枪
#include <ansi.h>
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name(HIW"龙骑士枪"NOR, ({"magic clubd", "mclubd"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIC"这是一把龙骑士枪,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",200);
        }
     init_club(400);
        setup();
}       