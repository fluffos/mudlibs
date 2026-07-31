// SN:;b1hY^5mU7o?:PTR
// ITEM Made by player(摩诃流星:lastlord) /data/item/l/lastlord-myclaw.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Aug  6 20:37:24 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m无求[1;36m易诀[2;37;0m", ({ "myclaw" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：摩诃流星(lastlord)
");
	set("value", 2100000);
	set("point", 603);
	set("material", "magic stone");
	set("wear_msg", "[1;37m$N手中绽出万丈白光，刺得周围一片炫目，脑海里一阵空白[2;37;0m\n");
	set("remove_msg", "[1;36m$N手中白光渐渐退去，留下四周片片寒意[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
