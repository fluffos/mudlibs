
inherit ROOM;

void create()
{
	set("short", "平安城南街");
	set("long", @LONG
这是平安城南街，宽敞的街道看的人不竟心情一畅。西面有一家
不小的房子，两个武功教头正在比试着武功。门口招牌上写着训练中心
四个大字。肯定是一个练武的好地方。东北角有座镖局。你不知不觉已
走到了路的尽头。前面的南门好像还没有开放.
LONG
	);
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	set("outdoors", "/d/pingan");
//	set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/man3" : 1,
//]));
	set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"congwu",
  "west" : __DIR__"xunlian",
  "north" : __DIR__"nan2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
