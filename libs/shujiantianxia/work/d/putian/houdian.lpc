// Room: /d/putian/houdian.c 后殿
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"后殿"NOR);
        set("long", @LONG
这里是寺中的后殿，进得殿来，顿时眼前一片光亮，只见殿中两侧点满了
香烛，何止百数十枝。靠墙摆有一些香炉和供桌，因为没有开窗子，殿中有些
显得烟雾缭绕。
LONG
        );

        set("exits", ([
                "north" : __DIR__"zhongdian",
                "south" : __DIR__"xm-dian",
                "east" : __DIR__"fatang3",
                "west" : __DIR__"fatang2",

        ]));

        set("objects",([
                CLASS_D("putian") + "/yuanshang" : 1,
        ]));

        setup();
}
