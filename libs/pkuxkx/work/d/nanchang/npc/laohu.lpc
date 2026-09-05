
#include <ansi.h>

inherit NPC;

void die();

int kill_target();

void create()
{
	set_name("老虎", ({ "lao hu", "hu","tiger" }) );
	set("race","野兽");
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs",({"bite"}));
	set("age", 1+random(5));
	set("long", "这是一只猛虎，身上黄黑花纹斑驳。\n");
	set("combat_exp", 10000000);
	set("random_npc",1);
    set("food",500);
    set("water",500);
	set("uni_target", 1);
	setup();
    
	
	call_out("kill_target",10);
}



void init()
{
	add_action("do_perform", "perform");
}

int do_copy(object me)
{
	if(!objectp(me))
		return 0;
    set("str",me->query("str"));
    set("dex",me->query("dex"));
    set("uni_target", me);
    set("max_qi", me->query("max_qi"));
	set("eff_qi", me->query("max_qi"));
	set("qi", me->query("max_qi"));
	set("max_jing", me->query("max_qi"));
	set("eff_jing", me->query("max_qi"));
	set("jing", me->query("max_qi"));
	set("max_jingli", me->query("max_qi"));
	set("jingli", me->query("max_qi"));
	set("max_neili", me->query("max_qi"));
	set("neili", me->query("max_qi"));
	
}

void unconcious()
{
	die();
    return;
}

int do_perform()
{
    tell_object(this_player(),RED"老虎不是人类，你突然觉得人类所有武学都不适合用在它身上。\n"NOR);
    return 1;
}
void die()
{
	object me = query("uni_target");
	object ob = this_object();
	object laohu2=new(__DIR__"laohu2");

	if(!objectp(me)) return ::die();
	tell_object(me,BLINK+HIY+"老虎渐渐要被你打死，你突然发现，什么老虎？原来竟是人假扮的！\n"+NOR);
    laohu2->set_temp("seeme",me->query("id"));
    laohu2->do_copy(me);
    laohu2->move(environment(this_object()));
    laohu2->kill_ob(me);
    me->kill_ob(laohu2);
	
	::die();	
}





int visible(object ob)
{
    if(query("uni_target") != ob) return 0;
    return 1;
}

int kill_target()
{
	object target = query("uni_target");
	if(objectp(target))
	{
		command("kill "+target->query("id"));
	}
	remove_call_out("kill_target");
	call_out("kill_target",5+random(5));
	return 1;
}

