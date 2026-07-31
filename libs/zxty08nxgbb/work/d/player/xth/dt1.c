// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "灼日堂大厅");
	set("long", "这是个宽敞明亮的大厅，大厅中间摆着一张长桌和两排椅
子。灼日堂的堂主和弟子经常在这儿互相交流心得。往里去就
是灼日罩地和堂主的卧室。\n");

	set("exits", ([
                "northdown" : __DIR__"ncs",
		"southdown" : __DIR__"wcs",
                "east" : __DIR__"dt2",
                "west" : __DIR__"dt",
                "southeast" : __DIR__"ws3",
	]));
	setup();
	replace_program(ROOM);
}

