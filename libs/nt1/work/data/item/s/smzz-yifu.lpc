// SN:YRN`@<QIR3g0:^@C
// ITEM Made by player(张无忌:smzz) /data/item/s/smzz-yifu.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jul  8 04:06:55 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m教主[1;31m长袍[2;37;0m", ({ "yifu" }));
	set_weight(3600);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[33m乌金丝[2;37;0m炼制而成的一件战衣。
[1;37m它看上去只是一件很普通的明教教主服装[1;31m只是衣服的边缘隐隐闪现出道道红光。[2;37;0m
战衣缘上刻着一行小字：张无忌(smzz)
");
	set("value", 1500000);
	set("point", 273);
	set("material", "silk");
	set("wear_msg", "[1;37m一道闪电滑破长空\n[1;36m一小股明教弟子突然出现在眼前为$N更换上[1;34m教主[1;31m长袍。\n[1;37m又是一道闪电滑破长空，[1;31m那群弟子居然又不见了。[2;37;0m\n");
	set("remove_msg", "[1;37m一道闪电滑破长空\n[1;36m一小股明教弟子突然出现在眼前为$N脱下[1;34m教主[1;31m长袍。\n[1;37m又是一道闪电滑破长空，[1;31m那群弟子居然又不见了。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
