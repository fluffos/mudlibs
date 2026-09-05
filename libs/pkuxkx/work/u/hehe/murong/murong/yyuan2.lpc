//yyuan2.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "庭院");
    set("long", @LONG
燕子坞的庭院，不时有仆人走来走去。
LONG
    );

    set("exits", ([
		"south" : __DIR__"yyuan1",
		"north" : __DIR__"yyuan3",
		"west" : __DIR__"yxiang4",
		"east" : __DIR__"yxiang3",
    ]));
    
	set("objects", ([
		__DIR__"npc/gong" : 1,
		]));

    set("outdoors", "murong");
    setup();
	replace_program(ROOM);
}
