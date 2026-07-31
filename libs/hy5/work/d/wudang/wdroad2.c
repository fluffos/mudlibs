// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，北边隐约可见到扬州城的城墙。此处往东南
望去，可以看到一个市镇。
LONG );
        set("outdoors", "wudang");
	set("exits", ([
		"north" : __DIR__"wdroad1",
		"southeast" : "/d/yixing/yixing",
                "southwest" : "/d/jingzhou/wdroad5",
	"south" : __DIR__"wdroad3",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

