//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;
void create()
{
object ob = this_player();
int lvl = ob->query("qi");
int sklv = to_int(pow(to_float(ob->query("combat_exp")*10),0.333333333)+random(15));

	set_name("马匪",({"ma fei"}));
	set("gender", "男性");
	set("long", "十分强壮的马匪，经常到扬州城内打家劫舍");
	set("per",20);
	set("age", 30);
	set("combat_exp", 1000000+random(3000000));
	set("str", 100);
	set("int", 100);
	set("con", 100);
	set("dex", 100);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 5000000);
	set("max_qi", 5000000);
	set("jing", 100000);
	set("max_jing", 100000);
	set("neili", 100000);
	set("max_neili", 100000);
	set("jiali", 1500);
	set("combat_exp", 5000000);
	set("score", 1500);
    set_skill("force", 1500+random(1500));
    set_skill("unarmed", 1500+random(1500));
    set_skill("dodge", 1500+random(1500));
    set_skill("parry", 1500+random(1500));
    set_skill("sword", 1500+random(1500));
    set_skill("hand", 1500+random(1500));
    set_skill("cuff", 1500+random(1500));
    set_skill("strike", 1500+random(1500));
    set_skill("finger", 1500+random(1500));
    set_skill("claw", 1500+random(1500));
    set_skill("blade", 1500+random(1500));
    set_skill("staff", 1500+random(1500));
    set_skill("hammer", 1500+random(1500));
    set_skill("club", 1500+random(1500));
    set_skill("whip", 1500+random(1500));
    
    set_skill("xiuxian-gongfas", 1500+random(1500));
    set_skill("xiuxian-gongfas", 1500+random(1500));
    set_skill("xiuxian-gongfas", 1500+random(1500));
    set_skill("xiuxian-gongfas", 1500+random(1500));
    set_skill("xiuxian-gongfas", 1500+random(1500));
    set_skill("xiuxian-gongfas", 1500+random(1500));
    set_skill("xiuxian-gongfas", 1500+random(1500));
		
	map_skill("force", "xiuxian-gongfas");
    map_skill("sword", "xiuxian-gongfas");
    map_skill("parry", "xiuxian-gongfas");
    map_skill("unarmed", "xiuxian-gongfas");
    map_skill("dodge", "xiuxian-gongfas");
	map_skill("hand", "xiuxian-gongfas");
    map_skill("cuff", "xiuxian-gongfas");
    map_skill("strike", "xiuxian-gongfas");
    map_skill("finger", "xiuxian-gongfassA");
    map_skill("claw", "xiuxian-gongfas");
	map_skill("blade", "xiuxian-gongfas");
    map_skill("staff", "xiuxian-gongfas");
    map_skill("hammer", "xiuxian-gongfas");
    map_skill("club", "xiuxian-gongfas");
    map_skill("whip", "xiuxian-gongfas");

    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "force.xiuxianb1" :),
		(: perform_action, "force.xiuxianb2" :),
		(: perform_action, "force.xiuxianb3" :),
		(: perform_action, "force.xiuxianb4" :),
		(: perform_action, "force.xiuxianb5" :),
		(: perform_action, "force.xiuxianb6" :),
		(: perform_action, "force.xiuxianb7" :),
		(: exert_function, "force.xiuxiana1" :),
	}));
	set_temp("apply/attack", 20000);
	set_temp("apply/defense", 1000);
	set_temp("apply/unarmed_damage", 20000);
	set_temp("apply/armor", 1000);

    setup();
}

void die()
{
	object me, ob = this_object();
	
	me = ob->query_last_damage_from();
/*	if (userp(me) && me->query("fuben/huanjing/ask_job"))  {
		me->add("fuben/huanjing/kill_1", 1);
		tell_object(me, "你已经杀了"+me->query("fuben/huanjing/kill_1", 1)+"个"+name()+NOR"\n");
	}*/
	return ::die();
}
void unconcious()
{
	die();
}

