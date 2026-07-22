#include <room.h>
inherit ROOM;

void create()
{
        set("short", "闺房");
        set("long", @LONG
这是凌小姐的闺房，一股幽香扑面而来。一张绣榻放在墙角，垂着细纱。
凌小姐正对着一盆菊花在沉思。西面是座花园。
LONG
        );

        set("exits", ([
                "south" : __DIR__"houyuan",
                "west" : __DIR__"huayuan",
        ]));

        set("objects", ([
                __DIR__"npc/shuanghua" : 1,
        ]));
        set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("no_quest") && dir == "west")
		return 0;
	return ::valid_leave(me, dir);
}
