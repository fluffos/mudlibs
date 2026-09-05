//玄武门 /d/jinyang/xuanwumen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"

void create()
{
        set("short", HIR"玄武门"NOR);
        set("long", @LONG
这里是太极宫北门【玄武门】，著名的玄武门之变就发生
在这个地方。南面就是西大内太极宫，北面是西内苑和大明宫。
LONG        );

        set("exits", ([
                "south" : __DIR__"chengxiangdian",
                "eastup" : __DIR__"innerwall1",
                "westup" : __DIR__"innerwall2",
                "north" : __DIR__"xineiyuan-1",
                
        ]));

        set("objects", ([
		      __DIR__"npc/jinwu-4": 1,
		      __DIR__"npc/jinwu-5": 1,
          __DIR__"npc/jinwu-1": 2,
        ]));
        
        set("locate_level",2);

        set("outdoors", "changan");
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
}

int valid_leave(object me,string dir)
{
	if ( check_obj_enter(me, dir) )
		return ::valid_leave(me, dir);
	else
	  return notify_fail("大明宫禁地，闲人免入！\n");
}