#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY"天蚕宝甲"NOR, ({ "baojia", "jia" , "tiancan baojia" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一件用天蚕丝制成的宝甲\n");
		set("material", "cloth");
		set("unit", "件");
        set("value",1000000);
		set("armor_prop/armor", 800);
	}
	setup();
}
