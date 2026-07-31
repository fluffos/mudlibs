// SN:oHT:0:S7KBj_54jJ
// ITEM Made by player(堕落天使:depravity) /data/item/d/depravity-swordarm.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Nov 24 13:50:29 2003
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34m万剑魔甲[2;37;0m", ({ "swordarm" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
[35m万剑翼翅再生，浓烈魔气紫雾随剑锋冒出涌喷，围绕在[2;37;0m[34m万剑魔甲[2;37;0m[35m周围。[2;37;0m
护甲缘上刻着一行小字：堕落天使(depravity)
");
	set("value", 2100000);
	set("point", 217);
	set("material", "magic stone");
	set("wear_msg", "[1;31m魔气消散，$N全身已被崭新的魔甲覆盖，只见万剑以蜕变\n成邪恶的黑色，闪耀著一抹抹诡异紫芒！[2;37;0m\n");
	set("remove_msg", "[1;31m刹那之间，$n[1;31m已从$N身上消失的无影无踪。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
