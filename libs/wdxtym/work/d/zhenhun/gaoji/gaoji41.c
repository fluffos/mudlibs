 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji40",
	"north" : __DIR__"gaoji42",
	"east" : __DIR__"gaoji32",
	"west" : __DIR__"gaoji50",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}