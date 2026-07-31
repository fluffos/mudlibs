// heaven_soldier.c


#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"

void backattack();
void create()
{

	set_name(HIG"护法弟子"NOR, ({ "dizi", "guard" }) );
	set("long", "这是一位专门担任保护之责的弟子。\n");
	set("attitude", "friendly");


	set("max_neili", 10000);
	set("neili", 10000);
	set("max_jing", 5000);
	set("max_qi", 5000);
	set("str", 40);
	set("dex", 60);

	set("combat_exp", 2000000);
	set_skill("sword", 170);
	set_skill("parry", 170);
	set_skill("dodge", 170);
       set("str", 33);
        set("con", 36);
        set("int", 30);
        set("dex", 33);
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
	set_skill("taiji-shengong", 300);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 300);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("array",100);
	set_skill("taoism", 250);
	set_skill("blade", 150);
	set_skill("shiren-jianfa", 150);
	set_skill("shiren-quanfa", 150);
	set_skill("wuxing-dun", 150);
	map_skill("unarmed", "shiren-quanfa");
	map_skill("parry", "shiren-jianfa");
	map_skill("blade", "shiren-jianfa");
	map_skill("dodge", "wuxing-dun");
	map_skill("force", "taiji-shengong");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 150);
        set("eff_qi", 4500); 
        set("qi", 4500); 
        set("max_qi", 4500); 
        set("eff_jing", 4500); 
        set("jing", 4500); 
        set("max_jing", 4500); 
        set("eff_jingli", 4000); 
        set("neili", 5000); 
        set("max_neili", 5000);
	setup();

	//carry_object("/quest/weiguo/japan/obj/japanblade")->wield();
	//carry_object("/clone/cloth/male3-cloth")->wear();	
//initlvl(300,26);

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
	object owner;
	message("vision",
		 name() + "说道：随时谨听召唤！\n\n"
		+ name() + "闪了闪就消失不见了。\n" , environment(),
		this_object() );
        if(objectp(owner=this_object()->query("possessed")))
		owner->add_temp("number",-1);
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i;
	object *enemy;
        who=this_player();

        
        who->apply_condition("zdizi_busy",8);
        level=who->query("combat_exp");
        set("no_drop",1);
        set("no_get",1);
	set("double_attack", who->query("double_attack"));
	set("szj", who->query("szj"));

	set("str", (who->query("str") > 60 ? 60 : who->query("str")));
	set("int", (who->query("int") > 60 ? 60 : who->query("int")));
	set("con", (who->query("con") > 60 ? 60 : who->query("con")));
	set("dex", (who->query("dex") > 60 ? 60 : who->query("dex")));
	set("kar", (who->query("kar") > 60 ? 60 : who->query("kar")));
	set("combat_exp", (int)who->query("combat_exp") / 4);
	set("max_neili", (int)who->query("max_neili") /4);
	set("neili", query("max_neili"));
	set("max_qi", (int)who->query("max_qi")/3);
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("max_jing", (int)who->query("max_jing")/3);
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("food", (query("str") + 10) * 10);
	set("water", (query("str") + 10) * 10);
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			fight_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->fight_ob(this_object());
		}
	}
	set_leader(who);
	set("possessed",who);
}
void backattack()
{
	int i;
	object owner, *enemy;
	if(objectp(owner=this_object()->query("possessed")))
	{
		enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->fight_ob(enemy[i]);
                        enemy[i]->fight_ob(owner);
                }
        }

	}

}

void die()
{
	object owner;
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("number",-1);
	backattack();
	::die();
}
