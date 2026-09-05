// mayue.c
// Made By:pingpang
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(BLK"黑鹰"NOR,({"hei ying","ying"}));
	set("race", "野兽");
	set("age", 1);
	set("long", "一只凶狠的黑鹰。\n");
	set("limbs", ({ "头部", "身体", "前腿", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("combat_exp",15000);
	set("str",30);
	set("max_qi",500);
	set("chat_chance", 50);
	set("chat_msg", ({"呲呲呲呲.......\n",
		(: this_object(), "random_move" :),
	}));
	set_temp("apply/dodge", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 10);

	set("shen_type",-1);
set("score",500);
setup();
}
void init()
{
	object ob;
	::init();
	if(interactive(ob=this_player())&&ob->query("race")!="野兽")
	this_object()->kill_ob(this_player());
}
