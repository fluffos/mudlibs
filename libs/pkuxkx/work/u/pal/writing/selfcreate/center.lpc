//mjth 2003/10/7

inherit ROOM;

void create()
{
 	set("short","4A风景区");
	set("long", @LONG
这里就是北侠有名的4A级世界风景区。甫一踏入，你只觉花香
醉人，鹿鸣啾啾，青天碧水，万峰叠翠，不由心旷神怡荣辱偕
忘。一瞬间尘世上的尔与我诈江湖纷争仿佛不再与你有丝毫纠
缠，然而难移的本性又使你想到，如果在这里开办一处山庄渡
假村，肯定能财源滚滚日进千金。仰目望去，东边的山百转千
回，西边的湖波光点点，南边的枫叶层林尽染，北边挤在入口
的游客接踵摩肩。
LONG
	);
	set("no_sleep_room",1);
	set("no_fight",1);
	set("outdoor","city");
	set("no_steal",1);
	set("no_beg",1);
	set("exits",([
		"east" : __DIR__"qifengya",
		"west" : __DIR__"weiminghu",
		"south" : __DIR__"xiangsilin",
		"north" : __DIR__"4arukou",
	]));
	setup();
	replace_program(ROOM);
}