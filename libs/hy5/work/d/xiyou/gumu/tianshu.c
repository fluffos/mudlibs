//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
         set("short", "天枢");
        set("long", @LONG

天罡北斗主星，走到这里你的眼前突然一道光线
前面好像有个灯火通明的大殿......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"beiji.c",
  "south" : __DIR__"jin.c",
  "west" : __DIR__"shui.c",
  "east" : __DIR__"tianxuan.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

