
int do_yanke(string arg)
{
    object ob=this_object();
    object me=this_player();
    string words,log;
    
    if (!me->query_temp(ob->query("yanke_no")+"/permit"))
    {
        tell_object(me,"你必须征得"+ob->query("boss")+"的同意才能使用宴会厅。\n");
        return 1;
    }
    if (ob->query("yanke")||ob->query("lingjiang"))
    {
        tell_object(me,"宴客厅此时正在使用，你还是去用别的地方宴客吧。\n");
        return 1;
    }
    else
    {
        ob->set("yanke",1);
        ob->set("yanke_ownername",me->query("name"));
        ob->set("yanke_owner",me->query("id"));
        ob->set("guestnumber",0);
        ob->set("yankestart",time());
        me->set(ob->query("place")+"宴客",time());
        if (!arg)
        {
            words="今日，"+me->query("name")+"在"+ob->query("place")+"宴客厅大摆宴席，欢迎各位朋友光临。\n";
        }
        else
        {
            words=arg+"，地点："+ob->query("place")+"宴客厅。主人："+me->query("name")+"\n";
        }
        if (me->query_temp(ob->query("yanke_no")+"/gemname"))
        {
            words+="【江湖】这次宴客抽奖的头奖是"+me->query_temp(ob->query("yanke_no")+"/gemname")+"总计三颗。";
        }
        if (me->query("pyh_obtain_high_gem"))
        {
            me->delete("pyh_obtain_high_gem");
            tell_object(me,"上次在鄱阳湖获得大宝石带来的霉运终于离开了你。\n");
        }
        ob->set("bonuslevel",me->query_temp(ob->query("yanke_no")+"/gemlevel"));
        ob->set("bonustype",me->query_temp(ob->query("yanke_no")+"/gemmaterial"));
		log=me->query("id")+"  于"+ctime(time())+"，宝石等级:"+chinese_number(ob->query("bonuslevel"))+"宝石种类:"+ob->query("bonustype")+"\n";
		log_file("user/yanke_log",log);
        me->delete_temp(ob->query("yanke_no"));
        ob->set("yankeslogan",words);
        CHANNEL_D->do_channel(this_object(), "jh", words, -1);
        call_out("gettime",10);
        return 1;
    }
}

int do_lingjiang()
{
    object gift;
    int bonus,index;
    object me=this_player();
    object ob=this_object();
    string gem=ob->query("bonustype");
    string moneygiven;
    if (ob->query("pending"))
    {
        tell_object(me,"领奖还没有开始，请稍候……\n");
        return 1;
    }
    if (!ob->query("lingjiang"))
    {
        tell_object(me,"领奖时间已经过了或者还没有开始领奖。这里的人都散去了。\n");
        return 1;
    }
    if (!me->query(ob->query("yanke_no")+"/getbonus"))
    {
        tell_object(me,"你的领奖券呢？\n");
        return 1;
    }
    if (!ob->query("guestnumber"))
    {
        tell_object(me,"现在并不是领奖时间。\n");
        return 1;
    }
    if ((int)me->query(ob->query("yanke_no")+"getbonus")>(int)ob->query("guestnumber"))
    {
        tell_object(me,"你参加的是上次宴会吧？\n");
        return 1;
    }
    if (time()-(int)me->query(ob->query("yanke_no")+"/getbonus_time")>3600*24)
    {
        tell_object(me,"你参加的是上次宴会吧？\n");
        return 1;
    }
    bonus=5000000/(int)ob->query("guestnumber");
    if (me->query(ob->query("yanke_no")+"/getbonus")==ob->query("prize1")||me->query(ob->query("yanke_no")+"/getbonus")==ob->query("prize2")||me->query(ob->query("yanke_no")+"/getbonus")==ob->query("prize3"))
    {
        gift=new("/obj/gem/gem");
        if (ob->query("bonuslevel")==8)
        {
            index=9995;
        }
        if (ob->query("bonuslevel")==7)
        {
            index=9990;
        }
        if (ob->query("bonuslevel")==6)
        {
            index=9970;
        }
        if (ob->query("bonuslevel")==5)
        {
            index=9930;
        }
        if (ob->query("bonuslevel")==4)
        {
            index=9810;
        }
        if (ob->query("bonuslevel")==3)
        {
            index=9400;
        }
        if (ob->query("bonuslevel")==2)
        {
            index=8000;
        }
        if (ob->query("bonuslevel")==1)
        {
            index=4000;
        }
        gift->set_level(index,index,gem);
        gift->move(me);
        tell_object(me,"作为大奖获得者，小厮递给你一个"+gift->query("name")+"。\n");
        CHANNEL_D->do_channel(this_object(), "jh", me->query("name")+"在本次宴会中获得了大奖"+ gift->query("name") +"一枚。", -1);
    }
    MONEY_D->pay_player(me,bonus);
    moneygiven=MONEY_D->money_str(bonus);
    tell_object(me,"本次宴会的所有参与者都得到了宴会主人的喜钱"+moneygiven+"。\n");
    me->delete(ob->query("yanke_no"));
    return 1;
}

