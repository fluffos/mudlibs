// guolin5.c By River 98/09

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"果林"NOR);
	set("long",@LONG
转过山腰，出现一大片果林。果树高大茂盛，枝叶繁密，累累鲜果，鲜嫩
诱人。清风拂叶，沙沙作响，更令这群果随风招摇起舞，送来阵阵果香。但听
密林深处，杜鹃儿间或轻啼。正前方的一棵果树上挂着个蜂巢(fengchao)。
LONG );

	set("outdoors","古墓");

       	set("exits" ,([
		"east" : __DIR__"guoyuan",
       	]));

	set("item_desc", ([
		"fengchao" : "你走近巢边观察，只见蜂巢周围玉蜂正在忙碌的采蜜。\n"
	]));

	setup();
}

void init()
{
	add_action("do_tong","tong");
}

int do_tong(string arg)
{
	object me = this_player();
	object name1=me->query("id");
	object target,ob;
	int i , j = 0;
	mapping fam;        
        
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓派传人，不要再在古墓久留了。\n");
	if ( arg =="fengchao"){
		if ( me->query_temp("gm_job1"))
			return notify_fail("你已经采好蜜了，可以去药房制成玉蜂浆了。\n");
		if ( me->query_condition("gumu_job" ) > 0 )
			return notify_fail("你捅了半天发现蜂巢里什么都没有了。\n");
		if ( me->query("jing") < 15 || me->query("qi") < 20 )
			return notify_fail("你只觉得双手无力，好想去休息一会。\n");         
		if ( !wizardp(me) && me->query("combat_exp") > 35000 )
			return notify_fail("你武功已经够高，采蜂蜜的事就让小弟子们去做吧。\n");
		if ( me->query_temp("gm_fengmi") < 10 + random(5)){
			i = me->query("combat_exp")/100000*18;
			j = me->query_temp("gm_bee");
			if ( j > 2 || random(10) > i || me->query("combat_exp") < 10000 ){
				write("你用力捅着蜂巢，从中挖出了一点蜂蜜。\n");
				me->add_busy(1);
				me->receive_damage("jing",5+random(5));
				me->receive_damage("qi",5+random(10));
				me->add_temp("gm_fengmi", 1);
			}
			else {
				message_vision(HIY"\n突然周围传来一阵嗡..嗡...的响声，$N定睛一看，原来是$N招惹了玉蜂。\n\n"NOR,me);
				target=new(__DIR__"npc/bee2");
				target->set_temp("gm/caimi",name1);
				target->move(environment(me));
				me->add_temp("gm_bee", 1);
				me->add_busy(2);
			}
			return 1;
		}
		me->apply_condition("gumu_job", random(6)+ 4);
		tell_object(me,HIR"你已经采出足够的蜂蜜，可以去制成玉蜂浆了。\n"NOR);
		me->delete_temp("gm_fengmi");
		me->delete_temp("gm_bee");
		me->set_temp("gm_job1", 1);
		ob=new(__DIR__"obj/fengmi");
		ob->set_temp("gm/make", name1);
		ob->move(me); 
		return 1;
	}
	return notify_fail("你胡乱捅了几下，结果什么也没有发生。\n");
}
