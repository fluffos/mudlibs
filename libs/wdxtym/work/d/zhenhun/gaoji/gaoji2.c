 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"north" : __DIR__"gaoji7",
	"east" : __DIR__"gaoji63",
	"west" : __DIR__"gaoji1",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}