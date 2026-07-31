#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIY"王下御护卫"NOR, ({ "wangx yhw" }));
	set("age", 999999);
	set("gender", "无性");
	set("long", "。\n");
	set("attitude", "peaceful");

	set("str", 350);
	set("int", 350);
	set("con", 350);
	set("dex", 350);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 1000000000);
	set("max_qi", 1000000000);
	set("jing", 1000000);
	set("max_jing", 1000000);
	set("neili", 1000000);
	set("max_neili", 1000000);
	set("jiali", 5000);
	set("combat_exp", 10000000);
	set("score", 5000);
    set_skill("force", 50000+random(5000));
    set_skill("unarmed", 50000+random(5000));
    set_skill("dodge", 5000+random(5000));
    set_skill("parry", 5000+random(5000));
    set_skill("sword", 50000+random(5000));
    set_skill("hand", 50000+random(5000));
    set_skill("cuff", 50000+random(5000));
    set_skill("strike", 50000+random(5000));
    set_skill("finger", 50000+random(5000));
    set_skill("claw", 50000+random(5000));
    set_skill("blade", 50000+random(5000));
    set_skill("staff", 50000+random(5000));
    set_skill("hammer", 50000+random(5000));
    set_skill("club", 50000+random(5000));
    set_skill("whip", 50000+random(5000));

    set_skill("shanggu-mijing", 50000+random(5000));
		
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
		(: perform_action, "force.shanggub4" :),
		(: exert_function, "force.shanggua1" :),
		(: exert_function, "force.shanggua2" :),
		(: exert_function, "force.shanggua3" :),
		(: exert_function, "force.shanggua4" :),
	}));
	set_temp("apply/attack", 150000);
	set_temp("apply/defense", 100000);
	set_temp("apply/unarmed_damage", 150000);
	set_temp("apply/armor", 100000);
	
	if (clonep(this_object()))
	{
	set("chat_chance", 100);
	set("chat_msg", ({ (: random_move :) }));
	set("born_time", time());
	keep_heart_beat();
	}
	setup();

	if (clonep()) 
	{
		set("chat_chance", 50);
		set("chat_msg", ({
			(:NPC_D->random_move(this_object()):),
        }) );
		
		keep_heart_beat();
	}
	
}
	
void init()
{
        object me,ob;
        ::init();
        if ( interactive(me = this_player()) && living(this_object()) )
        {
	if (!(ob = present("killpalyerling", this_player())))          
               {
	       remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
		}
        }
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


		exp = 10000000;
		pot = 10000000;
		me->add("combat_exp",10000000);
		me->add("potential",10000000);
		me->add("yuanshen/exp",1000000);
		me->add("yuanbao",5000);
        obj1 = new("/clone/GMwupin/GMSSS43");
        obj1->move(env);
        obj1 = new("/clone/GMwupin/GMSSS43");
        obj1->move(env);
        obj1 = new("/clone/GMwupin/GMSSS43");
        obj1->move(env);
        obj1 = new("/clone/GMwupin/GMSSS43");
        obj1->move(env);
		tell_object(me,sprintf(GRN"你获得了%d点修为，%d点潜能，%d点元神修为，5000灵石，4个碎片宝箱，请及时拾取，以免丢失\n"NOR,exp,pot,50000));

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