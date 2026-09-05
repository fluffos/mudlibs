//铁锤
#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

int is_SmithHammer()
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
        set_name("铁锤",({ "tie chui", "chui", "hammer"}) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
				set("no_store",1);
				set("no_sell",1);
				set("no_pawn",1);
				set("no_sell_in_playershop",1);
                set("value", 250000);
				set("worn",3000);
                set("material", "steel");
                set("weapon_prop/dodge", -15);
                set("wield_msg", "$N运力提起了一把铁锤。\n");
                set("long", "这是铁匠常用的铁锤。\n");                
                set("unwield_msg", "$N把铁锤放了下去。\n");                
			}
        init_hammer(15);
        setup();
}
