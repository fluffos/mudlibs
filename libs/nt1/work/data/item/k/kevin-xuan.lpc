// SN:K2FYe:4YM6D[S[0M
// ITEM Made by player(道魔:kevin) /data/item/k/kevin-xuan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 10 13:32:29 2004
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36m玄冥神鞭[2;37;0m", ({ "xuan" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[33m乌金丝[2;37;0m炼制而成的一根鞭。
[1;31m这是一把旷古绝伦的神器。[2;37;0m
鞭柄上刻着一行小字：道魔(kevin)
");
	set("value", 1500000);
	set("point", 70);
	set("material", "silk");
	set("wield_msg", "[1;33m嗖的一声，神鞭自行跃入手中，刹时杀气腾腾！[2;37;0m\n");
	set("unwield_msg", "[35m神鞭在空中划出一道优美的弧线落入腰间。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
