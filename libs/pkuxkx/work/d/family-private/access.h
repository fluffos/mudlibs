void init()
{
    add_action("do_list","list");
    add_action("do_juanxian","juanxian");
    add_action("do_leave","leave");
}

object get_exit(object here)
{
    string family = here->query("family");
    string exit;
    object ob;
    switch(family)
	{
		case "少林派": exit = "/d/shaolin/dmyuan"; break;
		case "大轮寺": exit = "/d/dalunsi/fatang2"; break;
		case "武当派": exit = "/d/wudang/fuzhen4"; break;
		case "丐帮": exit = "/d/city/gbxiaowu"; break;
		case "桃花岛": exit = "/d/taohuadao/shijianfeng"; break;
		case "星宿派": exit = "/d/xingxiu/tianxiugong"; break;	
		case "峨嵋派": exit = "/d/emei/jxan"; break;
		case "白驼山": exit = "/d/baituo/dating"; break;
		case "华山派": exit = "/d/huashan/shufang"; break;
		case "明教": exit = "/d/mingjiao/dadian"; break;
		case "日月神教": exit = "/d/riyuejiao/wanghaishi"; break;
		case "古墓派": exit = "/d/gumu/ceshi"; break;
		case "灵鹫宫": exit = "/d/lingjiu/mishi"; break;
		case "全真派": exit = "/d/quanzhen/jingsy"; break;
		case "天龙寺": exit = "/d/tianlong/muwu"; break;
		case "姑苏慕容": exit = "/d/murong/yshufang"; break;
		case "天地会": exit = "/d/luoyang/qingmutang"; break;
		case "神龙教": exit = "/d/shenlongdao/qianlongtang"; break;
		case "雪山派": exit = "/d/lingxiao/jingxiushi"; break;
		case "大理段家": exit = "/d/family-private/shaolin/shimen"; break;
	    case "红花会": exit = "/d/family-private/shaolin/shimen"; break;
	}
    if (load_object(exit))
    {
        ob=load_object(exit);
    }
    return ob;
}

int do_leave()
{
    object me=this_player();
    object here=this_object();
    object exit=get_exit(here);
    if (exit->isroom())
    {
        tell_room(exit,me->name()+"不知从哪里走了出来。\n");
        message_vision("$N向"+exit->query("short")+"方向离开。\n",me);
        me->move(exit);
    }
    else
    {
        tell_object(me,"出口出错。\n");
    }
    return 1;
}

int get_average_user()
{
    object *users,ob=this_object();
    string family=ob->query("family");
    int sta_times=ob->query("average_user/sta_times");
    int overall_users=ob->query("average_user/overall_users");
    int this_time_users=0,family_players,i;
    users = filter_array(children(USER_OB), (: userp :));
	users = filter_array(users, (: environment :));
    for (i=0;i<sizeof(users);i++)
    {
        if (users[i]->query("family/family_name") == family)
        {
            this_time_users+=1;
        }
    }
    ob->restore();
    sta_times+=1;
    overall_users=overall_users+this_time_users;
    family_players=overall_users/sta_times;
    ob->set("average_user/sta_times",sta_times);
    ob->set("average_user/overall_users",overall_users);
    ob->set("average_user/family_players",family_players);
    ob->save();
    remove_call_out("get_average_user");
    call_out("get_average_user",3600,ob);
    return family_players;
}

int rebuild()
{
    object ob=this_object();
    string family=ob->query("family");
    ob->restore();
    delete("realmap");
    set("short", "石门");
	set("long",  "这里是一座废弃的石门，机关被破坏，无法下到底处，门上有一行淡淡的小字(zi)。\n");
	set("accessed_long", "这是一座石门，已经被"+query("family")+"弟子修复，向下通往"+query("family")+"闭关的密室，门上有一行淡淡的小字(zi)。\n");
    set("exits", ([
              "down" : __DIR__"biguanchu",
        ]));
    set("item_desc", ([
        "zi" : "可以捐献(juanxian)钱财给师门，也可以查看(list)别人的贡献度。闭关结束可以离开(leave)这里。\n"+HIR+"(注：一次捐献一千金以上可增加门派贡献度)\n"+NOR,
	]));
    set("no_task", 1);
    if (ob->query("access"))
    {
        ob->set("long",ob->query("accessed_long"));
    }
    return 1;
}

