// shandong2.c

inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
山谷里积雪被拢成几个雪堆，这里时常有人扫除积雪。你前面的峭
壁下隐隐约约有一个山洞。南北两旁都是崖壁，东面则是一处峭壁，非
常险要。
LONG );
	set("exits", ([
		"enter" : __DIR__"shandong3",
		"west"  : __DIR__"sroad9",
		"south" : __DIR__"syabi",
		"north" : __DIR__"nyabi",
		"east"  : __DIR__"eyabi",
	]));
	set("objects", ([
		CLASS_D("xuedao") + "/baoxiang" : 1,
	]));
	set("outdoors", "xuedao");
	set("valid_startroom", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	object guarder;

	if (dir == "west" ||
	    ! objectp(guarder = present("bao xiang", this_object())) ||
	    ! living(guarder))
		return ::valid_leave(me, dir);

	return guarder->permit_pass(me, dir);
}

