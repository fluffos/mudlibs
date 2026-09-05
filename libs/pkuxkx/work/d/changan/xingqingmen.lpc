//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"

void create()
{
        set("short", "兴庆门");
        set("long", @LONG
这是南大内兴庆宫的正门兴庆门，东边是朝会正殿兴庆殿，
兴庆门正对着丹凤门大街。
LONG);
        set("exits", ([
           "west" : __DIR__"danfengstreet-2",
           "east" : __DIR__"xingqingdian"
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