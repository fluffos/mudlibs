// rouw_home 梦庭院

// 在生成房屋时：
// /**/开头的语句将被去掉
// //**开头的语句将被使用。

/**/inherit ROOM;
//**inherit PRIVATE_ROOM;

void create()
{
	set("short","偏厅");
	set("long",@LONG
这里是大厅西面的偏厅，是主人家用来进餐时所用。偏厅之中有一张
圆桌，上面还放着一副茶具。一个小丫环正站在圆桌旁边，小心翼翼的擦
拭着。
LONG
);
	set("playerhouse",1);
/**/	set("default_long","这里是大厅西面的偏厅，是主人家用来进餐时所用。偏厅之中有一张圆桌，上面还放着一副茶具。一个小丫环正站在圆桌旁边，小心翼翼的擦拭着。");
	set("objects",([
		"/d/room/npc/yahuan":1,
	]));
	set("exits", ([
		"east" : __DIR__"room1",
	]));
	set("owner", "ROOM_OWNER");
	setup();
}
