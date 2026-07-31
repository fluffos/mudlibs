// sword.c : an example weapon
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIY"七彩情剑"NOR, ({ "qing jian" , "swird" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把七彩情剑。\n");
		set("value", 400);
		set("material", "steel");
	}
	init_sword(666);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N放下手中的$n。\n");


	setup();
}
