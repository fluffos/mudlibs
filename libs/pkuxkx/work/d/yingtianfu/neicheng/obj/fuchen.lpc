//官印
//create by zine 29/3/2011
#include <ansi.h>

#define HEADER HIY"┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR
#define TAIL   HIY"┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR 
#define LINE   HIY"┃━━━━━━━━━━━━━━━━━━━━━━━━━┃\n"NOR
inherit ITEM;
inherit F_MORE;
void create()
{	
	set_name(WHT"拂尘"NOR, ({ "fu chen","fuchen"}));
	set_weight(50);
	set("long", "这是一把宫里公公喜欢用的拂尘。\n");
	set("material", "wood");
	set("unit", "把");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("is_fuchen",1);
    set("no_store",1);
	setup();
}

int query_autoload() { return 1; }

void init()
{
    object ob=this_object();
    object belong=environment(ob);
    
    set("long","这是一把内廷官员喜欢随身携带的拂尘，侧面刻着"+belong->query("name")+"。\n");
    add_action("do_fu","fu"); 
    add_action("do_players","players");
    add_action("do_daming","daming");//聊天通道
    add_action("do_query","query");
    if (!userp(belong))
    {
        destruct(ob);
        return;
    }
    if (!belong->query("ming/tj/pin"))
    {
        destruct(ob);
        return;
    }
    if (belong->query("gender")!="无性")
    {
        destruct(ob);
        return;
    }
}

int do_query()
{
    object me=this_player();
    string msg,info;
    int mins;
    msg="\n\n";
    msg+=HEADER;
    info=HIY"              ★★★"+HIM+"大 明 内 廷"+HIY+"★★★\n"NOR;
    msg+=info;
    msg+=LINE;
    if (me->query("ming/tj/pin"))
    {
        info="  【官爵】你是大明内廷"+chinese_number(me->query("ming/tj/pin"))+"品官员 "+me->query("ming/title")+"\n";
        msg+=info;
    }
    if (!me->query("mingtj/pin"))
    {
        info="  【官爵】无。\n";
        msg+=info;
    }
    if (me->query("ming/taskstime"))
    {
        mins=((int)me->query("mud_age")-(int)me->query("ming/taskstime"))/60;
        if (mins<1)
        {
            mins=1;
        }
        info="  【庶务】你上次做内廷任务是在"+chinese_number(mins)+"分钟之前。\n";
        msg+=info;
    }
    if (!me->query("ming/taskstime"))
    {
        info="  【庶务】无任务记录。\n";
        msg+=info;
    }
    if (me->query("ming/salary"))
    {
        mins=((int)me->query("mud_age")-(int)me->query("ming/salary"))/60;
        if (mins<1)
        {
            mins=1;
        }
        info="  【俸薪】你上次领取俸薪是在"+chinese_number(mins)+"分钟之前。\n";
        msg+=info;
    }
    if (!me->query("ming/salary"))
    {
        info="  【俸薪】无俸薪领取记录。\n";
        msg+=info;
    }
    /*if (me->query("ming/exam"))
    {
        info="  【岁考】无上次岁考记录。\n";
        msg+=info;
    }
    if (!me->query("ming/exam"))
    {
        info="  【岁考】无上次岁考记录。\n";
        msg+=info;
    }*/
    if (me->query("ming/special"))
    {
        if (me->query("ming/special")=="fengshui")
        {
            info="  【特技】风水。天机难测，万象始生。\n";
        }
        if (me->query("ming/special")=="tanlan")
        {
            info="  【特技】贪婪。贪狼一出，天下尽墨。\n";
        }
        if (me->query("ming/special")=="wenqu")
        {
            info="  【特技】文曲。文曲下凡，国泰民安。\n";
        }
        if (me->query("ming/special")=="tuji")
        {
            info="  【特技】突击。其势如火，疾不可阻。\n";
        }
        if (me->query("ming/special")=="qunzhan")
        {
            info="  【特技】群战。百战不屈，骄阳似我。\n";
        }
        if (me->query("ming/special")=="guwu")
        {
            info="  【特技】鼓舞。借势助力，顺乎天意。\n";
        }
        msg+=info;
    }
    if (!me->query("ming/special"))
    {
        info="  【特技】无。\n";
        msg+=info;
    }
    msg+=LINE;
    info="                   "+me->query("name")+"\n";
    msg+=info;
    msg+=TAIL;
    tell_object(me,msg);
    return 1;
}

int refreshmingchat(object me)
{
    me->delete_temp("ming/stopchatting");
    return 1;
}

