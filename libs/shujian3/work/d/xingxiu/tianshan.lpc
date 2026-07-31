// room: /d/xingxiu/tianshan
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "天山山路");
        set("long",@LONG
这里是天山东麓，山风从山上吹下来，冷得你瑟瑟发抖。这儿背靠天山，
阳光充裕。常年有雪水灌溉，土地肥沃，滋长了一片草原。草原上肥羊成群结
队，一对对牧羊男女弹起了冬不拉，互诉衷肠。
LONG );

        set("exits", ([
		"southeast" : "/d/hj/senlin1",
		"west" : "/d/tianshan/kongchang",
        ]));

        set("outdoors", "天山");

        set("objects", ([
                __DIR__"npc/hkid" : 1,
                __DIR__"npc/hgirl" : 1,
                __DIR__"npc/yang" : 3,
        ]));

	setup();
}
