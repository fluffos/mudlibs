// Room: /d/cangzhou/beijie3.c

inherit ROOM;
void create()
{
        set("short", "北街");
        set("long", @LONG
沧州城北街，到了这里，风几乎已经完全停下。向南就到了最热闹的沧州
大客栈了。那里来来往往的每天都有许多人，街的左边是个民居。
LONG );
        set("exits", ([
                "north" : __DIR__"beijie2",
        	"south" : __DIR__"kezhan",
		"west" : __DIR__"mingju",
		"east" : __DIR__"feiyuan",
		"southwest" : __DIR__"xijie1",
		"southeast" : __DIR__"dongjie1",
	]));
	set("objects", ([
                CLASS_D("gaibang/qigai") : 1,
        ]));
	set("outdoors", "沧州");
	setup();
}