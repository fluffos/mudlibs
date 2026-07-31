// SN:beA8i;KXBFDFde1`
// ITEM Made by player(小达子:mimee) /data/item/m/mimee-magua.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 17 16:08:54 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m黄马褂[2;37;0m", ({ "magua" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
皇帝才能穿的袍子，有时也赏赐给宠爱的大臣。[2;37;0m
战衣缘上刻着一行小字：小达子(mimee)
");
	set("value", 2100000);
	set("point", 155);
	set("material", "silk");
	set("wear_msg", "[1;33m$N穿上黄马褂，真是贵气逼人！[2;37;0m\n");
	set("remove_msg", "[1;33m$N将黄马褂小心的收了起来，弄丢了可是要掉脑袋的。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
