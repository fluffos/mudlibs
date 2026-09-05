//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"

void create()
{
        set("short", "延喜门");
        set("long", @LONG
这里是宫城东面的延喜门。西面是宽阔的承天门横街，
东面是通化门大街。
LONG);

        set("exits", ([
                "northup" : __DIR__"innerwall3",
                "southup" : __DIR__"innerwall5",
                "east" : __DIR__"tonghuastreet-1",
                "northwest" : __DIR__"chengtianstreet-1",
                "southwest" : __DIR__"chengtianstreet-2",
        ]));
        set("objects", ([
		      __DIR__"npc/jinwu-4": 1,
          __DIR__"npc/jinwu-1": 2,
        ]));
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        set("outdoors", "changan");
        setup();
   
}

int valid_leave(object me,string dir)
{
	if ( check_obj_enter(me, dir) )
		return ::valid_leave(me, dir);
	else
	  return notify_fail("皇城禁地，闲人免入！\n");
}