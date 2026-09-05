// xue-dao.c 血刀
//whuan

#include <ansi.h>;
#include <weapon.h>;
inherit F_UNIQUE;
inherit BLADE;

void create()
{
	set_name( RED"血刀"NOR , ({ "blood blade", "blade", "dao" }));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", HIR "一柄软软的缅刀，刀身不住颤动，宛如活蛇一般。引光望去，刀锋全是暗红之色，血光隐隐，极是可怖。\n" NOR );
		set("value", 1000);
		set("material", "steel");
                set("wield_msg", RED"只听「唰」的一声，血刀脱鞘飞出，$N手中似是握住一条赤蛇泛着红光，弥漫着一片血气！\n"NOR);
		set("unwield_msg", RED"只见$N随手一挥,血刀象一条赤蛇飞舞入鞘。\n"NOR);
	  set("preorder",0);
    set("robinterval",7200); 
	}
	init_blade(180);
	setup();
}


