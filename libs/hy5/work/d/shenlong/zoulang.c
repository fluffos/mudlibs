#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "走廊");
    set("long", @LONG
这是一条走廊,两边都是石头柱子, 西边是大厅,东边是厨
房,南面是练武场,北面是休息室.
LONG );

    set("exits", ([
	"east" : __DIR__"chufang",
	"west" : __DIR__"dating",
	"south" : __DIR__"wuchang",
	"north" : __DIR__"xiuxishi",
    ]));
    set("objects", ([
	CLASS_D("shenlong")+"/zhang" : 1,
    ]));
    set("outdoors", "shenlong");
    setup();
    replace_program(ROOM); 
}

