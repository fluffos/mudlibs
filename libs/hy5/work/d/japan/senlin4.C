// Room: d/japan/senlin4.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "森林");
set("long", @LONG
这是一快森林，森林中地下布满了一层厚厚的树叶踩上去卡卡做响，
透过森林的一些阳光洒落下，很是美丽。
LONG );
set("exits",  ([
        "west"  : __DIR__"senlin1",
        "east"  : __DIR__"senlin1",
        "south"  : __DIR__"senlin4",
        "north"  : __DIR__"senlin3",
      ]));
        setup();
        replace_program(ROOM);
}