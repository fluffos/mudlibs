// fishroom.c
// 4/16/2000 by lag

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "钓鱼台");
        set("long", @LONG
你走进这里，哇，有好多的人在这里钓鱼呀！不时的传来兴
奋的喊叫声，这肯定又是有谁钓到了大鱼，看到他们忙忙碌碌、
兴奋的样子，你还有什么值得犹豫的，赶快收拾好你的鱼杠开始
钓鱼(diao)吧？里面是一间休息室。
LONG );
        set("exits", ([
//                "enter" : __DIR__"xiuxi",
                "west" : "d/shaolin/hanshui1",
        ]));
	set("item_desc", ([
		"【钓竿】": "你可以拿起来("ZJURL("cmds:diao")ZJSIZE(15)""HIY"钓鱼"NOR")，不想钓了就("ZJURL("cmds:halt")ZJSIZE(15)""HIY"放下"NOR")吧。\n",
	]) );
        set("no_steal", 1);
        set("no_sleep", 1);
        set("no_drop", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_draw", "draw");
        add_action("do_fish", "diao");
}

int do_fish(string arg)
{

	object yr;
	object ob;
	object me = this_player();

        if (me->query("combat_exp") > 1000000) {
                message_vision(HIG"江湖使者的身影突然出现在一阵烟雾之中。\n" +
            HIR "江湖使者冲着$N大喝：出去，别捣乱，这么大了还来钓鱼，你羞不羞呀！\n\n\n"NOR,me);
                    me->move("/d/shaolin/hanshui1");
                     return 1;
                                               } else
  //      if ( !arg || ( arg != "鱼" ) ) return
   //                notify_fail("你要钓什么啊?钓命？\n");


	if (me->is_busy() || me->is_fighting())
		return notify_fail("你还是忙完手头上的事情再说吧。\n");

	message_vision("$N掏出一点鱼饵，仔细的放在钓钩上，轻轻一甩杆，只见水面上荡起了一个个圆圈，中间只有一个白色的浮子在随着水波荡漾。\n", me);
	//yr->add_amount(-1);
	me->start_busy((: call_other, __FILE__, "finishing" :),
		       (: call_other, __FILE__, "halt_finishing" :));
	set_temp("owner", me);
	me->set_temp("fishing", 0);
	me->set_temp("pending/auto_diao",1);
	me->set_temp("fishing_env", environment(me));
	return 1;
}

int finishing(object me)
{
	int stage;

	if (environment(me) != me->query_temp("fishing_env"))
	{
		me->delete_temp("fishing");
		me->delete_temp("fishing_env");
		return 0;
	}

	switch (stage = me->query_temp("fishing"))
	{
	case 1:
		if (random(3))
		{
			tell_object(me,  "浮子轻轻的震动，一上一下的摇晃个不停。\n");
			break;
		}
			tell_object(me,  "浮子忽然剧烈的震荡起来。\n");
		stage++;
		break;

	case 2:
	case 3:
			tell_object(me, "浮子猛然向下一窜，然后又跳出水面\n");
		stage++;
		break;

	default:
		if (random(3))
		{
			if (random(2)) return 1;
			tell_object(me, random(2) ? "水面波澜不惊，没有什么变化。\n"
						  : "微风轻轻的吹，水面荡起一层层细浪，就是没有鱼上钩。\n");
			break;
		}
		tell_object(me,  "忽然你的浮子震动了一下。\n");
		stage = 1;
		break;
	}

	me->set_temp("fishing", stage);
	if(me->query_temp("pending/auto_diao")&&stage==2&&random(3))
	{
		tell_object(me,ZJFORCECMD("draw"));
	}
	return 1;
}

int halt_finishing(object me)
{
	delete_temp("owner");
	me->delete_temp("fishing");
	message_vision("$N收起钓竿，看样子是不想再钓了。\n",  me);
	return 1;
}

void auto_fish(object me)
{
	if(!interactive(me)) return;
	if(me->is_busy())
		call_out("auto_fish",1,me);
	else
		tell_object(me,ZJFORCECMD("diao"));
}

int do_draw(string arg)
{
	string *fish;
	object ob;
	object me;
	int stage;
	int exp;
	int pot;

	me = this_player();


	if (environment(me) != me->query_temp("fishing_env"))
		return 0;

	stage = me->query_temp("fishing");
	if (stage < 2)
	{
		tell_object(me,  "你连忙一拉钓竿，高高的举了起来，却见上面鱼饵依然，还是老样子，只好垂头丧气的重新把杆甩了出去。。\n");
		//message_vision("$N连忙一拉钓竿，高高的举了起来，却见上面鱼饵依然，还是老样子，只好垂头丧气的重新把杆甩了出去。\n", me);
		me->set_temp("fishing", 0);
		return 1;
	}

	fish = environment(me)->query("resource/fish");
	tell_object(me,  "手急眼快，猛地一收钓竿，只见上面挂着一条扭来扭去的顺势一拉杆，登时把一条鱼钓了上来。。\n");
	//message_vision("$N手急眼快，猛地一收钓竿，只见上面挂着一条扭来扭去的顺势一拉杆，登时把一条鱼钓了上来。\n", me);
	delete_temp("owner");
	me->delete_temp("fishing");
	me->delete_temp("fishing_env");
/*
	if (me->query("combat_exp") < 10000000 || me->query("combat_exp") > 180000)
	{
		call_out("auto_fish",1,me);
		return 1;
	}
*/
	exp = 300 + random(100);
	pot = exp / 2;
	me->add("combat_exp", exp);
	if (me->query("potential") < me->query_potential_limit())
		me->add("potential", pot);
		tell_object(me, HIC "\n你获得了" + chinese_number(exp) + "点修为和" + chinese_number(pot) + "点潜能。"NOR"\n");
	//tell_object(me, HIC "你心中微微一动，对武学的理解又深了一层。"NOR"\n");
	call_out("auto_fish",1,me);
	return 1;
}