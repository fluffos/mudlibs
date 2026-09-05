// 墓边
//by male

inherit ROOM;

void create()
{
        set("short", "墓边小道");
	set("long", @LONG
       这是岳王墓旁边的小道,四周非常的安静肃穆,你的心情也不由得沉重起来.
LONG
	);
        set("outdoors", "yuewangmu");

	set("exits", ([
               "southeast" : __DIR__"yuefeimu",
               "northeast" : __DIR__"muhou",

	]));

/*
        set("objects", ([
                CLASS_D("shaolin") + "/tuoboseng" : 1,
        ]));
*/

	setup();
}

/*
int valid_leave(object me, string dir)
{
	if (dir == "east" && (int)me->query("age") < 14 && !wizardp(me))
		return notify_fail("小朋友不要到那种地方去！！\n");
	return 1;
}
*/
