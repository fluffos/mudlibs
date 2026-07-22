// customer	顾客
// by augx@sj	9/11/2001

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

#include <ansi.h>

void create()
{
	mapping name;
	int i = random(3) + 1;

	name = RNAME_D->get_random_name(i);
	set_name(name["name"], name["id"]);
	set("gender", (i==0?"女性":"男性"));

	set("age", 15 + random(15));
	set("long", "这是位在江湖上行侠仗义的侠客。\n");
	set("combat_exp", 3000000);
	set("meitude", "peaceful");
        set("no_bark", 1);
	set("str", 36);
	set("int", 36);
	set("con", 36);
	set("dex", 36);
	set("shen",10000);
	set("max_qi", 90000);
	set("eff_jingli",90000);
	set("max_jing", 90000);
	set("max_neili",90000);
	set("neili", 90000);
	
	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("unarmed", 300);
	set_skill("literate", 150);
	set_skill("sword", 300);
	
	set_temp("apply/dodge",888);
	set_temp("apply/force",888);
	set_temp("apply/attack",888);
	set_temp("apply/damage",333);
	set_temp("apply/armor",888);
	        
	set_temp("no_return",1);
	set("no_clean_up",1);
	setup();
	carry_object(BINGQI_D("sword"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("coin", random(35));
	
	call_out("dest", 1000);
}       

void init()
{
	object ob;
        
	::init();
        
	if( interactive(ob = this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	command("haha");
}

void dest()
{
        command("emote 慢慢离开了。");
	destruct(this_object());
}

void kill_ob(object ob)
{
	command("fear");
	command("!!!");
        ob->remove_killer(this_object());
        this_object()->remove_enemy(ob);
        return;
}

int accept_fight(object me)
{
	command("shake");
	return 0;       
}

void finish()
{
	int i = remove_call_out("dest");
	if(i>20) i=20;
	if(i>=0) call_out("dest",i);
}
