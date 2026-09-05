// 哲别
// create by zine Aug 30 2010
#include <ansi.h>
#include "checking.h"
#include "/d/menggu/shediao_bonus.h"
inherit NPC;

void create()
{
	set_name("铁木真", ({"tie muzhen","tie","muzhen"}));
	set("long", 
            HIR"他就是大名鼎鼎铁木真。\n"NOR);
	set("gender", "男性");
	set("age", 50);
    set("combat_exp", 15000);
    set_skill("unarmed", 35);
    set_skill("force", 35);
    set_skill("dodge", 40);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth4")->wear();
	
    call_out("check",2);
}
	
int visit()
{
    object bo=new(__DIR__"bo");
    object zhebie=present("zhe bie",environment(this_object()));
    command("say 你说什么？");
    command("say 博尔术，你和他比比。");
    message_vision("$N话音刚落，一人闪身而出。\n",this_object());
    bo->set("owner",this_object()->query("owner"));
    bo->move(environment(this_object()));
    this_object()->set("bo",bo);
    if (bo&&zhebie)
    {
		zhebie->fullme();
        bo->fight_ob(zhebie);
        zhebie->fight_ob(bo);
    }
    return 1;
}

int leave()
{
    object bo;
    bo=this_object()->query("bo");
    if (bo)
    {
        destruct(bo);
    }
    if (this_object())
    {
        destruct(this_object());
    }
    return 1;
}

int say_good()
{
    command("say 好兵法！");
}

int say_shang(object me)
{
    object bow,arrow,diao;
    bow=new("/d/menggu/obj/she_bow");
	arrow=new("/d/menggu/obj/arrow");
    command("say 射中的有赏。");
    command("say "+me->query("name")+"，你来射！");
    message_vision("$N交给$n一副上弦的弓和一支备用的箭。\n",this_object(),me);
    bow->move(me);
	arrow->move(me);
	diao=new("/d/menggu/npc/heidiao");
	diao->move(environment(this_object()));
	tell_room(environment(this_object()),"这时黑雕转身欲逃。\n");
	diao->showup();
	return 1;
}

int byebye(object me)
{
	object tuo,hua,ob=this_object();
	tuo=present("tuo lei",environment(ob));
	hua=present("huazheng gongzhu",environment(ob));
	tuo->handshake(me);
	hua->lean(me);
	message_vision("众人转身离开，留下了不知所措的$N。\n",me);
	destruct(hua);
	destruct(tuo);
	destruct(ob);
	return 1;
}

int shang(object me)
{
	int e_reward;
	e_reward=bonus(me,1400);
	user_record(me,e_reward,"shediao");
	command("pat "+me->query("id"));
	command("say 好孩子，你很好。");
    me->add("combat_exp",e_reward);
	me->set("shediaoquest/shediao",1);
    tell_object(me,HIC"完成射雕主线任务【射雕英雄】，你被奖励了"+chinese_number(e_reward)+"点经验！\n"NOR);
	call_out("byebye",2,me);
	return 1;
}