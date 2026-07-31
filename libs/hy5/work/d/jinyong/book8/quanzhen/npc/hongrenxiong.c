// hong.c
inherit NPC;

#include <ansi.h>
void fighting(object who);
void create()
{
	set_name("洪人雄", ({ "hong renxiong", "hong", "renxiong" }));
	set("gender", "男性");
	set("nickname", HIC"青城四秀"NOR);
	set("age", 25);
	set("long", "他就是「英雄豪杰，青城四秀」之一，武功也远高同门。\n");

	set("qi", 10000);
	set("max_qi", 10000);
	set("jing", 10000);
	set("max_jing", 10000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 60);
	
	set("combat_exp", 3000000);
	set("shen_type", -1);

	set_skill("sword", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike", 150);
	set_skill("unarmed", 150);
	set_skill("force", 150);
	set_skill("pixie-sword", 150);
	set_skill("songfeng-jian", 150);
	set_skill("chuanhua", 150);
	set_skill("wuying-leg", 150);
	set_skill("cuixin-strike", 150);
	set_skill("qingming-xuangong", 150);
	map_skill("force", "qingming-xuangong");
	map_skill("unarmed", "wuying-leg");
	map_skill("strike", "cuixin-strike");
	map_skill("dodge", "chuanhua");
	map_skill("parry", "bixie-sword");
	map_skill("sword", "songfeng-jian");
	prepare_skill("unarmed", "wuying-leg");
	prepare_skill("strike", "cuixin-strike");
	
		set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.dieying" :),	
		(: perform_action, "unarmed.fanti" :),	
		(: perform_action, "strike.cuixin" :),	
	      }) );
	
	create_family("青城派", 6, "弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void init()
{
        object ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) {
		remove_call_out("fighting");
		call_out("fighting", 1, ob);
        }
}

void fighting(object who)
{
	object where = environment(who);
	object hong = this_object();
	object linghu = present("linghu chong",where);
        if( !who || environment(who) != environment() ) return;
	if(linghu) 
	{
		hong->fight_ob(linghu);
		linghu->fight_ob(hong);
		add_action("do_quanjia", "quanjia");
	}
}

int do_quanjia()
{
	object who = this_player();
	object where = environment(who);
	object hong = this_object();
	object linghu = present("linghu chong",where);
	
	if(who->query("jinyong/book8")) return 0;

	if(hong && linghu) 
	{
		if(hong->is_fighting(linghu) && linghu->is_fighting(hong))
		{	
			message_vision("$N大喝一声：“两位大侠住手！＂\n", who);
			linghu->remove_all_enemy();
			hong->remove_all_enemy();
			message_vision("两人停止了打斗，回过头来看着$N＂\n", who);
			if (who && interactive(who)) 
				call_out ("killhong", 1, who);  
			return 1;
		}
		else
		{
			tell_object(who,"这里没人打架，你劝什么架？");
			return 1;
		}
	}
	else
	{
		tell_object(who,"这里没人打架，你劝什么架？");
		return 1;
	}	
}

void killhong(object who)
{
	object where = environment(who);
	object hong = present("hong renxiong",where);
	if(hong) 
	{
		if(!hong->is_fighting())
		{	
			message_vision("$N恶狠狠的对$n说道： 我就是青城四秀之一的$N，这位"+ RANK_D->query_respect(who) +"活的不耐烦了，敢来管青城派的事？\n",hong,who);
			hong->set("qi", 10000);
			hong->set("max_qi", 10000);
			hong->set("jing", 10000);
			hong->set("max_jing", 10000);
			hong->set("neili", 10000);
			hong->kill_ob(who);
		}
	}
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
who->set_temp("killhrx",1);
	::die();
}