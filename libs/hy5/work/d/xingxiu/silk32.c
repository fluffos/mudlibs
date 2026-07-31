// /d/xingxiu/silk3.c
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIM"颂摩崖"NOR);
        set("long", @LONG
颂摩崖又名黄龙碑。周围山势陡峭，两山对峙，一泓中流，两峡旁有潭，
渊深莫测。俗传有黄龙自潭飞出，因名黄龙潭。潭左侧摩崖成碑。汉隶真迹，
笔触遒劲，刀刻有力，记叙了开天井道的过程。往东南是仇池山，往西则是
石门。
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "eastdown" : __DIR__"silk31",
                "westdown" : __DIR__"silk4",
                "north" : __DIR__"silk3a",
        ]));

        setup();
//        replace_program(ROOM);
}

