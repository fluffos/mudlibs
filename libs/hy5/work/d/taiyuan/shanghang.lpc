// /d/taiyuan/shanghang.c
// Room in 太原
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "商行");
	set("long", @LONG
这家商行是一个西域商人所开，专门负责中原和西域之间贷物的运
送，另外也是西域商队在太原的落脚之处。
LONG
	);
set("exits", ([
                "south" : __DIR__"xidajie1", 
	]));
	set("objects",([
	__DIR__"npc/li":1,
	]));
       setup();
	replace_program(ROOM);
}	
