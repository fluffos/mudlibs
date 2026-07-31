// Room: d/kyoto/shangyuan5
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "上原");
set("long", @LONG
这里就是上原，往北就是京都最繁华的中心，熙熙攘攘的人群不断从
身边擦身而过，两边店铺的叫卖声不绝于耳。东面是维新政府的市政厅，
守卫森严。西面是管制所，做奸犯科之徒都被关押在那里。
LONG );
set("exits",  ([
        "west"  : __DIR__"guanzhisuo",
        "east"  : __DIR__"shizhengting",
        "north"  : __DIR__"dashiqiao",
        "south"  : __DIR__"nanmen",
      ]));
        setup();
        replace_program(ROOM);
}