// Room: tomb
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "坟墓内部");
	set("long", @LONG
你用力往墓碑一推，忽然眼前一黑，掉进了一个大坑，这里黑乎乎的，似乎看不见
任何东西。
LONG
	);
        

	set("exits", ([
		"south" : __DIR__"sec1",
		"west" : __DIR__"luan2",
			]));
//	set("objects", ([
//		CLASS_D("mingjiao") + "/zhangwuji" : 1,
//	]));

	

        set("no_clean_up", 0);
        

        setup();
        replace_program(ROOM);
}
