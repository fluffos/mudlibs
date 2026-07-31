// townroad1.c 小镇路
// Town of mingjiao  
// Ver 1.0 10/8/1998 by Shark

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "小 镇 街 道"NOR);
	set("long",   @LONG
你正走在小镇唯一的一条街道，不时有风沙袭来。西面有间客栈，东
边是家当铺，南边是座龙王庙。往西南就是去昆仑山的路了。
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
                "west" : __DIR__"kedian",//有间客栈
             	"east" : __DIR__"dangpu",//当铺
                "south" : __DIR__"longwangmiao",//龙王庙
                "north" : __DIR__"townroad",
//                "northwest" : __DIR__"luzhou",
//                "northeast" : __DIR__"shaqiu1",
                "southwest" : __DIR__"huangmo",//去昆仑山
//                "southeast" : __DIR__"town",
	]));
	
  	set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));
	
	setup();
	replace_program(ROOM);
}

