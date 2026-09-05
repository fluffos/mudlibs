//Cracked by Roath
// /d/changbai/gaoliangdi.c

inherit ROOM;

void create()
{
        set("short", "高粱地");
        set("long", @LONG
这里是北京近郊的高粱地，共二三十亩，高粱稀稀落落。高粱田后有两
间农舍，过了篱笆，推开板门，你发现角里堆了不少农具。后面有一个小院子。

LONG
        );

        set("outdoors", "shenlong");

       /* set("item_desc",([ "高粱地" : 
                "一片茂密的高粱地，隐隐约约有一条小路！\n"
        ]));*/

        set("exits", ([
                "south" : __DIR__"yidao2",
        ]));

        set("objects",([
            //    "/kungfu/class/shenlong/hong" : 1,
//                "/kungfu/class/shenlong/xu" : 1,
                "/d/changbai/npc/huyidao" : 1,
                
        ]));

        set("cost", 3);

        setup();
//        replace_program(ROOM);
}
/*void init()//丐帮暗道出口南移到黄河以南。By Zine Dec 2 2010
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();
        
                        message("vision",
                                me->name() + "一弯腰往高粱堆里钻了进去，一闪就不见了。\n",
                                environment(me), ({me}) );
                        me->move("/d/gaibang/bjandao5");
                        message("vision",
                                me->name() + "不知道从哪里钻了进来。\n",
                                environment(me), ({me}) );
                        return 1;

} */
