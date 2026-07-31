 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji67",
	"north" : __DIR__"gaoji69",
	"east" : __DIR__"gaoji77",
	"west" : __DIR__"gaoji59",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}