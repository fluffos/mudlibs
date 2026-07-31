// chongyanggate.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "重阳宫大门");
	set("long", @LONG
你已走到了终南山半山腰，前面就是全真教的总部重阳宫了。殿
宇依山而筑，高低错落有致。周围古木森森，翠竹成林，景色清幽。
正前方黄墙碧瓦，飞檐翘檩，正中一道二丈来宽，三丈来高的朱红杉
木包铜大门(door)。上方一块大匾，龙飞凤舞地书着『重阳宫』三个
大字。南下是广场。
    全真派暂不开放。
LONG
	);
	set("outdoors", "gumu");
	set("exits", ([
		"southdown"   : __DIR__"daxiaochang",
	]));

	setup();
}
