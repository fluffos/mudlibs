#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
   这是一条崎岖的山路，四周都是茂密的灌木丛，时不时传来
一声野兽的吼叫声。
LONG );
	set("exits", ([
		"east" : __DIR__"migong2",
                "west" :"d/sdxl/conglin3",		                          	
		                          	]));
                set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
