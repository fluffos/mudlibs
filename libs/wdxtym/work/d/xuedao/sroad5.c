// sroad5.c
inherit ROOM;
void create()
{
	set("short", "大雪山");
	set("long", @LONG
这儿遍地冰雪，你眼前白皑皑的一片。从东边爬上来的，心跳开始加速。
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"sroad4",
		"southup"   : __DIR__"sroad6",
	]));
	set("outdoors", "xuedao");
	setup();
}
