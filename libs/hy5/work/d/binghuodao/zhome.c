// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "山洞");
        set("long", @LONG
这儿是张无忌一家住的山洞,旁边住着谢逊.
无忌住在这.地上铺着草垫,草垫上是兽皮.
LONG );
set("exits", ([
          //      "north" : __DIR__"whome",
                 "east" : __DIR__"home",
 //             "south" : __DIR__"mroad3",
//               "west"  : __DIR__"zhome",
        ]));

        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
