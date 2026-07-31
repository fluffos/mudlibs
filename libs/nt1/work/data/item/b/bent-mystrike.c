// SN:]ceCYAZZMW=[eb6_
// ITEM Made by player(段微风:bent) /data/item/b/bent-mystrike.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov 21 19:08:49 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m结草[1;34m御环[2;37;0m", ({ "mystrike" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;32m它安然畅意，似乎就要腾空而去，跳出三界，不入五行。世间万物，仿佛俱在它霸气所及之处。冤魂不舞、群邪辟易，无不被这双[1;31m结草[1;34m御环[2;37;0m
[1;32m上古神兵的霸气所制。[2;37;0m
铁掌缘上刻着一行小字：段微风(bent)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "magic stone");
	set("wear_msg", "$N伸手一指，$n像有生命似的跃动起来。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m结草[1;34m御环[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
