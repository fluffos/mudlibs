//troad5.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小路");
    set("long", @LONG
这是一条鹅卵石铺成小路，此处甚为幽静。东边有间别致的江
南农舍。
LONG
    );

    set("exits", ([
		"south" : __DIR__"troad4",
		"north" : __DIR__"troad6",
		"east" : __DIR__"thouse2",
    ]));
    
    set("outdoors", "murong");
    setup();

}
