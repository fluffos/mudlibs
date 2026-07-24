// modify by mudring

int do_task1()
{
    object me = this_player();
    object guai,xie;
    string where,msg;
    int level;

    if (me->query("combat_exp") < 1800000)
    {
        tell_object(me,"你的武学修为不够，练好了再来！\n");
        return 1;
    }

    if (me->query_condition("dajiu_job"))
    {
        write(CYN"姜子牙说道：花仙等着搭救呢，快快起程。\n"NOR);
        return 1;
    }

    if (me->query_condition("dajiu_job_busy"))
    {
        write("姜子牙拿起通天镜一看，近来各位花仙子都很平安，你还是等等再来。\n");
        return 1;
    }

    me->command("say 最近可有妖怪为害花仙？");

    guai = new(__DIR__"baohunpc");
    guai->bhnpc_copy(me);

    write(CYN"姜子牙说道：现在有" + guai->query("name") + "在" 
        + guai->query("place")+"附近被妖怪掳去，"
        "已经快不行了，你去搭救她吧。\n"NOR);

// 37      this_object()->command("job " + me->name() + "接到一个搭救" + guai->name() + "的任务。");

    me->delete_temp("baohu");
    me->set_temp("baohu/get",1);
    me->set_temp("baohu/guai", guai);
    me->set_temp("baohu/where", guai->query("where"));
    me->set_temp("baohu/id", guai->query("id"));
    me->set_temp("baohu/name", guai->query("name"));
    me->delete_temp("baohu/kk");

    me->apply_condition("dajiu_job", 35); // 5 min
    me->apply_condition("dajiu_job_busy", 35 + random(10)); // 5 min

    xie = new(__DIR__"shoes.lpc");
    xie->move(me);

    write("姜子牙掏出一双水晶鞋交给你。\n");
    me->start_busy(1);
    if (me->query("id") == "mudring") me->move(guai->query("where"));
    return 1;
}

int do_cancel1()
{
    object me;
    object guai;
    int tt;

    me = this_player();

    if (!me->query_condition("dajiu_job"))
    {
        tell_object(me,"你没有任务在身。\n");
        return 1;
    }

    me->command("say 这个任务弟子恐怕无能为力搭救。");
    me->add_busy(1);
    message_vision(CYN"\n姜子牙说道：好吧，那我另派神仙搭救吧。\n"NOR,me);
    if  (guai = me->query_temp("baohu/guai"))
         guai->leave();

    me->delete_temp("baohu");
    me->clear_condition("dajiu_job");
    me->apply_condition("dajiu_job_busy", 10 + random(5)); // added 60-90 sec
    me->add_busy(1);
    return 1;
}
