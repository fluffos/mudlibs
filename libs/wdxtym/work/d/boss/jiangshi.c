#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIB"丧尸"NOR, ({"sangshi"}));
	set("nickname", "嗷嗷嗷");
	set("gender", "无性");
	set("age", 9999);
	set("long", 
		"一切都是美利坚众合国的阴谋，大批丧尸袭击扬州城。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("chat_chance", 1);
set("chat_chance",30);
        	 set("chat_msg", ({
		"丧尸：撕裂一切！！！\n",
		"丧尸：嗷嗷嗷！！！ \n",
		"丧尸：血，我要血！！！\n",

	}) );
	set("chat_chance_combat", 1);
	set("chat_msg_combat", ({
		(: perform_action, "strike.xianglong" :),
		(: exert_function, "recover" :),
	}) );
//		set("chat_chance", 60);
//	set("chat_msg", ({
//                (: random_move :),
//        }) );
	set("qi", 25000);
	set("max_qi", 25000);
	set("jing", 25000);
	set("max_jing", 25000);
	set("neili", 25000);
	set("max_neili", 25000);
	set("jiali", 100);
	set("combat_exp", 25000);
	set("score", 200);
	set_skill("cuff", 250);
	set_skill("poyu-quan", 250);

	set_skill("force", 250+random(250));
	set_skill("jiaohua-neigong", 250+random(250));
	set_skill("huntian-qigong", 250+random(250));
	set_skill("unarmed", 250+random(250));
	set_skill("changquan", 250+random(250));
	set_skill("dodge", 250+random(250));
	set_skill("xiaoyaoyou", 250+random(250));
	set_skill("feiyan-zoubi", 250+random(250));
	set_skill("parry", 250+random(250));
	set_skill("staff", 250+random(250));
	set_skill("strike", 250+random(250));
	set_skill("dragon-strike", 250+random(250));
	set_skill("jiaohua-bangfa", 250+random(250));
	set_skill("dagou-bang", 250+random(250));
	set_skill("throwing", 250+random(250));
	set_skill("mantianhuayu-zhen", 250+random(250));
	set_skill("begging", 250+random(250));
	set_skill("checking", 250+random(250));
	set_skill("training", 250+random(250));
	map_skill("throwing", "mantianhuayu-zhen");
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("parry", "changquan");
	map_skill("staff", "dagou-bang");
	map_skill("strike", "dragon-strike");

	prepare_skill("strike", "dragon-strike");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "staff.wugou" :),
		(: perform_action, "staff.ban" :),
		(: perform_action, "staff.chan" :),
		(: perform_action, "strike.leiting" :),
		(: perform_action, "strike.xiang" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "cuff.leidong" :),

	}));
	set_temp("apply/attack", 500);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 500);
	set_temp("apply/unarmed_damage", 500);
	set_temp("apply/armor", 200);

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
//  message("channel:chat", HIC"【保家卫国】听说"HIR""HIC""HIY""+me->query("name")+""NOR""HIC"击败了丧尸，保卫了。\n"NOR,users());

			exp = 250000;
			pot = 250000;
			me->add("combat_exp",250000);
			me->add("potential",250000);
			me->add("yuanshen/exp",1000);
			me->add("guoqing/s1",1);

//        obj1 = new("/clone/good/huoyun/10000");
//        obj1->move(env);
//       obj1 = new("/clone/good/huoyun/20000");
//        obj1->move(env);
			tell_object(me,sprintf(GRN"你获得了%d点修为，%d点潜能，%d点元神修为，以免丢失\n"NOR,exp,pot,500));

	

	destruct(ob);
}