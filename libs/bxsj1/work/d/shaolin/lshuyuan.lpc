//lshuyuan.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIM"龙树院"NOR);
	set("long", @LONG
这是一处偏僻的小院，院中栽着两株高大的槐树，显得极是宁静幽深。
这里是少林武僧们领取武器和防具之地，汇集了天下各派惯用的各类兵刃。
少林武技天下驰名，为防止练功受伤，这里也一并供给各类防具。院门口站
着两名僧兵，手持戒刀，严密的守护着这里。  
LONG
	);

	set("exits", ([
		"east" : __DIR__ "huaishu5",
                "north" : __DIR__ "wuqiku",
                "south" : __DIR__ "fangjuku",
        ]));

        set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));

	set("coor/x",20);
  set("coor/y",320);
   set("coor/z",120);
   setup();
}



