// /d/city/beidajie3.c

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
你走在一条繁忙的街道上，看着操着南腔北调的人们行色匆匆，许多人都
往西南边走去，那里是扬州的中心广场。东边是扬州驿站，来自京城的快马有
时会急驶而入，片刻后又会有另一匹快马从里面冲出来绝尘而去。
LONG
	);
        set("outdoors", "扬州");

	set("exits", ([
		"east" : __DIR__"yizhan",
                "south" : __DIR__"guangchangdong",
		"west" : __DIR__"guangchangbei",
		"north" : __DIR__"beidajie2",
	]));

        set("objects", ([
                __DIR__"npc/jingchengke" : 1,
                NPC_D("zhaojy") : 1,
        ]));
   set("incity",1);
	setup();
}

