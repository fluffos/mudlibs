// /d/ruzhou/ximen.c 汝州西门
inherit ROOM;

void create()
{
	set("short", "汝州西门");
	set("long", @LONG
这里是汝州的西城门。从这里是通向西域去的必经要道，一旦有
大案发生或是战事起来，立即会在此设卡盘查，平时，官兵也懒得过
来多事，城门下一片太平盛世景象。
LONG
	);

	set("exits", ([
 		"west"  : "/d/kaifeng/torz",

             "east" : __DIR__"wangxi-lu",
	]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



