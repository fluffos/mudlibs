#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include "skill.h";
#include <job_mul.h>

string *k_weapon = ({"sword","blade","staff","whip","gun",});
void create()
{
	string weapon;
	weapon = k_weapon[random(sizeof(k_weapon))];

	set_name("粘而帖", ({ "zhan ertie","zhan", "ertie" }));
	set("title","蒙古 中军元帅");
	set("gender", "男性");
	set("no_quest",1);
	set("long", "这是此次负责进攻襄阳的蒙古大军统帅。\n");
	set("age", 35);
	set("str", 30);
	set("int",20);
	set("con",30);
	set("dex",20);
	set("combat_exp", 650000+random(350000));
	set("attitude", "friendly");
	set("max_qi",4000);
	set("max_jing",2000);
	set("neili",4000);
	set("max_neili",4000);
	set("qi",4000);
	set("jing",2000);
	set("eff_jingli",2500);
	set("score", 100);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("cuff", 200);
	set_skill("jingang-quan", 200);
	set_skill("parry", 200);
	set_skill("yijin-jing", 200);
	set_skill("shaolin-shenfa", 200);
	set_skill("blade", 200);
	set_skill("xiuluo-dao", 200);
	set_skill("buddhism", 200);
	set_skill("literate", 200);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "xiuluo-dao");
	map_skill("blade", "xiuluo-dao");
	map_skill("cuff", "jingang-quan");
	prepare_skill("cuff", "jingang-quan");

	setup();
        add_money("gold",1);
	carry_object(BINGQI_D("blade"))->wield();
	carry_object(ARMOR_D("armor"))->wear();
}

void die()
{
	object ob = this_object(),me;
	object ob1;

	int i, exp, pot, shen;

	me = ob->query_temp("last_damage_from");

	if(!me)
		return;

	if( objectp(me)
	 && userp(me)
	 && me->query_temp("gb_job3")){
		me->delete_temp("gb_job3");
		me->delete_temp("gb_job3_enter");
		me->apply_condition("gb_job3",-1);
	}
	else {
		::die();
		return;
	}

	i = me->query_temp("kill_zhongjun");
	if ( i > 6) i = 6;

	exp = 200 + i * 80 + random(400);
	
	exp = me->add_exp_combat(exp,"易大彪","刺杀");
	
	pot = exp/5+random(exp/10);
	shen = exp/2 + pot/2;
	
	me->add( "potential", pot );
	if ( me->query("gb_job2")){
		me->add("job_time/报效国家", me->query("gb_job2"));
		me->delete("gb_job2");
	}
	me->add("job_time/报效国家",1);
		
	if( me->query("potential") > me->query("max_pot") )
        	me->set("potential",me->query("max_pot"));
	me->add( "shen", shen );

    	message_vision( sprintf(HIW "\n好，任务完成了，你得到了"
	    	+ CHINESE_D->chinese_number(exp)
        	+ "点实战经验，"
        	+ CHINESE_D->chinese_number(pot)
        	+ "点潜能和"
       		+ CHINESE_D->chinese_number(shen)
	        + "点正神。\n" NOR),me);

	log_file("job/zhongjun", sprintf("%8s%-10s刺杀敌元帅任务，经验：%4d，潜能：%3d，杀敌：%d，目前经验：%d。\n",
		me->query("name"), "("+me->query("id")+")", exp,pot, i, me->query("combat_exp") ),me);

	if( ob1 = present( "shiwei 3",environment(me)))
		destruct( ob1 );
	if( ob1 = present( "shiwei 2",environment(me)))
		destruct( ob1 );
	if( ob1 = present( "shiwei",environment(me)))
		destruct( ob1 );

	me->set("job_name","刺杀敌元帅");
	me->delete_temp("kill_zhongjun");
	message_vision(HIW"\n你趁着混乱冲出了元军大营。\n"NOR,me);
	me->move("/d/xiangyang/xuanwumen");
	::die();

}

void kill_ob(object ob)
{
	if( present("zhongjun shiwei",environment(ob))){
	    	ob->remove_killer(this_object());
    		remove_killer(ob);
	    	message_vision(CYN"粘而帖大声喊道：来人哪，有人要行刺本帅。\n"NOR, ob);
    		return;
	}
	::kill_ob(ob);
}
