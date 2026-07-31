// ITEM Made by player(蛋仔:mxjd001_1) /data/item/m/mxjd001_1-llll.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 27 21:37:27 2023
#include <ansi.h>
#include <weapon.h>

inherit CLUB;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m定[1;34m海[1;36m神[30m针[2;37;0m", ({ "llll" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;31m真龙[2;37;0m炼制而成的一根棍。
棍柄上刻着一行小字：蛋仔(mxjd001_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;36m管他那么多，上天安排的最大嘛！[2;37;0m\n");
	set("unwield_msg", "[1;33m因为你看上去像女人，我才不伤害你。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_club(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
