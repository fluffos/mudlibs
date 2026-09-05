//李萍，郭靖的妈
//created by zine 30 Aug 2010

inherit NPC;
#include "muyang.h";
string ask_job();
void create()
{
        set_name("李萍", ({ "li ping", "ping", "li" }) );
        set("gender", "女性" );
		set("title", "郭母");
        set("age", 32);
        set("long", 
            "他是射雕大侠郭靖的母亲，粗手大脚，姿色很是平庸。\n");
        set("str", 30);
        set("dex", 10);
        set("con", 20);
        set("int", 10);
		set("shen_type", 1);
		set_skill("force", 5);
		set("combat_exp", 5000);
		set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 1);
		set("per",15);
        set("max_neili", 1);
		set("uni_target",1);
		set("attitude", "friendly");
        set("inquiry", ([
            "name" : "我叫李萍。",
            "郭靖" : "他是我的儿子,他长大以后要为他爹爹报仇 。",
            "报仇" : "一定要杀了段天德这狗贼，为郭靖他爹爹报仇。",
			"段天德" : "段天德这狗贼，我死都不会放过他。",
            "here" : "我们娘俩一路逃到了大草原。",
			"job" : (: ask_job :),
            "放羊" : (: ask_job :),
            
       	]) );
		set("chat_chance", 3);
        set("chat_msg", ({
                "李萍喃喃说道：靖儿如果再聪明点就好了。\n",
                "李萍怒骂道：段天德，我做鬼也不会放过你的。\n",
                "李萍叹道：不知道包家妹妹和杨叔叔怎么样了。\n",
        }) );
        setup();
		carry_object(__DIR__"items/pixue")->wear();
		carry_object(__DIR__"items/cloth")->wear();
		
}
int dest(object ob)
{
	if (ob)
	{
		destruct(ob);
	}
	return 1;
}

int accept_object(object me,object ob)
{
	if (!me->query_temp("shediaoquest/zjk/farewell")||!me->query_temp("shediaoquest/zjk/bye_tie"))
	{
		return notify_fail(this_object()->name()+"不想要你的东西。\n");
	}
	if (me->query_temp("shediaoquest/zjk/bye_liping"))
	{
		return notify_fail(this_object()->name()+"道：“这孩子，马上要上路了，总要给自己留点啊。”\n");
	}
	else if (ob->query("money_id") && ob->value() >= 1000000)
	{
		me->set_temp("shediaoquest/zjk/bye_liping",1);
		call_out("dest",1,ob);
		command("smile");
		command("say 好吧，我就帮你存起来，等你以后回来用处大呢。");
		tell_object(me,"你心里暗暗盘算了一下路线，从东面离开铁木真的部落，横穿科尔沁草原，就是张家口了。\n");
		return 1;
	}
	else
	{
		return notify_fail(this_object()->name()+"不想要你的东西。\n");
	}
}

