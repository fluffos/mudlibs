int do_jiejiu(string arg);

void init()
{
        object me = this_player();
        add_action("do_jiejiu", "jiejiu");
        if (!me->query_temp("was_job") && userp(me) && !wizardp(me))
        {
                message_vision("什么人竟然擅闯万安寺？快放箭！\n");
                message_vision("一阵乱箭射来，$N连中数箭，落荒而逃。\n", me);
                me->move("/d/nanyang/kedian1");
                me->unconcious();
        }
}

int valid_leave(object me, string dir)
{
        object ob = present("yuanbing shouwei", environment(me));
        if (ob)
                return notify_fail("元兵守卫冲到你面前大叫：哪里走！\n");
        if (!query("save"))
                return notify_fail("还没救人就走了？不是吧你？来做什么的？\n");
        if (dir == "up" && me->query_temp("was_job/floor") > FLOOR)
                return notify_fail("你已经逃出来了，还上去做什么？\n");

        return ::valid_leave(me, dir);
}

int do_jiejiu(string arg)
{
        object me = this_player(), ob = present("yuanbing shouwei", environment(me));
        object *obs = all_inventory();
        if (query("save"))
                return notify_fail("已经解救成功，向上前进吧。\n");
        if (ob)
                return notify_fail("这里还有守卫在，如何进行解救？\n");
        if (!me->query_temp("was_job/asked"))
                return 0;
        foreach(ob in obs)
                if (ob->query_temp("was_job/floor") < FLOOR)
                        ob->set_temp("was_job/floor", FLOOR);
        set("save", 1);
        message_vision(HIC"$N见守卫已经全部杀光，便上前打开牢门，将" + SAVE_NPC + "解救出来。\n"NOR, me);
        return 1;
}

int query_floor()
{
        return FLOOR;
}

void check_death(object ob)
{
//        ob->delete_temp("was_job");
}

void setup_shouwei(int num)
{
        while (num--)
                new(NPC_D("jingcheng/yuanbing-shouwei"))->move(this_object());
}
