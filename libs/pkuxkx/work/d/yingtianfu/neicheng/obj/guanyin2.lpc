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
	set_name(WHT"官印"NOR, ({ "guan yin","yin"}));
	set_weight(50);
	set("long", "这是一具官印。\n");
	set("material", "jade");
	set("unit", "具");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("guanyin",1);
    set("no_store",1);
	setup();
}

int query_autoload() { return 1; }

void init()
{
    
    add_action("do_players","players");
    add_action("do_kanyu","kanyu"); //堪舆
    add_action("do_tandu","tandu"); //贪渎
    add_action("do_wencai","wencai");//文采
    add_action("do_tupo","tupo"); //突破
    add_action("do_buqu","buqu"); //不屈
    add_action("do_jili","jili"); //激励
    //add_action("do_daming","daming");//聊天通道
    add_action("do_zhao","zhao");
    add_action("do_query","query");
    add_action("do_qing","qing");
}

int do_qing(string arg)
{
    object me=this_player();
    object target;
    if (!me->query_temp("mingtasks/libu/target"))
    {
        return 0;
    }
    if (me->query_temp("mingtasks/libu/qinged")>2)
    {
        tell_object(me,"你已经尝试过请"+me->query_temp("mingtasks/libu/targetname")+"出山了。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    target=find_player(me->query_temp("mingtasks/libu/target"));
    if (!target||!living(target)||base_name(environment(target))!=base_name(environment(me)))
    {
        tell_object(me,"你要请的贤士不在这里。\n");
        return 1;
    }
    else
    {
        message_vision("$N对着$n深深一揖：先生可愿出山复兴我大明？\n",me,target);
        me->set_temp("mingtasks/libu/task1finish",1);
        me->add_temp("mingtasks/libu/qinged",1);
        target->set_temp("mingtasks/libu/theone",1);
        target->set_temp("mingtasks/libu/introducer",me->query("id"));
        tell_object(me,"只要"+target->query("name")+"跟你回到应天府，必得大功一件。\n");
        tell_object(target,"看来"+me->query("name")+"真心诚意邀请你出山，如果愿意，可以随他回吏部答应(daying)大明的要求。\n");
        return 1;
    }
    
}

int do_query()
{
    object me=this_player();
    string msg,info;
    int mins;
    msg="\n\n";
    msg+=HEADER;
    info=HIY"              ★★★"+HIW+"大  明"+HIY+"★★★\n"NOR;
    msg+=info;
    msg+=LINE;
    if (me->query("mingpin"))
    {
        info="  【官爵】你是大明"+chinese_number(me->query("mingpin"))+"品官员 "+me->query("ming/title")+"\n";
        msg+=info;
    }
    if (!me->query("mingpin"))
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
        info="  【政务】你上次做大明任务是在"+chinese_number(mins)+"分钟之前。\n";
        msg+=info;
    }
    if (!me->query("ming/taskstime"))
    {
        info="  【政务】无任务记录。\n";
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
    if (me->query("ming/exam"))
    {
        info="  【岁考】无上次岁考记录。\n";
        msg+=info;
    }
    if (!me->query("ming/exam"))
    {
        info="  【岁考】无上次岁考记录。\n";
        msg+=info;
    }
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

int do_zhao()
{
    object me=this_player();
    object env=environment(me);
    if (!env)
    {
        return 0;
    }
    if (!me->query_temp("mingtasks/hubu/task"))
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!env->query("zhao"))
    {
        tell_object(me,"你开始仔细搜寻失落的残图，却一无所获。\n");
        return 1;
    }
    else
    {
        tell_object(me,"你找到失落于此地的残图，仔细注释后，觉得自己可以回户部交差了。\n");
        me->set_temp("mingtasks/hubu/task1finish",1);
        return 1;
    }

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
    if (!me->query("mingpin"))
    {
        return notify_fail("只有大明官员才可以使用这个频道。\n");
    }
    if (me->query_temp("ming/stopchatting"))
    {
        return notify_fail("歇会儿再说吧，老用大明朝廷的名义也不太合适。\n");
    }
    me->set_temp("ming/stopchatting",1);
    call_out("refreshmingchat",5,me);
    message("chat",HIW"【大明】"+me->query("name")+"("+me->query("id")+"):"+arg+"\n"+NOR,ob);
    return 1;
}

int do_kanyu()
{
    object me=this_player();
    object room=environment(me);
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    if (!me->query("mingpin"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    if (!wizardp(me))
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }
    else
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }
}

int do_tandu()
{
    object me=this_player();
    object room=environment(me);
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    if (!me->query("mingpin"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    if (!wizardp(me))
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }
    else
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }
}

int do_wencai()
{
    object me=this_player();
    object room=environment(me);
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    if (!me->query("mingpin"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    if (!wizardp(me))
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }
    else
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }
}

int do_tupo()
{
    object me=this_player();
    object room=environment(me);
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    if (!me->query("mingpin"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    if (!wizardp(me))
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }
    else
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }
}

int do_buqu()
{
    object me=this_player();
    object room=environment(me);
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    if (!me->query("mingpin"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    if (!wizardp(me))
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }
    else
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }
}

int do_jili()
{
    object me=this_player();
    object room=environment(me);
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    if (!me->query("mingpin"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    if (!wizardp(me))
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }
    else
    {
        tell_object(me,HIW"此功能暂时限制玩家使用！\n"NOR);
        return 1;
    }
}
