// Room: /u/cuer/emei/chfang12.c

inherit ROOM;

void create()
{
	set("short", "禅房");
	set("long", @LONG
这里是文怡的禅房。简单而整齐的摆放着一张床
和一张小桌，桌上放着几本佛经，文怡正端坐在床上
，一边敲着木鱼一边念经。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dlang5",
]));
	set("objects", ([ 
             __DIR__"npc/wenyi" : 1
                   ]));
	
        setup();
	replace_program(ROOM);
}
