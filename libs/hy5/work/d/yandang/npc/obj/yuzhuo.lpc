#include <ansi.h>
#include <armor.h>

inherit HANDS;

void create()
{
	set_name("玉镯",({"yuzhuo","zhuozi"}));
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","只");
	set("long","这是一只和阗美玉雕刻成的玉镯。\n");
	set("value",5000);
	set("material","glass");
	set("armor_prop/personality",2);
	set("armor_prop/karma",3);
	set("armor_prop/armor",14);
	set("armor_prop/dodge",3);
	}
	set("wear_msg",HIC"$N小心翼翼的戴上了$n。\n"NOR);
	set("unequip_msg",HIC"$N慢慢的把$n摘了下来。\n"NOR);
	setup();
}


