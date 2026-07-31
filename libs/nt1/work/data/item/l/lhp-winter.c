// SN:Qh?ihP`dfYYGOXfX
// ITEM Made by player(少龙:lhp) /data/item/l/lhp-winter.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun  9 18:01:13 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m冬季恋歌[2;37;0m", ({ "winter" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[1;37m如果这是最好的结局，为何我还忘不了你，时间改变了我们告别了单纯。[2;37;0m
战衣缘上刻着一行小字：少龙(lhp)
");
	set("value", 2100000);
	set("point", 682);
	set("material", "silk");
	set("wear_msg", "[1;37m从没想过我会再次见到你，从没想过我会仍然爱著你。[2;37;0m\n");
	set("remove_msg", "[1;37m那一刻当我闭上双眼历历在眼前[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
