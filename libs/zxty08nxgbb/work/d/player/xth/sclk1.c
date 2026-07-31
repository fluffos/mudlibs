// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "三叉路口");
	set("long", "这里是啸天会的中心，南面就是总堂了，西南面通向冷月堂，东南是灼日堂。\n");

	set("exits", ([
                "north" : __DIR__"sclk",
		"south" : __DIR__"zt",
                "southwest" : __DIR__"lt",
                "southeast" : __DIR__"dt",

	]));
	setup();
	replace_program(ROOM);
}

