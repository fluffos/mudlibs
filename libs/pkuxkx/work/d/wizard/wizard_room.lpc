// Room: /d/wizard/wizard_room.c
#include <ansi.h>
#include "wizards.h"

inherit ROOM;

void create()
{
	set("short", "巫师休息室");
	set("long", @LONG
这里就是「北大侠客行」巫师的休息所在，刚粉刷过的四周墙壁上光
秃秃的什么都没有，屋子的正中央放着一张楠木桌，上面摆着一本巫师
留言簿(board)。
LONG
	);
	set("no_clean_up", 0);
	set("realmap", "                                               
                                    
                         [1;32m巫师休息室[2;37;0m--[1;31m异[1;35m想[1;33m天[1;32m开[2;37;0m  
                             [1;36m〓[2;37;0m     
                         巫师会客室            
");
	set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 2 */
		  "east" : __DIR__"dream_room",
		  "down" : __DIR__"guest_room",
		]));
	set("room_location", "/d/city/");
	setup();

    call_other("/clone/board/plan_b", "???");
	call_other("/clone/board/wiz_b", "???");
}
void init()
{
object me;
me=this_player();
if (SECURITY_D->get_status(me) == "(player)" && !used_to_be_wiz(me) )
{
                message_vision("这里是巫师休息室，$N是怎么混进来的？请到下面等候！\n",me);
me->move(__DIR__"guest_room");
return;
}
else
 return;
}


