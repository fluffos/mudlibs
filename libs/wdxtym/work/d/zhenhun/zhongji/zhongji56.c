 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji57",
	"north" : __DIR__"zhongji55",
	"east" : __DIR__"zhongji71",
	"west" : __DIR__"zhongji17",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}