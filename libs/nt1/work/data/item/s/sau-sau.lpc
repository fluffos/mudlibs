// SN:13akX6PFIoF=mo0L
// ITEM Made by player(白云:sau) /data/item/s/sau-sau.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar  1 17:15:33 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m玄冥掌[2;37;0m", ({ "sau" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：白云(sau)
");
	set("value", 2100000);
	set("point", 435);
	set("material", "magic stone");
	set("wear_msg", "[1;32m天堂有路～～～你不走啊！[2;37;0m\n");
	set("remove_msg", "[1;34m地狱无门～～～你自来投啊！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
