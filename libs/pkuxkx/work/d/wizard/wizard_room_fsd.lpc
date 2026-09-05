// Room: /d/wizard/wizard_room.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"一声叹息"NOR"的工作间");
        set("long", @LONG
这里就是巫师 一声叹息 的工作间 。屋子的正中央放着一张楠木桌、
几把小藤椅，刚刚沏好的一壶大红袍还冒着热气，一阵淡淡的茶香隐隐飘来。
先坐下品盏香茗，有什么事再慢慢写到留言簿(board)上也不迟。
LONG );

        set("exits", ([ /* sizeof() == 1 */
        "out" : __DIR__"wizard_room" ,
        "city":"/d/city/guangchang",
        ]));

        set("valid_startroom", 1);
        set("no_clean_up", 0);
        setup();
  "/clone/board/fsd_b"->foo() ;
 //   call_other("/clone/board/plan_b", "???");
//      call_other("/clone/board/wiz_b", "???");
        replace_program(ROOM);
}

