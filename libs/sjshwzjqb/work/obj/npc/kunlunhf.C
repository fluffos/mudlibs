// jingang.c

#include <ansi.h>

inherit NPC;

void create()
{
	object ob1, ob2;
	
	 set_name("雷震子", ({ "leizhen zi" }) );
        set("long", "这是一位天将，专门担任昆仑护法之责。\n");
	 set("attitude", "friendly");
        set("max_gin", 1200);
        set("max_kee", 1200);
        set("max_sen", 1200);
        set("max_mana", 1200);
        set("mana", 1200);
        set("max_force", 1200);
        set("force", 1200);
	 set("str", 40);
        set("cor", 40);
        set("cps", 40);

        set("combat_exp", 800000);
        set_skill("dashen-bian", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("mace", 100);
        set_skill("lingyunbu", 100);

	map_skill("dodge", "lingyunbu");
	map_skill("mace", "dashen-bian");
	map_skill("parry", "dashen-bian");
        setup();

        ob1=carry_object("/d/obj/armor/jinjia");
	ob1->wear();
	ob1->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
        ob2=carry_object("/d/obj/weapon2/mace/mace");
	ob2->wield();
	ob2->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
               HIY + name() + "说道：雷震子奉法主召唤，现在已经完成护法任务，就此告辞！\n\n"
                + name() + "化成一片雷光，消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
                HIB "只听轰！的一声，一团雷光一闪，现出一个身穿金甲的雷震子。\n\n"
                + name() + "说道：雷震子奉法主召唤，特来护法！\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
}
