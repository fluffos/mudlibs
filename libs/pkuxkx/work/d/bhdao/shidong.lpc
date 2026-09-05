// by advent

inherit ROOM;

void create()
{
        set("short", "石洞");
        set("long", 
"但见山洞极是宽敞，有八九丈纵深，中间\n"
"透入一线天光，宛似天窗一般。\n"
        );
        set("exits", ([
                "north" : __DIR__"hole",
                "south" : __DIR__"bhdong",
                "east"  : __DIR__"pyuan1",
        ]));
        set("sleep_room", 1);
        set("no_steal", "1");
        set("no_perform", "1");
        set("no_fight", "1");
        set("objects",([        
                __DIR__"npc/xie" : 1,
                ]));
        setup();
}
void init()
{
        add_action("do_fight", "perform");
        add_action("do_fight","yong");
        add_action("do_fight","yun");
        add_action("do_fight","exert");
        
}
int do_fight()
{
        write("你也不想想，你会是狮王的对手吗？！\n");
        return 1;
}


int valid_leave(object me,string dir)
{       
        if( ( (int)me->query("marks/mupai") != 1 ) && dir=="north" )
        return notify_fail("谢逊拦住你说道：洞中是我一生心血所在，岂容你随意出入？\n");       
        if( ( me->query_skill("qishang-quan",1) > 1 ) && objectp(present("xie xun",environment(me))) 
                && dir=="north" && (int)me->query_temp("marks/hole") != 1)
        return notify_fail("谢逊拦住你说道：老子现在饿得紧，给我找些食物才许你进去。\n");
        return ::valid_leave(me, dir);   
}

