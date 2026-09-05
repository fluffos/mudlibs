// qiecuo.c 
// 改正切磋中的bug，限制切磋只能用在基本武功和技能类武功中
// 判师者可以与师傅切磋，但是难度增大

#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;

string *reject_msg = ({
        "说道：您太客气了，这怎么敢当？\n",
        "像是受宠若惊一样，说道：在下怎么能与您相提并论呢？\n",
        "笑着说道：您见笑了，我这点雕虫小技怎么够资格，还不够您笑话的呢。\n",
        });
string *skill_list = ({
        "strike", "sword", "cuff", "club", "parry", "hammer", "force", "staff", "pestle",
        "hand", "dodge", "spear", "unarmed", "throwing", "fanwen", "axe","medical-skill","halberd",
        "claw", "blade", "finger", "literate", "whip", "poison", "training", "music", "taoism",
        "buddhism", "mahayana", "stealing", "begging", "checking", "daoxue-xinfa", 
        });

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    string skill, teacher, skill_name, msg;
    object ob;
    int master_skill, my_skill, gin_cost, betrayer; 
    int times, i, learntimes=0;

    if(me->is_busy()) return notify_fail("你现在正忙着呢。\n");
    if(me->is_fighting() ) return notify_fail("临阵磨枪？来不及啦。\n");
    if(me->query("lingjiu/last_xiulian_time"))
        return notify_fail("你现在正在恢复武功，没有精力研究武功。\n");

    if(!arg || (sscanf(arg, "%s %s %d", teacher, skill,times)<2 ))
        return notify_fail("指令格式：qiecuo <某人> <技能> [次数]\n");
    if(times>50) return notify_fail("你也太贪心了，最多做50次！\n");

    if( !(ob = present(teacher, environment(me))) || !ob->is_character())
        return notify_fail("你想与谁切磋？\n");
    if( !living(ob) ) return notify_fail("你得先把" + ob->name() + "弄醒再说。\n");
    if( ob->query("env/no_teach") )
        return notify_fail("但是" + ob->name() + "现在并不准备与你切磋。\n");
    if( !master_skill = ob->query_skill(skill, 1) )
        return notify_fail(ob->name() + "并没有学会这个技能。\n");
    //是否属于可以切磋的武功
	if(member_array(skill,skill_list) == -1)
        return notify_fail("基本武功和知识类技能才能切磋提高。\n");

    if(!SKILL_D(skill)->valid_learn(me)) return 0;
    my_skill = me->query_skill(skill, 1);
    if( my_skill < master_skill)
        return notify_fail("就你这么几手三脚猫的功夫，学高点再说吧。\n" );

    if( (string)SKILL_D(skill)->type()=="martial"
            &&  my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
        return notify_fail("由于缺乏实战经验，你总是无法领会更高深的武功。\n" );
    //悟性高的话，消耗精力多，但是技能提高快
    gin_cost = random(my_skill/10) + me->query("int");
    if(times<1) times=1;
    betrayer = 3 + me->query("betrayer");
    msg = ob->name() + "和你讨论有关" + to_chinese(skill) + "的疑问。\n";
    tell_object(ob, sprintf("%s与你讨论有关「%s」的问题。\n", me->name(), to_chinese(skill)));
    for(i=0;i<times;i++)
    {
        //检查是否拜师了，或者是否交了足够的钱
        if( !me->is_apprentice_of(ob) && !ob->recognize_apprentice(me))
        {
            msg += (ob->name() + reject_msg[random(sizeof(reject_msg))]);
            break;
        }
        if((int)me->query("learned_points") > (int)me->query("potential") - 10)
        {
            msg += "现在你的潜能太少，没有办法再切磋了。\n";
            break;
        }

        if( (int)ob->query("jing") < gin_cost/5 + 1 )
        {
            tell_object(ob, "现在你太累了，没有办法与" + me->name() + "讨论武功。\n");
            msg += "现在" + ob->name() + "太累了，没有办法与你讨论什么。\n";
            break;
        }
        if( userp(ob) ) ob->receive_damage("jing", gin_cost/5 + 1);

        if( (int)me->query("jing") < gin_cost )
        {
            msg += "现在你太累了，没有办法与" + ob->name() + "讨论武功。\n";
            break;
        }

        me->receive_damage("jing",gin_cost);
        learntimes++;
        me->add("learned_points", 5);
        //去掉了增长点数与经验的关系，大概5点换3~16点
        me->improve_skill(skill,3 + random(me->query_int() * master_skill/my_skill/betrayer));
    }
    if(learntimes)
        msg += HIR"你们在一起切磋了"+chinese_number(learntimes)+"次，你觉得很有收获。\n"NOR;
    write(msg);
    return 1;
}

int help(object me)
{
    write(@HELP
            指令格式 : qiecuo <某人> <技能> [次数]

这个指令可以让你与别人切磋有关某一种技能的疑难问题，你的技能等级至少要与请
教的对象在这相等，你的悟性越高，技能级别越低，能获得的收益就越高。目前可以
切磋的技能包括知识类和基本武功。

其他相关指令 : apprentice, practice, skills, study, learn
HELP
    );
    return 1;
}

