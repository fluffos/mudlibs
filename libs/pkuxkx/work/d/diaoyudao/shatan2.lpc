// Room: /d/diaoyudao/shatan2.c 沙滩
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "沙滩");
	set("long", @LONG
这里是钓鱼岛的南岸，你走在细软的沙滩上，发出沙沙的声音。
这里有不少的海鸟和海鸥，有的冲入海面捕鱼，有的落在礁石上整
理羽毛，有的欢快地鸣叫。东北边是一片树林。
LONG
	);
	
	set("exits", ([
		 "southeast" : __DIR__"shatan3",
		 "west": __DIR__"shatan1",
		 "northeast" : __DIR__"shulin3",
	]));
   set("objects",([
       __DIR__"npc/hainiao" : 2,
    ]));
	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

