// 扫钟楼任务
// derondog@ZLZY

string ask_job()
{
        object me = this_player();
        int time = 480 + random(120);

        if ( me->query("quest/type")=="打扫钟楼" )
                return "我不是叫你去打扫钟楼吗，怎么又跑回来了？\n";

        if ( me->query("quest") )
                return "你还有其他的任务吧？\n";
        
        if ( me->query("fail_time") && me->query("fail_time") + 300 > time() )
                return "你上一次任务失败了，你还是回去好好反省吧！”\n";

        if ( me->query("combat_exp") > 50000 )
                return RANK_D->query_respect(me) + "身手已经如此了得，无需再在这里做事了。\n";

        me->set("quest/type", "打扫钟楼");
        me->set("quest/task_time", time() + time);
        return "请你到工具房找管事领取扫帚，然后去钟楼打扫吧。\n";      
}

string ask_over()
{
        object me = this_player();
        int exp, pot;

        exp = 50 + random(50);
        pot = 25 + random(50);

        if ( me->query("quest/type") != "打扫钟楼" )
                return "我什么时候给叫你去打扫钟楼了？\n";

        if ( !me->query_temp("quest/saozhou") )
                return "你好象还没有把工具还回去吧！\n";

        if ( !me->query("quest/zhonglou1")
        || !me->query("quest/zhonglou2")
        || !me->query("quest/zhonglou3")
        || !me->query("quest/zhonglou4")
        || !me->query("quest/zhonglou5")
        || !me->query("quest/zhonglou6")
        || !me->query("quest/zhonglou7")
        || !me->query("quest/zhonglou8") ) 
                return "你好象还没有扫完吧？\n";

        if ( me->query("quest/task_time") < time() ) {
                command("sigh");
                me->delete("quest");
                me->delete_temp("quest");
                return "你没有在规定的时间完成，我不能给你任何奖励了。\n";
                }    
        command("nod " + me->query("id"));
        tell_object(me, sprintf(HIW"你被奖励了：\n%s点实战经验，\n%s点潜能。\n"NOR,
                chinese_number(exp), chinese_number(pot)));
        me->add("combat_exp", exp);
        me->add("potential", pot);
        me->delete("quest");
        me->delete_temp("quest");

        return "不错，以后好好干！\n";
}

string ask_fail()
{
        object me = this_player();
 
        if ( me->query("quest/type") != "打扫钟楼" )
                return "我什么时候给你任务了？\n";

        me->delete("quest");
        me->set("fail_time", time());
        return "做事贵在坚持，既然你不愿意，我也不强求你了。\n";
}

