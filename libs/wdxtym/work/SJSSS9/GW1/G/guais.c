#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIR"仙人"NOR, ({"xrsa9"}));
	set("nickname", "渡劫境");
	set("gender", "神性");
	set("age", 9999);
	set("nolook", 1);
	set("attitude", "peaceful");
	set("str", 888);
	set("int", 888);
	set("con", 888);
	set("dex", 444);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 90000000);
	set("max_qi", 90000000);
	set("jing", 90000000);
	set("max_jing", 90000000);
	set("neili", 1000000);
	set("max_neili", 1000000);
	set("jiali", 9000);
	set("combat_exp", 90000000);
	set("score", 9000);
    set_skill("force", 35000+random(2500));
    set_skill("unarmed", 35000+random(2500));
    set_skill("dodge", 7500+random(2500));
    set_skill("parry", 7500+random(2500));
    set_skill("sword", 35000+random(2500));
    set_skill("hand", 35000+random(2500));
    set_skill("cuff", 35000+random(2500));
    set_skill("strike", 35000+random(2500));
    set_skill("finger", 35000+random(2500));
    set_skill("claw", 35000+random(2500));
    set_skill("blade", 35000+random(2500));
    set_skill("staff", 35000+random(2500));
    set_skill("hammer", 35000+random(2500));
    set_skill("club", 35000+random(2500));
    set_skill("whip", 35000+random(2500));
    
    set_skill("xiuxian-gongfa", 35000+random(2500));
    set_skill("xiuxian-gongfa", 35000+random(2500));
    set_skill("xiuxian-gongfa", 35000+random(2500));
    set_skill("xiuxian-gongfa", 35000+random(2500));
    set_skill("xiuxian-gongfa", 35000+random(2500));
    set_skill("xiuxian-gongfa", 35000+random(2500));
    set_skill("xiuxian-gongfa", 35000+random(2500));
		
	map_skill("force", "xiuxian-gongfa");
    map_skill("sword", "xiuxian-gongfa");
    map_skill("parry", "xiuxian-gongfa");
    map_skill("unarmed", "xiuxian-gongfa");
    map_skill("dodge", "xiuxian-gongfa");
	map_skill("hand", "xiuxian-gongfa");
    map_skill("cuff", "xiuxian-gongfa");
    map_skill("strike", "xiuxian-gongfa");
    map_skill("finger", "xiuxian-gongfa");
    map_skill("claw", "xiuxian-gongfa");
	map_skill("blade", "xiuxian-gongfa");
    map_skill("staff", "xiuxian-gongfa");
    map_skill("hammer", "xiuxian-gongfa");
    map_skill("club", "xiuxian-gongfa");
    map_skill("whip", "xiuxian-gongfa");

    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "force.xiuxianb1" :),
		(: perform_action, "force.xiuxianb2" :),
		(: perform_action, "force.xiuxianb3" :),
		(: perform_action, "force.xiuxianb4" :),
		(: perform_action, "force.xiuxianb5" :),
		(: exert_function, "force.xiuxiana1" :),
	}));
	set_temp("apply/attack", 200000);
	set_temp("apply/defense", 30000);
	set_temp("apply/unarmed_damage", 200000);
	set_temp("apply/armor", 30000);
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


		exp = 900000;
		pot = 900000;
		me->add("combat_exp",900000);
		me->add("potential",900000);
		me->add("yuanshen/exp",1000);
		me->add("yuanbao",900);
        obj1 = new("/SJSSS9/BOX/box1");
        obj1->move(env);
		tell_object(me,sprintf(GRN"你获得了%d点修为，%d点潜能，%d点元神修为，900灵石，1个渡劫宝箱，请及时拾取，以免丢失\n"NOR,exp,pot,50000));

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