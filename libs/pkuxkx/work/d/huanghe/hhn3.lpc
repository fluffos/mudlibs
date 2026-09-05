//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄河南岸"NOR);
        set("long", @LONG
这里是黄河南岸，滚滚黄河一刻不停地奔腾东去。堤坝上有个小洞(hole)。
LONG
        );
        set("exits", ([
             "east" : __DIR__"dkn1",
             "northwest" : __DIR__"hhn4",
        ]));
       
        set("couldfish",1);
        set("item_desc",([ "hole" : 
                "这个小洞黑乎乎的，什么也看不清，你可以钻(zuan)进去看看。\n"
        ]));

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");

        setup();
}

int rebuild()
{
    this_object()->set("exits/northwest", __DIR__"hhn4");
}

int valid_leave(object me,string dir)
{  
    
	if (dir=="northwest" && random(300)>294)
    {
        this_object()->delete("exits/northwest");
        call_out("rebuild",60);
        return notify_fail(HIY"你正要前行，有人大喝：黄河决堤啦，快跑啊！\n"NOR);
    }
	return ::valid_leave(me, dir);
}

void init()
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
                                me->name() + "一弯腰往堤坝上的小洞里钻了进去，一闪就不见了。\n",
                                environment(me), ({me}) );
                        me->move("/d/gaibang/bjandao5");
                        message("vision",
                                me->name() + "不知道从哪里钻了进来。\n",
                                environment(me), ({me}) );
                        return 1;

} 
