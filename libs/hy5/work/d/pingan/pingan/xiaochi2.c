//canchang
  

inherit ROOM;

void create()
{
	set("short", "小吃店内");
	set("long", @LONG
这里是小吃店的厨房,由于店里面的生意很不错,这二天,做菜的大师傅有点做不过
来了,只见他手忙脚乱的在干活.
LONG
	);
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

	set("exits", ([
		"west" : __DIR__"xiaochi",
                "east" : __DIR__"xiaochi3",
	]));
        set("objects", ([
		__DIR__"npc/shifu" : 1,
	]));

	setup();
	replace_program(ROOM);
}

