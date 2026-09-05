void init()
{
    add_action("do_eat","eat");
    add_action("do_drink","drink");
    add_action("do_query","query");
    add_action("do_convert","convert");
}

int do_convert(string arg)
{
    object me=this_player();
    object ob=load_object(__DIR__"shimen");
    int amount,got;
    if (!wizardp(me)&&me->query("family/family_name")!=ob->query("family"))
    {
        message_vision("因为不是"+ob->query("family")+"弟子，$N被人叉了出去。\n",me);
        me->move(__DIR__"shimen");
    }
    if( !arg || !sscanf(arg, "%d", amount))
    {
        tell_object(me,"你打算兑换多少点"+ob->query("family")+"门派贡献度？\n");
        return 1;
    }
    if (amount<=0)
    {
        tell_object(me,"你在实验什么bug呢？别异想天开了！\n");
        return 1;
    }
    if (amount>(int)me->query("family_donate_degree"))
    {
        tell_object(me,"理想很美好，可惜现实很残酷，你的门派贡献度只有"+chinese_number(me->query("family_donate_degree"))+"点。\n");
        return 1;
    }
    got=amount*15;
    me->add("family_donate_degree",-amount);
    me->apply_condition("family_private_area",(int)me->query_condition("family_private_area")+got);
    message_vision(HIC"$N消耗了"+chinese_number(amount)+"点门派贡献度，获得闭关区域内修炼的资格。\n"NOR,me);
    if (got/5>1)
    {
        tell_object(me,"你大约获得(增加)了"+chinese_number(got/5)+"分钟门派闭关区域修炼时间，可用来在加成状态下dazuo/tuna/xiulian/lingwu/lian各种武学。\n");
        tell_object(me,"离开闭关区域则不消耗闭关区域修炼时间。\n");
    }
    return 1;
}

int do_query()
{
    object me=this_player();
    object ob=load_object(__DIR__"shimen");
    object ob1=load_object(__DIR__"dazuo");
    object ob2=load_object(__DIR__"lingwu");
    object ob3=load_object(__DIR__"xiulian");
    object ob4=load_object(__DIR__"lian");
    int dazuo=ob->query("dazuo_tuna_level");
    int lian=ob->query("practice_level");
    int lingwu=ob->query("lingwu_level");
    int xiulian=ob->query("xiulian_level");
    string msg;
    if (!wizardp(me)&&me->query("family/family_name")!=ob->query("family"))
    {
        message_vision("因为不是"+ob->query("family")+"弟子，$N被人叉了出去。\n",me);
        me->move(__DIR__"shimen");
    }
    else
    {
        if (!ob->query("dz_bonus_1"))
        {
            ob1->get_lv();
        }
        if (!ob->query("l_bonus_1"))
        {
            ob4->get_lv();
        }
        if (!ob->query("lw_bonus_1"))
        {
            ob2->get_lv();
        }
        if (!ob->query("xl_bonus_1"))
        {
            ob3->get_lv();
        }
        ob->restore();
        
        msg=ob->query("family")+"发展情况如下：\n";
        msg+="打坐吐纳加成级别："+HIC+chinese_number(dazuo)+NOR+" 级\n";
        msg+="练功加成级别："+HIC+chinese_number(lian)+NOR+" 级\n";
        msg+="领悟加成级别："+HIC+chinese_number(lingwu)+NOR+" 级\n";
        msg+="修炼加成级别："+HIC+chinese_number(xiulian)+NOR+" 级\n";
        msg+=HIW+"---------------------------------------------------\n"+NOR;
        msg+="0-4级加成效果如下：\n";
        msg+="打坐吐纳：0  "+ob->query("dz_bonus_1")+"%  "+ob->query("dz_bonus_2")+"%  "+ob->query("dz_bonus_3")+"% "+HIR+"  "+ob->query("dz_bonus_4")+"%"+NOR+"\n";
        msg+="练习外功：0  "+ob->query("l_bonus_1")+"% "+ob->query("l_bonus_2")+"%  "+ob->query("l_bonus_3")+"% "+HIR+"  "+ob->query("l_bonus_4")+"%"+NOR+"\n";
        msg+="领悟武功：0  "+ob->query("lw_bonus_1")+"%  "+ob->query("lw_bonus_2")+"%  "+ob->query("lw_bonus_3")+"% "+HIR+"  "+ob->query("lw_bonus_4")+"%"+NOR+"\n";
        msg+="修炼内功：0  "+ob->query("xl_bonus_1")+"%  "+ob->query("xl_bonus_2")+"%   "+ob->query("xl_bonus_3")+"% "+HIR+"   "+ob->query("xl_bonus_4")+"%"+NOR+"\n";
        tell_object(me,msg);
    }
    return 1;
}

int do_eat()
{
    object me=this_player();
    if (me->query("food")>=300)
    {
        tell_object(me,"再吃就要撑破肚皮了。\n");
        return 1;
    }
    me->set("food",300);
    message_vision("$N拿起石桌上的果蔬，开始吃了起来。\n",me);
    return 1;
}

int do_drink()
{
    object me=this_player();
    if (me->query("drink")>=300)
    {
        tell_object(me,"再喝就要撑破肚皮了。\n");
        return 1;
    }
    me->set("drink",300);
    message_vision("$N拿起石桌上的水罐，慢慢喝了几口。\n",me);
    return 1;
}