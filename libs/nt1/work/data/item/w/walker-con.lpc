// SN:8WUmmc=fcRlZ:T5=
// ITEM Made by player(拾荒者:walker) /data/item/w/walker-con.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Apr  6 03:19:55 2004
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("连线器[2;37;0m", ({ "con" }));
	set_weight(2250);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一对护腕。
护腕缘上刻着一行小字：拾荒者(walker)
");
	set("value", 700000);
	set("point", 7);
	set("material", "iron");
	set("wear_msg", "嗨\n战斗中不能练内功，会走火入魔。[2;37;0m\n");
	set("remove_msg", "嗨\n忽然浑身一阵剧痛，你中的化骨绵掌毒发了！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
