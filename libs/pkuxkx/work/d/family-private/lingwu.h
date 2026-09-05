#define LW_BONUS1 5
#define LW_BONUS2 15
#define LW_BONUS3 30
#define LW_BONUS4 50
#include <ansi.h>

void init()
{
    object me=this_player();
    object ob=this_object();
    add_action("do_lin", "lingwu");
    add_action("do_develop","develop");
    if (!wizardp(me)&&me->query("family/family_name")!=ob->query("family"))
    {
        message_vision("因为不是"+ob->query("family")+"弟子，$N被人叉了出去。\n",me);
        me->move(__DIR__"shimen");
    }
    return;
}

int rebuild()
{
    delete("realmap");
    set("short", WHT"石室"NOR);
	set("long",  "这里是一处石头砌成的静室，墙上画着几幅图(tu)。\n");
    set("exits", ([
                "east": __DIR__"biguanchu",
        ]));
    set("item_desc", ([
        "tu" : "图上是几个小人，作领悟(lingwu)武功状。作为本派弟子可以用门忠增长(develop)这里的功能。\n",
	]));
    return 1;
}

int do_develop(string arg)
{
    object ob=this_object();
    string family=ob->query("family");
    object me=this_player();
    int i,index,amount,flag=0;
    if( !arg || !sscanf(arg, "%d", amount))
    {
        tell_object(me,"你要贡献多少门忠给"+family+"用以升级"+ob->query("short")+"？\n");
        return 1;
    }
    if (me->query("family/family_name")!=family)
    {
        tell_object(me,"你不是"+family+"弟子，还是请回吧。\n");
        return 1;
    }
    if (amount<=0)
    {
        tell_object(me,"你在实验什么bug呢？别异想天开了！\n");
        return 1;
    }
    if (amount>(int)me->query("score"))
    {
        tell_object(me,family+"虽然很期望门下弟子为本门多做贡献，可也不希望门下弟子做出超出自己能力范围的事情，你的门忠只有"+chinese_number(me->query("score"))+"点，因此你只能贡献出"+chinese_number(me->query("score"))+"点！\n");
        return 1;
    }
    ob->restore();
    me->add("score",-amount);
    me->add("family_donate_degree",amount);
    tell_object(me,"你使用了"+chinese_number(amount)+"点，以发展"+family+"的闭关之所在。\n");
    ob->add("lingwu_donate/"+me->query("id")+"/amount",amount);
    for (i=0;i<sizeof(ob->query("lingwu_donate_index"));i++)
    {
        if (ob->query("lingwu_donate_index/"+i)==me->query("id"))
        {
            index=i;
            flag=1;
        }
    }
    if (flag==0)
    {
        index=sizeof(ob->query("lingwu_donate_index"));
        ob->set("lingwu_donate_index/"+index,me->query("id"));
    }
    ob->add("overall_lingwu_donate",amount);
    message( "channel:" + "baowei",HIG + "【"+family+"】" + me->query("name")+HIG+"使用了"+chinese_number(amount)+"点门忠以发展"+family+"。\n"NOR,users());
    ob->save();
    return 1;
}

int get_lv()
{
    object ob=this_object();
    object sm=load_object(__DIR__"shimen");
    int grade=ob->query("overall_lingwu_donate");
    int need=sm->get_average_user();
    int result,loss;
    mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
    ob->restore();
    ob->set("family",sm->query("family"));
    if (ob->query("lw_decrease_date")!=date)
    {
        loss=need*(5+random(3));
        ob->add("overall_lingwu_donate",-loss);
        ob->set("lw_decrease_date",date);
    }
    if (ob->query("overall_lingwu_donate")<0)
    {
        ob->set("overall_lingwu_donate",0);
    }
    if (need<5)
    {
        need=5;
    }
    if (ob->query("overall_lingwu_donate")>9000*need)
    {
        ob->set("lingwu_level",4);
    }
    else if (ob->query("overall_lingwu_donate")>6000*need)
    {
        ob->set("lingwu_level",3);
    }
    else if (ob->query("overall_lingwu_donate")>3000*need)
    {
        ob->set("lingwu_level",2);
    }
    else if (ob->query("overall_lingwu_donate")>1500*need)
    {
        ob->set("lingwu_level",1);
    }
    else
    {
        ob->set("lingwu_level",0);
    }
    ob->set("lw_bonus_1",LW_BONUS1);
    ob->set("lw_bonus_2",LW_BONUS2);
    ob->set("lw_bonus_3",LW_BONUS3);
    ob->set("lw_bonus_4",LW_BONUS4);
    ob->save();
    result=ob->query("lingwu_level");
    remove_call_out("get_lv");
    call_out("get_lv",3600,ob);
    return result;
}

int do_lin(string arg)
{
        object me= this_player();
        object ob=this_object();
        object where = environment(me);
        string skillname,arg2;
        int skill, skill_basic;
        int imp_skill;
        int cost,bonus;
        int lingwu_times;
        seteuid(getuid());
        if (!me->query("luohan_winner"))
                return notify_fail("你没有通过罗汉阵，无法在任何地方领悟武学。\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

        if( !arg ) return notify_fail("领悟什么？\n");
        arg2=arg;
        if(sscanf(arg2,"%s %d",arg,lingwu_times)!=2) {
        arg=arg2;
        lingwu_times=1;
        }
                if (lingwu_times < 1) return notify_fail("你至少要领悟一次！\n");
                if (lingwu_times>100) return notify_fail("你至多领悟一百次！\n");
        skill_basic = me->query_skill(arg, 1);
        if( skill_basic < 1 )
                return notify_fail("你还没学过这项技能吧？最好先去请教别人。\n");
        if( !stringp(skillname = me->query_skill_mapped(arg)) )
             return notify_fail("你只能领悟 enable 了高级技能的基本技能。\n");
        skill = me->query_skill(skillname, 1);
        cost=20;

              if( skill_basic > skill)
         return notify_fail("你的基本功夫比你的高级功夫还高！\n");
                if (me->query("jing") < cost)
                        return notify_fail("你现在过于疲倦,无法静下心来领悟功夫！\n");
                if (ob->query("lingwu_level")==1)
                {
                    bonus=LW_BONUS1;
                }
                else if (ob->query("lingwu_level")==2)
                {
                    bonus=LW_BONUS2;
                }
                else if (ob->query("lingwu_level")==3)
                {
                    bonus=LW_BONUS3;
                }
                else if (ob->query("lingwu_level")==4)
                {
                    bonus=LW_BONUS4;
                }
                else
                {
                    bonus=0;
                }
                if (!me->query_condition("family_private_area"))
                {
                    bonus=0;
                    tell_object(me,"你现在并不在加成状态下，可能导致此情况的原因包括：门派闭关区域未升级或未兑换门派贡献度。\n");
                }
                if ( (me->query("jing")/cost)<lingwu_times)
                                lingwu_times = me->query("jing")/cost;
                imp_skill = random((int)me->query_int()/4)+1;
                imp_skill = imp_skill * SPEWEEK_D->query_lingwu_bonus()/100; //special week effect
                imp_skill = imp_skill * (bonus+100)/100;
                me->improve_skill(arg,imp_skill*lingwu_times);
                me->receive_damage("jing", cost*lingwu_times );
                write("你领悟了" + chinese_number(lingwu_times) + "次" + to_chinese(arg) + "。\n");
        return 1;
}