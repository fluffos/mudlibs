// SN:oh_^DdFdAdj<F<;O
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-cap.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jul 24 21:09:55 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m望帝春心托杜鹃[2;37;0m", ({ "cap" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
[1;34m一个非常细致的发簪，右端弯曲成为一只杜鹃的模样，簪尖则刻有一颗心。[2;37;0m
头盔缘上刻着一行小字：慕容新月(xinyue)
");
	set("value", 2100000);
	set("point", 393);
	set("material", "magic stone");
	set("wear_msg", "[1;34m$N嫣然一笑，抽出一支杜鹃模样的发簪别在头上，把原先披散的青丝盘在脑后。\n然而盘上之后，那支发簪居然嗡嗡而鸣，其音凄惨悲切，仿佛有莫大的冤屈，而那杜鹃的嘴角鲜红欲滴，仿佛有血溅在上面。[2;37;0m\n");
	set("remove_msg", "[1;34m$N取下盘在脑后的那支发簪，先前那股莫可名状的嗡嗡之声，由强变弱，终至不可闻。\n$N看了看手中那支发簪，不知该如何是好，为什么它的上面有蜀国望帝的魂魄附在其上，难道是杜鹃的缘故？[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
