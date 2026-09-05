// Room: /d/wizard/wizard_room.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"NEEQU"NOR"的工作间");
	set("long", @LONG
这里就是NEEQU巫师的工作间，刚粉刷过的四周墙壁上光
秃秃的什么都没有，屋子的正中央放着一张楠木桌，上面摆着一本巫师
留言簿(board)。
LONG );

	set("exits", ([ /* sizeof() == 1 */
  	"out" : __DIR__"wizard_room" ,
  	"city":"/d/city/guangchang",
  	]));

	set("valid_startroom", 1);
	set("no_clean_up", 0);
	setup();
  "/clone/board/neequ_b"->foo();

 //   call_other("/clone/board/plan_b", "???");
//	call_other("/clone/board/wiz_b", "???");
	replace_program(ROOM);
}
