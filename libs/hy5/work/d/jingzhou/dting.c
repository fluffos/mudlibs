// Room: dting
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "东厅");
	set("long", @LONG
这里是万府的东，房间里摆着一张桌子，以及一个书架，书架上放着很多书籍，
墙上挂着几幅字画，这里好像是是万门弟子练功的地方。
LONG
	);

	set("exits", ([
		"west" : __DIR__"dayuan",
		
	]));



	setup();
	replace_program(ROOM);
}

