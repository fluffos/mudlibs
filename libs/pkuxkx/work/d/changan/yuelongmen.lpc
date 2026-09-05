//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"

void create()
{
        set("short", "跃龙门");
        set("long", @LONG
这是南大内兴庆宫的北门跃龙门，南面是正殿南薰殿，
北面是繁华的通化门大街。
LONG);
        set("exits", ([
           "south" : __DIR__"nanxundian",
           "north" : __DIR__"tonghuastreet-3"
        ]));

        set("objects", ([
		      __DIR__"npc/jinwu-4": 1,
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
	  return notify_fail("兴庆宫岂是你随便可以逛的！\n");
}