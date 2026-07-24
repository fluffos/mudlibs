#include <room.h>
// Room: /dream/chapu.c
// HEM 1998/9/28 
#include <room.h>

inherit ROOM;

void create()
{
//	set("outdoors", "tangmen");
	set("short", "茶铺");
	set("long", @LONG
	这是路旁一个简陋的茶铺，周围满是竹林环绕，环境倒是清幽，简单的几张竹
桌.竹椅，时不时有人坐着歇歇脚，喝两口茉莉花茶。茶铺的主人是个十五.六岁的小姑
娘，可爱伶俐，来这儿就算是不喝茶，看看她也是很开心的事儿。南边有一道竹门虚掩着。

LONG
	);
        set("exits", ([	
       	"south" : __DIR__"zhulin",
        "west"  : "/d/jingzhou/shudao10",
	]));
create_door("south", "竹门", "north", DOOR_CLOSED);

	set("objects", ([
		__DIR__"npc/tangtian" : 1,
	]));

	setup();
	replace_program(ROOM);
}

