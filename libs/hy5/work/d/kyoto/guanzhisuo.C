// Room: d/kyoto/guanzhisuo
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "管制所");
set("long", @LONG
这里就是京都的管制所，戒卫森严，一些做奸犯科之徒都被关押在那
里。不断听到有警官的打骂声和犯人的哭嚎。
LONG );
set("exits",  ([
        "east"  : __DIR__"shangyuan5",
      ]));
        setup();
        replace_program(ROOM);
}