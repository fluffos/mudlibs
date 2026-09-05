// wujiang.c 武将

inherit NPC;

int ask_pass()
{
	object me=this_player();
	if (!environment(me)->query("dufu_gate"))
	{
		command("say 什么意思？");
	}
	else if (me->query_temp("dutongfu/greet"))
	command("say 那你就进去吧。");
	else
	{
		me->set_temp("dutongfu/greet",1);
		command("say 已经有人帮你通传了，你快进去吧。");
	}
	return 1;
}
void create()
{
	set_name("都统制府侍卫", ({ "shiwei", "wei","shi" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他是一名都府侍卫，正在这里巡逻。\n");
	set("combat_exp", 650000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("spear", 200);
	set_skill("yangjia-qiang", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);

	map_skill("spear", "yangjia-qiang");
	map_skill("parry", "yangjia-qiang");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 4000); 
	set("max_neili", 4000);
	set("jiali", 10);
	set("inquiry", ([
                "通传" : (:ask_pass:) ,
				]));
	setup();
	carry_object("/clone/weapon/changqiang")->wield();
	carry_object("/clone/armor/pifeng")->wear();
}
