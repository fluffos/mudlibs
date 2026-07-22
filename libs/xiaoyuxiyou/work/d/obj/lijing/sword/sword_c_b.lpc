#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
    set_name(HIY"豪曹宝剑"NOR, ({"sword","jian" }) );
    set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
                set("no_put",1);
                set("no_zm",1);
                set("value", 200000);
                set("material", "iron");
                set("weapon_prop/strength", 10);
        	set("long", "这是一件上古宝物。\n");
        	set("wield_msg","一道金光闪过，$N手中已多了把$n。\n");
        	set("unwield_msg", "$N放下手中的$n。\n");
	}
        init_sword(145);
	setup();
}
