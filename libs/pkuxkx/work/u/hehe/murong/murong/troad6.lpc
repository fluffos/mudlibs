//troad6.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小路");
    set("long", @LONG
这是一条鹅卵石铺成小路，此处甚为幽静。西面有两座楼房，
房子四周都种满了杨柳,路边的花圃里栽满了各种各样的玫瑰、
茉莉、寒梅等花草，姹紫嫣红，份外妖娆。
LONG
    );

    set("exits", ([
		"south" : __DIR__"troad5",
		"west" : __DIR__"tingxiang",
    ]));
    
    set("outdoors", "murong");
    setup();

}
