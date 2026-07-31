// SN:7h6GTZOLYZ18TFK2
// ITEM Made by player(独孤傲:shadowkwan) /data/item/s/shadowkwan-finger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Mar 17 19:03:51 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m穿云[1;33m破日[1;37m指[2;37;0m", ({ "finger" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
[1;37m以[1;36m万年玄冰[1;37m和[1;33m千年烈焰[1;37m铸成的指套，水火不侵，威力惊人，可纵横天地人三界[2;37;0m
指套缘上刻着一行小字：独孤傲(shadowkwan)
");
	set("value", 2100000);
	set("point", 311);
	set("material", "magic stone");
	set("wear_msg", "[1;37m天崩[1;33m地裂，[1;36m风[1;34m云[1;37m变色，[1;37m十丈内卷起风尘百丈。[2;37;0m\n");
	set("remove_msg", "[1;33m但见天地一片祥和，万物寂静。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
