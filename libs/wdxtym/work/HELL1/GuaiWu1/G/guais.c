#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIY"史莱姆王"NOR, ({"shilai mus"}));
	set("nickname", "经验怪");
	set("gender", "无性");
	set("age", 9999);
	set("nolook", 1);
	set("attitude", "peaceful");
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 1000000);
	set("max_qi", 1000000);
	set("jing", 1000000);
	set("max_jing", 1000000);
	set("neili", 1000000);
	set("max_neili", 1000000);
	set("jiali", 1);
	set("combat_exp", 1000000);
	set("score", 100);
    set_skill("force", 100+random(100));
    set_skill("unarmed", 100+random(100));
    set_skill("dodge", 100+random(100));
    set_skill("parry", 100+random(100));
    set_skill("sword", 100+random(100));
    set_skill("hand", 100+random(100));
    set_skill("cuff", 100+random(100));
    set_skill("strike", 100+random(100));
    set_skill("finger", 100+random(100));
    set_skill("claw", 100+random(100));
    set_skill("blade", 100+random(100));
    set_skill("staff", 100+random(100));
    set_skill("hammer", 100+random(100));
    set_skill("club", 100+random(100));
    set_skill("whip", 100+random(100));
    
    set_skill("shanggu-mijing", 100+random(100));
    set_skill("shanggu-mijing", 100+random(100));
    set_skill("shanggu-mijing", 100+random(100));
    set_skill("shanggu-mijing", 100+random(100));
    set_skill("shanggu-mijing", 100+random(100));
    set_skill("shanggu-mijing", 100+random(100));
    set_skill("shanggu-mijing", 100+random(100));
		
	map_skill("force", "shanggu-mijings");
    map_skill("sword", "shanggu-mijings");
    map_skill("parry", "shanggu-mijings");
    map_skill("unarmed", "shanggu-mijings");
    map_skill("dodge", "shanggu-mijings");
	map_skill("hand", "shanggu-mijings");
    map_skill("cuff", "shanggu-mijings");
    map_skill("strike", "shanggu-mijings");
    map_skill("finger", "shanggu-mijings");
    map_skill("claw", "shanggu-mijings");
	map_skill("blade", "shanggu-mijings");
    map_skill("staff", "shanggu-mijings");
    map_skill("hammer", "shanggu-mijings");
    map_skill("club", "shanggu-mijings");
    map_skill("whip", "shanggu-mijings");

    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "force.shanggub1" :),
		(: perform_action, "force.shanggub2" :),
		(: perform_action, "force.shanggub3" :),
		(: perform_action, "force.shanggub4" :),
		(: exert_function, "force.shanggua1" :),
		(: exert_function, "force.shanggua2" :),
		(: exert_function, "force.shanggua3" :),
		(: exert_function, "force.shanggua4" :),
	}));
	set_temp("apply/attack", 1);
	set_temp("apply/defense", 1000);
	set_temp("apply/unarmed_damage", 1);
	set_temp("apply/armor", 1000);

	if (clonep(this_object()))
	{
	set("chat_chance", 100);
	set("chat_msg", ({ (: random_move :) }));
	set("born_time", time());
	keep_heart_beat();
	}
	setup();
}



void unconcious()
{
	die();
}
void die()
{
	object me,ob,memory,item,env,obj,obj1;
	mapping team;
	string location;
	int i,level,exp,rand,pot;
	string file;

	ob = this_object();
	me  = ob->query_last_damage_from();


        env = environment(this_object());
//	CHANNEL_D->do_channel(this_object(), "chat", HIR"唉，老身去也！"NOR"");


		exp = 210000;
		pot = 210000;
		me->add("combat_exp",210000);
		me->add("potential",210000);
		me->add("yuanshen/exp",1000);
		me->add("yuanbao",5);
		tell_object(me,sprintf(GRN"你获得了%d点修为，%d点潜能，%d点元神修为，5灵石！\n"NOR,exp,pot,10000));

	destruct(ob);
}

void random_move()
{
	if (time() - query("born_time") > 1800)
	{
		message_vision("$N急急忙忙的走了。\n", this_object());

		destruct(this_object());
		return;
	}
}