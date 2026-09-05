//baoxiang-jingshe.c -- 宝相精舍
//Zone: 万安寺
//Created by ddid
//2009-6-17

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"宝相精舍"NOR);
  set("long", @LONG
这里是万安寺的宝相精舍，万安寺的住持方丈应该就住在这里。不过
自从番僧霸占了万安寺，方丈就搬出去了，这里留给汝阳王府的入幕之宾
居住。屋内的南边和北边各有一个小门，分别通向南厢房和北厢房。

LONG
  );

  set("exits", ([     
      "east" : __DIR__"xiaoyuan",
  ]));

  setup();
}

void init()
{
	add_action("do_break", "break");
}

int do_break(string arg)
{
	object me;
	me = this_player();
	
	if ( !arg || (arg !="south" && arg != "north") )
		return notify_fail("你要干什么？\n");
	
	if ( (int)me->query("neili") < 1000 || (int)me->query("jiali") < 100 )
		return notify_fail("你的气力不足，撞不开小门。\n");
	
	if( arg=="south" )
	{
		message_vision(
				"$N撞开了南厢房的小门。\n", me);
        set("exits/south", __DIR__"xiangfang-south");
        call_out("closesouth",5);
        return 1;
	}
	
	if( arg=="north" )
	{
		message_vision(
				"$N撞开了北厢房的小门。\n", me);
        set("exits/north", __DIR__"xiangfang-north");
        call_out("closenorth",5);
        return 1;
	}
	
	return 1;
}

int closesouth()
{
	delete("exits/south",);
    tell_room(this_object(),"小门又被人从里面关上了。\n");
	return 1;
}

int closenorth()
{
	delete("exits/north",);
    tell_room(this_object(),"小门又被人从里面关上了。\n");
	return 1;
}