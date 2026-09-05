//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"

void create()
{
        set("short", "国子监");
        set("long", @LONG
国子监是大唐的最高学府，下设国子学、太学、四门学、律学、
书学、算学六个学院，学院内常年有博士教授学员儒家经典。
LONG);
        set("exits", ([
           "south" : __DIR__"eaststreet-1",
           "east" : __DIR__"shuxue",
           "northeast" : __DIR__"simenguan",
           "north" : __DIR__"taixue",
           "west" : __DIR__"guozixue",
        ]));
        
        set("objects", ([
          __DIR__"npc/jijiu": 1,
		      __DIR__"npc/jinwu-2": 1,
          __DIR__"npc/jinwu-1": 4,
        ]));
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}

int valid_leave(object me,string dir)
{
	if ( check_obj_enter(me, dir) )
	  return ::valid_leave(me, dir);
	else
	  return notify_fail("你的爵位不够无法进入该学院！\n");
}