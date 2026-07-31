// Room: //Room: /d/japan/path1.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "土路");
set("long", @LONG
一条宽阔的黄土大道向远方延伸开去，西边巍峨的神户东门
高高的耸立着，几名城卫在来回巡视。喧闹的人声不停的传来。
LONG );
set("exits",  ([
        "west"  : __DIR__"path",
        "east"  : __DIR__"senlin1",
      ]));
        setup();
        replace_program(ROOM);
}