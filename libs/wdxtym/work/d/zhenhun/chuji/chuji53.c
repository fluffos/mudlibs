 

inherit ROOM;

void create()
{
	set("short", "初级区");
	set("long", @LONG
初级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji54",
	"north" : __DIR__"chuji52",
	"east" : __DIR__"chuji38",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}