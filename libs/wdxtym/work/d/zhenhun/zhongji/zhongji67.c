 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji66",
	"north" : __DIR__"zhongji68",
	"east" : __DIR__"zhongji78",
	"west" : __DIR__"zhongji60",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}