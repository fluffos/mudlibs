// Room: /d/wizard/wizard_room.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"行云工作室"NOR);
        set("long", HIW @LONG
[0;32m测试一下。[0;33m这是颜色。
LONG NOR);

        set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"wizard_room" ,
        "north" : "/u/advent/workroom" ,
        "zt" : "/d/wizard/wizard_room_iszt",
        "xueshan" : "/d/dalunsi/zanpugc",
        "south":"/d/city/guangchang",
        ]));

        set("valid_startroom", 1);
        set("no_clean_up", 0);
        setup();
  "/clone/board/advent_b"->foo();

 //   call_other("/clone/board/plan_b", "???");
//      call_other("/clone/board/wiz_b", "???");
        replace_program(ROOM);
}