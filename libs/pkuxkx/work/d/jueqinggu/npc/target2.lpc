
#include <ansi.h>
inherit NPC;
void dest()
{
	object ob=this_object();
	if (environment())
	{
		if (ob->query("owner")&&objectp(ob->query("owner"))&&query("pin")==ob->query("owner")->query_temp("gongsun/pin"))
		tell_object(ob->query("owner"),"你突然心里泛起一丝不祥的预感，也许永远都无法解开绝情谷弟子失踪的迷了。\n");
		if (ob)
		{
			message_vision("$N飘然离去了。\n",ob);
			destruct(ob);
		}
	}
}
int ask_quest();
int JQG_target()
{
	return 1;
}
void create()
{
	int i=random(2);
    string name,*tmp,*pinying;
    name=i?NAME_D->create_name():NAME_D->create_female_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("shen_type", 1);

	set("str", 30);
	set("gender", i?"男性":"女性");
	set("age", 40+random(10));
	set("combat_exp", 60000);
	set("attitude", "friendly");
	set("random_npc",1);
	set("inquiry", ([
			"wound" : (: ask_quest :),
            "伤势" : (: ask_quest :),
       	]) );
	setup();
    carry_object("/clone/cloth/cloth")->wear();
	call_out("dest",180);

}
int answer(object ob,object me)
{
	object env,npc;
	if (!ob||!me) return 1;
	if (environment(ob)!=environment(me)) return 1;
	npc=new(__DIR__"target3");
	npc->move(MAP_D->random_place());
	if (!npc)
	{
		command("say 我派叛徒已被逐出师门，听说他现在已经在江湖仇杀中死掉了。");
	}
	else
	{
		env=environment(npc);
		npc->do_copy(me,ob->query("menpai"));
		command("say 我派叛徒已被逐出师门，听说他现在正在"+MAP_D->place_belong(env)+"一带的"+env->query("short")+"活动。");
	}
	command("say 没事我先走了。");
	message_vision("$N转身离去。\n",ob);
	destruct(ob);
	return 1;
}
int ask_quest()
{
	object me=this_player();
	if (me!=query("owner")||!me->query_temp("gongsun/job"))
	command("say 你说什么玩意啊？");
	else if (me->query_temp("gongsun/finish")>=2)
	command("say 我不是和你说过了？");
	else
	{
		message_vision("$N对着$n一揖，道：“绝情谷弟子伤在贵派武功之下，不知有何解释？”\n",me,this_object());
		command("consider");
		call_out("answer",1,this_object(),me);
		me->set_temp("gongsun/finish",2);
	}
	return 1;
}
void owner(object me,string mp,int pin)
{
	set("owner",me);
	set("menpai",mp);
	set("family/family_name",mp);
	set("pin",pin);
}

void init()
{
	object me=this_player();
	if (me==query("owner"))
	{
		command("hi "+me->query("id"));
	}
}