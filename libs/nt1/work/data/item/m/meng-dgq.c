// SN:lKS`^X``YP96lGMd
// ITEM Made by player(胡逸:meng) /data/item/m/meng-dgq.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Nov  1 23:48:34 2004
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m点钢枪[2;37;0m", ({ "dgq" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
这是一根白缨长钢枪，长可丈二，枪头隐隐透出寒光。[2;37;0m
刀柄上刻着一行小字：胡逸(meng)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "$N一声长啸，抖出[1;37m点钢枪[2;37;0m，一时间，阴风袭袭。[2;37;0m\n");
	set("unwield_msg", "$N一挥手，收起了[1;37m点钢枪[2;37;0m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
