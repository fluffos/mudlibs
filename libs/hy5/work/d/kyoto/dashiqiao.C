// Room: d/kyoto/dashiqiao
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "大石桥");
set("long", @LONG
这里就是大石桥，是明治时期新建的，由钢筋混凝土制成，习惯上人
们还是把它称为大石桥，桥面很宽可以容十马十车并行。
LONG );
set("exits",  ([
        "south"  : __DIR__"shangyuan5",
        "north"  : __DIR__"shangyuan4",
      ]));
        setup();
        replace_program(ROOM);
}