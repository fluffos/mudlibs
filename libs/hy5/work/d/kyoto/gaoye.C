// Room: d/kyoto/gaoye
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "高野");
set("long", @LONG
走在一条长长的道路上，一边是昔日繁华的［御所行宫］，另一边则是
天下闻名的京都第一古寺［清水寺］。世尘和清静之所隔着不远的距离，但
是却好像时空被拉长了一样。让人迷茫。

LONG );
set("exits",  ([
        "west"  : __DIR__"qingshuisi",
        "east"  : __DIR__"yuqiao",
      ]));
        setup();
        replace_program(ROOM);
}