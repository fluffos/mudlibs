//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "北大街");
        set("long", @LONG
你走在一条宽阔的青石大道上,街上行人很多,个个衣着
鲜明,神气的很,就是不时传来几句四川特有的脏话,"龟儿子
的","先人板板",不过他们并不一定是在骂人哦,只是口头禅
不雅而已!西面是一家珠宝店，东面有一间赌场。
LONG
        );

        set("exits", ([
                "north" : __DIR__"beijie1",
                "south" : __DIR__"guangchang",
               "east" : __DIR__"duchang",
                "west" : __DIR__"zhubaodian",                
        ]));
        set("outdoors","chengdu");
      
        setup();
        replace_program(ROOM);
}

 
