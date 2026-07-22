//Yanqi 08/10/2k

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIY"黄河大堤"NOR);
        set("long", @LONG
这里就是黄河大堤了，汹涌的黄河水咆哮着向东流去，水里还不时夹杂着
从上游冲下来的一些动物、木板、铁锅......。你四下里看了看，很多人在这
里忙着加固堤坝。
LONG );
        set("exits", ([
                "southdown" : __DIR__"huanghe7",
        ]));

        set("no_get_from", 1);
	set("no_fight",1);
	set("no_sleep_room",1);
	
        set("outdoors", "黄河");
        setup();
}

void init()
{
	add_action("do_qi","qi");
}

int do_qi(string arg)
{
	object me,shi;
	
	me=this_player();
	
	if (arg!="shi") return notify_fail("你要砌什么？\n");
	
	shi=present("shi kuai",me);
	
	if (!shi) return notify_fail("你要用什么砌？\n");
	
	if (me->query_temp("newbiejob1/start"))
	{
          if ((me->query("qi")<10) || (me->query("jingli")<20)) 
		{
			me->unconcious();
			return 1;
		}
		me->add_temp("newbiejob1/over",1);
		message_vision(HIY"$N把一块巨石放在了堤坝的一脚，然后用灰泥给砌好。\n"NOR,me);
		tell_object(me,HIM"你卸下身上的巨石，感觉轻松了不少！\n"NOR);

		if( (int)me->query_skill("cuff", 1) < 51 ) {
			tell_object(me, HIY"这一路艰难，你觉得自己的对基本拳法有些领悟。\n"NOR);
			me->improve_skill("cuff", me->query_int()/2 );
		}
		if( (int)me->query_skill("hand", 1) < 51 ) {
			tell_object(me, HIY"这一路艰难，你觉得自己的对基本手法有些领悟。\n"NOR);
			me->improve_skill("hand", me->query_int()/2 );
		}

		me->add("qi",-5);
		me->add("jingli",-10);
		destruct(shi);
		return 1;
	}
	else 
	{
		tell_object(me,HIR"突然一阵旋晕，你不由昏了过去。\n"NOR);
		destruct(shi);
		me->delete_temp("newbiejob1");
		me->unconcious();
		return 1;
	}
}
