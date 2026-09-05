
#include <ansi.h>

inherit NPC;

void die();

int kill_target();

void create()
{
	set_name("恶龙", ({ "e long", "long","dragon" }) );
	set("race","野兽");
	set("limbs", ({ "头部", "身体", "尾巴","爪子" }) );
	set("verbs",({"bite"}));
	set("age", 1+random(5));
	set("long", "这是一条恶龙，十分狡猾。\n");
	set("combat_exp", 3000);
    set("max_qi",1000);
    set("eff_qi",1000);
    set("qi",1000);
    set("max_jing",1000);
    set("eff_jing",1000);
    set("jing",1000);
    set("max_jingli",1000);
    set("jingli",1000);
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
    set("max_qi", me->query("max_qi")*2);
	set("eff_qi", me->query("max_qi")*2);
	set("qi", me->query("max_qi")*2);
	set("max_jing", me->query("max_qi")*2);
	set("eff_jing", me->query("max_qi")*2);
	set("jing", me->query("max_qi")*2);
	set("max_jingli", me->query("max_qi")*2);
	set("jingli", me->query("max_qi")*2);
	set("max_neili", me->query("max_qi")*2);
	set("neili", me->query("max_qi")*2);
	
}

void unconcious()
{
	die();
    return;
}

int do_perform()
{
    tell_object(this_player(),RED"恶龙无比狡猾，你突然觉得人类所有武学都不适合用在它身上。\n"NOR);
    return 1;
}
void die()
{
	object me = query("uni_target");
	object ob = this_object();
	object pi;
    if(!objectp(me)) return ::die();
	tell_object(me,BLINK+HIY+"恶龙终于被你打死了，几片龙鳞掉落下来，可以交给周处！\n"+NOR);
    pi =new(__DIR__"obj/ling");
    pi->set("owner",me->query("id"));
    me->delete_temp("zc");
    pi->move(me);
    destruct(ob);
    return;
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
		kill_ob(target);
	}
	remove_call_out("kill_target");
	call_out("kill_target",5+random(5));
	return 1;
}

