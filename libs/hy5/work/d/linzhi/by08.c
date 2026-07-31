// Room: /d/linzhi/by08.c

inherit ROOM;

void create()
{
	set("short", "镇北小路");
	set("long", @LONG
这里是镇北的一条小路，路面坑坑洼洼，不太好走。你一不
小心，脚踩进了一处水洼，你急忙把脚缩了回来，小声地骂了一
句。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by07",
  "north" : __DIR__"by09",
]));
        set("outdoors", "linzhi");
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/sheepgirl" : 2,  	
"/clone/npc/man" : 3, 	
]));
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
