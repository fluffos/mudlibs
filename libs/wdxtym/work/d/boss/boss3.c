#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIR "芬里尔", ({"fles"}));
	set("nickname", "神之浩劫");
	set("gender", "无性");
	set("age", 9999);
	set("long", 
		"曾吞噬并且杀死北欧众神之父奥丁的恐怖魔狼。\n");
	set("attitude", "peaceful");
	set("str", 250);
	set("int", 250);
	set("con", 250);
	set("dex", 250);
	set("chat_chance", 1);
   set("quest2/kuihua/pass", 1);

	set("qi", 10000000);
	set("max_qi", 10000000);
	set("jing", 10000000);
	set("max_jing", 10000000);
	set("neili", 10000000);
	set("max_neili", 10000000);
	set("jiali", 1000);
	set("combat_exp", 10000000);
	set("score", 1000);
    set_skill("force", 2500+random(100));
    set_skill("unarmed", 2500+random(100));
    set_skill("dodge", 2500+random(100));
    set_skill("parry", 2500+random(100));
    set_skill("sword", 2500+random(100));
    set_skill("hand", 2500+random(100));
    set_skill("cuff", 2500+random(100));
    set_skill("strike", 2500+random(100));
    set_skill("finger", 2500+random(100));
    set_skill("claw", 2500+random(100));
    set_skill("blade", 2500+random(100));
    set_skill("staff", 2500+random(100));
    set_skill("hammer", 2500+random(100));
    set_skill("club", 2500+random(100));
    set_skill("whip", 2500+random(100));
    
    set_skill("shanggu-mijings", 2500+random(100));
		
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
	set_temp("apply/attack", 7500);
	set_temp("apply/defense", 1500);
	set_temp("apply/unarmed_damage", 7500);
	set_temp("apply/armor", 1500);
    carry_object("/d/fuzhou/obj/xiuhua")->wield();
    carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();
			if (clonep(this_object()))
	{
		set("chat_chance", 30);
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


		exp = 250000;
		pot = 250000;
		me->add("combat_exp",250000);
		me->add("potential",250000);
		me->add("yuanshen/exp",100000);
        obj1 = new("/clone/vip2/dan_jiuzhuan");
	    obj1->set_amount(50);
        obj1->move(env);
		tell_object(me,sprintf(GRN"你获得了%d点修为，%d点潜能，%d点元神修为。从芬里尔身上掉落50颗九转金丹，请及时拾取，以免丢失\n"NOR,exp,pot,50000));

	destruct(ob);
}

void random_move()
{
	if (time() - query("born_time") > 1800)
	{
		message_vision("因无人击败$N，所以他不屑的离开了。\n", this_object());

		destruct(this_object());
		return;
	}
}