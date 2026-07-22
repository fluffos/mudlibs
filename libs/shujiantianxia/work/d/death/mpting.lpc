inherit ROOM;

void create()
{
	set("short", "孟婆亭");
	set("long", @LONG
传说，在黄泉路上，过了奈何桥，有座凉亭，唤作“孟婆亭”。由一个面
貌阴森的老妇“孟婆”掌管，凡是赶往投胎、在此过路的地狱阴魂都要喝她的
“孟婆汤”。喝完以后，将忘却所有的恩怨。。。
LONG);
	set("exits", ([ 
		"out" : "/d/death/gate",
	]));
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/mengpo": 1
	]) );
	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;
	if( dir == "out") 
		return notify_fail("孟婆对着你叹了口气：别再想啦，来喝了这口汤吧。喝了它，就什么都忘记了！\n");
	else return 1;
}
