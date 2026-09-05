//  Room:  /d/wizard/judge_room.c
//  Modify: Mark 

#include  <ansi.h>
inherit  ROOM;

//could not chat, rumor here :)
//and  can't  quit  here...hehe:)
int  do_chat();
int  do_rumor();
int  do_quit();
int check_robot_shout(string msg);

int check_robot();
int sent_out_user(string id);

void  create()
{
	set("short",  "全自动机器人检查室");
	set("long",  @LONG

这里是人工方式检查机器人的地方，你一定是被人检举或是行为太像机器人，才
会来到这里。检查者将在十五分钟内提问三次以上，如果三个问题都不能正确回
答，将被认定为机器人。

被人工认定为机器人后，巫师将在论坛公告版进行一天的公示。公示期间，
玩家可以在意见投诉版进行申述。申述由巫师大殿受理。申述成功者，不
添加机器人标记。申述失败者，增加一次机器人标志。

对于在主流任务中使用全自动机器人的，巫师将予以严惩。
    a) 第一次发现的，所有任务奖励和掉宝降低50%，直到exp增长1M
    b) 第二次发现的，所有任务奖励和掉宝降低90%，直到exp增长1M
    c) 第三次发现的，所有任务奖励和掉宝降低95%，直到exp增长5M
    d) 第四次发现的，所有任务奖励和掉宝降低99%，直到exp增长50M
    e) 超过四次者，永久禁止该账号登陆。
若有重大贡献，如报告bug等，以上记录可以由巫师酌情消除。
顺利通过人工机器人测试者，在接下来的一小时内，所有任务奖励和掉
宝增加20%。


LONG
	);
	set("no_remote_message",  1);
    set("no_clean_up",1);
    set("no_reset",1);
    call_out("check_robot",60);
	setup();
}

void  init()
{
	add_action("do_any",  "");
    if(wizardp(this_player())) 
    {
        add_action("add_question","add");
        add_action("list_question","list");
        add_action("del_question","del");
        add_action("set_plan","plan");
        add_action("list_plan","listplan");
        add_action("del_plan","delplan");
    }
}

int del_plan(string arg)
{
    mixed* check_list;
    int i;

    if(sscanf(arg,"%d",i) != 1)
    {
        write("请输入序号。\n");
        return 1;
    }

    if(!query("check_list") || !arrayp(query("check_list")) || sizeof(query("check_list")) == 0)
    {
        write("无计划。\n");
        return 1;
    }
    check_list = query("check_list");

    if(i < 1 || i > sizeof(check_list))
    {
        write("没有这个计划。\n");
        return 1;
    }
    check_list -= ({check_list[i-1]});

    set("check_list",check_list);

    write("删除成功。\n");
    return 1;
}

int list_plan()
{
    mixed* check_list;
    int i;
    write("机器人检查计划:\n");
    if(!query("check_list") || !arrayp(query("check_list")) || sizeof(query("check_list")) == 0)
    {
        write("无。\n");
        return 1;
    }
    check_list = query("check_list");
    for(i=0;i<sizeof(check_list);i++)
    {
        printf("%d:%s at %s\n",i+1,check_list[i][0],ctime(check_list[i][1]));
    }
    return 1;
}

int set_plan(string arg)
{
    string id;
    int h,m,s;
    int schedule_time;
    mixed* check_list;
    if(!arg || sscanf(arg,"%s %d:%d:%d",id,h,m,s) != 4)
    {
        write("plan id hh:mm:ss. it means do check after specified time\n");
        return 1;
    }
    schedule_time = time() + h*3600+m*60+s;
    if(file_size("/data/login/"+id[0..0]+"/"+id+".o") == -1)
    {
        write("没有这个玩家。\n");
        return 1;
    }
    if(!query("check_list") || !arrayp(query("check_list")))
    {
        check_list = ({});
    }
    else
    {
        check_list = query("check_list");
    }
    check_list += ({ ({id,schedule_time}) });
    set("check_list",check_list);
    write("计划添加成功！listplan查看。\n");
    return 1;
}
int add_question(string arg)
{
    string* questions = query("questions");
    if(!arrayp(questions))
    {
        questions = ({});
    }
    questions += ({arg});
    set("questions",questions);
    write("添加问题成功。\n");
    return 1;
}

