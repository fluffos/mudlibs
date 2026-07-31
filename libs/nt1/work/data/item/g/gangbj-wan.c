// SN:E4lSHAH37bidnQH;
// ITEM Made by player(唐三藏:gangbj) /data/item/g/gangbj-wan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov 16 01:27:18 2003
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m护腕[2;37;0m", ({ "wan" }));
	set_weight(3000);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一对护腕。
这双护腕看上去制作得非常精美，是唐三藏的心爱之物。[2;37;0m
护腕缘上刻着一行小字：唐三藏(gangbj)
");
	set("value", 2100000);
	set("point", 63);
	set("material", "magic stone");
	set("wear_msg", "[1;36m$N将$n[1;36m戴在腕上。[2;37;0m\n");
	set("remove_msg", "[1;36m$N将$n[1;36m自腕上除下。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
