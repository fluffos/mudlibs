//石屋
//by icer
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "石屋");
        set("long", @LONG
只见室中小几上点着一炉檀香，几旁蒲团上坐着一个白眉老僧。旁边站着两个小沙弥。
LONG
);
set("exits", ([
                 "southeast" :__DIR__"zhulin1",
		"north":__DIR__"houshan",
]));
set("no_task",1);
set("objects",([
      __DIR__"npc/yideng" : 1,
      __DIR__"npc/shami1" : 2,
     ]));
        create_door("southeast", "竹门", "northwest", DOOR_CLOSED);
setup();
}

