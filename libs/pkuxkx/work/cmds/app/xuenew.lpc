// learn.c
// Modified by iszt@pkuxkx, 2007-05-19

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "说道：「您太客气了，这怎么敢当？」\n",
        "像是受宠若惊一样，说道：「请教？这怎么敢当？」\n",
        "笑着说道：「您见笑了，我这点雕虫小技怎够资格「指点」您什么？」\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string teacher, skill;
        int times;
        object ob;
        int jing_cost;
        int master_skill, my_skill;
        int points;
        int query_int, age, max_skill;
        string skill_name;

        if(me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
        if(me->is_fighting())
                return notify_fail("临阵磨枪？来不及啦。\n");
        if(me->query("lingjiu/last_xiulian_time"))
                return notify_fail("你现在正在恢复武功，没有精力向师父学习。\n");

        if(!arg || ( sscanf(arg, "%s %s %d", teacher, skill, times) != 3
                && sscanf(arg, "%s for %s %d", teacher, skill, times) != 3
                && sscanf(arg, "%s %s", teacher, skill) != 2 ))
                return notify_fail("指令格式：learn|xue <某人> <技能> [次数]\n");
        if(!times)
                times = 1;
        if(times < 1 || times > 50)
                return notify_fail("学习次数应该在 1-50 次之间！\n");
        if( (int)me->query("learned_points") + times > (int)me->query("potential") )
                return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
        if( !(ob = present(teacher, environment(me))) || !ob->is_character())
                return notify_fail("你附近没有 "+teacher+" 这个人，请用 id here 指令看看周围人物 id 。\n");
        if( !living(ob) )
                return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");
        if(!me->is_apprentice_of(ob) && !ob->recognize_apprentice(me) )
                return notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
        if( !master_skill = ob->query_skill(skill, 1) )
                return notify_fail(ob->name()+"不会 "+skill+" 这项技能，请用 skills 指令看人物的技能。\n");
        if( ob->prevent_learn(me, skill) )
                return notify_fail(ob->name() + "不愿意教你这项技能。\n");
        if( ob->query("env/no_teach") )
                return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");

        notify_fail("依你目前的能力，没有办法学习这种技能。\n");
        if( !SKILL_D(skill)->valid_learn(me) )
                return 0;

        //基本条件满足，开始请教
        write(sprintf("你向%s请教"+chinese_number(times)+"次有关「%s」的疑问。\n", ob->name(),to_chinese(skill)));
        tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",
                me->name(), to_chinese(skill)));

        jing_cost = 150 / (int)me->query("int") * times;
        my_skill = me->query_skill(skill, 1);
        master_skill = ob->query_skill(skill, 1);
        if( my_skill >= master_skill)
                jing_cost = jing_cost * 10;

        if(me->query("jing") < jing_cost + 10)
        {
                write("你今天太累了，结果什么也没有学到。\n");
                me->set("jing", 0);
                return 1;
        }
        me->receive_damage("jing", jing_cost );

        if( (int)ob->query("jing") > jing_cost/5 + 1 )
        {
                if( userp(ob) )
                        ob->receive_damage("jing", jing_cost/5 + 1);
        }
        else
        {
                write("但是" + ob->name() + "显然太累了，没有办法教你什麽。\n");
                tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
                return 1;
        }

        if( (string)SKILL_D(skill)->type()=="martial"
                &&  my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
        {
                write("也许是缺乏实战经验，你对"+ob->name()+"的回答总是无法领会。\n");
                return 1;
        }

        //一切条件满足，获得进步
        query_int = me->query_int();
        age = me->query("age");
        //exp = me->query("combat_exp");
        max_skill = pow(me->query("combat_exp")/100, 1.0/3) * 10;

        //points = query_int; 后天悟性越高，学习效率越高
        points = query_int - 10;
        //points += max_skill; 最大武功等级越高，学习效率越高
        points += max_skill / 20;
        //points += master_skill; 师父等级越高，学习效率越高
        points += master_skill / 10;
        //age; 年龄对学习效率的影响
        if((string)SKILL_D(skill)->type()=="martial")
        {
                //age==18时达到学习效率的巅峰，越老学习效率衰退越快
                if(age >= 100)
                        points -= (age-100)/2;
                if(age >= 40)
                        points -= (age-40);
                if(age >= 25)
                        points -= (age-25);
                if(age >= 18)
                        points -= (age-18);
                else
                        points -= (18-age);
        }
        else
        {
                //age==40时达到学习效率低谷
                if(age < 40)
                        points += (40-age);
                else
                        points += (age-40);
                points -= 40;
        }
        points = points / 4 * 3 + random(points / 2);
        if(points < 14)
                points = 10 + random(5);

        if( my_skill >= master_skill)
        {
                if( (int)me->query("learned_points") + times*4 > (int)me->query("potential") )
                        times /= 4;
                me->add("learned_points", times * 4);
        }

        me->add("learned_points", times);
        points *= times;

        if( my_skill >= master_skill)
                write(HIR"你和师父切磋了"+chinese_number(times)+"次，消耗了大量潜能。\n"NOR);
        if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
                printf("你听了%s的指导，对「%s」这一招似乎有些心得。\n", ob->name(), skill_name);
        else
                printf("你听了%s的指导，似乎有些心得。\n", ob->name());

        me->improve_skill(skill, points);

        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : learn|xue <某人> for <技能> <次数>

这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你请教的对象在这
项技能上的造诣必须比你高，而你经由这种方式学习得来的技能也不可能高於你所请
教的人，然而因为这种学习方式相当於一种「经验的传承」，因此学习可以说是熟悉
一种新技能最快的方法。

此外学习也需要消耗一些精力，而消耗的精力跟你自己、与你学习对象的悟性有关。

当你要学习的功夫等级已经高于你的师父时，再学就是以切磋的形式来学了。这时消耗
的潜能、精力都是正常学习时的好几倍。除非没有更厉害的师父可以拜了，否则还是
尽量拜更高级师父以保证正常的学习速度。

其他相关指令 : apprentice, practice, skills, study
HELP
                 );
        return 1;
}
