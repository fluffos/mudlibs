 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"north" : __DIR__"gaoji62",
	"east" : __DIR__"gaoji64",
	"west" : __DIR__"gaoji2",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}