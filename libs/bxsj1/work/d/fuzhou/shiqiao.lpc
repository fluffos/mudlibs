// Room: /d/fuzhou/shiqiao.c
// Lklv modify 2001.9.6
inherit ROOM;

void create()
{
	set("short", "石桥");
	set("long", @LONG
这是一座白石堆砌成的小桥，桥下流着一汪弯弯的流水。从这里往桥北方
向走，过桥就是东大街了。站在桥头往南边望，可以远远望见一条小巷。巷口
立有一块石碑，上写着“向阳巷”三个小字。
LONG
	);

	set("exits", ([
        	"south" : __DIR__"xyxiang",
                "north" : __DIR__"dongjie",
	]));

	set("objects", ([
                NPC_D("boy"):1,
                NPC_D("girl"):2,
	]));

	set("outdoors", "福州");
	setup();
}
