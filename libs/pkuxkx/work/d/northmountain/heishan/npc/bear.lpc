// 熊
// Zine@pkuxkx2014

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(YEL+"熊"+NOR, ({ "xiong", "bear" }) );
        set("race", "野兽");
        set("age", 4+random(2));
        set("long", "这是一头熊，经常攻击人类。\n");
        set("max_qi", 10000);
        set("qi", 10000);
        set("str", 55);
        set("con", 55);
        set("dex", 30);
        set("limbs", ({ "头部", "身", "前爪","后爪"  }) );
        set("verbs",({"claw","bite"}));
        set("combat_exp", 110000);
        setup();
}
void die()
{
	object killer,ob;
	if(killer=get_damage_origin_object())//无伤害来源
	{
		if (killer->query_skill("herbalism",1)>=40)
		{
			ob="obj/remedy/reference"->ObtainDrug("熊胆");
			ob->move(this_object());
		}
	}
	::die();
}

void init()
{
	if (userp(this_player())) kill_ob(this_player());
	::init();
}