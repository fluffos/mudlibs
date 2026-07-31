// SN:kHQ2ceEFW8TD@C>;
// ITEM Made by player(辛弃疾:wizzle) /data/item/w/wizzle-mystrike.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Sep 25 23:25:14 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m五毒掌[2;37;0m", ({ "mystrike" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：辛弃疾(wizzle)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "magic stone");
	set("wear_msg", "[1;36m$N吸了一口气，[1;32m掌心先是一绿，[1;34m接着一黑，[1;32m然后转成深碧的颜色。[2;37;0m\n");
	set("remove_msg", "[1;35m$N微微颔首，[1;32m惨碧的掌心慢慢转成[1;37m白玉一般颜色。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
