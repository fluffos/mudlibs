#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIG"流浪武士"NOR, ({"liulang ws"}));
	set("nickname", "初级怪");
	set("gender", "无性");
	set("age", 9999);
	set("nolook", 1);
	set("attitude", "peaceful");
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 50000);
	set("max_qi", 50000);
	set("jing", 50000);
	set("max_jing", 50000);
	set("neili", 50000);
	set("max_neili", 50000);
	set("jiali", 200);
	set("combat_exp", 50000);
	set("score", 500);
    set_skill("force", 500+random(50));
    set_skill("unarmed", 500+random(50));
    set_skill("dodge", 500+random(50));
    set_skill("parry", 500+random(50));
    set_skill("sword", 500+random(50));
    set_skill("hand", 500+random(50));
    set_skill("cuff", 500+random(50));
    set_skill("strike", 500+random(50));
    set_skill("finger", 500+random(50));
    set_skill("claw", 500+random(50));
    set_skill("blade", 500+random(50));
    set_skill("staff", 500+random(50));
    set_skill("hammer", 500+random(50));
    set_skill("club", 500+random(50));
    set_skill("whip", 500+random(50));
    
    set_skill("yinyangjiuzhuanshierchongtian", 500+random(50));
    set_skill("yinyangjiuzhuanshierchongtian", 500+random(50));
    set_skill("yinyangjiuzhuanshierchongtian", 500+random(50));
    set_skill("yinyangjiuzhuanshierchongtian", 500+random(50));
    set_skill("yinyangjiuzhuanshierchongtian", 500+random(50));
    set_skill("yinyangjiuzhuanshierchongtian", 500+random(50));
    set_skill("yinyangjiuzhuanshierchongtian", 500+random(50));
		
	map_skill("force", "yinyangjiuzhuanshierchongtian");
    map_skill("sword", "yinyangjiuzhuanshierchongtian");
    map_skill("parry", "yinyangjiuzhuanshierchongtian");
    map_skill("unarmed", "yinyangjiuzhuanshierchongtian");
    map_skill("dodge", "yinyangjiuzhuanshierchongtian");
	map_skill("hand", "yinyangjiuzhuanshierchongtian");
    map_skill("cuff", "yinyangjiuzhuanshierchongtian");
    map_skill("strike", "yinyangjiuzhuanshierchongtian");
    map_skill("finger", "yinyangjiuzhuanshierchongtian");
    map_skill("claw", "yinyangjiuzhuanshierchongtian");
	map_skill("blade", "yinyangjiuzhuanshierchongtian");
    map_skill("staff", "yinyangjiuzhuanshierchongtian");
    map_skill("hammer", "yinyangjiuzhuanshierchongtian");
    map_skill("club", "yinyangjiuzhuanshierchongtian");
    map_skill("whip", "yinyangjiuzhuanshierchongtian");

    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "force.zhen" :),
		(: perform_action, "force.tian" :),
		(: perform_action, "force.sha" :),
		(: perform_action, "force.powerup" :),
		(: perform_action, "force.roar" :),
		(: exert_function, "shield" :),
		(: exert_function, "jiu" :),
	}));
	set_temp("apply/attack", 1000);
	set_temp("apply/defense", 50);
	set_temp("apply/unarmed_damage", 1000);
	set_temp("apply/armor", 50);

    setup();
    carry_object("/HELL9/GuaiWu1/Gzb/wuqi")->wield();
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


		exp = 50000;
		pot = 50000;
		me->add("combat_exp",50000);
		me->add("potential",50000);
		me->add("yuanshen/exp",50000);
		me->add("yuanbao",50);
        obj1 = new("/HELL9/BOX/box1");
        obj1->move(env);
		tell_object(me,sprintf(GRN"你获得了%d点修为，%d点潜能，%d点元神修为，50枚灵石，1个天照宝箱，请及时拾取，以免丢失\n"NOR,exp,pot,50000));

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