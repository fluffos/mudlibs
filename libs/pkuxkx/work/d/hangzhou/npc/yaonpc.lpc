inherit NPC;
#include <ansi.h>

int ask_job();

void create()
{
	string name,*tmp,*pinying;
	string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("title",color1+({"悬壶济世","杏林名医","青囊传人"})[random(3)]+NOR);
	set("age", 30+random(20));
	set("gender", "男性");
	set("long", "这是一位大医者，也是临安府药铺老板的朋友。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 3000);
	set("shen_type", 1);
	set("random_npc",1);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("force", 40);
	set("CustomizedAskMode","药材");
	set("job_id",1);//辨别不同药师任务
	set("inquiry", ([
			"药材" :(:ask_job:)
			]));
	setup();
	call_out("leave",600);
	carry_object("clone/cloth/ycloth")->wear();
	carry_object("clone/cloth/yshoe")->wear();
}
int leave()
{
	message_vision("一转眼，$N就不见了。\n",this_object());
	destruct(this_object());
	return 1;
}
int ask_job()
{
	object me=this_player(),ob;
	message_vision("$N对着$n作了一个揖，道：“在下是临安药铺老板的人，请先生相助。”\n",me,this_object());
	if (query("owner")!=me)
	command("shake");
	else if (!me->query_temp("AlchemyJob/"+this_object()->query("job_id")+"/drug1"))
	command("say 我也不知道为什么，就是不想帮你。");
	else
	{
		ob="/obj/remedy/reference"->ObtainDrug(me->query_temp("AlchemyJob/"+this_object()->query("job_id")+"/drug1"));
		ob->move(this_object());
		command("say 好吧。");
		command("give "+me->query("id")+" "+ob->query("id"));
		command("wave");
		call_out("leave",1);
	}
	return 1;
}

void die()
{
	object killer,ob;
	if(killer=get_damage_origin_object())//无伤害来源
	{
		if (userp(query("owner")))
		command("tell "+query("owner")->query("id")+" 我想帮你的，可惜我被"+killer->name()+"害死啦。\n");
	}
	::die();
}