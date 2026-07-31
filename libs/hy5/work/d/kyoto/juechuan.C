// Room: d/kyoto/juechuan
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "掘川");
set("long", @LONG
这里被称作掘川，是一条发源自上贺神社的溪流，为护城河提供活水，往
东走就是上贺神社，据说那里封印了上古时期可怕的力量。

LONG );
set("exits",  ([
        "east"  : __DIR__"shangheshenshe",
        "west"  : __DIR__"hongqiao",
      ]));
        setup();
        replace_program(ROOM);
}