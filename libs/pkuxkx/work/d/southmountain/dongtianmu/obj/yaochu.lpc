//药锄
#include <weapon.h>
#include <ansi.h>

inherit AXE;

int is_DrugHoe()
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
        set_name("药锄",({ "yao chu", "chu", "hoe"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
				set("no_store",1);
				set("no_sell",1);
				set("no_pawn",1);
				set("no_sell_in_playershop",1);
                set("value", 100000);
				set("worn",150);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("wield_msg", "$N抓起了一把锄头。\n");
                set("long", "这是一小巧的锄头，可以用来采药。\n");                
                set("unwield_msg", "$N把药锄别在了腰中。\n");                
			}
        init_axe(5);
        setup();
}
