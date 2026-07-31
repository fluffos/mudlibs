// SN:9B<nS];XXS\K<\Z[
// ITEM Made by player(勇哥:hanweiyong) /data/item/h/hanweiyong-weiyong.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr 25 18:10:01 2004
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m圣战披肩[2;37;0m", ({ "weiyong" }));
	set_weight(3000);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一对护腕。
[1;37m这似乎是传奇年代最高级战士穿的披肩[2;37;0m
护腕缘上刻着一行小字：勇哥(hanweiyong)
");
	set("value", 2100000);
	set("point", 25);
	set("material", "magic stone");
	set("wear_msg", "[1;33m我穿上了圣战披风抖了抖两下[2;37;0m\n");
	set("remove_msg", "[1;31m披风上掉下了一文铜钱[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
