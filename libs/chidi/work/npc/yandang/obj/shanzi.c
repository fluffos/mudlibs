
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIW"湘妃竹素纸扇子"NOR , ({ "shan", "shanzi" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "上面是唐伯虎的美人图,把上系了个汉白玉坠子。\n");
		set("value", 120);
		set("material", "wood");
		set("wield_msg", "$N唰的一声打开$n。\n");
		set("unwield_msg", "$N收拢起手中的$n。\n");
	}

	init_sword(10);
	setup();
}
