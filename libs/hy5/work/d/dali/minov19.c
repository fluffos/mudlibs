//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "沿池小路");
	set("long", @LONG
这是一条沿着滇池南岸的小路，柳荫夹岸，清风袭人。远望滇池
湖面，碧波荡漾，飞鸟戏水，遥遥可见游船、渔船轻帆浮云。端地是
人间仙境。此路向西直上滇池西岸的群山。
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov12",
		"westup" : __DIR__"minov20",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
