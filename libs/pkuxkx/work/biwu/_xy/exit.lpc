// Room: exit.c
// edit: by zine Aug 29 2010
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是一条泥泞的小路。
LONG
	);
	set("exits", ([
		  
		]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	object me=this_player();
	me-> delete_temp("xiangyang");
    if (!me->query_temp("xiangyang/poem"))
    {
        call_out("poem", 1 , me);
    }
	return;
}

int poem(object me)
{
	tell_object(me,HIC"你回想其刚才在襄阳的经历，不禁唏嘘。正所谓：\n");
    me->set_temp("xiangyang/poem",1)
	call_out("poem2", 2 , me);
	return 1;
}

int poem2(object me)
{
	tell_object(me,HIW"天下风云出我辈，一入江湖岁月催。皇图霸业笑谈中，不胜人生一场醉。\n"NOR);
	return 1;
}