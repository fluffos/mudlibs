// baling/xunhuange
// Room in 龟兹 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "百花苑");
	set("long", @LONG
这里是百花苑，龟兹第一妓的住处。厅中摆着一张杉木圆桌和几张
椅子，桌上是一套精致的宜兴瓷器。墙上挂着一幅巨画，画的是美女飘
香，是吴道子的手笔。一个美女正向窗外望着。
LONG
	);

	set("exits", ([
		"down" : __DIR__"micunyuan",
	]));

	set("objects",([
	 __DIR__"npc/girl":1,
	 ]));
	
	setup();
	replace_program(ROOM);
}