int aftergetbonus()
{
    object ob=this_object();
    int i,*pool=({}),a1,a2,a3;
    if (!sizeof(ob->query("guest_list")))
    {
        ob->delete("pending");
        ob->set("lingjiang",1);
        
        ob->set("yankeover",time());
        call_out("yankeover",1);
        CHANNEL_D->do_channel(this_object(), "jh", "本次宴会大奖无人获得！", -1);
        CHANNEL_D->do_channel(this_object(), "jh", "除大奖外，所有参与人员均有奖励，请与半天以内到"+ob->query("place")+"宴客厅门厅领奖。", -1);
        return 1;
    }
    for (i=1;i<=ob->query("guestnumber");i++)
    {
        if (ob->query("guest_list/"+i))
        {
            pool+=({i});
        }
    }
    a1=pool[random(sizeof(pool))];
    pool-=({a1});
    if (!sizeof(pool))
    {
        ob->set("prize1",a1);
        ob->delete("pending");
        ob->set("lingjiang",1);
        
        ob->set("yankeover",time());
        call_out("yankeover",1);
        CHANNEL_D->do_channel(this_object(), "jh", "本次宴会大奖一名，获奖人是"+ob->query("guest_list/"+a1+"/name")+"("+ob->query("guest_list/"+a1+"/id")+")奖券号是"+a1+"！", -1);
        CHANNEL_D->do_channel(this_object(), "jh", "除大奖外，所有参与人员均有奖励，请与半天以内到"+ob->query("place")+"宴客厅门厅领奖。", -1);
        return 1;
    }
    a2=pool[random(sizeof(pool))];
    pool-=({a2});
    if (!sizeof(pool))
    {
        ob->set("prize1",a1);
        ob->set("prize2",a2);
        ob->delete("pending");
        ob->set("lingjiang",1);
        
        ob->set("yankeover",time());
        call_out("yankeover",1);
        CHANNEL_D->do_channel(this_object(), "jh", "本次宴会大奖一名，获奖人分别是是"+ob->query("guest_list/"+a1+"/name")+"("+ob->query("guest_list/"+a1+"/id")+")和"+ob->query("guest_list/"+a2+"/name")+"("+ob->query("guest_list/"+a2+"/id")+")！", -1);
        CHANNEL_D->do_channel(this_object(), "jh", "除大奖外，所有参与人员均有奖励，请与半天以内到"+ob->query("place")+"宴客厅门厅领奖。", -1);
        return 1;
    }
    a3=pool[random(sizeof(pool))];
    ob->set("prize1",a1);
    ob->set("prize2",a2);
    ob->set("prize3",a3);
    ob->delete("pending");
    ob->set("lingjiang",1);
    
    ob->set("yankeover",time());
    call_out("yankeover",1);
    CHANNEL_D->do_channel(this_object(), "jh", "本次宴会大奖三名，获奖号码分别是"+a1+"、"+a2+"、"+a3+"！", -1);
    CHANNEL_D->do_channel(this_object(), "jh", "除大奖外，所有参与人员均有奖励，请与半天以内到"+ob->query("place")+"宴客厅门厅领奖。", -1);
    return 1;
}

