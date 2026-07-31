// wujiang.c 武将

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("武将", ({ "wu jiang", "wu", "jiang" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他站在那里，的确有说不出的威风。\n");
	set("combat_exp", 105000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("leadership", 80);
	set_skill("strategy", 80);
	set_skill("sword", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);

           set("chat_chance_combat", 90);
      set("chat_msg_combat", ({
 	             (: command, "alert" :),
        }) );
             setup();
  carry_object(__DIR__"obj/gangjian")->wield();
//	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("d/city/npc/obj/tiejia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
