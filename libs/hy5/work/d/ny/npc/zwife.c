
// girl.c

#include <ansi.h>
inherit NPC;
void create()
{	
	string *name =({"大","二","三","四","五","六","七","八","九","小"});
	set("nickname",HIC"河东狮吼"NOR);
	set_name((name[random(10)])+"姨太", ({ "zwife",}) );
        set("shen_type",-1);
        set("gender", "女性" );
        set("age", 23);
        set("str", 16);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);
        set("max_force", 200);
        set("force", 200);
        set("force_factor", 5);
	set("max_mana",300);
	set("mana",300);
        set("long", "这是一个发了疯的女人\n");
        set("combat_exp", 8000);
	set("pursure",1);
	set("attitude","aggressive");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
 	(:command("say 还我老公命来！！"):),
	(:command("say 尝尝老娘的河东狮吼！！"):),
           (: perform_action, "sword.lian" :),
           (: perform_action, "sword.chanup" :),
           (: perform_action, "sword.sui" :),
       }) );
	set("max_qi", 1500);
	set("max_jing", 1200);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 50);
	set("combat_exp", 100000+random(100000));
	set("score", 20000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("sword", 80);
	set_skill("taiji-jian", 120);
	set_skill("taiji-quan", 120);
	set_skill("tiyunzong",50);
        set_skill("taiji-shengong", 120);
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("unarmed", "taiji-quan");
        map_skill("force", "taiji-shengong");
	set_temp("apply/attack", 15);
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 25);


        setup();
	carry_object("/clone/weapon/changjian")->wield();

        carry_object(__DIR__"obj/pink_cloth")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
}
int greeting(object ob)
{	
	if(ob->query_temp("marks/杀镇"))
		kill_ob(ob);			  	
	return 0;
}
void init()
{	object ob;
	::init();
	if(interactive(ob=this_player()))
	{	remove_call_out("greeting");
		call_out("greeting",1, ob);}
}
