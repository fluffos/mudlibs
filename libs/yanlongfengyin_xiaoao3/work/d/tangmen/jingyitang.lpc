// Room: /d/tangmen/jingyitang.c

inherit ROOM;

void create()
{
	set("short", "精益堂");
	set("long", @LONG
	精益堂是唐门弟子武功到了一定境界之后，精进勤修的地方。精益堂主唐亮
是唐门第一高手，江湖号称“千手千眼”，暗器功夫已入化境。
LONG
	);
	

	set("exits", ([
		
		"west" : __DIR__"qulang4",
		"east" : __DIR__"dating",
		
	]));
	 set("objects", ([

                __DIR__"npc/tang_liang" : 1,
        ]));


	setup();
	replace_program(ROOM);
}

