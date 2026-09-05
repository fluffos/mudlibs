// Room: /d/diaoyudao/dongkou.c 洞口
// hongdou 98.09.20

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
这里是山崖下的一个洞口，旁边有茂密的灌木丛包围着，
外面根本就发现不了这里有个洞口。从外面向洞里看，黑漆
漆的，一股潮气和霉气向外涌出，不知道里面有没有危险。
LONG
);

	set("exits", ([
                 "southwest" : __DIR__"xiaodao",
		 "enter" : __DIR__"midong1",
            ]));
	
	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}
