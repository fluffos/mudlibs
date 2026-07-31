inherit ROOM;

void create()
{
	set("short", "青石路");
	set("long", @LONG
这是一条由青色条石铺成的大道，道面由四辆马车并行那样宽，
因为这条大道专供官府使用，所以道上几乎没有行人。
LONG );

	set("exits", ([
               "south"      : __DIR__"guanlu1",
               "northwest"      : __DIR__"xingze",
		
	]));

 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



