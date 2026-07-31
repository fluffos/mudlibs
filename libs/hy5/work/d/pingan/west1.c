//west1
inherit ROOM;
void create()
{
  set ("short", "平安西路");
  set ("long", @LONG
这里就是平安西路，是平安的一条老街。两边的房屋看上去已经很陈
旧了。路上冷冷清清的，偶尔有一两个人路过。再往前走，就能隐隐的看
见西城楼了。路南面有间武器店，北面有有防具店，估计生意应该不错.
LONG);

set("outdoors","pingan");

        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

  set("exits", ([  
    "west" : __DIR__"west2",
    "south" : __DIR__"shop1",
    "north" : __DIR__"shop2",
    "east"  : __DIR__"guangchang",
]));
//	set("objects",([
//		__DIR__"npc/man3":1,
//	]));
       
	 setup();
        replace_program(ROOM);
}
