// Room: /d/xiangyang/conglin3.c

inherit ROOM;


void create()
{
	set("short", "山路");
	set("long", @LONG
这里已经看不见人的足迹了，只有一些纷杂的野兽脚印。路越
发陡峭，一般人来到这里就不感再前行了。
LONG	);
	set("exits", ([  
        "eastdown" : __DIR__"conglin2",
         "westup" : __DIR__"conglin4",
         "east" : "d/migong/migong1",
        ]));
        set("objects",([
              "/d/heimuya/npc/snake" : 1,
        ]));      
	 
        set("outdoors", "xiangyang");
	setup();
}
int valid_leave(object me, string dir)
{
        if ((dir != "westup") && (dir != "eastdown"));
         if ((userp(me)) && (dir == "westup")){
            me->receive_damage("jing", 90); 
            me->receive_damage("qi", 50);       
            write("陡峭的山麓，让你颇感吃力，一会你就汗流浃背。\n");
    }

        if ((userp(me)) && (dir == "eastdown")){
        me->receive_damage("jing", 90);    
        me->receive_damage("qi", 50);     
        write("陡峭的山麓，让你颇感吃力，一会你就汗流浃背。\n");
}
        return 1;
}
