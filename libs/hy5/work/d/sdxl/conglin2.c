// Room: /d/xiangyang/conglin2.c

inherit ROOM;


void create()
{
	set("short", "山路");
	set("long", @LONG
这里的路面更加陡峭，地上的足迹越来越少。一阵阵腐朽的味
从密林里面传出。偶尔比能看见一些猎户们捕捉野兽的陷阱。
LONG	);
	set("exits", ([  
        "eastdown" : __DIR__"conglin1",
        "westup" : __DIR__"conglin3", 
]));
	 
        set("outdoors", "xiangyang");
	setup();
}
int valid_leave(object me, string dir)
{
        if ((dir != "westup") && (dir != "eastdown"));
           if ((userp(me)) && (dir == "westup")){
        me->receive_damage("jing", 40);
            write("陡峭的山麓，让你颇感吃力，一会你就汗流浃背。\n");
    }

        if ((userp(me)) && (dir == "eastdown")){
        me->receive_damage("jing", 100);       
        write("陡峭的山麓，让你颇感吃力，一会你就汗流浃背。\n");
}
        return 1;
}
