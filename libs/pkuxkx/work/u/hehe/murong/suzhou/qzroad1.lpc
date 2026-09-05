// Room: /d/quanzhou/qzroad2.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条山路上。时值春日，路旁的山坡上开满了金黄色的油菜花。
东面是江南名城嘉兴,西边就是苏州城的东门。
LONG
	);

	set("exits", ([
                "east" : __DIR__"qzroad2",
				"west" : "/d/suzhou/dongmen",
	]));

	set("outdoors", "suzhou");
	setup();
	replace_program(ROOM);
}

