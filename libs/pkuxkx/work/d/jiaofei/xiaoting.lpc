//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR"小亭"NOR);
        set("long", @LONG
这是一座供人休息的六角小亭，修建年代已不可考。但见其飞檐流角，红柱绿瓦，
你不由的发出一声赞叹。小亭的西北便是铁掌山拇指峰的所在。
LONG    );
        set("exits", ([ 
  "northwest" : __DIR__"mshanlu1",
  "northeast" : __DIR__"jshanlu", 
  "southdown" : __DIR__"shijie3",
]));

        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
}
