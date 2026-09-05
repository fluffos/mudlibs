// 鹿，采药高了杀了有鹿茸
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
        set_name(CYN+"鹿"+NOR, ({ "lu", "deer" }) );
        set("race", "马类");
        set("age", 4+random(2));
        set("long", "这是一头鹿，正警惕地望着四周。\n");
        set("max_qi", 1000);
        set("qi", 1000);
        set("str", 20);
        set("con", 50);
        set("dex", 30);
        set("limbs", ({ "头部", "前蹄", "后蹄",  }) );
        set("verbs", ({ "hoof" }) );
        set("combat_exp", 80000);
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
		if (killer->query_skill("herbalism",1)>=40)
		{
			ob="obj/remedy/reference"->ObtainDrug("鹿茸");
			ob->move(this_object());
		}
	}
	::die();
}