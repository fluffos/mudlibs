// Room: /u/jpei/thd/haibin.c
// Modified by Numa 19990906

#include <ansi.h>

inherit ROOM;

int do_jump(string arg);
int do_look(string arg);
int do_use(string arg);
int prevent_get();

void create()
{
        set("short", "海滨");
        set("long", @LONG
这里是钱塘江的入海口。波涛汹涌，咆哮不息。海潮(tide)不断地扑面而
来，拍在岸边，溅起的水珠在半空飞舞，好象大雪纷纷一样。
LONG
        );
        set("no_clean_up", 0);
        set("outdoors","牛家村");

        set("exits", ([
        "west": __DIR__"niujia/jiangpan3",
        ]) );

        set("item_desc", ([
                "tide" : "海潮滚滚而来，似乎欲将天地吞没。\n",
        ]) );   

        setup();
}

void init()
{
        add_action("do_jump", ({"jump", "tiao"}));
        add_action("do_use", "use");
        add_action("do_look", "look");
        add_action("prevent_get", "get");
}

int do_use(string arg)
{
        object me = this_player();
        object *ob;
        int i;
        ob = all_inventory(me);
	if (me->query_condition("killer"))
		return notify_fail("你还是了结完江湖恩怨再说吧。\n");
        if (me->is_busy()) return notify_fail("你正忙着呢！\n");
        for(i = 0; i < sizeof(ob); i++) {
               if (userp(ob[i])) {
                     return notify_fail("你跳上小船，结果因为背了人无法平衡，又摔回岸上。\n"); }
        }
        if ((arg == "boat" || arg == "chuan") && me->query_temp("thd_boat")) {
                me->delete_temp("thd_boat");
                write("你跳上小船，将船划向桃花岛。\n");
//                write("海上正是顺风，船借风势，数日内便到达了。\n");
                call_out("do_arrive",4,me);
                return 1;
        }
        return 0;
}

void do_arrive(object me)
{
        if (!me) return;
        message_vision("船将近岛，你已闻到海风中夹着扑鼻花香。\n",me);
        message_vision(HIW"你远远望去，岛上郁郁葱葱，一团绿、一团红、一团黄、一团紫，端的是繁花似锦。\n"NOR, me);
        message_vision("船「咣」的一声撞到了岸边，你急忙纵身跳上了岸。\n",me);
        me->move(__DIR__"shore");
        tell_room(environment(me), "一艘海船停靠过来，" + me->query("name") + "纵身跳起，稳稳落在岸上。\n", ({me}));
}
        
int do_jump(string arg)
{
        object me = this_player();

        if (me->is_busy()) return notify_fail("你正忙着呢！\n");
        if (arg == "boat" || arg == "chuan")
                return do_use(arg);

        if (arg != "chao" && arg != "tide")
                return notify_fail("你要往哪里跳？\n");

           if (me->query_dex() < 99)
                return notify_fail("你试图跳进海潮里，却总觉得力不从心。\n");
        if (me->query_skill("dodge") < 80)
                return notify_fail("你试图跳进海潮里，却发现自己的轻功修为还没有达到这么高的境界。\n");
        message_vision("$N耸身一跃，跳进了海潮中！\n", me);
//        me->move(__DIR__"niujia/tide");
        return 1;
}

int do_look(string arg)
{
        object me = this_player();

        if (me->query("family/family_name") != "桃花岛" && me->query_skill("qimen-bagua", 1) < 50) {
                set("long", @LONG
这里是钱塘江的入海口。波涛汹涌，咆哮不息。海潮(tide)不断地扑面而
来，拍在岸边，溅起的水珠在半空飞舞，好象大雪纷纷一样。
LONG
);
                me->look(arg);
        }
        else {
                if (!arg) {
                        set("long", @LONG
这里是钱塘江的入海口。波涛汹涌，咆哮不息。海潮(tide)不断地扑面而
来，拍在岸边，溅起的水珠在半空飞舞，好象大雪纷纷一样。远处有一块巨岩
(rock)，后面似乎隐藏着什么。
LONG
);
                        me->look(arg);
                }
                else if (arg == "rock" || arg == "yanshi" || arg == "juyan") {
                        write("一块巨岩，后面隐约露出一条船(boat)的船首来。\n");
                        me->set_temp("thd_boat", 1);
                        return 1;
                }
                else if ((arg == "boat" || arg == "chuan") && me->query_temp("thd_boat")) {
                        write("一条藏着的小船，不精通奇门八卦是很难发现的。\n");
                        return 1;
                }
        }
}

int prevent_get()
{
     write("你别开玩笑了。\n");
     return 1;
}
