// SN:C=C9I;h:Q8X5F_QM
// ITEM Made by player(狐踪魅影:ydzzgb) /data/item/y/ydzzgb-pbu.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Oct 19 02:41:57 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m破布[2;37;0m", ({ "pbu" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：狐踪魅影(ydzzgb)
");
	set("value", 2100000);
	set("point", 137);
	set("material", "silk");
	set("wear_msg", "[1;31m$N仰天一声长哮，提运血海魔功，全身骨骼爆响，真气荡漾，衣衫顿时膨胀，气势迫人。\n[2;37;0m\n");
	set("remove_msg", "[1;31m$N淡淡一笑，脸现慈和之意，衣裳无风自动，似乎有一股气流回旋。\n[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
