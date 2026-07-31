// /d/dzd/obj/hulu.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("葫芦",({"hulu"}));
	set_weight(100);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("long","这是一个装着冰蚕的葫芦。葫芦外便结了一层白霜,但冷气还是不断从葫芦上冒出来。
听说里边的蚕宝宝可以放(putout),也可以收(putin)哦。\n");
		set("value",200000);
		set("unit","个");
             set("dzd",1);
	}
	setup();		
}

void init()
{
	add_action("do_putout","putout");
	add_action("do_putin","putin");
}

object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int do_putout(string arg)
{
	object target,ob;
	object me = this_player();
	
	if( environment(me)->query("no_fight"))
	 	return notify_fail("这里不准战斗。\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	
	//if(!arg || arg!= "bingcan")
		//return notify_fail("你想干什么？\n");
	
	if( !arg ) 
		target = offensive_target(me);
	else  target = present(arg, environment(me));
	
	if(!target)
		return notify_fail("你想对谁使用冰蚕？\n");	
	if(!target->is_character()) return notify_fail("您老搞笑啊？\n");
	//if( !target ) target = offensive_target(me);
	//if(!target || !target->is_character() || !me->is_fighting(target))
		//return notify_fail("冰蚕只能对战斗中的对手使用！\n");
	if(!living(target))
		return notify_fail("那是活人么？\n");	
	if(me->query_temp("dzd_quest/bingcan_used"))
		return notify_fail("你正在使用冰蚕！\n");
	message_vision(HIW"$N从腰间解下葫芦，将葫芦一抖，已把冰蚕放了出来！\n"NOR,me,target);
	me->set_temp("dzd_quest/bingcan_used",1);
	ob = new(__DIR__"bingcan");
	ob->move(environment(me));
	ob->set_leader(me);
	ob->kill_ob(target);
	return 1;
}

int do_putin(string arg)
{
	object me = this_player();
	object ob;
	//if(!arg || arg != "bingcan")
		//return notify_fail("你想收什么东西？\n");
	ob = present("bingcan",environment(me));
	if(!ob) ob = find_object("bingcan");
	if(!ob && !me->query_temp("dzd_quest/bingcan_used")) 
		return notify_fail("你放过冰蚕么？\n");
	else if(!ob) 
		return notify_fail("你的冰蚕已经死了！\n");	
	message_vision(HIW"$N在地上用药物画了一个黄色的圆圈，将葫芦口慢慢移向圆圈。葫芦口一伸入圈内，那蚕儿嗤的一声，便钻入葫芦。\n"NOR,me);
	me->delete_temp("dzd_quest/bingcan_used");
	destruct(ob);
	return 1;
}