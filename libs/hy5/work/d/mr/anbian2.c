// /u/beyond/mr/anbian2.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIY"岸边"NOR);
         set("long",
"远远看去，只见一个小洲上八九间房间，其中两间是楼房。阁宇中隐约露\n"
"出一个牌坊「"HIY"听香水榭"NOR"」。\n"
);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"shuixie",
]));
         setup();
         replace_program(ROOM);
}
