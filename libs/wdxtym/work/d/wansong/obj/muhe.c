// smallbox.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("木盒子", ({"木盒子"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
"这小木盒子满是灰尘，粘满了煤屑柴草，你似乎可以把它"ZJURL("cmds:打开 木盒子")ZJSIZE(15)"打开"NOR"看看!\n");
		set("unit", "只");
		set("open_count", 1);
		set_weight(1000);
	}
}

void init()
{
	add_action("do_open","打开");
}

int do_open(string arg)
{
	object ob, me = this_player();
	if (! id(arg))
		return notify_fail("你想打开什么？\n");
	else if (query("open_count") > 0)
	{
       		message_vision(HIR 
"$N伸手打开木盒子，盒子里有一本书，上写《魔教医术》四字，用
钳子揭开数页，见写满密密小字，又有许多图画。有的是地图，
有的是药材图案。"NOR"\n", this_player());
		ob = new("/clone/book/mojiao");
		ob -> move(me);
		return 1;
	}
	else return notify_fail("木盒子已经被别人打开过了。\n");
}