int list_question()
{
    int i;
    string* questions = query("questions");
    if(!arrayp(questions))
    {
        questions = ({});
    }
    write("现在机器人抽查题库有如下题目。\n");
    for(i=0;i<sizeof(questions);i++)
    {
        printf("%d:%s\n",i+1,questions[i]);
    }
    return 1;
}

int del_question(string arg)
{
    int i,index;
    string* questions = query("questions");
    if(!arrayp(questions))
    {
        questions = ({});
    }
    if(!arg || sscanf(arg,"%d",index) != 1)
    {
        write("del 序号\n");
        return 1;
    }
    if(index < 1 || index > sizeof(questions))
    {
        write("没有这个问题。\n");
        return 1;
    }
    questions -= ({questions[index-1]});
    set("questions",questions);
    write("删除问题成功。\n");
    return 1;
}


int do_any(string arg)
{
    int i;
    object* obs;
    int show_items = 0;
    string cmd = query_verb();
    if(cmd != "say" && cmd !="look" && cmd != "l" && cmd != "done" && !wizardp(this_player())) 
    {
        message("sound", "你正处于全自动机器人检测阶段，请暂时停下其他活动，使用say命令和巫师交流。回答图灵测试问题。\n",  this_player());
        return 1;
    }
    if(cmd == "look" && !wizardp(this_player()))
    {
        message("sound", query("long"),  this_player());
        message("sound", query("long"),  this_player());
        obs = all_inventory();

        for(i=0;i<sizeof(obs);i++)
        {
            if(wizardp(obs[i]))
            {
                if(!show_items)
                {
                    message("sound", "你的面前站着：\n",  this_player());
                    show_items = 1;
                }        
                message("sound", SECURITY_D->get_status(obs[i])+" "+obs[i]->name()+"\n",  this_player());
            }
        }
        return 1;
    }

    if(cmd == "say")
    {
        if(time()-this_player()->query_temp("antirobot/last_say_time") < 5)
        {
            message("sound","你回答的太快了，思考一下再说。\n",this_player());
            return 1;
        }
        message("sound",this_player()->query("id")+"在"+ctime(time())+"说道："+arg+"\n",all_inventory());
        log_file("antirobot/check",this_player()->query("id")+"在"+ctime(time())+"说道："+arg+"\n");
        this_player()->set_temp("antirobot/last_say_time",time());
    }

    if(cmd == "done")
    {
        log_file("antirobot/check",this_player()->query("id")+"主动选择结束答题。在"+ctime(time())+"\n");
        sent_out_user(this_player()->query("id"));
        return 1;
    }
	return  0;
}

int suspect_robot(string id)
{
    object pl;
    if(!objectp(pl=find_player(id))) return 0;
    //主要的检查依据是看最近15分钟的exp,balance增长。如果15分钟增长超过2000，不是打坐学习朱熹等机器人。
    if(REWARD_D->get_stat_rate("exp",id)/4 > 2000 || REWARD_D->get_stat_rate("balance",id)/4 > 200000)
    {
        return 1;
    }
    return 0;
}
int start_check(string id)
{
    object pl;
    
    if(!objectp(pl=find_player(id))) return 1;

    log_file("antirobot/check","开始对玩家"+id+"进行机器人图灵测试。以下为1分钟内该玩家的消息记录。作为判断是否正在进行主流任务的辅助依据。\n");
    log_file("antirobot/check","玩家"+id+"在最近15分钟内的经验增加了"+REWARD_D->get_stat_rate("exp",id)/4+",金钱增加了"+REWARD_D->get_stat_rate("balance",id)/4+"。\n");
    pl->set_temp("antirobot/snooper",this_object());
    
    call_out("start_check_step2",60,id);

    return 1;
}

