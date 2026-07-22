// 花丛 修炼乐音
// By River@SJ 7.26.2001

inherit ROOM;
#include <ansi.h>

int yueyin = 0;

void create()
{
	set("short", HIR"花丛"NOR);
	set("long", @LONG
你脚踏柔软的青草，走在一条小路上面。四下里树影婆娑，花香扑鼻。这
里几株小树郁郁葱葱，树下一片青草，几簇龙女花开得格外娇艳。空谷幽静，
潭水清澈，这是实在是个演练武功的好地方。
LONG        );

	set("outdoors", "绝情谷");

	set("exits", ([
		"west" : __DIR__"xiaolu",
	]));

	set("no_fight", 1);
	setup();
}

void do_leave(object me)
{
	if(!me) return;
	tell_object(me, HIC"你发现有人在这里修炼武功，还是不打扰为好，于是静静地离开了。\n"NOR);
	me->move(__DIR__"xiaolu");
	message("vision", me->name()+"从"HIR"花丛"NOR"走了过来。\n",environment(me), ({me}));
}

void init()
{
	if(this_player()->query_temp("yueyin/ask") && yueyin == 0)
		call_out("do_wait", 2 + random(2), this_player());
	else if( yueyin > 0)
		do_leave(this_player());
	add_action("do_lian", ({"yanlian", "lianxi", "xiulian"}));
	add_action("do_wubian", "wubian");
}

int do_lian(string arg)
{
	object me, weapon;
	string msg;

	me = this_player();
	weapon = me->query_temp("weapon");

	if(!me->query_temp("yueyin/ask")) return 0;

	if( arg != "yueyin" || !arg)
		return notify_fail("你要练什么呢？\n");

	if(me->query("yueyin",1))
		return notify_fail("你不是已经会在鞭法中融入乐声了吗？ \n");

	if(!weapon || weapon->query("skill_type") != "whip")
		return notify_fail("你手里空空，怎么能弄出乐音来呢? \n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你内力不继，无法继续修炼了。\n");

	if( me->query_temp("yueyin/done"))
		return notify_fail("你刚才的舞鞭动作还没完成。\n");

	me->add_temp("yueyin/lian", 1);

	switch(me->query_temp("yueyin/lian")) {
		case 1:  msg = HIC"\n$N微微一笑，右手一抖，"+weapon->name()+HIC"如矫夭飞舞，好比彩凤朝阳一般划向天际。\n"NOR; break;
		case 2:  msg = HIC"\n$N心中默想，手中"+weapon->name()+HIC"招式源源不绝，"+weapon->name()+HIC"发出噼啪的声音。\n"NOR; break;
		case 3:  msg = HIC"\n$N手中挥动的"+weapon->name()+HIC"发出玎玎声响，声虽不大，却是十分怪异，入耳荡心摇魄。\n"NOR; break;
		case 4:  msg = HIC"\n$N不断催动内力，将一套银索金玲发挥得淋漓尽致，只见鞭舞生风，呼呼作响。\n"NOR; break;
		case 5:  msg = HIC"\n$N舞至酣处，手中"+weapon->name()+HIC"神出鬼没，内力运至鞭梢，"+weapon->name()+HIC"已经能发出比较悦耳的乐声了。\n"NOR; break;
		default: msg = HIC"\n$N随手的一挥，"+weapon->name()+HIC"随着手臂的摆动，翻飞中，发出有节奏的音律。\n"NOR; break;
	}
	message_vision(msg, me);

	me->receive_heal("jing", me->query_con()* 10);
	me->receive_damage("neili", 500);
	message_vision("随着"+weapon->name()+"的挥动，$N定了定神，神情恢复了些许的正常。\n\n", me);
	me->set_temp("yueyin/done", 1);
	return 1;
}

int do_wait(object me)
{
	object *obj, ob = this_object();
	object weapon;
	int i;

        weapon = me->query_temp("weapon");        

	if(!me || environment(me) != ob
	 || !living(me) || me->is_fighting()) 
		return 0;

	if (! weapon || weapon->query("skill_type") != "whip") return 0;

	tell_room(ob, HIW"\n你听了小龙女的指点，来到此僻静处，准备修炼乐音绝技。\n\n" NOR);
	tell_room(ob, HIW"你见此地如此僻静，随意地挥动了下手中的"+weapon->query("name")+HIW"，不经意间发出了点响声。\n"NOR);
	ob->delete("exits");
	obj = all_inventory(ob);
	if(obj)
		for(i=0; i<sizeof(obj); i++) {
			if(obj[i]->query_temp("yueyin/ask")) continue;
			if(!obj[i]->is_character()) continue;
			if( obj[i]->is_corpse()) continue;
			do_leave(obj[i]);
		}

	yueyin = 10;

	me->start_busy(5);
	me->set_temp("yueyin/done", 1);

	call_out("do_wait2", 5+random(5), me, weapon);
	return 1;
}

