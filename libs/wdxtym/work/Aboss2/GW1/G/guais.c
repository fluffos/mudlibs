#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIR"盘古"NOR, ({"Aboss2"}));
	set("nickname", "世界创造者");
	set("gender", "神性");
	set("age", 9999);
	set("nolook", 1);
	set("attitude", "peaceful");
	set("str", 99999);
	set("int", 99999);
	set("con", 99999);
	set("dex", 99999);

	set("qi", 100000000000);
	set("max_qi", 100000000000);
	set("jing", 100000000000);
	set("max_jing", 100000000000);
	set("neili", 100000000);
	set("max_neili", 100000000);
	set("jiali", 1000000);
	set("combat_exp", 100000000);
	set("score", 1000000);
    set_skill("force", 999999+random(999999));
    set_skill("unarmed", 999999+random(999999));
    set_skill("dodge", 999999+random(999999));
    set_skill("parry", 999999+random(999999));
    set_skill("sword", 999999+random(999999));
    set_skill("hand", 999999+random(999999));
    set_skill("cuff", 999999+random(999999));
    set_skill("strike", 999999+random(999999));
    set_skill("finger", 999999+random(999999));
    set_skill("claw", 999999+random(999999));
    set_skill("blade", 999999+random(999999));
    set_skill("staff", 999999+random(999999));
    set_skill("hammer", 999999+random(999999));
    set_skill("club", 999999+random(999999));
    set_skill("whip", 999999+random(999999));
    
    set_skill("xiuxian-gongfa", 999999+random(999999));
    set_skill("xiuxian-gongfa", 999999+random(999999));
    set_skill("xiuxian-gongfa", 999999+random(999999));
    set_skill("xiuxian-gongfa", 999999+random(999999));
    set_skill("xiuxian-gongfa", 999999+random(999999));
    set_skill("xiuxian-gongfa", 999999+random(999999));
    set_skill("xiuxian-gongfa", 999999+random(999999));
		
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
	set_temp("apply/attack", 1);
	set_temp("apply/defense", 1);
	set_temp("apply/unarmed_damage", 1000000000);
	set_temp("apply/armor", 1000000000);
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
		me->add("yuanbao",10000);
        obj1 = new("/Aboss2/BOX/box1");
        obj1->move(env);
		tell_object(me,sprintf(GRN"你获得了%d点修为，%d点潜能，%d点元神修为，10000灵石，1个世界宝箱，请及时拾取，以免丢失\n"NOR,exp,pot,50000));

	destruct(ob);
}

void random_move()
{
	if (time() - query("born_time") > 180000)
	{
		message_vision("$N急急忙忙的走了。\n", this_object());

		destruct(this_object());
		return;
	}
}