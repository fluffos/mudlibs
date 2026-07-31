//niren dao.c
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
    set_name(HIW"逆刃刀"NOR, ({ "niren dao", "liren","dao" }) );
    set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
        	set("value", 30000);
        	set("no_drop", "1");
        	set("material", "iron");
        	set("long", "这是一把非刀非剑的武士刀，最奇怪的是刀刃向里。\n" );
        	set("wield_msg", HIW "一阵寒光闪过$N以拔刀术将逆刃刀拔了出来\n" NOR);
        	set("unwield_msg", HIW "$N快如闪电般将$n收回鞘内。\n" NOR);
	}
    	init_blade(300);
	setup();
}
