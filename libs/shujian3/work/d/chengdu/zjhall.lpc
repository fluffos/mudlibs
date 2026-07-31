// Room: /d/chengdu/zijuefuhall.c
// By Jpei

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "大厅");
	set("long", @LONG
这是子爵府的大厅，装饰的十分豪华，比较奇怪的是四周的墙上挂着的不
是名家字画，却是许多张棋谱，看来主人是很喜欢围棋的。一位衣着华贵的中
年人坐在太师椅上，几个家丁在一旁陪侍。
LONG
	);

	set("objects", ([
		__DIR__"npc/liuhaoyi" : 1,
	]));

	set("exits", ([
                "north" : __DIR__"zjmen",
                "west" : __DIR__"shufang",
	]));

	set("no_fight", 1);
	set("incity",1);
	setup();
}

void init()
{
	object me = this_player();

	if (present("ou xie pu", me)) me->set_temp("ouxiepu_got", 1);
}

int valid_leave(object me, string dir)
{
	object ob;

	if (dir == "west" && is_wanted(me))
		return 0;

	if (dir == "west" && !me->query_temp("qipu_guess_win")) {
		if ((ob = present("liu haoyi", this_object())) && living(ob)) {
			return notify_fail("刘好弈拦住你说：“我这个书房不同一般，门口装有厉害的机关，如果你想进去，先解一道题(question)再说！”\n");
		}
		return notify_fail("你踏步正要往里走，一道钢铡忽然从头上落下来，你连忙往后退，铡刀落在紧贴着你的大脚趾尖前，你吓出了一身冷汗！\n");
	}
	return ::valid_leave(me, dir);
}
