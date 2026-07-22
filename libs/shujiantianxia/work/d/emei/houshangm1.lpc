// emei 灌木丛

#include <room.h>
inherit ROOM;

int do_zong(string arg);

void create()
{
	set("short", "灌木丛");
	set("long", @LONG
这里是一片一人多高的灌木丛，这里已经罕见足迹。一阵风吹过，灌木丛
发出沙沙的声音。东南西北都是矮树灌木，这里没有路，每走一步，荆棘都会
钩刺到衣裤，划破你的身体。前面是一面很高的峭壁，隐约地似乎看到有一个
不大的洞口，峭壁下面是一个水潭。
LONG
	);

	set("exits", ([
		"westup" : __DIR__"houshangm",
	]));

	set("outdoors", "峨眉山");
	setup();
}

void init()
{
	add_action("do_zong", ({"zong", "yue"}));
}

int do_zong(string arg)
{
	object me=this_player();

	if (!arg && arg != "峭壁" && arg != "洞口" )
		return notify_fail("你要干什么？\n");

	if ( random((int)me->query("jingli")) >= 100 
	|| me->query("family/master_id") == "guhong zi") {
		message_vision("$N一纵身向峭壁的洞口跃去。\n", me);
		me->move(__DIR__"houshandk");
	}
	else {
		message_vision("$N一纵身向峭壁的洞口跃去，结果一个不小心，摔下了水潭。\n", me);
		me->move(__DIR__"shuitan");
		me->set("water", 555);
		me->unconcious();
	}
	return 1;
} 
