// Room: /d/linzhi/inn05.c

inherit ROOM;

void create()
{
	set("short", "客店客房");
	set("long", @LONG
这里是客店三楼的客房，几个过路的客人正在休息。你慢手
慢脚，轻轻的来到一个空的床位上坐下。好好睡(sleep)一觉吧，
前面的旅途还长着呢。
LONG
	);
	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"inn03",

]));
  set("objects", ([ /* sizeof() == 4 */
"/clone/npc/man" : 3,  	
]));
	setup();
	replace_program(ROOM);
}
