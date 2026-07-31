 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji69",
	"north" : __DIR__"zhongji71",
	"east" : __DIR__"zhongji75",
	"west" : __DIR__"zhongji57",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}