// SN:1jU?@OZMjh4;nXMk
// ITEM Made by player(狐战四野:ydzzjz) /data/item/y/ydzzjz-dyd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Nov  8 00:10:50 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m东洋刀[2;37;0m", ({ "dyd" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
腰带缘上刻着一行小字：狐战四野(ydzzjz)
");
	set("value", 2100000);
	set("point", 58);
	set("material", "silk");
	set("wear_msg", "[1;33m$N嘿嘿一声冷笑，手中的东洋刀左突右伸，刀刀都从意想不到的地方砍向你！\n[2;37;0m\n");
	set("remove_msg", "[1;36m$N大喝一声，眼中凶光毕露，手中的东洋刀化作一道光弧直劈而下，正是扶桑密学「迎风一刀斩」。\n[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
