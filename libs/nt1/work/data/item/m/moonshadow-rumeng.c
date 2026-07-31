// SN:OMBG7XR;IP\IDLCl
// ITEM Made by player(月影:moonshadow) /data/item/m/moonshadow-rumeng.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jul  8 21:22:46 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m如梦[1;33m令[2;37;0m", ({ "rumeng" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;31m月梦宫宫主[1;35m月影[1;31m的贴身武器。[2;37;0m
铁掌缘上刻着一行小字：月影(moonshadow)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wear_msg", "[1;35m$N[1;37m轻轻拂过$n，[1;37m幽幽吟道：知否知否，应是[1;32m绿[1;37m肥[1;31m红[1;37m瘦。四周顿时弥漫着[1;31m红[1;32m绿[1;37m色的迷雾。[2;37;0m\n");
	set("remove_msg", "[1;35m$N[1;36m缓缓将$n[1;36m收回剑鞘，四周的迷雾才渐渐飘散。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
