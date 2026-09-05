#define XL_BONUS1 2
#define XL_BONUS2 3
#define XL_BONUS3 5
#define XL_BONUS4 8

#include <ansi.h>
#include <skill.h>


void init()
{
    object me=this_player();
    object ob=this_object();
    add_action("do_xl", "xiulian");
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
                "west": __DIR__"biguanchu",
        ]));
    set("item_desc", ([
        "tu" : "图上是几个小人，作修炼(xiulian)内功状。作为本派弟子可以用门忠增长(develop)这里的功能。\n",
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
    ob->add("xiulian_donate/"+me->query("id")+"/amount",amount);
    for (i=0;i<sizeof(ob->query("xiulian_donate_index"));i++)
    {
        if (ob->query("xiulian_donate_index/"+i)==me->query("id"))
        {
            index=i;
            flag=1;
        }
    }
    if (flag==0)
    {
        index=sizeof(ob->query("xiulian_donate_index"));
        ob->set("xiulian_donate_index/"+index,me->query("id"));
    }
    ob->add("overall_xiulian_donate",amount);
    message( "channel:" + "baowei",HIG + "【"+family+"】" + me->query("name")+HIG+"使用了"+chinese_number(amount)+"点门忠以发展"+family+"。\n"NOR,users());
    ob->save();
    return 1;
}

int get_lv()
{
    object ob=this_object();
    object sm=load_object(__DIR__"shimen");
    int grade=ob->query("overall_xiulian_donate");
    int need=sm->get_average_user();
    int result,loss;
    mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
    ob->restore();
    ob->set("family",sm->query("family"));
    if (ob->query("xl_decrease_date")!=date)
    {
        loss=need*(5+random(3));
        ob->add("overall_xiulian_donate",-loss);
        ob->set("xl_decrease_date",date);
    }
    if (ob->query("overall_xiulian_donate")<0)
    {
        ob->set("overall_xiulian_donate",0);
    }
    if (need<5)
    {
        need=5;
    }
    if (ob->query("overall_xiulian_donate")>9000*need)
    {
        ob->set("xiulian_level",4);
    }
    else if (ob->query("overall_xiulian_donate")>6000*need)
    {
        ob->set("xiulian_level",3);
    }
    else if (ob->query("overall_xiulian_donate")>3000*need)
    {
        ob->set("xiulian_level",2);
    }
    else if (ob->query("overall_xiulian_donate")>1500*need)
    {
        ob->set("xiulian_level",1);
    }
    else
    {
        ob->set("xiulian_level",0);
    }
    ob->set("xl_bonus_1",XL_BONUS1);
    ob->set("xl_bonus_2",XL_BONUS2);
    ob->set("xl_bonus_3",XL_BONUS3);
    ob->set("xl_bonus_4",XL_BONUS4);
    ob->save();
    result=ob->query("xiulian_level");
    remove_call_out("get_lv");
    call_out("get_lv",3600,ob);
    return result;
}

int do_xl(string arg)
{
    object me=this_player();
    string skill;
    int my_skill;
    int xl_time, fpot, outpar;
    
    seteuid(getuid());
    if(!stringp(arg))
           {
            return notify_fail("指令参数错误！正确的格式是：xiulian <技能名称>\n");
           } 
           
    if(me->is_busy()) return notify_fail("你现在正忙着呢。\n");
        
    if(me->is_fighting()) return notify_fail("战斗中不能练内功，会走火入魔。\n");
        
    if(me->query("lingjiu/last_xiulian_time"))
        return notify_fail("你现在正在恢复武功，没有精力研究武功。\n");

    skill=(string)arg;
    
        if( !me->query_skill(skill, 1) )
                return notify_fail("你不会这种技能。\n");

    //判断是否是内功，否则不能修炼
    if( !find_object(SKILL_D(skill)) && file_size(SKILL_D(skill)+".lpc") < 0)//判断是否是自创武功
            {
                if(!PLAYER_SKILL_D(skill)->valid_enable("force") )
                   return notify_fail("你只能修炼内功！\n");
            }
          else
            {
                   if(!SKILL_D(skill)->valid_enable("force") )
                   return notify_fail("你只能修炼内功！\n");
            }
               
    if(!SKILL_D(skill)->valid_learn(me)) return 0;
        
//门派检查，非本门非公共武学非出师前功夫不能修炼    
    outpar=F_KUNGFU->valid_xiulian(me, skill);
    if ( outpar<0 )
    	return 0;

    my_skill = me->query_skill(skill,1);
    if(my_skill < 100) 
        return notify_fail("你的"+to_chinese(skill)+"必须高于 100 级才能修炼。\n" );

    if( my_skill >= me->query_skill_limit() )//破坏公式美感，但是至少不会溢出了。 byZine
        return notify_fail("由于缺乏实战经验，你无法领会更高深的武功。\n" );
    
    if((int)me->query("learned_points") > (int)me->query("potential") - my_skill*2)
        return notify_fail("你的潜能必须大于 "+my_skill*2+" 才能修炼。\n");
    fpot=F_KUNGFU->xiulian_pot(my_skill, outpar*30);
    me->add( "learned_points", fpot );    
    
    xl_time=to_int(30 - (int)me->query("con")/2);
    
    if (xl_time>30 ) xl_time=30;
    if (xl_time<10 ) xl_time=10;
        
    me->set_temp("pending/xiulian", xl_time);
    
    //每次消耗潜能数等于skill级别，高等级时修炼不至于太难
    message_vision(HIM"\n$N盘膝坐下，运起丹田之气，开始修炼"+to_chinese(skill)+"......\n\n"NOR, me);
    me->start_busy("do_xiulian","halt_xiulian");
    me->set_temp("xiulian_skill",skill);
    return 1;
}

int do_xiulian(object me)
{
    string skill;
    int my_skill;
    int my_con;
    int imp_skill,bonus;
    object ob=this_object();
    my_con=(int)me->query("con")/2+(int)me->query("int")/2+5;
    if (my_con >=40) my_con=40;
    if (my_con <=10) my_con=10;
    //防止中途换内功
    if(!(skill = me->query_temp("xiulian_skill"))) return 0;
    my_skill = me->query_skill(skill,1);
    
    if ( !random(to_int(my_con/3))) 
    {
        tell_object( me, 
        MAG"......你摧动真气沿体内经脉流动，在百会、人中、神阕、丹田、会阴、命门、玉枕等要穴\n"+
        "      间不住流转，然后散之于四肢体骸......\n\n"NOR);
    }
    else if (!random(to_int(my_con/2)))
        tell_object(me,HIW"......你心中默念内功心法，缓缓催动体内气息运行周天。\n"
                "      只觉体内一股热气直透上来，你进入了一种玄妙的境界......\n\n"NOR);    
        if(me->is_fighting() && !random(20) )
    {
                tell_object(me, HIR "由于你在战斗中强行修炼内功，你走火入魔了！\n" NOR );
        log_file("nosave/xiulian_zouhuo",
        sprintf("%s(%s) 修炼内功走火于%s,%s等级掉一级。\n", 
        me->query("name"),me->query("id"),ctime(time()), to_chinese(skill) ));
        me->set_skill(skill, my_skill-1);
        return 0;
    }
    if (ob->query("xiulian_level")==1)
    {
        bonus=XL_BONUS1;
    }
    else if (ob->query("xiulian_level")==2)
    {
        bonus=XL_BONUS2;
    }
    else if (ob->query("xiulian_level")==3)
    {
        bonus=XL_BONUS3;
    }
    else if (ob->query("xiulian_level")==4)
    {
        bonus=XL_BONUS4;
    }
    else
    {
        bonus=0;
    }
    if (me->query_temp("pending/xiulian") < 2)
    {
        if (!me->query_condition("family_private_area"))
        {
            bonus=0;
            tell_object(me,"你现在并不在加成状态下，可能导致此情况的原因包括：门派闭关区域未升级或未兑换门派贡献度。\n");
        }
        F_KUNGFU->xiulian_improve(me, my_con, bonus+100);
        return 0;
    }
    me->add_temp("pending/xiulian", -1 );
    return 1;
}

int halt_xiulian(object me)
{
    string skill;
    if(!(skill = me->query_skill_mapped("force"))) return 0;
    
    me->delete_temp("pending/xiulian");
    tell_object(me,HIR"你强行将内力纳入丹田,缓缓吐了口气,站了起来.\n"NOR);
    if ( !random(30) )
    {
        tell_object(me,HIY"你由于强行中断修炼，不禁一阵头昏目眩......你走火了！\n"NOR);
        log_file("nosave/xiulian_zouhuo",
        sprintf("%s(%s) 修炼内功走火于%s,%s等级掉一级。\n", 
        me->query("name"),me->query("id"),ctime(time()), to_chinese(skill) ));
        me->set_skill(skill,me->query_skill(skill,1)-1);
    }
    return 1;
}