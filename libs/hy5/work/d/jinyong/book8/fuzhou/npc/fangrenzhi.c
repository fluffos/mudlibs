// fang.c 

inherit NPC;
//inherit F_SKILL;
void fighting(object who);

void create()
{
	set_name("方人智", ({ "fang renzhi", "fang", "renzhi" }));
	set("gender", "男性");
	set("age", 20);
	set("long", "他就是「青城派」年轻一代弟子，以智计为师尊喜爱。\n");

	set("qi", 12000);
	set("max_qi", 12000);
	set("jing", 12000);
	set("max_jing", 12000);
	set("neili", 12000);
	set("max_neili", 12000);
	set("jiali", 60);
	
	set("combat_exp", 3500000);
	set("shen_type", -1);

	set_skill("sword", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("strike", 180);
	set_skill("unarmed", 180);
	set_skill("force", 180);
	set_skill("pixie-sword", 180);
	set_skill("songfeng-jian", 180);
	set_skill("chuanhua", 180);
	set_skill("wuying-leg", 180);
	set_skill("cuixin-strike", 180);
	set_skill("qingming-xuangong", 180);
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
	object me = this_object();
	object who= this_player();
	if(me->is_fighting()) return;
	if (who && interactive(who)) 
		call_out ("fighting", 1, who);  
}


void fighting(object who)
{
	object where = environment(who);
	object fang = this_object();
	object lin = present("lin pingzhi",where);
	if(fang && lin) 
	{
		fang->kill_ob(lin);
		lin->fight_ob(fang);
	}
}