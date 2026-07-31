// SN:9@4iN8_@I6Ro@S0b
// ITEM Made by player(张无忌:smzz) /data/item/s/smzz-yaodai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 12 20:42:07 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m教主[1;31m腰带[2;37;0m", ({ "yaodai" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
[1;37m一条用金丝绣成的教主专用[1;31m腰带。[1;32m上面绣着一团[31m红色火焰[2;37;0m
腰带缘上刻着一行小字：张无忌(smzz)
");
	set("value", 2100000);
	set("point", 156);
	set("material", "silk");
	set("wear_msg", "[1;37m一道闪电划破长空[1;32m一群身着红色火焰图案的[31m名教弟子\n[1;32m必恭必敬的为他们的教主系好[1;34m教主[1;31m腰带。[2;37;0m\n");
	set("remove_msg", "[1;37m一道闪电划破长空[1;32m一群身着红色火焰图案的[31m名教弟子\n[1;32m必恭必敬的为他们的教主换下[1;34m教主[1;31m腰带。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
