#include <ansi.h>

inherit F_CLEAN_UP;
int potential_lv(int exp);

int main(object me, string arg)
{
        object ob,*inv;
        int i, exp, max_pots, pots, bonus;
        mapping quest ;

        exp = (int)me->query("combat_exp");
        max_pots = (int)me->query("max_pot");
        pots = (int)me->query("potential") - (int)me->query("learned_points");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( !arg )
              return notify_fail("指令格式：gei <对象>\n");

        if( !objectp(ob = present(arg, environment(me))))
                return notify_fail("你想送信给谁。\n");

        ob = present(arg, environment(me));
        quest = me->query("quest");

//         if((quest["quest_type"] != "把信送给"))
//              return notify_fail("你现在的任务不是送信。\n");

        if(ob == me)
                return notify_fail("自己送信给自己，真是个好主意．．．\n");

        if(!(ob->query("name") == quest["quest"]))
                return notify_fail("对方不接受你的信件，你送错人了。\n");

        if(userp(ob))
                return notify_fail("你挺聪明，可惜不管用，嘻嘻。\n");

        if((int)time() > (int)me->query("task_time"))
                return notify_fail("你没有按时送到，不会有奖励了。\n");

        message_vision("$N对$n说道：多谢！多谢！这是你的酬劳。我将它存入你钱庄的帐号了。\n",ob,me);
        me->add("balance",500);
        me->add("combat_exp",(int)quest["exp_bonus"]);
         me->add("potential",(int)quest["pot_bonus"]);
        bonus = (int)me->query("potential");
        bonus = bonus - (int)me->query("learned_points");
        bonus = bonus + (int)quest["pot_bonus"];
        if ( bonus > potential_lv((int)me->query("combat_exp")) )
        bonus = potential_lv((int)me->query("combat_exp"));
        bonus += (int)me->query("learned_points");
        me->set("potential", bonus );

        tell_object(me, HIW "你被奖励了：\n" +
        chinese_number((int)quest["exp_bonus"]) + "点实战经验\n"+
        chinese_number((int)quest["pot_bonus"]) + "点潜能\n" NOR);

        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
                if(inv[i]->query("name") == "信件")
                        destruct(inv[i]);
        }
        me->set("quest", 0 );
        return 1;
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp /500;
        return grade;
}