int do_players()
{
        object me=this_player();
        string str, name, str1, *option;
        object *ob, *list;
        int i, j, ppl_cnt, wiz_cnt, total_cnt, idle, all_menpai;
        int *tmp, *tmp2;

        if(!wizardp(me) && time()-me->query_temp("scan_time") < 5)
                return notify_fail("等等，系统喘气中......\n");
        me->set_temp("scan_time",time());
        str = "「" +HIW+ "大明在线官员列表" + NOR + "」\n";
        str += "———————————————————————————————————\n";

        ob = filter_array(children(USER_OB), (: userp :));
        ob = filter_array(ob, (: environment :));
        ob = filter_array(ob, (: $1->query("mingpin")||$1->query("ming/tj/pin") :) );
        list = sort_array(ob,"sort_user");
                j = sizeof(list);
                while( j-- ) 
                {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        if( !me->visible(list[j]) ) continue;
                        if (list[j]->query("noDeadNetnoIdle") != "Pkuxkx" && list[j]->query_temp("netdead")) continue;
                        if( wizardp(list[j]) )
                                wiz_cnt++;
                        else
                                ppl_cnt++;
                        
                        str = sprintf("%s%12s%s",
                                str,
                               // RANK_D->query_rank(list[j]),
                                list[j]->query("title"),
                                list[j]->query("name"),

                        );
                        str+="\n";
                }
       
    

        str += "———————————————————————————————————\n";
        
        start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        if( wizardp(ob1) && !wizardp(ob2) )
                return -1;
        
        if( wizardp(ob2) && !wizardp(ob1) )
                return 1;

        if( wizardp(ob1) && wizardp(ob2) )
                return (int)SECURITY_D->get_wiz_level(ob2) 
                        - (int)SECURITY_D->get_wiz_level(ob1);

        if( ob1->query("id") && !ob2->query("id") )
                return -1;
        if( ob2->query("id") && !ob1->query("id") )
                return 1;
        if( ob1->query("id") && ob2->query("id") )
                return (int)ob2->query("mingpin") - (int)ob1->query("mingpin");
        return strcmp(ob2->query("id"), ob1->query("id"));
}


int do_daming(string arg)
{
    object me=this_player();
    object *ob;
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: $1->query("mingpin")||$1->query("ming/tj/pin") :) );
    if (!arg)
    {
        arg="……";
    }
    if (!me->query("ming/tj/pin"))
    {
        return notify_fail("只有大明内廷官员才可以使用这个频道。\n");
    }
    if (me->query_temp("ming/stopchatting"))
    {
        return notify_fail("歇会儿再说吧，老用大明内廷的名义也不太合适。\n");
    }
    me->set_temp("ming/stopchatting",1);
    call_out("refreshmingchat",5,me);
    message("chat",HIW"【大明】"+me->query("name")+"("+me->query("id")+"):"+arg+"\n"+NOR,users());
    return 1;
}

int do_fu(string arg)
{
    object me=this_player();
    object ob=this_object();
    object room=environment(me);
    object target;
    object toy;
    string *toyname=({"包子","干粮","鱼饵","包袱","兔肉","军服","钢剑","长鞭","竹剑","钢杖","飞沙走石十三式"});
    string *toyid=({"baozi","gan liang","yuer","bao fu","tu rou","junfu","jian","chang bian","zhujian","gangzhang","blade book"});
    int n;
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    /*if (ob->query("owner")!=me->query("id"))
    {
        tell_object(me,"你在哪里捡的拂尘？\n");
        return 1;
    }*/
    if (!me->query("ming/tj/pin"))
    {
        tell_object(me,"你在哪里捡的拂尘？\n");
        return 1;
    }
    if (me->query("ming/tj/pin")>5)
    {
        tell_object(me,"你的级别不够使用这个功能。\n");
        return 1;
    }
    if (me->query("gender")!="无性")
    {
        tell_object(me,"你在哪里捡的拂尘？\n");
        return 1;
    }
    if (me->query("taijian/nofuchen"))
    {
        tell_object(me,"你的这套把戏老用就不灵光了。\n");
        return 1;
    }
    if (room->query("nofuchen"))
    {
        tell_object(me,"此处不能使用拂尘。\n");
        return 1;
    }
    /*if (!wizardp(me))
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }*/
    if (!arg)
    {
        tell_object(me,"你要用拂尘对付谁？\n");
        return 1;
    }
    target=find_player(arg);
    if (!target)
    {
        tell_object(me,"你要对付的人目前不在。\n");
        return 1;
    }
    if (base_name(environment(target))!=base_name(environment(me)))
    {
        tell_object(me,"你要对付的人不在这里。\n");
        return 1;
    }
    else
    {
        n=random(sizeof(toyname));
        toy=new(__DIR__"toy");
        toy->set("name",toyname[n]);
        toy->set("id",toyid[n]);
        toy->move(target);
        message_vision(HIM"$N拿起拂尘往$n脸上拂去，$n立刻变得神情恍惚。\n"NOR,me,target);
        me->set("taijian/nofuchen",1);
        me->apply_condition("fuchen", 100*(int)me->query("ming/tj/pin")+random(10)*2);
        return 1;
    }
}

