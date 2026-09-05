//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"

void create()
{
        set("short", "安福门");
        set("long", @LONG
这里是宫城西面的安福门。东面是宽阔的承天门横街，
西面是通化门大街。
LONG);

        set("exits", ([
                "northup" : __DIR__"innerwall4",
                "southup" : __DIR__"innerwall6",
                "northeast" : __DIR__"chengtianstreet-5",
                "southeast" : __DIR__"chengtianstreet-6",
                "west" : __DIR__"tonghuastreet-4"
        ]));
        set("objects", ([
		      __DIR__"npc/jinwu-5": 1,
          __DIR__"npc/jinwu-1": 2,
        ]));
        
        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}

int valid_leave(object me,string dir)
{
	if ( check_obj_enter(me, dir) )
		return ::valid_leave(me, dir);
	else
	  return notify_fail("皇城禁地，闲人免入！\n");
}