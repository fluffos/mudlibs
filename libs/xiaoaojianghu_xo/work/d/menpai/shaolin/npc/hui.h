int attempt_apprentice(object who)
{
    if(who->query("gender")!="男性")
        command("say  阿弥陀佛，女施主不要跟老纳开玩笑。");
    else if (who->query("class")!="bonze")
        command("say 未得方丈准许，老纳不敢擅收俗家弟子。施主还是请回吧.");
    else if (!who->query_marks("defeat_huilun"))
    {
        command("pat " + who->query("id"));
        command("say 嗯,等你武功再好些在来吧.");
    }
    else
    {
        command("say 好,老纳今天就破例受下你了,还望你好自为之使少林武学发扬光大");
        command("recruit " + who->query("id"));
        command("recruit " + who->query("id"));
    }
}

int accept_fight(object who)
{
    if((string)who->query("class")=="bonze")
        command("say 阿弥陀佛！出家人戒逞强恶斗！贫僧不敢违反清规。");
    else
        command("say 施主既然身负绝艺，贫僧佩服便是，也不必较量了。");
    return 0;
}

int accept_bihua(object who)
{
    return accept_fight(who);
}



