// SN:fS\Jii0ZKkRa8I88
// ITEM Made by player(唐甜:tangt) /data/item/t/tangt-moto.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Aug 22 23:20:19 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m摩托罗拉[2;37;0m", ({ "moto" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
最新款手机，重两公斤，成功人士必备[2;37;0m
铁掌缘上刻着一行小字：唐甜(tangt)
");
	set("value", 2100000);
	set("point", 289);
	set("material", "magic stone");
	set("wear_msg", "兴奋地向大家宣布：“有空打我的全泥巴通，我全天开机。”[2;37;0m\n");
	set("remove_msg", "的铃铃全泥巴通手机响了起来[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
