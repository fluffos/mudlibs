// city guard 超级巡捕
// by augx@sj   8/31/2001

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

#include <ansi.h>

void create()
{
	set_name("巡捕王", ({"xunbu wang", "xunbu", "guard"}));
	set("title", HIW"金牌"NOR);
	set("gender", "男性");
	set("age", 20 + random(40));
	set("long", "这就是传说中的正义使者，超级高手，工匠的保护神！\n");

	set("combat_exp", 15000000);
	set("meitude","peaceful");
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("max_qi", 90000);
	set("max_jing", 90000);
	set("max_neili", 30000);
	set("neili", 30000);
	set("eff_jing", 20000);
	set("eff_jingli", 20000);
	set("jingli", 20000);
	set("max_jingli", 20000);
	set("jiali", 350);
	
	set_temp("apply/armor", 300);
	set_temp("apply/damage", 150);
	set("no_ansuan",1);
	set("no_bark", 1);
	
	set_skill("strike", 500);
	set_skill("cuff", 500);
	set_skill("dodge", 500);
	set_skill("sword", 500);
	set_skill("force", 500);
	set_skill("parry", 500);
        set_skill("literate", 500);

	set_skill("xuantian-wuji", 500);
	set_skill("taxue-wuhen", 500);
	set_skill("kunlun-zhang", 500);
	set_skill("liangyi-jian", 500);
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("parry", "kunlun-zhang");
	map_skill("strike", "kunlun-zhang");
	prepare_skill("strike", "kunlun-zhang");
	
	set("chat_chance_combat", 85);
	set("chat_msg_combat", ({
		(: perform_action, "diezhang" :),
	}));
                        
	setup();
	this_object()->start_call_out( (: call_other, this_object(), "check", this_object() :), 20);
}       

void die()
{
	::die();
}

void dest()
{
	destruct(this_object());
}

void dokill(object ob)
{
	object me = this_object();
	if(!ob || !userp(ob) || !living(ob)) return;
	set("target",ob);

	message("vision", CYN+me->query("name")+CYN"飞步跑了过来。\n"NOR, environment(), me );
	ob->add_busy(5);
	ob->set("eff_qi", 1000);
	command("look "+ob->query("id"));
	command("say "+ob->query("name")+"，你竟然敢在光天化日之下残害善良百姓！看招！");
	command("follow "+ob->query("id"));
	me->set_temp("kl/dzfail/"+ ob->query("id"), 3);
	me->kill_ob(ob);
	me->start_busy(0);
	command("perform diezhang");
}

int accept_fight(object ob)
{
	return 0;        
}

void check()
{
	object me = this_object();
	object ob = me->query("target");
        
        if( !ob 
	 || !objectp(ob) 
	 || !living(ob) 
	 || environment(ob)!=environment(me) ) {
	 	if( objectp(ob) ) ob->delete_temp("be_guard_kill");
		dest();
		return;
	}
	call_out("check",10);
}
