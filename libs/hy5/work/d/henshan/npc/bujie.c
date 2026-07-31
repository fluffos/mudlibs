// yanji.c
#include <ansi.h>;
inherit NPC;

int ask_wu();
void create()
{
	set_name("不戒", ({ "bu jie", "bujie" }));
	set("title", HIR"负心薄幸 好色无厌"NOR);
	set("gender", "男性");
	set("long", "仪琳之父，哑婆婆之夫。好色，逻辑怪异，武功高强！\n");
	set("age", 45);

	set("int", 20);
	set("con", 20);
	set("str", 20);
	set("dex", 20);
	set("per", 10);
	
	set("qi", 6000);
	set("max_qi", 6000);
	set("jing", 6500);
	set("max_jing", 6500);
	set("max_neili", 63500);
	set("shen_type", -1);

	set("combat_exp", 3500000);
	set("attitude", "heroism");
       set("max_neili",20000);
        set("neili",20000);
        set("max_qi",19800);
        set("qi",19800);
	set_skill("unarmed", 330);
	set_skill("dodge", 330);
	set_skill("parry", 360);
	set("neili", 33500);
	set_skill("force", 360);
	set_skill("blade", 360);
	set_skill("hujia-daofa", 360);
	map_skill("blade", "hujia-daofa");
        set_temp("apply/attack", 180);
        set_temp("apply/defense", 180);
        set_temp("apply/armor", 520);
        set_temp("apply/damage", 520);

	set("chat_chance", 40);
	set("chat_msg", ({
		(: random_move :),
	}));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.huanying" :),
                (: perform_action, "blade.cang" :),
                	(: perform_action, "blade.lian" :),
                		(: perform_action, "blade.xian" :),
                			(: perform_action, "blade.zhui" :),
		            (: random_move :),
        }) );


	setup();
	add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	who->set_temp("bujie",1);
	::die();
}