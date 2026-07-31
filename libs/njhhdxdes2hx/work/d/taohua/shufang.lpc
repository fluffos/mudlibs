// Room: /d/new_taohua/shufang.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
屋内琳琅满目,全是诗书典籍。几上桌上摆着许多铜器玉皿，看来都
是古物。壁上挂着一幅水墨画，画得是一个中年书生在月明之夜中庭伫立，
手按剑柄，仰天长叹，神情寂寞。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "west" : __DIR__"yonglu7",
  "north" :__DIR__"huangwshi",
  "south" :__DIR__"yinyueshi",
]));
	

	setup();
	replace_program(ROOM);
}
