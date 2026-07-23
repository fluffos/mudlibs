#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("钻石戒指",({"zuanshijiezhi","jiezhi"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","只");
	set("long","五彩缤纷的钻石戒指。\n");
	set("value",2000);
	set("material","glass");
	set("armor_prop/personality",2);
	set("armor_prop/karma",2);
	set("armor_prop/armor",24);
	set("armor_prop/dodge",2);
	}
	set("wear_msg",HIC"$N小心翼翼的戴上了$n。\n"NOR);
	set("unequip_msg",HIC"$N慢慢的把$n摘了下来。\n"NOR);
	setup();
}


