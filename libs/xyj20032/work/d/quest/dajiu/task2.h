// by mudring

int do_task2()
{
    object me = this_player();
    object guai;
    string where;
    int tt;

    if (me->query("combat_exp") < 1800000)
    {
        tell_object(me,"你的武学修为不够，练好了再来！\n");
        return 1;
    }

    if (me->query_condition("baohu_job"))
    {
        write(CYN"姜子牙脸色一沉：事关人命，火速行动！\n"NOR);
        return 1;
    }

    if (me->query_condition("job_busy"))
    {
        write("姜子牙拿起通天镜一看，近来魔教没有采取什么行动，大家相安无事。\n");
        return 1;
    }

    me->command("say 最近可有魔贼做乱？");

    guai = NPC_D->task_npc();
    where = guai->query("place");
    me->delete_temp("dajiu");
    me->set_temp("dajiu/get", 1);
    me->set_temp("dajiu/id", guai->query("id"));
    me->set_temp("dajiu/name", guai->query("name"));
    me->set_temp("dajiu/where", where);
    me->delete_temp("dajiu/kk");
    me->apply_condition("baohu_job", 35); // 5 min
    me->apply_condition("job_busy", 35 + random(10)); // 5 min

    write(CYN"姜子牙说道：夜观天象，最近魔教有可能对" + guai->query("name") +
        "("+ guai->query("id") + ")不利，你速去" + where + "保护其安全！\n"NOR);
/*
    this_object()->command("job " + me->name() + 
        "接到一个保护" + guai->name() + "的任务。");
*/
    me->start_busy(1);
    if (me->query("id") == "kuku") me->move(guai->query("where"));

    return 1;
}

int do_cancel2()
{
    object me = this_player();

    if (!me->query_condition("baohu_job"))
    {
        tell_object(me,"你没有任务在身。\n");
        return 1;
    }

    me->command("say 这个任务弟子恐怕无能为力保护。");
    message_vision(CYN"姜子牙说道：好吧，那我另派神仙去保护。\n"NOR, me);
    me->delete_temp("dajiu");
    me->clear_condition("baohu_job");
    me->apply_condition("job_busy", 10 + random(5)); // added 60-90 sec
    me->start_busy(1);
}

