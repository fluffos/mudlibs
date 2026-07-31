#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "兽族兵器库");
    set("long", @LONG
这里到处放满了兵器和护甲,其中不乏一些上古神兵,在一个大箱子
(box)里有一些比较不错的兵器.这些是用来奖赏对兽族有贡献的
兽族勇士.
LONG);
    set("exits", (
     "west" : __DIR__"shouwangdian",
    ]));
    setup();
    replace_program(ROOM); 
}
