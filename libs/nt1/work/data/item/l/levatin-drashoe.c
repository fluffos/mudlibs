// SN:BTOXJEkLg4KG_7h@
// ITEM Made by player(慕容伤:levatin) /data/item/l/levatin-drashoe.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jun 15 16:56:30 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m九幽灭神靴[2;37;0m", ({ "drashoe" }));
	set_weight(3600);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双靴子。
以血魔之魄幻化而成，穿上他的人将拥有穿梭时空的能力。[2;37;0m
靴子缘上刻着一行小字：慕容伤(levatin)
");
	set("value", 2100000);
	set("point", 126);
	set("material", "magic stone");
	set("wear_msg", "[1;32m忽然一股莫名的力量将你包围起来，你立时感到动弹不得，无形而又巨大的压力让你喘不过气来。[2;37;0m\n");
	set("remove_msg", "[1;32m包围着你的力量消失了，压迫感也没有了，你感到四肢松动了许多，人也象获得了重生般，你轻松了下来。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
