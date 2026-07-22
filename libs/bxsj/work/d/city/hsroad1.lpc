// hsroad1.c

inherit ROOM;

void create()
{
	set("short", "北门外");
	set("long", @LONG
这是扬州北门郊外的一条青石大道，路上人来人往非常热闹，不时地有人
骑着马匆匆而过。这条大道南边直通往扬州城。西北面是一条黄土小径，蜿蜒
通向一个小山冈。北面是一片密林。
LONG
	);
	set("outdoors", "扬州");
	set("exits", ([
		"north" : "/d/huanghe/caodi1",
		"south" : __DIR__"beimen",
		"northwest" : __DIR__"shangang",
	]));
        set("objects", ([
                NPC_D("poorman") : 1,
        ]));
	setup();
}
