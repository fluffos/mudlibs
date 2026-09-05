//mlin4.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "茶花林");
    set("long", @LONG
你在花林中信步而行，所留神的只是茶花，忘了记忆路径，眼见小路东
一条、西一条，不知那一条才是来路，一眼望将出去，都是红白缤纷的
茶花，不见房屋。
LONG
    );

    set("exits", ([
		"east" : __FILE__,
		"north" : __DIR__"mlin3",
		"south" : __DIR__"mlin5",
		"west" : __FILE__,
    ]));
    
    set("outdoors", "murong");
    setup();

}
