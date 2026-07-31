//canchang
  

inherit ROOM;

void create()
{
	set("short", "菜场");
	set("long", @LONG
这里是熙熙攘攘的菜场，地上湿湿的长年没有干的时候。小商小贩们
走来走去都想尽快卖完了回家。常年在这里摆摊的都要给南面屋里的恶霸
交保护费。
LONG
	);
set("outdoors","pingan");

	set("exits", ([
		 
		"south" : __DIR__"eba",
		"west" : __DIR__"wendingnan1",
		 
	]));
//        set("objects", ([
//                "/npc/npc": 2,
//	]));

        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	setup();
	replace_program(ROOM);
}

