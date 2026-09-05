//玄武门 /d/jinyang/xuanwumen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"

void create()
{
        set("short", HIR"丹凤门"NOR);
        set("long", @LONG
这里是大明宫南门【丹凤门】，南面是宽阔的丹凤门大街，
北面是大明宫，门口金吾卫警戒森严。
LONG        );

        set("exits", ([
                "eastup" : __DIR__"citywall7",
                "westup" : __DIR__"citywall9",
                "south" : __DIR__"danfengstreet-1",
                "north" : __DIR__"dfguangchang"
        ]));
        set("objects", ([
		      __DIR__"npc/jinwu-4": 1,
          __DIR__"npc/jinwu-2": 1,
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
	  return notify_fail("大明宫禁地，闲人免入！\n");
}