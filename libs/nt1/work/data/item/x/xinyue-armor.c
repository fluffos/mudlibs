// SN:YeX9\V]Pf;9E>;hV
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-armor.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jul 24 19:11:07 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m沧海月明珠有泪[2;37;0m", ({ "armor" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
[1;34m一件比大海还要深沉的蓝色甲衣，随着风的掠过，衣服居然自己澎湃起来，然而中间那粒月白色的钮扣却发出淡淡柔光。[2;37;0m
护甲缘上刻着一行小字：慕容新月(xinyue)
");
	set("value", 2100000);
	set("point", 629);
	set("material", "silk");
	set("wear_msg", "[1;34m$N穿上一件$n[1;34m，整个人便仿佛隐入了无边的大海里面去了，但又如圣洁的女神似的，漂浮在海面上。\n$N丝般的长发随风飞舞，映衬着那颗月白色钮扣散发出的阵阵柔和光芒，虽不刺目，但却让人心神悸动，如醉如痴。[2;37;0m\n");
	set("remove_msg", "[1;34m好像是海潮猛然间退去一般，周围的空气仿佛一下子被抽空了，让人觉得失落，却又不知怎么言喻，十分失落。\n原来是$N卸下了身上的$n[1;34m，先前笼罩在四野的圣光也渐渐地消失在长空里，变成一颗泪滴洒在$N的怀里。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
