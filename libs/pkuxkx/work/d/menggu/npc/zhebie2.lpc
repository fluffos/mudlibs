// 哲别
// create by zine Aug 30 2010
#include <ansi.h>
inherit NPC;
#include "/d/menggu/shediao_bonus.h"
int ask_arrow();
void create()
{
	set_name("哲别", ({"zhe bie", "zhe", "bie"}));
	set("title", WHT"神箭手"NOR);
	set("long", 
            HIR"他是草原上的第一神箭手哲别。\n"NOR);
	set("gender", "男性");
	set("age", 40);
    set("combat_exp", 150000);
    set_skill("unarmed", 35);
    set_skill("force", 35);
    set_skill("dodge", 40);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
	set("shen_type", 1);
    set("no_get",1);
    set("inquiry", ([
                "箭术":   (: ask_arrow() :),
                "arrow":   (: ask_arrow() :),
           
       	]) );
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth3")->wear();
	
	call_out("dest",600);
}
	
int dest()
{
	object ob=this_object();
	if (ob)
	{
		message_vision("$N见没有什么事，转身回到后帐。\n");
		destruct(ob);
	}
	return 1;
}
int leave(object ob)
{
    object *all=all_inventory(environment(ob));
    int i,flag=0;
    for (i=0;i<sizeof(all);i++)
    {
        if (userp(all[i])&&all[i]->query("shediaoquest/zhebie")<3)
        {
            flag=1;
        }
    }
    if (flag)
    {
        command("consider");
        call_out("leave",10,ob);
        return 1;
    }
    else
    {
        message_vision("$N看看左右无事，决定先离开了。\n",ob);
        destruct(ob);
        return 1;
    }
}
int study(object me)
{
    int e_reward;
    object ob=this_object();
	if (!me||environment(me)!=environment(ob))
	{
		message_vision("$N摇了摇头：这孩子！\n");
		message_vision("$N转身进了后帐。\n");
		destruct(this_object());
		return 1;
	}
    if (random(10)<7)
    {
        if (environment(me)==environment(ob))
        {
            message_vision("$N继续学习开弓射箭之术。\n",me);
            me->add_busy(1);
            call_out("study",1,me);
            return 1;
        }
        else
        {
            return 1;
        }
    }
    tell_object(me,HIG+"你觉得自己已经完全掌握了开弓射箭的要领。\n"+NOR);
    me->set_skill("arrow",(int)me->query_skill("arrow",1)+10);
    call_out("leave",1,ob);
    me->add("shediaoquest/zhebie",1);
    me->set("shediaoquest/zhebie_endtime",time());
    e_reward=bonus(me,600);
    me->add("combat_exp",e_reward);
	user_record(me,e_reward,"zhebie");
    tell_object(me,HIC"完成射雕主线任务【拜师哲别】，你被奖励了"+chinese_number(e_reward)+"点经验！\n"NOR);
	tell_room(environment(),ob->name()+"见"+me->query("name")+"已经掌握了神射的要领，挥了挥手，转身又进入了后帐。\n");
	destruct(this_object());
    return 1;
}

int ask_arrow()
{
    object ob=this_object();
    object me=this_player();
    if (!me->query("shediaoquest/zhebie"))
    {
        message_vision("$N转过身去，并不打算搭理$n。\n",ob,me);
        return 1;
    }
    if (me->query("shediaoquest/zhebie")>1)
    {
        command("say 我不是已经教过你了吗？");
        return 1;
    }
	if (me->query("id")!=this_object()->query("owner"))
	{
		command("say "+me->query("name")+"，你稍等一下，我这会儿正教着"+this_object()->query("owner")+"呢。\n");
		return 1;
	}
    me->add("shediaoquest/zhebie",1);
    me->add_busy(1);
    message_vision("$N开始认真教授$n开弓射箭的本领。\n",ob,me);
    call_out("study",1,me);
    return 1;
}
void die()
{
    this_object()->fullme();
    return;
}

int hello(object me)
{
    command("say "+me->query("name")+"你真的来了？太好了。");
    command("whisper "+me->query("id")+" 如果你想学习我的箭法，我一定倾囊相传。");
	set("owner",me->query("id"));
    return 1;
}