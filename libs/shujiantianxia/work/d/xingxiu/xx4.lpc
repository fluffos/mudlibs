// Room: /d/xingxiu/xx4.c

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
你走在一条在星宿海海边乱石堆里崎岖的小路上，路边有一群星宿弟子正
在长啸练功。这里，阴风凛冽，西面是望浩浩百里方圆的星宿海。东面是座陡
峭之极的山壁，壁上有一凸出的巨石(jushi) 。
LONG);
        set("exits", ([
            "west" : __DIR__"xxh1",
            "south" : __DIR__"xxh2",
            "northup" : __DIR__"xx5",
        ]));

        set("item_desc", ([
                "jushi" : "一数米高的黑褐色巨石。\n"
        ]));


        set("objects", ([
                __DIR__"npc/tianlang"  : 1,
                __DIR__"npc/xxdizi3" : 1,
        ]));

        set("outdoors", "xingxiuhai");

        setup();
}

void init()
{
        add_action("do_pa", "pa");
}

int do_pa(string arg)
{
        object me;
        mapping myfam;
        me = this_player();
        myfam = (mapping)me->query("family");

        if( !arg || arg=="" ) return 0;

        if( arg=="jushi" )
        {
           if ((!myfam || myfam["family_name"] != "星宿派") && (present("tianlang zi", environment(me)))) 
               return notify_fail("天狼子闪身拦在你面前, 喝道：不想死的就快滚开！\n");
           if(me->query_skill("dodge") < 100)
               return notify_fail("你想爬上巨石，怎奈身法不够上不去。\n");       
           message_vision("$N很费劲地爬上巨石。\n", me);
           message("vision", me->name() + "一转眼便消失在山壁上。\n", environment(me), ({me}) );
           me->move(__DIR__"jushi");
           message("vision", me->name() + "从山壁下爬了上来。\n", environment(me), ({me}) );
           return 1;
         }
}
