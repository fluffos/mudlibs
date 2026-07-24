// baohu npc copy
// by mudring

void bhnpc_copy(object me)
{
    int level;
    object guai = this_object();

    guai->set("title", me->query("name")+"搭救的");
    guai->set("owner", me);
    guai->set("level", me->query("level"));

    level = NPC_D->get_skill_level(me);
    STATU_D->set_npc_skill(guai, level, "月宫");
    NPC_D->set_npc_hp(guai, me, 100);
    NPC_D->place_npc(guai);
    call_out("leave", random(100)+600);
}

// 更改奖励算法.
// mudring Sep/07/2002
int accept_object(object who, object ob)
{
    int i, k;
    string str;
    object guai = this_object();
    object me = this_player();

    if (me != owner())
    {
        message_vision(CYN"$N说道：你不是我等的那个人。\n"NOR,guai);
        return 1;
    }
    if (!me->query_temp("baohu/done") || me->query_temp("baohu/killer") < 3)
    { 
        message_vision(CYN"$N说道：我还没脱险，别磨磨蹭蹭，动作快点。\n"NOR,guai);
        return 1;
    }
    if (ob->name() != "水晶鞋" || ob->query("id") != "shuijing xie")
    {
        message_vision(CYN"$N说道：这是什么玩意儿，快带我回家。\n"NOR,guai);
        return 0;
    }

    // 奖励修改，整体降低 Mudring Feb/24/2004
    i = (int)me->query("baohuhuaxian");
    i = 800 + random(200) + i / 10;
    if (i > 2000)  i = 2000 + random(100);
    k = i / 5 + random(50);

    me->add("daoxing", i);
    me->add("potential", k);

    str = " do dajiu got " + i + " daoxing " + k + " pot";
    tell_object(me, "你得到了" +chinese_daoxing(i)+"的道行！"
            +chinese_number(k)+"点潜能的奖励！\n");

    guai->command("kiss6 "+me->query("id"));

    message_vision(CYN"$N道了万福说道：谢谢你搭救了我！。\n"NOR, guai);
    message_vision(CYN"$N说完，穿上水晶鞋蹭了蹭，消失了！。\n"NOR, guai);
    MONITOR_D->mudring_log("dajiu", me, str);

    me->delete_temp("baohu");
    me->add("baohuhuaxian", 1);
    me->clear_condition("dajiu_job");
// 66      me->apply_condition("job_busy", 5 + random(5));

    guai->move(get_object("/obj/empty"));
    call_out("leave", 0);
    return 1;
}

