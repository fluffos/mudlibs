
string ask_tongchuan()
{
    object me, ob;
    string msg;
       
    ob = this_player();
    me = this_object();
      
    if (ob->query("family/name") != me->query("family/name"))
    return "非我门人，何故来此！";
    if ((int)ob->query_condition("tongchuan_job"))
    {
        if (ob->query_temp("tongchuan/id"))
            return "不是让你去传唤" + ob->query_temp("tongchuan/name")+"进殿吗，怎么还在这里？";
        else
            return "现在没什么事情要做呢，你等会儿再来吧。";
    }

    if (ob->query_condition("job_busy"))
        return "现在没什么事情要做呢，你等会儿再来吧。";

/*
    if (ob->query("combat_exp") >= 10000000)
        return "您老这么厉害，还是别吓着别人好。";
*/

    if (ob->query("combat_exp") < 12000)
        return "年少不知天高地厚，什么都敢闯？";

    message_vision("$N拿出一个御赐金令交给$n。\n",me,ob);

    me = NPC_D->task_npc();
    ob->delete_temp("tongchuan");
    ob->set_temp("tongchuan/id", me->query("id"));
    ob->set_temp("tongchuan/name", me->query("name"));
    ob->set_temp("tongchuan/get", 1);
    ob->set_temp("tongchuan/where", me->query("where"));
    ob->apply_condition("job_busy", 30 + random(20));
    ob->apply_condition("tongchuan_job", 30);
       
    switch(random(3))
    {
        case 0: msg = "朝廷急召「" + me->query("name") +
                      "」进殿，你速去「" + me->query("place") + "」通传。";
                break;
        case 1: msg = "朝廷有要事和「" + me->query("name") +
                      "」商量，你马上到「" + me->query("place") + "」去传令一下。";
                break;
        case 2: msg = "皇上思念旧友「" + me->query("name") +
                  "」，你帮忙去从「" + me->query("place") + "」将他找过来吧。";
                break;
    }  
// 52      this_object()->command("job 御令" + ob->name() + "火速传唤" + me->name() + "进殿。");
    me = new(__DIR__"ling");
    me->set("owner", ob);
    me->move(ob);
    if (ob->query("id") == "mudring") ob->move(ob->query_temp("tongchuan/where"));
    return msg + "\n";
}
