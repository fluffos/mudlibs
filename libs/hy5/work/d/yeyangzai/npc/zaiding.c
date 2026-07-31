#include <ansi.h>
inherit NPC;

void create()
{
	set_name("Ò°ÑòÕ¯Õ¯¶¡",({"zaiding"}));
        set("shen_type",-1);
	set("nickname","Ò°ÑòÕ¯");
	set("area","Ò°ÑòÕ¯");
	set("age",25);
	set_skill("dodge",60);
	set_skill("unarmed",60);
	set_skill("parry",60);
	set_skill("blade",60);
	set("max_force",600);set("force",600);
	set("combat_exp",60000);
        setup();
	carry_object("/clone/weapon/gangdao")->wield();
	add_money("silver",10);
	carry_object("/clone/misc/cloth")->wear();
}
	
void init()
{
	object ob,area;

	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	string banghui;
	if( !ob || environment(ob) != environment() ) return;
	banghui=(string) ob->query("banghui");
	if(! banghui || query("banghui")!=banghui)   {
		command("say ¾¹¸ÒË½´³Ò°ÑòÕ¯£¬ÎÒ¿´ÄãÊÇ²»Ïë»îÁË£¡\n");
		command("guard north");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}
}


