// SN:`4>JG;3j74[gZF@I
// ITEM Made by player(段灵:fifi) /data/item/f/fifi-king.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 25 12:19:33 2003
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m月[1;31m影[1;36m刀[2;37;0m", ({ "king" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
[1;36m带着寒气，阵阵寒风避人[2;37;0m
刀柄上刻着一行小字：段灵(fifi)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "[1;36m蓝光一出，[1;32m月影再现[2;37;0m\n");
	set("unwield_msg", "[1;31m蓝光回收，[1;33m月影入鞘[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