int do_wait2(object me,object weapon)
{
	object *obj, ob = this_object();
	int i, p;

	if(!me || !userp(me) || environment(me) != ob || me->is_ghost() ){
		remove_call_out("do_over"); 
		call_out("do_over", 5, ob, weapon);
		return 0;
	}

	if (!weapon || weapon->query("skill_type") != "whip") return 0; 

	if( yueyin <= 0) {
		remove_call_out("do_over"); 
		call_out("do_over", 5, me, weapon);
		return 0;
	}

	yueyin--;

	me->start_busy(5);

	if(!living(me)) {
		yueyin = 0;
		me->delete_temp("yueyin");
		me->set_temp("last_damage_from", "无法抵抗乐音迷惑而");
		me->die();
		this_object()->set("exits", ([	"west" : __DIR__"xiaolu",]));
		return 0;
	}

	obj = all_inventory(ob);
	if(obj)
		for(i=0; i<sizeof(obj); i++) {
			if(obj[i]->query_temp("yueyin/ask")) continue;
			if(!obj[i]->is_character()) continue;
			if( obj[i]->is_corpse()) continue;
			do_leave(obj[i]);
		}

	message_vision("\n$N耳中闻着"+weapon->query("name")+"随风发出的声音，有如乐曲，听了几下，不由神情有些恍惚。\n", me);
	me->receive_damage("jing", 200+random(300));
	p = (int)me->query("jing")*100/(int)me->query("max_jing");
	message_vision("( $N"+COMBAT_D->status_msg(p)+" )\n", me);
	me->delete_temp("yueyin/done");

	call_out("do_wait2", 5+random(5), me, weapon);
	return 1;
}

int do_over(object me,object weapon)
{
	yueyin = 0;

	tell_room(this_object(), HIW"\n回荡在花丛间的声音，刹那间消失了，周围又恢复了先前的寂静。\n\n"NOR);
	tell_room(me, WHT"你搽了搽脸上的汗，想起刚才的惊险不由还是有些后怕，你又随手挥动了下手中的"+weapon->query("name")+WHT"。\n"NOR);

	this_object()->set("exits", ([
		"west" : __DIR__"xiaolu",
	]));

	if(!me || !userp(me) || environment(me) != this_object()
	 || !living(me) || me->is_ghost())
		return 0;

	me->start_busy(1);

	if((int)me->query_temp("yueyin/lian") >= 5){
		me->delete_temp("yueyin");
		me->set("yueyin", 1);
		tell_object(me, WHT"你随手的一挥，"+weapon->query("name")+WHT"随着你手臂的摆动，翻飞中，发出有节奏的音律。\n\n"NOR);
		tell_object(me, HIY"恭喜！你学会了乐音绝技！\n"NOR);
		return 1;
	}
	me->delete_temp("yueyin");
	tell_object(me,WHT"可是无论你怎么挥动，除了划过风际的呼啸之声，根本没音律的感觉。\n"+
		"你顿时心灰意冷，颓然而立，觉得自己实在是没有天份，可能永远学不会乐音绝技了。\n"NOR);
	return 1;
}

int do_wubian()
{
	object me=this_player();
	object weapon = me->query_temp("weapon");
	
	if(! me->query("family") || me->query("family/family_name") != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");

	if( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if( me->query_skill("whip", 1) > 100 )
		return notify_fail("看来简单的舞鞭已经对你没有任何帮助了。\n");

	if( me->query("jing") < 30 )
		return notify_fail("你看起来很累，还是去休息一会吧。\n");

	if( !weapon || weapon->query("skill_type") != "whip")
		return notify_fail("你手里没有鞭子，来舞什么啊？\n");

	me->receive_damage("jing", 15 + random(10));
	me->improve_skill("whip", (int)(me->query_int()/2)+(int)(me->query_skill("whip")/4));
	tell_object(me ,WHT"你舞动手中的"+weapon->name()+WHT"，仿佛有了点心得。\n");
	return 1;
}
