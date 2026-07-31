// SN:clh[Kn4icoRD;TIb
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-axe.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jul 25 03:34:27 2004
#include <ansi.h>
#include <weapon.h>

inherit AXE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m天下英雄谁敌手[2;37;0m", ({ "axe" }));
	set_weight(13200);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把斧。
[1;34m一柄气势森森的斧子，斧刃上寒光不散，慑人心魄，斧面上雕刻的盘古，栩栩如生。[2;37;0m
斧柄上刻着一行小字：慕容新月(xinyue)
");
	set("value", 2100000);
	set("point", 786);
	set("material", "magic stone");
	set("wield_msg", "[1;34m$N双手拿起了一把斧子，威风凛凛、气势磅礴，仿佛最久远的大神盘古在辛勤的开天辟地，胸怀坦荡，无所奢求。\n$N手中的那把斧子上可以劈开时空，下可以斩开天地，当真是世间只此一人，天下莫可抗衡。[2;37;0m\n");
	set("unwield_msg", "[1;34m$N像盘古顶天立地一般，不让阴霾重现人间，就那么孤独的站着，终于累了，觉得应该休息一下了。\n$N于是放下了手中的巨斧，巨斧飞到了九天外的不周山山顶，守护着这由最为伟大的神创造出来的世界。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_axe(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
