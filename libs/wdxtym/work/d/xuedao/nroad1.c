// nroad1.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
	set("short", "山路");
	set("long", @LONG
山路越走越窄，能隐隐望见前方又分出了几条叉路。
LONG );
	set("exits", ([
		"westup"     : __DIR__"nroad2",
		"southup"    : __DIR__"sroad3",
		"northdown"  : __DIR__"nroad5",
	]));
	set("outdoors", "xuedao");
	setup();
}

