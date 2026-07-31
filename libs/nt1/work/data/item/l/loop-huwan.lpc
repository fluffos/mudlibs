// SN:8:KH`64B8C;WX^D\
// ITEM Made by player(胡小僧:loop) /data/item/l/loop-huwan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct  5 01:24:43 2003
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m秋月[2;37;0m", ({ "huwan" }));
	set_weight(3000);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一对护腕。
胡小僧的护腕，状如[1;36m秋月[2;37;0m，发出[1;36m蒙蒙青光。[2;37;0m
护腕缘上刻着一行小字：胡小僧(loop)
");
	set("value", 2100000);
	set("point", 43);
	set("material", "magic stone");
	set("wear_msg", "$N将$n套在腕上，内力到处，$n[1;36m青光[2;37;0m一展，隐隐有秋夜的凉意。[2;37;0m\n");
	set("remove_msg", "$N将$n自腕上除下，顿时[1;36m青光[2;37;0m一敛。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
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
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
