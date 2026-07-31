//Cracked by Kafei
// xuantie-jian 玄铁剑
// qfy July 5, 1996

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
        set_name(HIB"玄铁重剑"NOR,({ "xuantie jian", "xuantie", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 8000);
                set("material", "steel");
		set("rigidity", 10000);
                set("long", 
		"此剑黑黝黝的毫无异状，却是沉重之极。两边剑锋都是钝口，剑尖更圆圆的似是个半球。\n");
                set("wield_msg", HIY "$N举起$n，但见日月无光，沉雷郁郁，似乎要将一切生机压毁。\n" NOR);
                set("unwield_msg", HIY "玄铁乍收，生机徒现。\n" NOR);
                set("unequip_msg", HIY "玄铁乍收，生机徒现。\n" NOR);
        }
	init_sword(500);
        set("bwdhpk",1);setup();
//	::create();
}