int start_check_step2(string id)
{
    int i,index=0,size;
    object pl;
    string* questions = query("questions");
    
    if(!objectp(pl=find_player(id))) return 1;

    if(environment(pl))
    {
        pl->set_temp("antirobot/summon_from_place",base_name(environment(pl)));
    }
    pl->delete_temp("antirobot/snooper");   

    pl->move(this_object());

    check_robot_shout("北侠反全自动主流任务机器人图灵测试开始。\n");
    check_robot_shout("本次选择的玩家是:"+id+"\n");
    check_robot_shout("现在时间是"+ctime(time())+"\n");
    check_robot_shout("他最近15分钟的平均经验增长是："+REWARD_D->get_stat_rate("exp",id)/4+"\n");
    
    
    size = sizeof(questions);
    for(i=size-1;i>size-3-1;i--)
    {
        check_robot_shout(sprintf(HIW"问题%s:%s\n"NOR,chinese_number(++index),questions[i]));
        questions -= ({questions[i]});
    }
    set("questions",questions);
    check_robot_shout("请"+id+"在十五分钟内回答。结果24小时内公布。\n");
    message("sound", HIY"若是回答完毕，可以输入done离开这里。"NOR, pl);
    call_out("sent_out_user",900,id);
    return 1;
}

int check_robot()
{
    mixed* check_list;
    int i;
    int schedule;
    string* questions = query("questions");

    remove_call_out("check_robot");
    call_out("check_robot",60);
    
    
    if(!query("check_list") || !arrayp(query("check_list")) || sizeof(query("check_list")) == 0)
    {   
        return 1;
    }
    if(!arrayp(questions) || sizeof(questions) < 3) return 1;

    check_list = query("check_list");
    for(i=0;i<sizeof(check_list);i++)
    {
        schedule = check_list[i][1];
        if((schedule - time() > 0 && (schedule - time()) < 120) || (schedule - time() < 0 && (schedule - time()) > -120))
        {
            if(suspect_robot(check_list[i][0]))
            {         
                start_check(check_list[i][0]);
                check_list[i][0] = "";
            }
            else
            {
                //推迟一个随机的时间
                check_list[i][1] = schedule+60+random(1800);
            }
        }
    }
    //remove the checked item
    for(i=sizeof(check_list)-1;i>=0;i--)
    {
        if(sizeof(check_list[i][0]) == 0)
        {
            check_list -= ({check_list[i]});
        }
    }

    set("check_list",check_list);

    return 1;    
}

int sent_out_user(string id)
{
    object pl;
    if(!userp(pl=find_player(id))) return 0;
    if(environment(pl) != this_object()) return 0;//已经提前结束测试了。玩家已经离开。
    if(stringp(pl->query_temp("antirobot/summon_from_place")))
    {
        pl->move(load_object(pl->query_temp("antirobot/summon_from_place")));
        pl->delete_temp("antirobot/summon_from_place");
    }
    check_robot_shout(ctime(time())+id+"的机器人图灵测试已经结束。谢谢。结果将在24h内公布。\n");
    return 1;
}

int check_robot_shout(string msg)
{
    int i;
    object* inv;
    shout(msg);
    inv = all_inventory();
    for(i=0;i<sizeof(inv);i++)
    {
        if(userp(inv[i]))
        {
            message("sound", msg, inv[i]);
        }
    }
    log_file("antirobot/check",msg);
    return 1;
}

int receive_snoop(object snoopee,string msg)
{
    if(!objectp(snoopee)) return 1;
    log_file("antirobot/check",sprintf("%s,%s,%s\n",ctime(time()),snoopee->query("id"),msg));
    return 1;
}
