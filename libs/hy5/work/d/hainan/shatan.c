// Room: /d/hainan/shatan.c

inherit ROOM;

void create()
{
	set("short", "沙滩");
	set("long", @LONG
洁白的细沙宛如一匹纯色的丝绸,从你的脚下流过.一边是波涛阵阵 
的大海,微咸的海风中有海燕在飞翔.另一边就是嶙峋的岩石,由于亿万年 
来的海水冲刷,已经变得十分光滑. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/girl.c" : 1,
  __DIR__"obj/hailuo.c" : 1,
  __DIR__"obj/beike1.c" : 1,
		__DIR__"npc/man5":1,
		__DIR__"npc/man1":1,			
]));
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"haibian.c",
  "west" : __DIR__"underhill",
  "south" : __DIR__"shatan",
]));

	setup();
	replace_program(ROOM);
}
