// yaoguo.c
// by augx@sj  2/28/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"熬药锅"NOR, ({ "aoyao guo" , "yao guo" , "guo" }));
	set_weight(1000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "口");
		set("long",YEL"这是一口日夜不停的熬药的锅子。\n"NOR+
"你可以用它来提炼(tilian)药材：tilian 药材\n");
		set("value", 3000);
		set("no_get", 1);
	}
	setup();
}

void init()
{
	add_action("do_tilian","tilian");
}

int do_tilian(string arg)
{
	object me = this_player() ,obj,obj2,weapon;
	int delay,level,time;
	
	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
	if (me->is_fight()) return notify_fail("你正忙着呢！\n");
	if (!arg) return notify_fail("你要提炼什么？\n");
	if (!objectp(obj = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");
	obj = present(obj->query("id"), me);
	if (!objectp(obj2 = present(arg+" 2", me)))
		return notify_fail("你必须用两份"+obj->query("name")+"来提炼药材。\n");
	if( !(int)obj->query("shengcai") || !(int)obj->query("level") 
	 || !(int)obj2->query("shengcai") || !(int)obj2->query("level")
	 || obj->query("id") != obj2->query("id") )
		return notify_fail("在这里只能用两份同类的药材原料来提炼药材。\n");
	if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="yao chui" )
		return notify_fail("你必须装备药锤才能来提炼药材。\n");
	if ( !weapon->query("worker_tool"))
		return notify_fail("你必须装备药锤才能来提炼药材。\n");	
	if ( !wizardp(me) && (time()<(int)me->query("worker/tilian")) )
		return notify_fail("你刚刚提炼结束，感觉过于劳累！\n");		

	time = time()- me->query("pk_time");
	if ( time < 432000)
		return notify_fail("你目前的状态无法提炼。\n");

	level = (int)me->query_skill("tilian",1);
	if ( level<1 )
		return notify_fail("你根本就不会提炼药材！\n");
	if( level < obj->query("need_lvl") )
		return notify_fail("你的提炼技能等级不够！\n");

	message_vision(HIR"$N开始用药锤捣烂"+obj->query("name")+HIR"，然后放到熬药锅里开始提炼药材......\n"NOR, me);
	delay = 3 + random(5);
	if (wizardp(me) && (int)me->query("env/test")) delay = 2;
	me->start_busy(delay+1);
	obj->set_level( (obj->query("level")+obj2->query("level"))/2 );
	call_out("tilian_finish",delay*2-1,me,obj);
	destruct(obj2);
	return 1;
}

void tilian_finish(object me,object obj)
{
	object tools;
	int level,i,improve;
	
	if(!objectp(me) || !userp(me) || !objectp(obj)) return;	
	me->start_busy(-1);
	me->interrupt_me();
	tools = me->query_temp("weapon");
	level = (int)me->query_skill("tilian",1);
	if(level>390) level = 390 + (level-390)*11;
	
	message_vision(HIY"$N累的大汗淋漓，把提炼好的药材从滚烫的熬药锅里拿出来。\n"NOR, me);
	if ( objectp(tools) && tools->query("id")=="yao chui" )
		tools->use();
		
	i = obj->query("need_lvl");
	if(i<80)       i = 80;
	else if(i<160) i = 160;
	else if(i<240) i = 240;
	else if(i<320) i = 320;
	else if(i<360) i = 360;
	else if(i<390) i = 390;
	else           i = 500;
	i = 100 - (level - i)/2;
	if(i>200) i = 200;
	if(i< 10) i = 10;
	improve = me->query_int(1) * i/100;
	
	i = obj->query("need_lvl");
	if(i<80)       { i = 80;  if(level>150) level=150; }
	else if(i<160) { i = 160; if(level>250) level=250; }
	else if(i<240) { i = 260; if(level>350) level=350; }
	else if(i<320) { i = 350; if(level>450) level=450; }
	else if(i<360) { i = 420; if(level>500) level=500; }
	else if(i<390) { i = 500; if(level>500) level=500; }
	else           { i = 750; if(level>500) level=500; }
		
	if( random(level+i) > i ) {
		me->improve_skill("tilian", improve*7/3);
		if ( environment(me)->query("no_zhiye")
		 || me->query_temp("user_type") == "worker") {
			me->add("combat_exp", random(improve)/5);
			me->add("potential", random(improve)/10);
		}
		obj->change_state();
		obj->set_level( (obj->query_level()+me->query_skill("tilian",1))/2 );
		message_vision(HIC"$N拿到一份"+obj->query("name")+"。\n"NOR, me);
	}
	else {
		me->improve_skill("tilian", improve*2/3);
		if ( environment(me)->query("no_zhiye")
		 || me->query_temp("user_type") == "worker") {
			me->add("combat_exp", random(improve)/9);
			me->add("potential", random(improve)/15);
		}
		message_vision(HIC"但是$N却发现从熬药锅里拿出来的药材已经完全烤焦了。\n"NOR, me);
		destruct(obj);
	}
	if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
		me->set("potential" , me->query("max_pot", 1) );
	me->set("worker/tilian",time()+3+random(5));
}
