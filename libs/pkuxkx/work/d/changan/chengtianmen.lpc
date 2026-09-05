
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"

void create()
{
        set("short", HIW"承天门"NOR);
        set("long", @LONG
这是西大内太极宫前面的正门承天门，承天门旁边开了两个小门
永安门和长乐门，是朝臣朔望日觐见皇帝的通道。
LONG    );
        
        set("exits", ([
                "westup" : __DIR__"innerwall12",
                "south" : __DIR__"chengtianstreet-3",
                "eastup" : __DIR__"innerwall11",
                "north" : __DIR__"taijimen",
                
        ]));
        set("objects", ([
		      __DIR__"npc/jinwu-4": 1,
		      __DIR__"npc/jinwu-5": 1,
          __DIR__"npc/jinwu-2": 1,
          __DIR__"npc/jinwu-3": 1,
        ]));
        
        set("locate_level",1);
       
        set("outdoors", "changan");
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}

int valid_leave(object me,string dir)
{
	if ( check_obj_enter(me, dir) )
		return ::valid_leave(me, dir);
	else
	  return notify_fail("大内禁地，闲人免入！\n");
}
