//自动赌博机
//玩家开始赌博后，如果赢了，就从最低金额开始
//如果输了，就加倍，直到玩家退出或者钱庄没钱

//赌博机，搞笑的，不要随便开放。
//query("bet/gain2")可以知道玩家输赢情况，玩玩了可以手动恢复。
inherit ITEM;
#include <ansi.h>

int do_bet();
int do_fail();
int call_back();

object* bet_users = ({});
//最少金额
//1 gold
int minmoney = 10000;
int maxmoney = 10240000;
void create()
{
    set_name("乐翻天",({"shusini"}));
    set("long","输入bet开始赌博后，如果赢了，就自动从最低金额开始。
如果输了，就自动加倍，直到退出或者钱庄没钱。\n也可以用fail命令退出赌博。\n注意一切都是自动的。最低金额是1两金子，最高金额是1024两金子。\n");
    set("no_get",1);
    set("unit","台");
    set("value",1);
    setup();    
    remove_call_out("call_back");
    call_out("call_back",1);
}

void init()
{
    add_action("do_bet","bet");    
    add_action("do_yes","yes");    
    add_action("do_fail","fail");    
    if(wizardp(this_player()))
    {
        add_action("do_check","check");
    }
    
}

int do_yes()
{
   object me = this_player();
   if(member_array(me,bet_users) != -1)
   {
       return notify_fail("你已经开始赌了。要退出就quit或者输入fail\n");
   }        
            
    if(me->query_temp("bet/prepare") != 1)
    {
        write("请先输入bet\n");
    }
    else
    {
        if(me->query("balance") + me->query("bet/all_money") < 16*minmoney)
        {
            return notify_fail("这么点钱不够\n");
        }
   
           
        write("好啊，开始了。你的存款被冻结了。\n");
        
        write("要想退出，可以直接quit，或者来这里输入fail\n");
        write("这期间你可以自由活动，不用呆在这里。\n");
        
        me->set_temp("bet/next_bid",minmoney); 
        me->set_temp("bet/this_gain",0);
        //考虑如果玩家上次是quit的，那么all_money里的钱还是他的。
        me->add("bet/all_money",me->query("balance"));
        me->set("balance",0);  
        
        bet_users += ({me});        
    }
    return 1;
}

int do_fail()
{
    object me = this_player();
    if(member_array(me,bet_users) == -1)
    {
        return notify_fail("你并没有赌啊。\n");
    }    
    write("好吧，你退出了。\n");
    tell_object(me,sprintf("你累计一共赚了%d黄金。这次你赚了%d黄金。\n",me->query("bet/gain2")/10000,me->query_temp("bet/this_gain")/10000));        
    tell_object(me,sprintf("你的银行资金解冻了。\n"));
    me->delete_temp("bet");
    me->set("balance",me->query("bet/all_money"));
    me->set("bet/all_money",0);    
    
    bet_users -= ({me});
    return 1;
}

int do_bet()
{
    object me = this_player();
    if(member_array(me,bet_users) != -1)
    {
        return notify_fail("你已经开始赌了。要退出就quit或者输入fail\n");
    }
    
    //先警告
    write(HIR""BNK"警告！！！十赌九输，本赌博机风险巨大，既有暴富的机会，也有倾家荡产的可能。\n请仔细看规则：\n"NOR);
    write(sprintf(HIR"初始赌注是%d两黄金，如果输了，就自动加倍下注。如果赢了，自动从%d两黄金重新开始。\n"NOR,minmoney/10000,minmoney/10000));
    write(sprintf(HIW"输赢的规则很简单，丢一个筛子，1,2,3点你输，4,5,6 点你赢，如果筛子立起来，也是你输。\n也就是说，你赢的概率接近1/2，少一丁点。\n"NOR));
    write(HIR"一旦开始，银行存款将被冻结，除非你退出游戏或者来这里输入fail指令。否则赌博机会自动从你的银行存款中支钱。结束的条件只有一个：\n"NOR);
    write(sprintf(HIR"你的存款不足以支付下一次的赌注,或者赌注达到上限%d两黄金。\n"NOR,maxmoney/10000));
    write(HIY"输入yes表示已经阅读并理解以上说明，正式开始赌博。\n"NOR);
    me->set_temp("bet/prepare",1);
    return 1;
     
}

int filter_users(object user)
{
    if(!objectp(user) || !userp(user) || user->query_temp("bet/next_bid") == 0)
    {
        return 0;
    }
    if(user->query("bet/all_money") < user->query_temp("bet/next_bid"))
    {
        return 0;
    }
    return 1;
}

int betforuser(object user)
{
    //庄家有更大几率赢
    int i = random(20);
    if(i<9)//赢了
    {
        tell_object(user,sprintf("你赢了%d两黄金\n",user->query_temp("bet/next_bid")/10000));
        user->add("bet/all_money",user->query_temp("bet/next_bid"));
        user->add("bet/gain2",user->query_temp("bet/next_bid"));
        user->add_temp("bet/this_gain",user->query_temp("bet/next_bid"));        
        user->set_temp("bet/next_bid",minmoney);
    }
    else//输了
    {
        tell_object(user,sprintf("你输了%d两黄金\n",user->query_temp("bet/next_bid")/10000));
        user->add("bet/all_money",-user->query_temp("bet/next_bid"));
        user->add("bet/gain2",-user->query_temp("bet/next_bid"));      
        user->add_temp("bet/this_gain",-user->query_temp("bet/next_bid"));
        
        if(user->query("bet/all_money") >=   user->query_temp("bet/next_bid")*2)
        {
			if(user->query_temp("bet/next_bid")*2 > maxmoney)
			{
				tell_object(user,sprintf("赌注已经超过上限：%d黄金。\n",maxmoney/10000));				
				tell_object(user,sprintf("你累计一共赚了%d黄金。这次你赚了%d黄金。\n",user->query("bet/gain2")/10000,user->query_temp("bet/this_gain")/10000));
				tell_object(user,sprintf("你的银行资金解冻了。\n"));
				user->delete_temp("bet");
				user->set("balance",user->query("bet/all_money"));
				user->set("bet/all_money",0);           
			}
			else
			{
				tell_object(user,sprintf("你将赌注增加一倍到:%d两黄金\n",user->query_temp("bet/next_bid")*2/10000));
				user->set_temp("bet/next_bid", user->query_temp("bet/next_bid") * 2);
			}
        }
        else
        {
            tell_object(user,sprintf("你已经没钱了。你累计一共赚了%d黄金。这次你赚了%d黄金。\n",user->query("bet/gain2")/10000,user->query_temp("bet/this_gain")/10000));
            tell_object(user,sprintf("你的银行资金解冻了。\n"));
            user->delete_temp("bet");
            user->set("balance",user->query("bet/all_money"));
            user->set("bet/all_money",0);           
        }
    }
    return 1;
}
int call_back()
{
 
    bet_users = filter_array(bet_users,"filter_users"); 
        
    for(int i=0;i<sizeof(bet_users);i++)
    {    
        betforuser(bet_users[i]);                
    }
    
    remove_call_out("call_back");
    call_out("call_back",1);   
    return 1;
}

int do_check()
{
    object* alluser = users();
    write("当前正在赌博的玩家有：\n");
    bet_users = filter_array(bet_users,"filter_users"); 
    for(int i=0;i<sizeof(bet_users);i++)
    {
        write(sprintf(bet_users[i]->query("name")));
        write(sprintf(" 他目前盈利:%d两黄金\n",bet_users[i]->query_temp("bet/this_gain")/10000));
    }
    
    write("在线玩家中参与过赌博的情况：\n");
    for(int i=0;i<sizeof(alluser);i++)
    {
        if(alluser[i]->query("bet/gain2") != 0)
        {
            write(sprintf("%s:累计盈利%d两黄金\n",alluser[i]->query("name"),alluser[i]->query("bet/gain2")/10000));
        }
    }    
    return 1;
}