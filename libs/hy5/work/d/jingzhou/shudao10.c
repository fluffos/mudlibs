// Room: /d/chengdu/shudao10
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "石阶" NOR );
        set("long", @LONG
一条小石阶，有点破破烂烂，青草从石头的缝隙中长了出来，有些地方的
石阶由于年代久远，已经磨的光滑如镜。向上看去，只见云雾中有几座房子。
LONG
        );
        set("exits", ([
  "northup" :  __DIR__"baidicheng",
  "west" : __DIR__"sanxia1",
  "east" : "/d/tangmen/chapu",
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

