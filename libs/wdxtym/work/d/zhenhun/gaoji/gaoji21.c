 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji9",
	"north" : __DIR__"gaoji20",
	"east" : __DIR__"gaoji60",
	"west" : __DIR__"gaoji10",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}