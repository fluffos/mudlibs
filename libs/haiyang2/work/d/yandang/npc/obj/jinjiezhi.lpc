#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("金戒指",({"jinjiezhi","jiezhi"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","只");
	set("long","金光闪闪的金戒指。\n");
	set("value",1000);
	set("material","gold");
	set("armor_prop/personality",2);
	set("armor_prop/karma",2);
	set("armor_prop/armor",24);
	set("armor_prop/dodge",2);
	}
	set("wear_msg",HIC"$N小心翼翼的戴上了$n。\n"NOR);
	set("unequip_msg",HIC"$N慢慢的把$n摘了下来。\n"NOR);
	setup();
}

