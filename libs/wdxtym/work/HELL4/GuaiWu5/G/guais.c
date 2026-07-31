#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIR"剑灵老祖"NOR, ({"jian llaoz"}));
	set("nickname", "BOSS");
	set("gender", "无性");
	set("age", 9999);
	set("nolook", 1);
	set("attitude", "peaceful");
	set("str", 250);
	set("int", 250);
	set("con", 250);
	set("dex", 250);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 5000000);
	set("max_qi", 5000000);
	set("jing", 5000000);
	set("max_jing", 5000000);
	set("neili", 5000000);
	set("max_neili", 5000000);
	set("jiali", 1500);
	set("combat_exp", 5000000);
	set("score", 2500);
    set_skill("force", 2500+random(250));
    set_skill("unarmed", 2500+random(250));
    set_skill("dodge", 2500+random(250));
    set_skill("parry", 2500+random(250));
    set_skill("sword", 2500+random(250));
    set_skill("hand", 2500+random(250));
    set_skill("cuff", 2500+random(250));
    set_skill("strike", 2500+random(250));
    set_skill("finger", 2500+random(250));
    set_skill("claw", 2500+random(250));
    set_skill("blade", 2500+random(250));
    set_skill("staff", 2500+random(250));
    set_skill("hammer", 2500+random(250));
    set_skill("club", 2500+random(250));
    set_skill("whip", 2500+random(250));
    
    set_skill("wushang-jianjingsA", 2500+random(250));
    set_skill("wushang-jianjingsA", 2500+random(250));
    set_skill("wushang-jianjingsA", 2500+random(250));
    set_skill("wushang-jianjingsA", 2500+random(250));
    set_skill("wushang-jianjingsA", 2500+random(250));
    set_skill("wushang-jianjingsA", 2500+random(250));
    set_skill("wushang-jianjingsA", 2500+random(250));
		
	map_skill("force", "wushang-jianjingsA");
    map_skill("sword", "wushang-jianjingsA");
    map_skill("parry", "wushang-jianjingsA");
    map_skill("unarmed", "wushang-jianjingsA");
    map_skill("dodge", "wushang-jianjingsA");
	map_skill("hand", "wushang-jianjingsA");
    map_skill("cuff", "wushang-jianjingsA");
    map_skill("strike", "wushang-jianjingsA");
    map_skill("finger", "wushang-jianjingsA");
    map_skill("claw", "wushang-jianjingsA");
	map_skill("blade", "wushang-jianjingsA");
    map_skill("staff", "wushang-jianjingsA");
    map_skill("hammer", "wushang-jianjingsA");
    map_skill("club", "wushang-jianjingsA");
    map_skill("whip", "wushang-jianjingsA");

    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "force.wushangb1" :),
		(: perform_action, "force.wushangb2" :),
		(: perform_action, "force.wushangb3" :),
		(: perform_action, "force.wushangb4" :),
		(: perform_action, "force.wushangb5" :),
		(: perform_action, "force.wushangb6" :),
		(: perform_action, "force.wushangb7" :),
		(: exert_function, "force.wushanga1" :),
	}));
	set_temp("apply/attack", 10000);
	set_temp("apply/defense", 0);
	set_temp("apply/unarmed_damage", 10000);
	set_temp("apply/armor", 0);

    setup();
    carry_object("/HELL4/GuaiWu5/Gzb/wuqi")->wield();
	if (clonep(this_object()))
	{
	set("chat_chance", 250);
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


		exp = 130000;
		pot = 130000;
		me->add("combat_exp",130000);
		me->add("potential",130000);
		me->add("yuanshen/exp",130000);
		me->add("yuanbao",75);
        obj1 = new("/HELL4/BOX/box5");
        obj1->move(env);
		tell_object(me,sprintf(GRN"你获得了%d点修为，%d点潜能，%d点元神修为，75枚灵石，1个剑灵宝箱，请及时拾取，以免丢失\n"NOR,exp,pot,50000));

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