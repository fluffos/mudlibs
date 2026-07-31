// taohua5.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "桃花坪");
	set("long", @LONG
桃花坪是个小盆地。此处四面环山，山间白云缭绕，山上桃林层叠，
如列屏障。中有小溪潺潺流过，清澈碧透。春鸟娇鸣，游鱼踊跃，春岚气
动，景象万千。坪中大大小小琉瓦别墅，山野之中诸多风味。
LONG
);
	set("outdoors", "city");
	set("exits", ([
		"south"	 : __DIR__"taohua4",
	]));
	setup();
	replace_program(ROOM);
}
