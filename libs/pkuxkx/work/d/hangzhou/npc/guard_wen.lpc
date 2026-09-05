// heaven_soldier.c

#include <ansi.h>

inherit NPC;
void backattack();
int leave();

void create()
{

	set_name("大内高手", ({ "body guard", "guard" }) );
	set("long", "这是一位大内高手，专门担任保护之责。\n");
	set("attitude", "friendly");

	set("str", 40);
	set("con", 30);
	set("dex", 25);

	set("combat_exp", 100000);
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
    set_skill("force",70);

	setup();

	carry_object("/clone/armor/cloth")->wear();
    carry_object("/d/beijing/npc/obj/gangjian")->wield();

	call_out("leave",2);
}

int leave()
{
	object owner = this_object()->query("possessed");
	remove_call_out("leave");
	if( environment() && !is_fighting() )
	{
		if(objectp(owner))
		{
			tell_object(owner,
				 name() + "说道：如再有变化，发哨为警！\n\n"
				+ name() + "闪了闪就消失不见了。\n");		    
			owner->add_temp("max_guard",-1);
		}
		destruct(this_object());
	}
	else
	{
		call_out("leave",2);
	}
	return 1;
}

void invocation(object who, int level)
{
	int i;
	object *enemy;
	set("max_qi", level * 5);
	set("qi", level * 5);
	set("eff_qi", level * 5);
	set("max_jing", level * 5);
	set("eff_jing", level * 5);
	set("jing", level * 5);
	set("max_neili", level * 5);
	set("neili", level * 5);
	set("max_jingli", level * 5);
	set("jingli", level * 5);
	set("jiali", level / 4)	;
	set_skill("sword", 70 + random(level/2));
	set_skill("parry", 70 + random(level/2));
	set_skill("dodge", 70 + random(level/2));
	set_skill("unarmed", 70 + random(level/2));
        set("combat_exp", 500000 + random(level/10*level*level));
	tell_object(who,
		 name() + "喝道：大胆！竟敢和朝廷命官过不去！\n" NOR);
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
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        }

	}

}

void die()
{
	object owner;
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
	backattack();
	::die();
}
