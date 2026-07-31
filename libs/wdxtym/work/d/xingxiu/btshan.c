// room: /d/xingxiu/btshan
// Jay 3/27/96

inherit ROOM;

void create()
{
	set("short", "白驼山");
	set("long", @LONG
这是传说中神秘的白驼山。远远望去，两座白沙堆积形成的山峰好像
一只骆驼的脊背。一座山门立在你的眼前。山门后一条小路通向一座山腰
上的山庄。那里是「西毒」欧阳锋的秘宅，一般人闯进去非死即伤。
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"shamo4",
	    "westup" : __DIR__"btshan1",
	]));

	setup();
}