int getbonus()
{
    CHANNEL_D->do_channel(this_object(), "jh", "下面开始抽奖……", -1);
    call_out("aftergetbonus",10);
    return 1;
}

int yankeover()
{
    object ob=this_object();
    if (time()-(int)ob->query("yankeover")>60*60*12) //领奖时长
    {
        ob->delete("lingjiang");
        ob->delete("yanke");
		ob->delete("ip_list");
		ob->delete("guest_list");
        return 1;
    }
    else
    {
        CHANNEL_D->do_channel(this_object(), "jh", "请参与宴会的朋友抓紧时间到"+ob->query("place")+"宴客厅门厅领奖(lingjiang)。", -1);
        call_out("yankeover",900);
        return 1;
    }
}

int gettime()
{
    object ob=this_object();
    if (time()-(int)ob->query("yankestart")>60*60*12) //宴会时长
    {
        CHANNEL_D->do_channel(this_object(), "jh", ob->query("place")+"宴会厅的狂欢经过半天后，落下了帷幕。", -1);
        CHANNEL_D->do_channel(this_object(), "jh", "今日共有"+chinese_number(ob->query("guestnumber"))+"位嘉宾出席。", -1);
        CHANNEL_D->do_channel(this_object(), "jh", "让我们对本次宴会的主人"+ob->query("yanke_ownername")+"("+ob->query("yanke_owner")+")表示感谢之情。", -1);
        ob->delete("yanke");
		ob->set("pending",1);
        call_out("getbonus",600); //开奖延后时间
        return 1;
    }
    else
    {
        CHANNEL_D->do_channel(this_object(), "jh", this_object()->query("yankeslogan"), -1);
        call_out("gettime",900);
        return 1;
    }
}


int valid_leave(object me,string dir)
{  
    object ob=this_object();
    object mupai;
    string pl_ip,*ips=({});
    int i;
    if (userp(me))
    {
        pl_ip=query_ip_number(me);
    }
    if (ob->query("ip_list"))
    {
        ips=ob->query("ip_list");
    }
	if (dir==ob->query("pathway"))
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        else if ( !this_object()->query("yanke") )
        {
            return notify_fail("此时宴客厅并无宴会，大门紧闭着。\n");
        }
        else if (member_array(pl_ip,ips)!=-1)
        {
            return notify_fail("别老来浑水摸鱼了。\n");
        }
        else if (time()-(int)me->query(ob->query("save_me"))>3600*24)
        {
            mupai=new(__DIR__"obj/mupai");
            mupai->move(me);
            me->set(ob->query("save_me"),time());
            ips+=({pl_ip});
            ob->set("ip_list",ips);
            ob->add("guestnumber",1);
            ob->set("guest_list/"+ob->query("guestnumber")+"/id",me->query("id"));
            ob->set("guest_list/"+ob->query("guestnumber")+"/name",me->query("name"));
            ob->set("guest_list/"+ob->query("guestnumber")+"/ip",pl_ip);
            me->set(ob->query("yanke_no")+"/getbonus_time",time());
            me->set(ob->query("yanke_no")+"/getbonus",ob->query("guestnumber"));
            tell_object(me,"一个小厮忙不迭递上一张奖券给你。上面写着："+BLINK+HIR+chinese_number(ob->query("guestnumber"))+NOR"，一天后可以凭此号兑奖。\n");
            tell_object(me,"小厮递给你一块木牌，可以作为兑奖的凭证。\n");
        }
        else
        {
            return notify_fail("你刚刚才参加过宴会。\n");
        }
    }
	return ::valid_leave(me, dir);
}

