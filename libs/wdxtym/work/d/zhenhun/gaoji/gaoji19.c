 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji20",
	"north" : __DIR__"gaoji18",
	"east" : __DIR__"gaoji58",
	"west" : __DIR__"gaoji12",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}