#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIY"御剑宗师"NOR, ({"jian zongsi"}));
	set("nickname", "精英怪");
	set("gender", "无性");
	set("age", 9999);
	set("nolook", 1);
	set("attitude", "peaceful");
	set("str", 200);
	set("int", 200);
	set("con", 200);
	set("dex", 200);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 3000000);
	set("max_qi", 3000000);
	set("jing", 3000000);
	set("max_jing", 3000000);
	set("neili", 3000000);
	set("max_neili", 3000000);
	set("jiali", 1000);
	set("combat_exp", 3000000);
	set("score", 2000);
    set_skill("force", 800+random(200));
    set_skill("unarmed", 800+random(200));
    set_skill("dodge", 800+random(200));
    set_skill("parry", 800+random(200));
    set_skill("sword", 800+random(200));
    set_skill("hand", 800+random(200));
    set_skill("cuff", 800+random(200));
    set_skill("strike", 800+random(200));
    set_skill("finger", 800+random(200));
    set_skill("claw", 800+random(200));
    set_skill("blade", 800+random(200));
    set_skill("staff", 800+random(200));
    set_skill("hammer", 800+random(200));
    set_skill("club", 800+random(200));
    set_skill("whip", 800+random(200));
    
    set_skill("wushang-jianjing", 800+random(200));
    set_skill("wushang-jianjing", 800+random(200));
    set_skill("wushang-jianjing", 800+random(200));
    set_skill("wushang-jianjing", 800+random(200));
    set_skill("wushang-jianjing", 800+random(200));
    set_skill("wushang-jianjing", 800+random(200));
    set_skill("wushang-jianjing", 800+random(200));
		
	map_skill("force", "wushang-jianjing");
    map_skill("sword", "wushang-jianjing");
    map_skill("parry", "wushang-jianjing");
    map_skill("unarmed", "wushang-jianjing");
    map_skill("dodge", "wushang-jianjing");
	map_skill("hand", "wushang-jianjing");
    map_skill("cuff", "wushang-jianjing");
    map_skill("strike", "wushang-jianjing");
    map_skill("finger", "wushang-jianjing");
    map_skill("claw", "wushang-jianjing");
	map_skill("blade", "wushang-jianjing");
    map_skill("staff", "wushang-jianjing");
    map_skill("hammer", "wushang-jianjing");
    map_skill("club", "wushang-jianjing");
    map_skill("whip", "wushang-jianjing");

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
	set_temp("apply/attack", 8000);
	set_temp("apply/defense", 0);
	set_temp("apply/unarmed_damage", 8000);
	set_temp("apply/armor", 0);

    setup();
    carry_object("/HELL4/GuaiWu4/Gzb/wuqi")->wield();
	if (clonep(this_object()))
	{
	set("chat_chance", 200);
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


		exp = 200000;
		pot = 200000;
		me->add("combat_exp",200000);
		me->add("potential",200000);
		me->add("yuanshen/exp",200000);
		me->add("yuanbao",75);
        obj1 = new("/HELL4/BOX/box4");
        obj1->move(env);
		tell_object(me,sprintf(GRN"你获得了%d点修为，%d点潜能，%d点元神修为，75枚灵石，1个御剑宝箱，请及时拾取，以免丢失\n"NOR,exp,pot,50000));

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