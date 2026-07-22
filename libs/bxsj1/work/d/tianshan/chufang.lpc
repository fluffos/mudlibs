// Room: /d/tianshan/chufang.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
一间雅致的小厅，整个房间的装饰基调为翠绿色，看起来让人感觉赏心悦
目。这里就是灵鹫宫一起用餐的地方，上首是一张雕饰的十分绚丽的长几，左
右手分别是两张小几。
LONG);
	set("exits", ([
		"east" : __DIR__"qiandian",
        ]));       

	set("objects", ([
		FOOD_D("rice") : 2,
		FOOD_D("hulu") : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *ob = deep_inventory(me);
	int i = sizeof(ob);
	if((dir == "east")){
		while (i--)
		if(ob[i]->id("qing hulu") || ob[i]->id("rice"))
			return notify_fail("食物请在厨房内吃完，请勿带出厨房用膳。\n");
	}
	return ::valid_leave(me, dir);
}
