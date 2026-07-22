#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIY"匕首"NOR,({"bishou", "dagger"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit", "把");
                set("value", 7000);
                set("material", "steal");
                set("unique",1);
                set("long",HIY"这是一把精钢匕首，把手上刻着“郭靖”两个字。\n"NOR);
	}
	init_sword(20);
	setup();
}
