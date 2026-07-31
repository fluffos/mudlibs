//jinsi-shoutao.c 金丝手套
//By Kayin @ CuteRabbit Studio 1999/3/21 new

#include <armor.h>
#include <ansi.h> 
inherit HANDS;

void create()
{
	set_name( HIC"金丝手套"NOR, ({ "jinsi shoutao", "shoutao" ,"gloves"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
                set("treasure",1);
		set("long", "这是一双有金丝制成的手套，坚韧无比，刀剑不能伤。\n");
		set("value", 10000);
		set("material", "gold");
                 set("no_drop", "这样东西不能离开你。\n");
                set("no_give", "这样东西不能给人。\n");
             set("nopawn",1);
             set("no_get",1);
                set("wield_msg", HIY"$N从怀中掏出一双$n戴在手上。\n"NOR);
                set("unwield_msg", HIY"$N取下$n放入怀中。\n"NOR);
		set("armor_prop/armor", 300);
		set("armor_prop/damage",200);
	}
	setup();
}
