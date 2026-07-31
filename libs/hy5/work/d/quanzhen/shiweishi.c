// shiweishi.c 事为室
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "事为室");
        set("long", @LONG
这里是全真七子之首马钰的居室。房间很小，只摆放了一张床、
一张书桌和一把椅子。书桌上放着一本‘老子’，只看了一半，床上
被褥折叠得整整齐齐。
LONG
        );
        set("exits", ([
                "south" : __DIR__"cetang",
        ]));

        set("objects", ([
                __DIR__"npc/ma" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
