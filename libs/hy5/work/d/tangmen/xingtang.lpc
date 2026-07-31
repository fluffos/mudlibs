// Room: /d/tangmen/xingtang.c

inherit ROOM;

void create()
{
	set("short", "刑堂");
	set("long", @LONG
	这里是唐门的刑堂。唐老太太门规森严，对于擅闯唐门的人和犯错的门下弟
子从来就不轻饶。刑堂堂主唐无情是江湖上有名的煞星，对于折磨人更是有独到的心
得，如果落在他手上，必定是生不如死。
LONG
	);
	

	set("exits", ([
		
		"west" : __DIR__"dating",
		"east" : __DIR__"bingqiku",
	]));
	 set("objects", ([

                "/d/tangmen/npc/tang_wuqing" : 1,
        ]));



	setup();
	replace_program(ROOM);
}

