// tulu1.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在一条土路上，偶尔会有人骑着马匆匆而过，搞得尘土飞扬。这里已
经距离长安很远了，再往西北方向走一会，就可以进入侯集镇，现在这里显得
格外的寂静。
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"northwest" : __DIR__"tulu2",
		"south" : __DIR__"xiaolu2",
	]));
	setup();
	replace_program(ROOM);
}
