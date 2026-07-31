// shejing.c  沙漠绿洲
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIG"沙漠绿洲"NOR);
	set("long", @LONG
这是一片周围长着青草的平地。这里有一口用石头堆起来的石井，井边有
一个为人喝水用的石碗，这里是专门供来住的人们休息之地。
LONG);
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"dashaqiu",
		"west" : __DIR__"bank",
		"north" : __DIR__"shanjiao",
//		"south" : "/d/chengdu/road6",
        ]));
	set("objects",([
		__DIR__"npc/shangren" : 2,
        ]));
        set("outdoors", "明教光明顶");
	setup();
}

void init()
{
        object me = this_player();
        if(me->query_temp("mj/xunluo") && !me->query_temp("mj/shejing"))
           me->set_temp("mj/shejing",1);
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;
	me = this_player();
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if (current_water<max_water) {
		me->set("water", current_water+20);
		message("vision", me->name()+"趴在石井边上用石碗舀了一碗水喝。\n", environment(me), ({me}) );
		write("你喝了一口石井中的泉水，顿时一股无比清凉的感觉涌上心头。\n");
	}
	else write("虽然你还想喝，但确实喝不下了！\n");
	return 1;
}
