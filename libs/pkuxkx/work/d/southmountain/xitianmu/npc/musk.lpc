// 麝
// Zine@pkuxkx2014

inherit NPC;
#include <ansi.h>
int deer_stuff()
{
	object *user=all_inventory(environment(this_object()));
	user=filter(user,(:userp:));
	if (sizeof(user)>0)
	{
		tell_room(environment(this_object()),"因为有人在，"+this_object()->name()+"受惊了地跑开了。\n");
		random_move();
	}
	return 1;
}
void create()
{
        set_name("麝", ({ "she", "musk" }) );
        set("race", "马类");
        set("age", 2+random(2));
        set("long", "这是一头麝，正警惕地望着四周。\n");
        set("max_qi", 10000);
        set("qi", 10000);
        set("str", 50);
        set("con", 50);
        set("dex", 30);
        set("limbs", ({ "头部", "前蹄", "后蹄",  }) );
        set("verbs", ({ "hoof" }) );
        set("combat_exp", 100000);
		set("chat_chance", 20);
		set("chat_msg", ({
                (: deer_stuff :),
		}) );
        setup();
}
void die()
{
	object killer,ob;
	if(killer=get_damage_origin_object())//无伤害来源
	{
		if (killer->query_skill("herbalism",1)>=35)
		{
			ob="obj/remedy/reference"->ObtainDrug("麝香");
			ob->move(this_object());
		}
	}
	::die();
}