// Room: /d/xiangyang/conglin1.c

inherit ROOM;


void create()
{
	set("short", "山路");
	set("long", @LONG
这里是山麓上唯一的一条土路，山势虽然并不算太高，但是极
为陡峭，四周丛林密部，不时传来野兽的鸣叫。只有很有经验的猎
户才敢来这里捕猎，据说这里的毒蛇怪蟒异常凶狠。所以这里少有
人迹。
LONG	);
	set("exits", ([  
        "eastdown" : __DIR__"outsroad3",
        "westup" : __DIR__"conglin2", 
         "northup" : "/d/jqg/shanlu3", 
]));
	 
        set("outdoors", "xiangyang");
	setup();
}
int valid_leave(object me, string dir)
{
        if ((dir != "westup") && (dir != "eastdown"));
         if ((userp(me)) && (dir == "westup")){
            me->receive_damage("qi", 100);       
            write("陡峭的山麓，让你颇感吃力，一会你就汗流浃背。\n");
    }

        if ((userp(me)) && (dir == "eastdown")){
        me->receive_damage("qi", 100);       
        write("陡峭的山麓，让你颇感吃力，一会你就汗流浃背。\n");
}
        return 1;
}
