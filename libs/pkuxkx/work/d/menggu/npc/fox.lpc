// Zine 2012/7/2

inherit NPC;
#include <ansi.h>
#include "/d/menggu/shediao_bonus.h"
void create()
{
        set_name(HIR"火狐狸"NOR, ({ "huo huli", "huli","fox" }) );
        set("race", "野兽");
        set("age", 2+random(3));
        set("long", "这是一只通体火红的狐狸。\n");
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 100);
        set("shen_type",1);set("score",100);setup();
		set("is__firefox",1);
		set("uni_target",1);
        set("chat_chance", 120);
        set("chat_msg", ({
		(:random_move:),
		(:random_move:),
		(:random_move:),
        }) );
		setup();
		call_out("dest",499);
}

int dest()
{
	destruct(this_object());
	return 1;
}

void init()
{
	add_action("do_none","fight");
	add_action("do_none","kill");
	add_action("do_none","hit");
	add_action("do_none","perform");
	add_action("do_none","steal");
	add_action("do_none","throw");
	add_action("do_none","killall");
	add_action("do_none","hitall");
}

int do_none()
{
	object me=this_player();
	if (me->query_temp("mengguquest/hunter/start")&&time()-me->query_temp("mengguquest/hunter/start")<=500)
	{
		tell_object(me,this_object()->query("name")+"灵得很，见你靠近，立即远远跑开了。\n");
		random_move();
		random_move();
		random_move();
		return 1;
	}
	return 0;
}
int over(object me)
{
	int e_reward;
	object ob=this_object();
	object fur=new("/d/menggu/obj/fur");
	
	fur->set("owner",me->query("id"));
	fur->move(environment(ob));
	if (me->query("mengguquest/hunter_finish"))
	{
		return 1;
	}
	e_reward=bonus(me,1400);
	me->add("potential",e_reward);
	user_record(me,e_reward,"fox");
	me->set("mengguquest/hunter_finish",1);
	tell_object(me,HIW"完成蒙古支线任务【火狐狸】，你被奖励了"+chinese_number(e_reward)+"点潜能！\n"NOR);
	destruct(ob);
	return 1;
}