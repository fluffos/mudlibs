// Room: d/kyoto/shanggeshuyuan
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "上阁书院");
set("long", @LONG
这里是一间书院，可以听到的朗朗书声，虽然叽哩瓜啦都是日语，如
果你想看懂日本的武学典籍，还是来这里学一学日语吧。
LONG );
set("exits",  ([
        "north"  : __DIR__"qianbending5",
      ]));
        setup();
        replace_program(ROOM);
}