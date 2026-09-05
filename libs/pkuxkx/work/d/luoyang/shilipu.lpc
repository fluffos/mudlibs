//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"城西集市"NOR);
        set("long", @LONG
这是城西的一个小市集，原先倒也热闹，最近因为万安寺住进了
番僧，隔三岔五就来搅扰，老百姓都敢怒不敢言，纷纷关门闭户。


LONG
			);

        set("exits", ([     
               "east" : __DIR__"hutong5", 
			"northwest" : __DIR__"songlin1",   
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}