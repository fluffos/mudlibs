// SN:62VoV\nG2KlOMOhi
// ITEM Made by player(李太白:libai) /data/item/l/libai-huwan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jan  2 14:19:04 2004
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m青玉镯[2;37;0m", ({ "huwan" }));
	set_weight(3000);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一对护腕。
护腕缘上刻着一行小字：李太白(libai)
");
	set("value", 2100000);
	set("point", 59);
	set("material", "magic stone");
	set("wear_msg", "[1;35m$N取出一对$n[1;35m，戴在手腕上。[2;37;0m\n");
	set("remove_msg", "[1;35m$N将$n[1;35m自手腕上除下，随手抛入空中。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
