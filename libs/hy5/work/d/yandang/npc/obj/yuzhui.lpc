#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("玉坠子",({"yuzuizi","yuzui"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","只");
	set("long","一只小巧玲珑的玉坠子。\n");
	set("value",1000);
	set("material","stone");
	set("armor_prop/personality",2);
	set("armor_prop/karma",2);
	set("armor_prop/armor",14);
	set("armor_prop/dodge",3);
	}
	set("wear_msg",HIC"$N小心翼翼的戴上了$n。\n"NOR);
	set("unequip_msg",HIC"$N慢慢的把$n摘了下来。\n"NOR);
	setup();
}


