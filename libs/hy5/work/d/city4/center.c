//changan  city

inherit  ROOM;

void  create  ()
{
	set  ("short",  "十字街头");
	set  ("long",  @LONG
这里便是长安城的中心，东南西北四条大街交汇于此。广场中央一
座巍峨高大的钟楼耸立于前，和市北的鼓楼遥相呼应，很是有些气势。
每到清晨，响亮的钟声便会伴着淡淡雾气传向长安城的大街小巷。路口
车水马龙，来往人潮不断。
LONG);
        //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));

        set("exits",  ([  //sizeof()  ==  4
            //"north" :  __DIR__"club",
            //"south" :  __DIR__"bank",
		"north" :  __DIR__"northroad2",
		"south" :  __DIR__"southroad2",
		"east"  :  __DIR__"eastroad2",
            //"west"  :  __DIR__"westgate",
            "west"  :  "/d/changan/ca34",
            //"east"  :  __DIR__"eastgate",
        ]));
        set("objects",  ([  //sizeof()  ==  1
             __DIR__"npc/petowner"  :  1,
        ]));
        set("outdoors",  "changan");
        setup();
	replace_program(ROOM);
}

