// Room: /d/fengtian/jjf3.c

inherit ROOM;

void create()
{
	set("short", "会客厅");
	set("long", @LONG
这里是大金皇帝会客和商谈军机大事的地方，四周墙上挂了不少
名人字画，可见皇帝并非粗人一个，大厅里摆着一个兵器架，架
上白着一把古香古色的宝剑。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lang1",
  "west" : __DIR__"jjf2",
  "east" : __DIR__"jjf4",
  "north" : __DIR__"xf1",
]));
        set("objects",([
        	__DIR__"npc/bing" :2,        
        	__DIR__"npc/wujiang2" :1,        	
        	//__DIR__"npc/wujiang3" :1	
       	
        ]));
	setup();
	replace_program(ROOM);
}
