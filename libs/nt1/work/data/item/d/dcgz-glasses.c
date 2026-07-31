// SN:fFa6?[@18bhQ@bDf
// ITEM Made by player(大肠干燥:dcgz) /data/item/d/dcgz-glasses.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jun 21 19:11:10 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m透视眼镜[2;37;0m", ({ "glasses" }));
	set_weight(3375);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一顶头盔。
[1;33m一副透视用的眼镜，镜腿上刻着：大肠干燥[2;37;0m
头盔缘上刻着一行小字：大肠干燥(dcgz)
");
	set("value", 700000);
	set("point", 15);
	set("material", "iron");
	set("wear_msg", "$N偷偷摸摸的戴上一副$n，眼睛直盯着周围的人看。[2;37;0m\n");
	set("remove_msg", "$N取下一副$n，感觉一片茫然。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
