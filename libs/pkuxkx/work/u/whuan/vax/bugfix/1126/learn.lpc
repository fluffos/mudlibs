// learn.c

#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;

string *reject_msg = ({
        "说道：您太客气了，这怎么敢当？\n",
        "像是受宠若惊一样，说道：请教？这怎么敢当？\n",
        "笑着说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
        });

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    string skill, teacher, master, skill_name;
    object ob;
    int master_skill, my_skill, gin_cost,exp,times,i,qijiaotimes=0,learntimes=0,zuanyantimes=0;

    if (me->is_busy())
        return notify_fail("你现在正忙着呢。\n");
    if( me->is_fighting() )
        return notify_fail("临阵磨枪？来不及啦。\n");
    if(me->query("lingjiu/last_xiulian_time"))
        return notify_fail("你现在正在恢复武功，没有精力向师父学习。\n");

    if(!arg || (sscanf(arg, "%s for %s %d", teacher, skill,times) !=3 ))
        return notify_fail("指令格式：learn|xue <某人> for <技能> <次数>\n");
    if (times < 1 || times>50)
        return notify_fail("学习次数应该在 1-50 次之间！\n");

    if( !(ob = present(teacher, environment(me))) || !ob->is_character())
        return notify_fail("你附近没有 "+teacher+" 这个人，请用 id here 指令看看周围人物 id 。\n");
    if( !living(ob) )
        return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

    if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me)) && me->query("marry/lover") != ob->query("id") ) {
        return  notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
    }

    if( !master_skill = ob->query_skill(skill, 1) )
        return notify_fail(ob->name()+"不会 "+skill+" 这项技能，请用 skills 指令看人物的技能。\n");
    if( ob->prevent_learn(me, skill) )
        return notify_fail(ob->name() + "不愿意教你这项技能。\n");

    my_skill = me->query_skill(skill, 1);

    notify_fail("依你目前的能力，没有办法学习这种技能。\n");
    if( !SKILL_D(skill)->valid_learn(me) ) return 0;

    gin_cost = 150 / (int)me->query("int");

    if( !my_skill ) {
        gin_cost *= 2;
        me->set_skill(skill,0);
    }
    if( my_skill >= master_skill)
        gin_cost = gin_cost * 10;

    if(times<1)times=1;
    printf("你向%s请教"+chinese_number(times)+"次有关「%s」的疑问。\n", ob->name(),to_chinese(skill));  
    for(i=0;i<times;i++)
    {
        my_skill = me->query_skill(skill, 1);
        if( (int)me->query("learned_points") >= (int)me->query("potential") )
            return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
        qijiaotimes++;
        if(!me->is_apprentice_of(ob) && !ob->recognize_apprentice(me) )
            return notify_fail("看上去"+ob->query("name")+"并不想教你！\n");
        if( ob->query("env/no_teach") )
            return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");

        tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",
                    me->name(), to_chinese(skill)));

        if( (int)ob->query("jing") > gin_cost/5 + 1 ) {
            if( userp(ob) ) ob->receive_damage("jing", gin_cost/5 + 1);
        } else {
            write("但是" + ob->name() + "显然太累了，没有办法教你什麽。\n");
            tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
            return 1;
        }


        if( (int)me->query("jing") > gin_cost ) {
            if( (string)SKILL_D(skill)->type()=="martial"
                    &&  my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
                printf("也许是缺乏实战经验，你对%s的回答总是无法领会。\n", ob->name() );
                me->receive_damage("jing",gin_cost);
                break;
            } else {
                learntimes++;
                me->add("learned_points", 1);
                if (my_skill==0) my_skill=1;
                exp=me->query("combat_exp");
                if (exp==0) exp=1;
                if( my_skill >= master_skill)
                {
                    if((int)me->query("learned_points") > (int)me->query("potential")-10)
                        return notify_fail("你的潜能不足以进行切磋！\n");
                    me->add("learned_points",4);
                    if( (int)me->query("jing") < gin_cost ) 
                        return notify_fail("你的精力不足，不能切磋！\n");
                    exp= random(exp/my_skill*me->query_int()*2/my_skill/my_skill);
                }
                else    
                {                       
                    exp= random(exp/my_skill*me->query_int()*4/my_skill/my_skill);
                    if (exp < 10)  exp=random(me->query_int()+1);
                }
                me->improve_skill(skill,exp);
            }
        } else {
            gin_cost = me->query("jing");
            write("你今天太累了，结果什么也没有学到。\n");
            me->receive_damage("jing",gin_cost );
            break;
        }

        me->receive_damage("jing", gin_cost );
    }
    if( my_skill >= master_skill)
        write(HIR"你和师父切磋了"+chinese_number(learntimes)+"次，消耗了大量潜能。\n"NOR);
    else 
        write("你共请教了" + chinese_number(learntimes)+"次\n");
    if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
        printf("你听了%s的指导，对「%s」这一招似乎有些心得。\n", ob->name(),
                skill_name);
    else
        printf("你听了%s的指导，似乎有些心得。\n", ob->name());

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

