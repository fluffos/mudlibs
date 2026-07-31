 // Room: d/kyoto/jinqiao
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "金桥");
set("long", @LONG
这是京都护城河上的金桥，整座桥由罕见的金色大理石做成，散发着闪
闪金光，照的人睁不开双眼，栏杆上雕刻精美，堪称旷世杰作。护城河环绕
的就是［京都御所］，是昔日天皇的行宫。
LONG );
set("exits",  ([
        "north"  : __DIR__"heyuan1",
        "east"  : __DIR__"huchenghe2",
        "west"  : __DIR__"huchenghe1",
      ]));
        setup();
        replace_program(ROOM);
}