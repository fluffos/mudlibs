//ROOM dating.c

inherit ROOM;

void create()
{
	set("short", "花海阁");
        set("long",@LONG
这就是『移花宫』的花海阁。房间里到处都是鲜花，这里大概
有上百种鲜花有名贵的，也有一些叫不出名的奇花异草，令人称奇。
LONG
	);
        set("exits", ([
		"north" : __DIR__"damen",
		"south" : __DIR__"changlang",
                "west" : __DIR__"liangong",
                "east" : __DIR__"sleeproom",
        ]));

	set("objects",([
        "/kungfu/class/yihua/yuenu" : 1,
	]));
	set("valid_startroom", 1);
	setup();   }
