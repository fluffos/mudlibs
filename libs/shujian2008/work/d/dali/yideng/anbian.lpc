// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "岸边");
	set("long", @LONG
只见此处水柱在太阳照耀下映出一条眩目奇丽的彩虹，当此美景，你纵有
百般赞美之意，却也不知说甚么话好，只是坐在石上，胸中一片明净，再无别
念，看了半晌，忽听得彩虹后传出一阵歌声，只听他唱的是个"山坡羊"的曲儿。
向旁边望去，只见山边一条手臂粗细的长藤(teng)，沿峰而上。
LONG
	);
	set("outdoors", "桃源县");

	set("exits", ([
		"enter" : __DIR__"shandong",
	]));

	set("item_desc", ([
		"teng": "你仰头上望，见山峰的上半截隐入云雾之中，不知峰顶究有多高。\n",
	]));

	set("objects", ([
		__DIR__"npc/jiaozi" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_pa", "pa");
}

int do_pa(string arg)
{
	object me = this_player();

	if ( ! arg || arg != "teng") return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if ( !me->query_temp("yideng/jiaozi_pass")){
		if (present("jiao zi", environment(me)))
			return notify_fail("那樵子在侧，挡住了你的路线。\n");
		else
			return notify_fail("这长藤不知通向何处，你不由有些犹豫。\n");
	}

	message_vision(YEL"\n$N双手握着长藤，提气而上，双臂交互攀援，爬得甚是迅捷，片刻之间，离地\n"+
		"已有十余丈，隐隐听得那樵子又在唱曲。\n\n"NOR, me);
	me->move(__DIR__"shanding");
	me->delete_temp("yideng");
	return 1;
}
