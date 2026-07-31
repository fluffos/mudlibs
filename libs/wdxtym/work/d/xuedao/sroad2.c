// sroad2.c
inherit ROOM;
void create()
{
	set("short", "山路");
	set("long", @LONG
一条山路蜿蜒在山间。向西望去，可以见到大雪山的银色的雪
顶在熠熠生辉。
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"sroad1",
		"westup"    : __DIR__"sroad3",
	]));
	set("outdoors", "xuedao");
	setup();
}
