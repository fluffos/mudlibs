// Room: /d/jinghai/zhuque6.c

inherit ROOM;

void create()
{
	set("short", "前院花园");
	set("long", @LONG
来到了这个院子里。扑鼻的香气让你精神一爽，你游目四顾
，落眼处尽是不知名的簇簇鲜花。红花绿枝淹荫之间，几条小路
深向花从深处。这里是靖海朱雀堂的花园，主人为了让来访者宾
至如归，对这个花园煞是费了一番苦心。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"zhuque8",
  "north" : __DIR__"zhuque4",
  "southwest" : __DIR__"zhuque7",
]));
        set("objects",([
       __DIR__"npc/guan6" : 1,
       __DIR__"npc/yong4" : 1,
]));


	setup();

}
