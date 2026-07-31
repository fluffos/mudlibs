// SN:GST9adXkh4\Xi@^9
// ITEM Made by player(俞佩玉:peiyu) /data/item/p/peiyu-kongque.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 16 23:25:44 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m孔雀东南飞[2;37;0m", ({ "kongque" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
[1;32m一个由相思草扎成孔雀模样的头结，那孔雀当真是栩栩如生，展翅欲飞。[2;37;0m
头盔缘上刻着一行小字：俞佩玉(peiyu)
");
	set("value", 2100000);
	set("point", 153);
	set("material", "magic stone");
	set("wear_msg", "[1;32m$N对着过往的浮云长啸一声：“舒卷无常的云啊，请呼唤来我心爱的孔雀！”\n只闻天空中传来一阵孔雀的鸣叫声，$N的头顶已经多了一个孔雀形头结，那孔雀栩栩如生，眼神流转处，透露出一种深深的悲哀。[2;37;0m\n");
	set("remove_msg", "[1;32m$N对着掠过的长风清叱一声：“来去无定的风啊，请把我的孔雀带给我的心上人。”\n一阵孔雀啾啾的鸣叫声，传自$N头顶的那个草结，风儿掠过之后，那草结也了无踪迹，远处隐隐传来的鸣叫声也凄惨如杜鹃啼血。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
