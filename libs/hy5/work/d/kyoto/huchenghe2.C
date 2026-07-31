// Room: d/kyoto/huchenghe2
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "护城河岸边");
set("long", @LONG
这里是护城河的岸边，泛泛凌波依水而照，散发着喜人的光，护城河环
绕的就是［京都御所］，是昔日天皇的行宫。如今已是物是人非，但是皇宫
的豪华建筑依然使人肃然起敬。
LONG );
set("exits",  ([
        "south"  : __DIR__"hongqiao",
        "west"  : __DIR__"jinqiao",
      ]));
        setup();
        replace_program(ROOM);
}