// yaofang.c by river 98/08/29
#include <ansi.h>
#include <job_mul.h>
inherit ROOM;

void create()
{
	set("short",HIG"药房"NOR);
	set("long", @LONG
这里是一间石室，周围的火把将石室照的灯火通明，石室里面摆满了很多
瓶瓶罐罐，上面都贴好了标签，一瓶瓶玉蜂浆被古墓弟子制成后放在此处。你
能看见几个古墓弟子正在忙碌的干活。
LONG        );

	set("exits", ([
		"west" : __DIR__"fang",
		"north" : __DIR__"shitou",
	]));             

	setup();
}

void init()
{
	add_action("do_make","make");
	add_action("do_make","huo");
}

int do_make(string arg)
{
	object me,ob,name1;
	int exp,pot;
	me= this_player();
	ob= present("feng mi", me);
	name1= me->query("id");
	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");        
	if ( arg =="jiang"){
		if (!me->query_temp("gm_job1"))
			return notify_fail("你还没去采蜜呢，怎么来制玉蜂浆？\n");
		if (!objectp(present("feng mi", me)))
			return notify_fail("你用什么来制成玉蜂浆？\n");
		if (ob->query_temp("gm/make") != name1 )
			return notify_fail("这蜂蜜好象不是你采来的吧？\n");         
		message_vision(HIY"$N仔细地将蜂蜜调和均匀，制成玉蜂浆，放在架上。\n"NOR,me);
		me->delete_temp("gm_job1");

		exp = 90 + random(30);
		exp = me->add_exp_combat(exp,"孙婆婆","古墓蜂巢");
		pot = exp/5+ random(exp/10);
		//me->add("job_time/古墓蜂巢",1);
		//GIFT_D->check_count(me,"孙婆婆","古墓蜂巢");
		//me->add("combat_exp",exp);
						
		if (((int)me->query("potential", 1) + pot) > (int)me->query("max_pot", 1)){
			me->set("potential", (int)me->query("max_pot", 1));
		}
		if(( (int)me->query("potential", 1) + pot) <= (int)me->query("max_pot", 1)){
			me->add("potential",pot);
		}
		call_out("destroying", 1, ob);
		tell_object(me,HIW"你被奖励了："+chinese_number(exp)+"点实战经验和"+chinese_number(pot)+"点潜能。\n"NOR);
		return 1;
	}
	return notify_fail("你想把蜂蜜制成什么啊？\n");
}

void destroying(object ob)
{
        destruct(ob);
        return;
}
