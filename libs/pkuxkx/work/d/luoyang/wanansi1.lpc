//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"万安寺大门"NOR);
        set("long", @LONG
这里就是万安寺的山门了。万安寺是洛阳名寺，历经百年，夕阳西下，
晚霞映照寺内红墙碧瓦的殿堂，衬托苍松翠柏，气象庄严。迎面的门楣上
写着"万安寺"三个大字。
LONG
			);

        set("exits", ([     
               "southeast" : __DIR__"songlin2",   
			"north" : __DIR__"wanansi-guangchang", 
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}