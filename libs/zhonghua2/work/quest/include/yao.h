// 找物品任务
// update by sun 

#define QUEST_L "/quest/list/yaolist"

string ask_job()
{
        object me;
        int time, exp;
        mapping quest;
        me = this_player();
        time = random(240);
        exp = me->query("combat_exp");

        if ( me->query("quest/type")=="寻找" )
                return "我不是叫你去找东西吗，怎么又跑回来了？\n";

        if ( me->query("quest") )
                return "你还有其他任务在身吧？\n";
        
        if ( me->query("fail_time") && me->query("fail_time") + 300 > time() )
                return "你上次任务失败了，已经派人代替你去完成任务了。你过一会再来吧。\n";

    if (me->query_temp("yao_wait",1))
          return "你刚刚才完成一个任务，先休息一会吧。\n";
        if (exp < 100000)
                return RANK_D->query_respect(me) + "以你现在的能力为我做事太危险，你还是先去提高自己的本领吧。\n";
        if ( exp > 5000000 )
                return RANK_D->query_respect(me) + "身手不凡，我可请不起啊。\n";
        else quest = QUEST_L->query_quest(140);

        me->set("quest/type", "寻找");
        me->set_temp("yao_wait",1);
        me->set("quest/task_time", time() + 480 - time);
        me->set("quest/quest", quest["quest"]);
        me->set("quest/bouns", quest["bouns"] + random(quest["bouns"]));
        command("whisper " + me->query("id") + " " + "如果能找回" HIM + me->query("quest/quest") + NOR + WHT"给我，我会好好答谢你的。");
        if ( quest["help"] )
        tell_object(me, sprintf(HIR "『" NOR + WHT"任务提示"NOR+ HIR "』" NOR +"：" + HIG "这东西也许可以在%s找到。\n" NOR, quest["help"]));
        return me->name() + "快快动身吧！！！\n";
}

string ask_fail()
{
        object me = this_player();
 
        if ( me->query("quest/type") != "寻找" )
                return "我什么时候给你任务了？\n";

        me->delete("quest");
        me->set("fail_time", time());
        me->delete_temp("yao_wait",1);
        return "哎，你要我怎么说你才行呢？\n";
}

int accept_object(object me, object obj)
{
        int exp, pot, score, weiwang, money, pot_limit;

        if ( this_object()->is_busy() ) {
                command("say 不要着急，我正忙着呢！\n");
                return 0;
                }

        if ( me->query("quest/type") != "寻找"
        || obj->query("name") != me->query("quest/quest") )
                return 0;

        if ( me->query("quest/task_time") < time() ) {
                command("sigh " + me->query("id"));
                me->delete("quest");
                me->delete_temp("yao_wait",1);
                remove_call_out("dest_obj");
                call_out("dest_obj", 1, obj);
                return 1;
                }

        command("nod " + me->query("id"));
        command("say 这是你的奖励。\n");
        exp = me->query("quest/bouns") + random(100);
        pot = exp/2 + random(20);
        pot_limit = me->query_potential_limit() - me->query("potential");
        if (pot > pot_limit) pot = pot_limit;
        if (pot < 1) pot = 0;
        
        score = 1 + random(3);
        weiwang = 1 + random(2);
        money = (50 + random(10))*200;
        tell_object(me, sprintf(YEL"通过这次锻炼你获得了：%s点实战经验，%s点潜能，%s点江湖阅历，%s点威望。\n"+
        "作为一点奖励，另外给你: "NOR+HIR+MONEY_D->money_str(money)+NOR+YEL+"，已经存入银号了。\n"NOR,
                chinese_number(exp), chinese_number(pot), chinese_number(score), chinese_number(weiwang)));
        
//        command("tell " + me->query("id")+YEL"作为一点奖励，另外给你: "HIR+MONEY_D->money_str(money)+YEL+"，已经存入银号了。\n"NOR);

        me->add("combat_exp", exp);
        me->add("potential", pot);      
        me->add("score", score);
	me->add("weiwang", weiwang);
	me->add("balance",money);
        me->delete("quest");
        me->delete("fail_time");        
//      message_vision("$N得意的将$n放进了身后的箱子里面。\n", this_object(), obj);
         this_object()->start_busy(1);
        remove_call_out("dest_obj");
        call_out("dest_obj", 1, obj);
        call_out("dest_yaowait",30);
        return 1;
}

int dest_yaowait()
{
        object me = this_player();
        me->delete_temp("yao_wait",1);
        command("tell " + me->query("id") + " 休息够了没有？可以继续来工作了。");
}
void dest_obj(object obj)
{
        destruct(obj);
}

