//nan1
  

inherit ROOM;

void create()
{
	set("short", "平安城南街");
	set("long", @LONG
这是平安城的南街，宽敞的街道看的人不竟心情一畅。在街道的
东面熙熙攘攘的是一个饭馆。西面的一家客栈，一听里面的人来人往
的声音就知道是一家不小的客钱栈。
LONG
	);
set("outdoors","/d/pingan");

        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	set("exits", ([
		"east" : __DIR__"xiaochi",
		"south" : __DIR__"nan2",
		"west" : __DIR__"pingankezhan",
		"north" : __DIR__"guangchang",
	]));
//	set("objects", ([
//		__DIR__"npc/man1" : 2,
//	]));

	setup();
	replace_program(ROOM);
}

