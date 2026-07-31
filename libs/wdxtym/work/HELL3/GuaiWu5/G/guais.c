#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIR"荒古帝君 "NOR, ({"huang djun"}));
	set("nickname", "世界BOSS");
	set("gender", "无性");
	set("age", 9999);
	set("nolook", 1);
	set("attitude", "peaceful");
	set("str", 9999);
	set("int", 9999);
	set("con", 9999);
	set("dex", 9999);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 990000000);
	set("max_qi", 990000000);
	set("jing", 100000000);
	set("max_jing", 100000000);
	set("neili", 100000000);
	set("max_neili", 100000000);
	set("jiali", 100000);
	set("combat_exp", 10000000);
	set("score", 5000);
    set_skill("force", 100000+random(50000));
    set_skill("unarmed", 100000+random(50000));
    set_skill("dodge", 50000+random(5000));
    set_skill("parry", 50000+random(5000));
    set_skill("sword", 100000+random(50000));
    set_skill("hand", 100000+random(50000));
    set_skill("cuff", 100000+random(50000));
    set_skill("strike", 100000+random(50000));
    set_skill("finger", 100000+random(50000));
    set_skill("claw", 100000+random(50000));
    set_skill("blade", 100000+random(50000));
    set_skill("staff", 100000+random(50000));
    set_skill("hammer", 100000+random(50000));
    set_skill("club", 100000+random(50000));
    set_skill("whip", 100000+random(50000));

    set_skill("shanggu-mijing", 100000+random(50000));
		
	map_skill("force", "shanggu-mijing");
    map_skill("sword", "shanggu-mijing");
    map_skill("parry", "shanggu-mijing");
    map_skill("unarmed", "shanggu-mijing");
    map_skill("dodge", "shanggu-mijing");
	map_skill("hand", "shanggu-mijing");
    map_skill("cuff", "shanggu-mijing");
    map_skill("strike", "shanggu-mijing");
    map_skill("finger", "shanggu-mijing");
    map_skill("claw", "shanggu-mijing");
	map_skill("blade", "shanggu-mijing");
    map_skill("staff", "shanggu-mijing");
    map_skill("hammer", "shanggu-mijing");
    map_skill("club", "shanggu-mijing");
    map_skill("whip", "shanggu-mijing");

    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "force.shanggub1" :),
		(: perform_action, "force.shanggub2" :),
		(: exert_function, "force.shanggua2" :),
	}));
	set_temp("apply/attack", 1000000);
	set_temp("apply/defense", 1000000);
	set_temp("apply/unarmed_damage", 1000000);
	set_temp("apply/armor", 1000000);
	
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


		exp = 100000000;
		pot = 100000000;
		me->add("combat_exp",100000000);
		me->add("potential",100000000);
		me->add("yuanshen/exp",100000000);
		me->add("tianji1",100);
        obj1 = new("/HELL3/BOX/box5");
        obj1->move(env);
		tell_object(me,sprintf(GRN"你获得了%d点修为，%d点潜能，%d点元神修为，100天机，1个古帝宝箱，请及时拾取，以免丢失\n"NOR,exp,pot,50000));

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