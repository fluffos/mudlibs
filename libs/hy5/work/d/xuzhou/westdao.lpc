inherit ROOM;

void create()
{
	set("short", "西边道");
	set("long", @LONG
你走在碎石铺成的小路上，旁边是皇宫的宫墙，宫墙并不高，你能
看见墙里的树木，仔细听你能听见墙里的嬉戏声。
LONG );

	set("exits", ([
		"northwest"      : __DIR__"xidajie",
		"southeast"      : __DIR__"houqiang",
		"west":__DIR__"yanju",
		
	]));
        set("objects",([
     "/clone/npc/man":1,
     ]));

 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



