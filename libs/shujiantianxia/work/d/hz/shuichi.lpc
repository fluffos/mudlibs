// /u/beyond/hz/shuichi.c 水池
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIW"水池"NOR);
        set("long", @LONG
假山中央的岩石上一道泉水从龙口中喷涌而出，形成多级瀑布，注入深
池。池畔两块山石上分别刻着“水不在深”，“有龙则灵”。池西面是一组
园林小筑。
LONG
        );
set("objects",([
__DIR__"npc/you" : 2,
]));
        set("exits", ([
            "northwest" : __DIR__"huanglong",
            "west" : __DIR__"xiaozhu",
]));
        set("coor/x",70);
  set("coor/y",-300);
   set("coor/z",0);
   setup();
}
