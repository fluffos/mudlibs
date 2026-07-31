inherit NPC;
#include <ansi.h>
void create()
{
	set_name("侍卫", ({ "shi wei", "shi", "wei" }));
        set("title", RED"皇城侍卫"NOR);
	set("gender", "男性");
	set("age", random(10) + 20);
	set("str", 28);
	set("dex", 30);
	set("long", "他站在那里，的确有说不出的威风。\n");
	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("halberd", 80);
	set_skill("lujia-ji", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);

	map_skill("halberd", "lujia-ji");
	map_skill("parry", "lujia-ji");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("force", 800); 
	set("max_force", 800);
	set("force_factor", 50);

	setup();
	carry_object("/obj/weapon/fangtianji")->wield();
	carry_object("/d/yueyang/npc/obj/tiejia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
