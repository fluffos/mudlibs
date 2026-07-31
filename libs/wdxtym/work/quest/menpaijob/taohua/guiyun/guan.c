// Room: /guiyun/jinship.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "官船");
	set("long", @LONG
这里是钦使的战船，船中旗杆上分明扯着旗号，飞扬跋
扈已极。船舱内贪官们一脸媚笑。
LONG );
        set("outdoors", "guiyun");
//	set("no_clean_up", 0);

	set("exits", ([
		"out" : __DIR__"ship",
	]));
	set("objects", ([
		"/quest/menpaijob/taohua/guan" : 1,
	]));
	setup();
	replace_program(ROOM);
}
