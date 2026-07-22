// Room: /d/heimuya/zhaoze/huozhao.c
inherit ROOM;
int do_pull(string);
void create()
{
        set("short", "洪荒古泽");
        set("long", @LONG
你站在齐腰深的水里，周围是给烧得乌黑的古树和芦苇。前面有
一缺口，象是被一种巨大的动物经过所形成的。远处隐隐传来阵阵的
低沉的声音和热浪。
LONG
);
        set("exits", ([ 
  "southwest" : __DIR__"huozhao1",
]));

        setup();
}
void init()
{
        object me=this_player();
        add_action("do_pull", "pull");
        if (random(me->query("kar"))<10){
            message_vision(RED "$N身子突然下沉... ...\n" NOR,me);
            me->set_temp("drop_zhaoze",1);
        }
}
int do_pull(string arg)
{
    object ob;
    object me = this_player(); 

    if (!arg)
        return notify_fail("你要拉谁？\n");

    if (!ob = present(arg,this_object()))
        return notify_fail("你要拉谁？\n");

    if (me->query_temp("drop_zhaoze"))
        return notify_fail("你自己都自身难保了，还想拉别人？\n");

    if (!ob->query_temp("drop_zhaoze"))
        return notify_fail(ob->name()+"不用你拉！\n");

    message_vision("你扯住$N的手，使劲把$n扯了上来。\n",me,ob);
    ob->delete_temp("drop_zhaoze");
    return 1;
}
int valid_leave(object me, string dir)
{
        if (dir=="south" && me->query_temp("drop_zhaoze")){
                message_vision("$N使劲挣扎一下，试图爬出泥潭.....\n",me);
                if (random(10)>5){   
                        me->apply_condition("scorpoin_poison",20);
                        tell_object(me,RED "\n你突然觉得脚被什么东西刺了一下... ...\n" NOR);
                }
                if (random(me->query_skill("dodge",1))>600){
                        message_vision("$N身形一纵，跃出泥潭。\n",me);
                        return 1;
                }else{
                        message_vision("$N结果越陷越深！\n",me);
                        me->set_temp("die_for","陷进沼泽闷");
                        me->receive_wound("qi",200);
                       return notify_fail("你陷入沼泽，动弹不得。\n");
                }
        }
        return 1;
}

