// Room: /city/kedian3.c
// YZC 1995/12/04 
// Modify by: hongdou 98.12.7

#include <ansi.h>
inherit ROOM;

void init()
{
   add_action("do_breakin","breakin");
}

void create()
{
        set("short", "浴室走廊");
	set("long", @LONG
这里是浴室的走廊，东边通向男宾房，西边
通向女宾房，外面是出口处。
LONG
	);

       set("objects", ([
       ]));

	set("exits", ([
       "east" : __DIR__"bath",
       "west" : __DIR__"bath1",
       "south" : __DIR__"anmofang",
        "out" : __DIR__"bathgate",
	]));

	setup();
}

int do_breakin()
{
    object me;
    me=this_player();
    if(me->query_temp("breakin"))
    {
	if( me->query("gender")=="女性")
	{
	    message_vision(HIY"$N轻叱一声，娇声道：“本姑娘什么没见过，有什么希奇的!”
随即闯了进去！\n"NOR,me);
	    me->move(__DIR__"bath");
	    tell_object(me,HIY"\n浴室里的所有人一惊，慌忙掩住了下体，不怀好意地看着你。\n"NOR);
	    return 1;
        }
	if( me->query("gender")=="男性" || me->query("gender")=="无性")
	{
	    message_vision(HIY"$N壮了壮色胆，猛的向女浴室冲了进去......\n"NOR,me);
	    tell_object(me,HIY"浴室里的女子们惊声尖叫起来，顾不得羞耻向你劈头盖脸地打来!\n"NOR);
	    message_vision(HIC"\n$N被打了出来，昏倒在地！\n"NOR,me);
	    me->unconcious();    
	    return 1;
	}
     }
     else return notify_fail("你要干什么？\n");
}

int valid_leave(object me, string dir)
{
   if ( dir == "out" ) 
   {
        me->delete_temp("rent_paid");
	me->delete_temp("breakin");
   }

   if((string)me->query("gender")=="女性" && dir=="east")
   {
	me->set_temp("breakin",1);
	return notify_fail("看清楚些，那里可是男浴室耶！难道你想闯入(breakin)吗?\n");
   }
 
   if(((string)me->query("gender")=="男性" || (string)me->query("gender")=="无性") && dir=="west")
   {
	me->set_temp("breakin",1);
	return notify_fail("大色狼！看清楚些，那里是女浴室，难道你想闯入(breakin)吗？\n");
   }
   return ::valid_leave(me,dir);
}
