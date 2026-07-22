//weiqi...97/12/11

inherit NPC;

string apply_dancer(object me);
string answer_leaving(object me);
int do_yes(string arg);
void do_something();

void create()
{
	set_name("公孙大娘", ({"gongsun daniang", "gongsun", "daniang"}));
	set_level(35);
	set("age", 62);
	set("gender", "女性");
	set("per", 30);
	set("long", "长安城内稍有名望的，不知道公孙大娘的人恐怕没几个。\n特别是那些文人骚客，跟公孙大娘不熟简直就是没面子。\n");
	set("title", "剑圣");
	set("attitude", "friendly");

	set("combat_exp", 8000000);
  set("daoxing", 6000000);

	set("max_force", 4000);
	set("force", 8000);
	set("force_factor", 200);
	set_skill("unarmed", 260);
        set("max_mana", 8000);
        set("mana", 8000);
        set("mana_factor", 500);
	set_skill("dodge", 290);
	set_skill("binfen-steps", 320);
	set_skill("parry", 260);
	set_skill("literate", 290);
	set_skill("sword", 390);
	set_skill("daya-jian", 390);
	map_skill("dodge", "binfen-steps");
	map_skill("sword", "daya-jian");
	map_skill("parry", "daya-jian");


	
set("chat_chance_combat", 90);
set("chat_msg_combat", ({
(: perform_action,"sword", "badao" :),
 }) );
	setup();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
	add_money("silver", 200);
}
