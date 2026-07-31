// SN:fE6MT=C8R5`HUS<<
// ITEM Made by player(行香子:michael) /data/item/m/michael-cxnx.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Oct 12 14:02:30 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m点绛唇[2;37;0m", ({ "cxnx" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
[1;32m点绛唇[2;37;0m
靴子缘上刻着一行小字：行香子(michael)
");
	set("value", 2100000);
	set("point", 89);
	set("material", "silk");
	set("wear_msg", "[1;32m寂寞深闺，柔肠一寸愁千缕。惜春春去，几点催花雨。倚遍栏干，只是无情绪！人何处？连天衰草，望断归来路。[2;37;0m\n");
	set("remove_msg", "[1;32m蹴罢秋千，起来慵整纤纤手。露浓花瘦，薄汗轻衣透。见有人来，袜铲金钗溜，和羞走。倚门回首，却把青梅嗅。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/dodge", apply_armor() / 10 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
