// Room: /d/zhongzhou/yanling2.c

inherit ROOM;

void create()
{
	set("short", "平安西路");
	set("long", @LONG
这里就是平安西路，是平安城的一条老街。两边的房屋看上去已经很陈
旧了。路上冷冷清清的，偶尔有一两个人路过。再往前走，就能隐隐的看
见西城楼了。要是想出城的话，就要赶紧走了。要不然等城门关了，想出
城都不行了。
LONG
	);
set("outdoors","pingan");

        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shop4",
  "north" : __DIR__"zuixianlou",
  "east" : __DIR__"west2",
  "west" : __DIR__"pinganmen",
]));
//	set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/man6" : 1,
//]));

	setup();
	replace_program(ROOM);
}
