// Room: /u/cuer/emei/xiangfang.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "厢房");
        set("long", @LONG
这是一间简简单单的厢房，屋内只有一张木床，一套木桌椅
而已。房子并不奢华，却是打扫的干干净净，一尘不染。屋内有
一个身着素色长衫的年轻人站在窗前，呆呆地看着窗外。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"wannian",
                ]));
        set("objects",([
                CLASS_D("wudang") + "/xiaosong" : 1,
                ]));
        create_door("west", "木门", "east", DOOR_CLOSED);
        setup();
}
int valid_leave(object me,string dir)
{
	me=this_player();
	if(me->query_temp("xiaosong") && objectp(present("song qingshu",environment(me))) 
		&& dir=="west")
	return notify_fail("宋青书拦住你，喝道：今天不是你死，就是我活！\n");
	return ::valid_leave(me,dir);
}
