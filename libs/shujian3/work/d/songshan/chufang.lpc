// Room: /u/swl/songshan/chufang.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
厨房里冒出阵阵菜香，不少嵩山弟子在练功之余要在这里打杂干活，
因而平时大家的伙食不错。
LONG);
	set("exits", ([
            "east" : __DIR__"lwdting",
        ]));
        set("objects", ([ 
            FOOD_D("fan") : 1+random(2),
            FOOD_D("zongzi") : 1+random(2),
            FOOD_D("zhuhu") : 1,
        ]));
	setup();
}
