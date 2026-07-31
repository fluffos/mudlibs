// SN:_PN\8@77<_;SUE`4
// ITEM Made by player(渡邪:xuan) /data/item/x/xuan-like.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Oct 21 18:56:25 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m左右为[1;37m难[2;37;0m", ({ "like" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;35m一把锋利的[1;33m左右为[1;37m难[2;37;0m，
[1;35m它在[1;37m阳光[1;35m下[1;31m闪闪发光。[2;37;0m
铁掌缘上刻着一行小字：渡邪(xuan)
");
	set("value", 2100000);
	set("point", 310);
	set("material", "magic stone");
	set("wear_msg", "[1;34m\n≮‖天堂有路你不走‖≯\n\n≮‖鬼门关前成骷髅‖≯\n\n≮‖邪哥度你走西口‖≯\n\n≮‖！公子请慢走！‖≯\n\n　[1;37m￡邪哥送你归西￡[2;37;0m\n");
	set("remove_msg", "[1;34m\n≮‖啸客半世攻文武‖≯\n\n≮‖取霸图王得胜无‖≯\n\n≮‖只怕浮名终误我‖≯\n\n≮‖空留笑柄落江湖‖≯\n\n　　　　[1;37m$N℃[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
