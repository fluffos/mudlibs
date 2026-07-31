#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIR"火云邪神"NOR, ({"huoyun xieshen"}));
	set("nickname", "走火入魔");
	set("gender", "无性");
	set("age", 9999);
	set("nolook", 1);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 45000);
	set("max_qi", 45000);
	set("jing", 45000);
	set("max_jing", 45000);
	set("neili", 45000);
	set("max_neili", 45000);
	set("jiali", 200);
	set("combat_exp", 45000);
	set("score", 200);
    set_skill("force", 450+random(450));
    set_skill("unarmed", 450+random(450));
    set_skill("dodge", 450+random(450));
    set_skill("parry", 450+random(450));
    set_skill("sword", 450+random(450));
    set_skill("hand", 450+random(450));
    
    set_skill("riyue-xinfa", 450+random(450));
    set_skill("riyue-guanghua", 450+random(450));
    set_skill("pixie-jian", 450+random(450));
    set_skill("kuihua-shengong", 450+random(450));
    set_skill("xuwu-piaomiao", 450+random(450));
    set_skill("piaomiao-shenfa", 450+random(450));
    set_skill("literate", 450+random(450));
		
	map_skill("force", "kuihua-shengong");
    map_skill("sword", "pixie-jian");
    map_skill("parry", "pixie-jian");
    map_skill("unarmed", "pixie-jian");
    map_skill("dodge", "piaomiao-shenfa");
    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "parry.pi" :),
		(: perform_action, "parry.kuihua" :),
		(: perform_action, "dodge.gui" :),
		(: perform_action, "force.luanwu" :),
		(: perform_action, "kuihua" :),
		(: perform_action, "pi" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	set_temp("apply/attack", 500);
	set_temp("apply/defense", 100);
	set_temp("apply/unarmed_damage", 500);
	set_temp("apply/armor", 100);
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
		me->add("yuanshen/exp",45000);
		me->add("yuanbao",100);
        obj1 = new("/clone/boss/putao1");
	    obj1->set_amount(50);
        obj1->move(env);
        obj1 = new("/clone/vip2/dan_jiuzhuan");
	    obj1->set_amount(25);
        obj1->move(env);
        obj1 = new("/clone/box/chaoji");
        obj1->move(env);
        obj1 = new("/clone/vip2/yuanshen");
	    obj1->set_amount(5);
        obj1->move(env);
		tell_object(me,sprintf(GRN"你获得了%d点修为，%d点潜能，%d点元神修为。从火云邪神身上掉落了100枚灵石，25个九转金丹，50串神奇葡萄，5个元神果，1个火云宝箱，请及时拾取，以免丢失\n"NOR,exp,pot,50000));

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