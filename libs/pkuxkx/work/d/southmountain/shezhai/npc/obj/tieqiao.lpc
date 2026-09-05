#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

int is_shovel()
{
	return 1;
}
int worn(int times)
{
	if (times<1)
	times=1;
	add("worn",-times);
	if (query("worn")<1)
	{
		message_vision(WHT"$N"+WHT+"，因为多次使用，已经被彻底损坏了。\n"NOR,this_object());
		destruct(this_object());
	}
	return 1;
}
void create()
{
	set_name("铁锹", ({"tie qiao","qiao","shovel"}));
	set_weight(2700+random(400));
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一把铁锹，矿工用来采矿(excavate)。\n");
            set("unit", "把");
            set("no_store",1);
			set("no_sell",1);
			set("no_pawn",1);
			set("no_sell_in_playershop",1);
			set("value", 100000);
			set("worn",150);
			set("material", "steel");
			set("weapon_prop/dodge", -5);
			set("wield_msg", "$N举起了一把铁锹，准备战斗。\n");              
			set("unwield_msg", "$N把铁锹放了下来。\n");                
	}
	init_hammer(10);
	setup();
}

