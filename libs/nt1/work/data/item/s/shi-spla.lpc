// SN:`NNI2KZY6705Ta3a
// ITEM Made by player(石破烂:shi) /data/item/s/shi-spla.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 20 14:39:39 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m玉蒲团[1;33m玉女心经[2;37;0m", ({ "spla" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
由舒淇小姐主演，想看请传呼白居不易先生。[2;37;0m
铁掌缘上刻着一行小字：石破烂(shi)
");
	set("value", 2100000);
	set("point", 218);
	set("material", "magic stone");
	set("wear_msg", "财主西门坚为了女儿西门柔避开狂风浪蝶的追求，令女儿作男装打扮，女儿求学结识了书生花道，彼此有一段友谊发展，当花道发现她是女儿身，拼命追求。[2;37;0m\n");
	set("remove_msg", "坚一方面好色，本为白痴儿子娶妻舒淇，垂涎舒美色，更把她纳为妾。原来舒淇乃魔女幻姬化身，懂采阴补阳，暗中把徐的其他妾侍杀掉，最后更吸尽徐的精华。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
