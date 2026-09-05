
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"

void create()
{
        set("short", HIR"朱雀门"NOR);
        set("long", @LONG
这里是长安城皇城的大门，戒备森严，四周城墙环绕，周围府兵严守。
LONG
        );
        
        set("exits", ([
                "south" : __DIR__"zhuque",
                "north" : __DIR__"chengtianstreet-9",
                "westup" : __DIR__"innerwall10",
                "eastup" : __DIR__"innerwall9",
                
        ]));
        set("objects", ([
		      __DIR__"npc/jinwu-4": 1,
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