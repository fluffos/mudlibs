//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"天矶璇阴殿"NOR);
        set("long", @LONG

大殿里金光闪烁灯火辉煌紫气环绕，殿中是雕龙绘凤祥云朵朵
殿心有一紫色水晶雕刻而成宝座，妲己怡然高坐。媚眼生情，
不住的打量着你

LONG
        );
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/daji.c" : 1,
]));
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"yongdao4.c",
  "south" : __DIR__"tianshu",
  "southwest" : __DIR__"xuanshi.c",
  "southeast" : __DIR__"tianzhi.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

