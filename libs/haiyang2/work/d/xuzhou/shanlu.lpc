inherit ROOM;
void create()
{
	set("short", "山路");
	set("long", @LONG
这是山间的土路，勉强可以通行一辆大车，而且越往前走道路就越
窄，开始还能看见路上的车辙印、马蹄印，后来只有人走的痕迹了，听
说这里有猛兽伤人。	
LONG );
	set("exits", ([
		"west"     : __DIR__"weixian",
		"northeast" : __DIR__"dadao10",
	]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}