int do_juanxian(string arg)
{
    object ob=this_object();
    string family=ob->query("family");
    object me=this_player();
    int gain,i,index,amount,limit,exp,requirement,flag=0;
    if( !arg || !sscanf(arg, "%d", amount))
    {
        tell_object(me,"你要捐献多少金给"+family+"？\n");
        return 1;
    }
    if (me->query("family/family_name")!=family)
    {
        tell_object(me,"你不是"+family+"弟子，还是请回吧。\n");
        return 1;
    }
    exp=(int)me->query("combat_exp");
    if (exp>=80000000) limit=2000000000;
        else limit=exp*25;
	if(limit > 2000000000 || limit < 0)
		limit = 2000000000;
	if(limit < 500000)
		limit = 500000;
    limit=limit/30000;//每人允许捐赠额不超过存款上限1/3
    if (amount+ob->query("donate/"+me->query("id")+"/amount")>limit)
    {
        tell_object(me,"你当次或累计捐款额已经超过允许的限度了！\n");
        return 1;
    }
    if (amount<=0)
    {
        tell_object(me,"你在实验什么bug呢？别异想天开了！\n");
        return 1;
    }
    if (amount*10000>(int)me->query("balance")/2)
    {
        tell_object(me,family+"虽然很期望门下弟子为本门多做贡献，可也不希望门下弟子做出超出自己能力范围的事情，捐款额度都超过你全部存款一半了！\n");
        return 1;
    }
    ob->restore();
    requirement=ob->get_average_user();
    requirement=requirement*4000;
    if (requirement<50000)
    {
        requirement=50000;
    }
    
    me->add("balance",-amount*10000);
    tell_object(me,"你捐赠了"+chinese_number(amount)+"金给"+family+"。\n");
    if (amount>1000)
    {
        gain=amount/500;
        me->add("family_donate_degree",gain);
        tell_object(me,"与此同时，你获得了"+chinese_number(gain)+"点门派贡献度。\n");
    }
    if (ob->query("access"))
    {
        ob->add("family_surplus",amount*6000);
        tell_object(me,family+"累积获得了"+MONEY_D->money_str(ob->query("family_surplus"))+"盈余。\n");
    }
    ob->add("donate/"+me->query("id")+"/amount",amount);
    for (i=0;i<sizeof(ob->query("donate_index"));i++)
    {
        if (ob->query("donate_index/"+i)==me->query("id"))
        {
            index=i;
            flag=1;
        }
    }
    if (flag==0)
    {
        index=sizeof(ob->query("donate_index"));
        ob->set("donate_index/"+index,me->query("id"));
    }
    ob->add("donate_overall",amount);
    message( "channel:" + "baowei",HIG + "【"+family+"】" + me->query("name")+HIG+"捐赠了"+chinese_number(amount)+"金给"+family+"。\n"NOR,users());
    if ((int)ob->query("donate_overall")>requirement&&!ob->query("access"))
    {
        ob->set("access",1);
        message( "channel:" + "baowei",HIG + "【"+family+"】在众弟子齐心协力之下，打开了本派前辈留下的闭关密室。\n"NOR,users());
    }
    ob->save();
    return 1;
}

int do_list()
{
    object ob=this_object();
    string family=ob->query("family");
    object me=this_player();
    int i;
    string id,msg;
    
    if (me->query("family/family_name")!=family)
    {
        tell_object(me,"你不是"+family+"弟子，不要乱翻人家的东西。\n");
        return 1;
    }
    ob->restore();
    if (!sizeof(ob->query("donate")))
    {
        msg=family+"暂无任何人捐赠的款项。\n";
    }
    msg=family+"被捐赠款项明细如下：\n";
    for (i=0;i<sizeof(ob->query("donate_index"));i++)
    {
        id=ob->query("donate_index/"+i);
        msg+=HIW+id+NOR+" 共捐赠"+chinese_number((int)ob->query("donate/"+id+"/amount"))+"两金。\n";
    }
    msg+=HIW+"总计"+family+"门下弟子共捐赠"+chinese_number(ob->query("donate_overall"))+"两金。\n"+NOR;
    if (!ob->query("access"))
    {
        i=ob->get_average_user();
        i=i*4000;
        i=i-(int)ob->query("donate_overall");
        if (i>0)
        {
            msg+="尚需"+chinese_number(i)+"两金，可重新打开连接闭关区域的"+ob->query("short")+"。\n";
        }
    }
    
    tell_object(me,msg);
    return 1;
}

int valid_leave(object me,string dir)
{
    object ob=this_object();
    if (dir=="down"&&!wizardp(me)&&me->query("family/family_name")!=ob->query("family"))
    {
        return notify_fail("你不是"+ob->query("family")+"弟子，不许乱闯禁地！\n");
    }
    
    if (dir=="down"&&!wizardp(me)&&!ob->query("access"))
    {
        return notify_fail("往下走的路已经废弃了，需要全派弟子共同努力捐献(juanxian)才能修好它。\n");
    }
    if (dir=="down"&&time()-(int)me->query("family_private_area_last_entry_time")<60*60*12)
    {
        return notify_fail("闭关区域不是菜市场，为了不打扰同门清修，每12小时允许进出一次。\n");
    }
    me->set("family_private_area_last_entry_time",time());
    return ::valid_leave(me,dir);
}