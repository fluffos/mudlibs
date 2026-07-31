// yuefei.h 杀奸细任务
// derondog@ZLZY

object target;

string ask_job()
{
        string *key = ({
                "行至水穷处",
                "江山凭指点",
                "流水如有意",
                "云度一时影",
                "云卷千峰色",
                "掬水月在手",
                "海面水平等",
                "山高先得月",
                });

        string *yz = ({
                "/d/city/guangchang",
        });

        object me = this_player();
        string str, place;
        int num, life_time = 200 + random(200);

        if ( me->query("combat_exp") < 3000000 )
                return "经验不够\n";

        if ( me->query("quest/type")=="杀奸细" )
                return "我不是给了你任务了吗？\n";

        if ( me->query("quest") )
                return "你还有其他的任务吧？”\n";

        if ( me->query("fail_time") && me->query("fail_time") + 300 > time() )
                return "你上一次任务失败了，你还是回去好好反省吧！”\n";

        me->set("quest/type", "杀奸细");
        me->set("quest/task_time", time() + life_time);
        target = new("/quest/jianxi");
        target->set("born", time());
        target->set("life", life_time);

        command("nod" + me->query("id"));
        command("say 最近常有辽国奸细假扮官兵，到中原来打探消息……");
        me->set("quest/type", "杀奸细");
        me->set("quest/number", num);
        me->set("task_time", time() + 600);
                                 
        target = new("/quest/jianxi");
        tell_object(me, HIG "【悄语】岳飞告诉你：今天的暗号是" + HIW + key[num] + HIG + "，你去盘问你遇到的所有官兵，若发现蒙古奸细，格杀勿论！\n" NOR);                           

        place = yz[random(sizeof(yz))];
        target->move(place);
        me->set("quest/place", place);

        target->set("num", num);
        str = "去吧！\n";
        return str;             
}

string ask_fail()
{
}

