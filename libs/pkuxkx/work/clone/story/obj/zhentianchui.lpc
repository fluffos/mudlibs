//yitianjian.c
#include <weapon.h>

#include <ansi.h>
inherit HAMMER;

void create()
{
    set_name(HIW"震天锤"NOR, ({ "zhentian chui", "hammer", "chui"}) );
    set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
        	set("value", 50000);
                set("no_pawn", 1);
                set("no_sell", 1);
//        	set("no_drop", "1");
        	set("material", "iron");
                set("long", "这是一把震天锤，传说中，雷公打雷的时候就是用这玩意，你掂量了一下，不愧为仙家兵器，十分趁手。\n");
                set("wield_msg","$N双手举出一柄$n，霎那间，风雷之声不绝于耳。\n");
                set("unwield_msg", "$N双手舞了一个花，往回一收，将$n别在腰带上。\n");
	}
        init_hammer(200+random(80), TWO_HANDED);
	setup();
}
