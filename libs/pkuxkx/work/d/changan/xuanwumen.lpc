
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"

void create()
{
        set("short", "玄武门");
        set("long", @LONG
这是大明宫的北大门玄武门，玄武门两边驻扎着皇家禁军
羽林军，守卫者大唐皇宫大明宫的安全。北面有一条官道通向
渭水河畔。
LONG        );
        
        set("exits", ([
                "south" : __DIR__"xuanwudian",
                "north" : __DIR__"guandaon1",
                "west" : __DIR__"yulin-2",
                "east" : __DIR__"yulin-1",
        ]));
        
        set("objects", ([
		      __DIR__"npc/jinwu-4": 1,
          __DIR__"npc/jinwu-1": 2,
        ]));
        
        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
}

int valid_leave(object me,string dir)
{
	if ( check_obj_enter(me, dir) )
		return ::valid_leave(me, dir);
	else
	  return notify_fail("大明宫禁地，闲人免入！\n");
}