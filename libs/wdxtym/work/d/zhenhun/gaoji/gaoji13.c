 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji12",
	"north" : __DIR__"gaoji14",
	"east" : __DIR__"gaoji18",
	"west" : __DIR__"gaoji25",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}