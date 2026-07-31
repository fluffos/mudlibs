
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "东厢走廊");
        set("long", @LONG
你走在一条走廊上，廊顶描绘着江南秀美的风景。每两根翠绿色的柱子间
相隔也就两三尺的距离，朱红色的琉璃瓦，嫩黄色的地砖。再往东是一间炼丹
房。这儿是武当禁地, 非常安静。
LONG
        );

        set("exits", ([
                "west" : __DIR__"zoulang1",
                "east" : __DIR__"ldfang",
        ]));

        setup();
} 
