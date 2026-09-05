//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"

void create()
{
        set("short", "通阳门");
        set("long", @LONG
这是兴庆宫的南门通阳门，通阳门北面就是美丽的龙池，西面是
勤政务本楼和花萼相辉楼相围的巨大广场。南面就是繁华的春明
门大街。
LONG);
        set("exits", ([
           "west" : __DIR__"qinzhenglou",
           "south" : __DIR__"eaststreet-3"
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
