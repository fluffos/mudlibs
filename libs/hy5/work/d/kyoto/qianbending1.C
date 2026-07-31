// Room: d/kyoto/qianbending1
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "千本町");
set("long", @LONG
这里就是千本町，贯穿京都东西的大动脉，也是最繁华的街区，两边
行馆店铺鳞次栉比。北面是一个酒馆，以京都清酒闻名。南面是武士行馆
武士可以在那里休息或者相互切磋武学。
LONG );
set("exits",  ([
        "east"  : __DIR__"qianbending2",
        "west"  : __DIR__"ximen",
        "north"  : __DIR__"jiuguan",
        "south"  : __DIR__"wushixingguan",
      ]));
        setup();
        replace_program(ROOM);
}