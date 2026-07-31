//room : /u/jpei/thd/cave.c
#include <ansi.h>

inherit ROOM;

int do_pull(string arg);

void create()
{
	set("short", "岩洞");
	set("long", @LONG
这是一个山壁上的小岩洞，虽然不甚宽敞，但也有足够的活动空间。阳光
透过桃树间的缝隙射了进来，映得洞中半明半暗。靠里的洞壁上依稀写有一行
小字(zi)。
LONG
	);
	set("exits",([
		"out" : __DIR__"dongkou.c",
	]) );
	set("no_clean_up",0);
	set("item_desc",([
		"zi": "只见洞壁上用尖利之物刻着字道：“奉上臭尿数罐，请啊请啊....”，后面的字被一片树叶(ye)盖了起来。\n",
		"ye": "一片普通的树叶，把下面的字全都遮住了。\n",
	]) );
	set("objects",([
		__DIR__"npc/zhou.c" : 1,
	]) ); 

	setup();
}

void init()
{
	add_action("do_pull","pull");
	add_action("do_pull","che");
	add_action("do_pull","move");
	add_action("do_pull","yi");
	add_action("do_quit","quit");
}

int do_pull(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
	if (arg == "ye") {
		message_vision("$N伸手揭起树叶，猛听得头顶忽喇喇声响，立时醒悟，忙向一旁跃开，哪知乒乒乓乓一阵响亮，从洞顶上掉下几只瓦罐，淋了$N一头臭尿。\n", me);
		return 1;
	}
	return 0;
}

int do_quit()
{
	write("这里不准退出！\n");
	return 1;
}
