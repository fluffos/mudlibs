// 朱三太子的线人
// created by Zine 30 Sep 2010

inherit NPC;
#include <ansi.h>
#include <random_name.h>

void create()
{
	set_name(get_rndname(), ({get_rndid(), }));
	set("gender", "男性" );
	set("long", "一个一脸菜色的家伙，目光毫无神采。\n");
	set("str", 20);
	set("int", 20);
	set("dex", 20);
	set("kar", 20);       
	set("qi", 100);
	set("max_qi", 100);
	set("jing", 100);
	set("max_jing", 100);
	set("eff_jingli", 10);
	set("neili", 10);
	set("max_neili", 10);
	set("jiali", 200);
	set("shen_type", 1);
    set("env/wimpy", 1);
	set("uni_target",1);
	set("combat_exp", 10000);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/sword/qingfeng")->wield();
	call_out("dest",10,this_object());
}

void init()
{
	object me;
	object ob=this_object();
	int i;
	int exp,exp2,lv;
	object* allob=all_inventory(environment());
	tell_room(this_object(),this_object()->query("name")+"从暗地里地冲了出来。\n");
	for (i=0;i<sizeof(allob);i++)
	{
		if (allob[i]->query("id")==ob->query("attack"))
		{
			me=allob[i];
		}
	}
	if (!me)
	{
		destruct(this_object());
	}
	else
	{
	lv=500;
	exp = me->query("combat_exp");
	exp2=exp*10;
	while (lv*lv*lv<exp2)
	{
		lv=lv+10;
	}
	ob->set_skill("dodge",lv*11/10);
	ob->set_skill("parry",lv*11/10);
	ob->set_skill("force",lv*11/10);
	ob->set_skill("claw",lv*11/10);
	ob->set_skill("longfeng-xiang",lv*11/10);
	ob->set_skill("bixue-xinfa",lv*11/10);
	ob->set_skill("kuihua-zhua",lv*11/10);
	ob->set_skill("kuangfeng-jian",lv*11/10);
	ob->set_skill("sword",lv*11/10);
	ob->map_skill("force", "bixue-xinfa");
	ob->map_skill("dodge", "longfeng-xiang");
	ob->map_skill("claw", "kuihua-zhua");
	ob->map_skill("parry", "kuihua-zhua");
	ob->map_skill("sword", "kuangfeng-jian");
	ob->prepare_skill("claw", "kuihua-zhua");
	ob->set("max_qi", me->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("max_jing", me->query("max_jing"));
	ob->set("jing", ob->query("max_jing"));
	ob->set("max_neili", me->query("max_neili"));
	ob->set("neili", ob->query("neili"));
	COMBAT_D->do_attack(ob, me, query_temp("weapon"), 1);
	tell_room(environment(),this_object()->query("name")+"一闪身就不见了。\n");
	destruct(this_object());
	}
}

int dest()
{
	tell_room(environment(),this_object()->query("name")+"一闪身就不见了。\n");
	destruct(this_object());
	return 1;
}

