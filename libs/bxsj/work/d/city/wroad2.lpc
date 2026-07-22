// /d/city/wroad2.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时有人骑着马匆匆而过。
大道往西进入安徽境内。东边通向扬州城。
LONG
	);
        set("outdoors", "扬州");
	set("objects", ([
		__DIR__"npc/caihuazei" : 1,
	]) );
	set("exits", ([
		"east" : __DIR__"wroad1",
                "west" : __DIR__"wroad3",
	]));
	setup();
}
