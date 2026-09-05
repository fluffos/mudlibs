//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_open(string);

void create()
{
	set("short", HIC"万安塔"NOR);
	set("long", @LONG
这里便是万安塔了，塔下木门紧闭。寻常人等似乎无法进入。
你可以跟鹿杖客打听打听怎么进塔。
LONG
	);

	set("exits", ([     
		"southeast" : __DIR__"wanansi-xiaolu1", 
		]));

	set("objects", ([
                __DIR__"npc/luzhangke" : 1,
				__DIR__"npc/hebiweng" : 1,
        ]));
	set("outdoors", "luoyang");
	set("no_fight", 1); // 太容易死人了，改成不可战斗 by haiv
	setup();
}
