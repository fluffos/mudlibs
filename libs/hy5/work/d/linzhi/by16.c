// Room: /d/linzhi/by16.c

inherit ROOM;

void create()
{
	set("short", "叉路口");
	set("long", @LONG
你来到小镇的叉路口，这里过往的人很多，你看着花花绿绿
的服饰，越看越觉得美丽。一个看上去像是珞巴族的姑娘不小心
碰了你一下，对着你迷人的一笑，然后走开了。你不禁呆了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"by15",
  "west" : __DIR__"by17",
  "east" : __DIR__"by04",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/man" : 1,  	
"/clone/npc/man" : 1, 	
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
