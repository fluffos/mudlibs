//Cracked by Kafei
// hammer.c

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
static int amount;

void create()
{
        set_name(HIY"金轮"NOR, ({ "jin lun", "falun", "lun" }) );
//	set_color("$HIY$");
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("base_unit", "只");
                set("base_weight", 10000);
		set("long", "这是一只纯金铸造直径尺半的一个圆环，上面刻满了密宗伏魔真言，环内中空，藏有九个铁球。\n");
		set("value", 7000);
		set("material", "iron");
		set("base_weapon", 50);
		set("rigidity", 100000);
		set("wield_msg", "$N拿出一副$n，试了试重量，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

        init_hammer(380);
//	set_amount(5);
	setup();
}


