#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("珍珠项链",({"zhenzhu","xianglian"}));
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","串");
	set("long","一串由上好珍珠串成的项链。\n");
	set("value",2000);
	set("material","glass");
	set("armor_prop/personality",2);
	set("armor_prop/karma",2);
	set("armor_prop/armor",13);
	set("armor_prop/dodge",2);
	}
	set("wear_msg",HIC"$N小心翼翼的戴上了$n。\n"NOR);
	set("unequip_msg",HIC"$N慢慢的把$n摘了下来。\n"NOR);
	setup();
}

