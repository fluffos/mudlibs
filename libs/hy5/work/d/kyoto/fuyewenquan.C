// Room: d/kyoto/fuyewenquan
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "福野温泉");
set("long", @LONG
这里是福野温泉，疲惫了一天的人们在这里泡温泉，消除一天的疲劳
，这里也是政界要员，达官贵人的常来之所。同时这里有漂亮的桑拿小姐
提供全方位的服务，爽极了。
LONG );
set("exits",  ([
        "north"  : __DIR__"xiaoxiang1",
        "east"  : __DIR__"xiaoxiang2",
      ]));
        setup();
        replace_program(ROOM);
}