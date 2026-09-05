// shishi.c 石室
// by paladin
inherit ROOM;

void create()
{
        set("short", "石室");
        set("long", @LONG
室中放着一只石桌，桌前有凳，桌上坚着一铜镜，镜旁放着些
梳子钗钏之属，看来竟是闺阁所居. 室中一座白玉雕成的玉像。
这玉像与生人一般大小，身上一件淡黄色绸衫微微颤动；更奇
的是一对眸子莹然有光，神彩飞扬. 玉像前本有两个蒲团，似
是供人跪拜磕头之用. 玉像双脚的鞋子内侧似乎绣得有字。凝
目看去，认出右足鞋上绣的是“磕首千遍，供我驱策”八字，
左足鞋上绣的是“遵行我命，百死无悔”八个字.
LONG
        );
       set("no_sleep_room",1);
        set("exits", ([
//              "west" : __DIR__"gate2",
		"east" :__DIR__"fudi",
		"north" :__DIR__"weiqishi",
		"south" :__DIR__"shifeng",
        ]));


    set("objects",(
[
            __DIR__"npc/obj/lbwb":1,
  ]));

        set("book_count",1);

        setup();

}

void init()
{
        this_player()->set_temp("ketou_times", 100);
        add_action("do_ketou", "ketou");
}

int do_ketou()
{
        object me, ob;

        me = this_player();

        if ((int)me->query("jing")<40)
        {
                write("你实在是太疲倦了，不能再磕头了！\n");
                return 1;
        }

        if ( me->query_temp("ketou_times") == 0 )
        {
                message_vision("$N磕头磕得晕了过去。\n", me);
                me->set_temp("ketou_times", random(50));
                me->unconcious();
                return 1;
        }

        me->add_temp("ketou_times", -1);


        message_vision("$N虔诚地跪下来，恭恭敬敬的向玉像磕起头来。\n", me);

        if ( random(100) == 37
        && !present("bmsg", me)
        && query("book_count") >= 1)
        {
                add("book_count", -1);
                ob=new("d/dali/obj/bmsg");
                ob->move("/d/dali/shishi");
                tell_object(me, "你面前的小蒲团破裂了，露出了一个绸包.
绸包里面是一卷帛卷, 那就是北冥神功\n");
        }

        if ((int)me->query_skill("force", 1) >= 30
        && (int)me->query_skill("force", 1) <= 100
        && present("bmsg", me) )
        {
                me->receive_damage("jing", 20);
                me->improve_skill("force", me->query("int"));
                if ( random(5) == 0 )
                tell_object(me, "冥冥之中，你似乎觉得内功方面将有所长进。\n");
        }

        return 1;

}

int valid_leave(object me, string dir)
{
     if(me->query_temp("ketou_times") >= 0 )
          me->delete_temp("ketou_times");
     return ::valid_leave(me,dir);
}
