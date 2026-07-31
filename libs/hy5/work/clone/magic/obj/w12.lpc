// 地狱鬼斧
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name(RED"矮灵之匕"NOR, ({"magic daggerc", "mdaggerc"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", RED"这是一把矮灵之匕,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",100);
        }
     init_dagger(400);
        setup();
}       