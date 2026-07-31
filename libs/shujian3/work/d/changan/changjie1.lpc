// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/changjie1.c

inherit ROOM;
#include <room.h>

void create()
{
        set("short", "长街");
        set("long", @LONG
这是一条长长的街，一眼望不到头，不知道通向哪里。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"changjie1",
                "west"   : __DIR__"changjie1",
        ]));

        set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        me->add_temp("ca_chj",1);
  
        if( dir =="east") {
        if( me->query_temp("ca_chj") > 5 + random(5) ) {
                me->move(__DIR__"changjie2");
                me->delete_temp("ca_chj");
                return notify_fail("你累得半死，终于走完了这长长的街。\n");
                }
        }
        if( dir =="west") {
        if( me->query_temp("ca_chj") > 5 + random(5) ) {
                me->move(__DIR__"southjie3");
                me->delete_temp("ca_chj");
                return notify_fail("你累得半死，终于走完了这长长的街。\n");
                }
        }
        return ::valid_leave(me,dir);
}
