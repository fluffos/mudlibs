// ITEM Made by player(临华:mmm9999_1) /data/item/m/mmm9999_1-zzz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May  2 07:08:51 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m紫霞[2;37;0m", ({ "zzz" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;31m真龙[2;37;0m炼制而成的一柄剑。
[31m我真真爱的紫霞，不知道在哪？我也不知何去何从[2;37;0m
剑柄上刻着一行小字：临华(mmm9999_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[31m如果上天再给我一次机会，我要打破魔咒，还我花果山一个清净[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
