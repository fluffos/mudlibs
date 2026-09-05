#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE; 

void create()
{
	set_name("骏马", ({ "horse", "ma" }) );
        set("race", "野兽");
        set("age", 4);
        set("long",@LONG
	这是一匹高头大马，毛色光亮，虽然不是日行千里，夜行八百的宝马，
但也是一匹可以用来代步的良驹。
LONG);
        set("limbs", ({ "头部", "身体","前腿", "后腿", "尾巴" }) );
        set("verbs", ({ "bite", "hoof" }) );

        set("attitude", "peaceful");
        set("str",200);
        set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("jing",4000); 
	//set("max_neili",4000);
        set("max_qi", 2000);
	set("eff_qi", 2000);
	set("qi", 2000);
	//set("jiali",150);
	set("combat_exp",100);

	set_skill("dodge",400);
        set_skill("move",300);
	set_skill("unarmed",150);

	set("times",0);
	set("max_times",200);

	set("mout1","骑着马往");
	set("mout2","奔去。\n");
	set("min","骑着马威风凛凛地赶了过来。\n");
	
	set("shen_type",1);set("score",200);setup();
}

void init()
{
	add_action("do_ride","ride");

}                 

int do_ride(string arg)
{
	object ma,me;

	ma=this_object();
	me=this_player();
        if (me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("你现在正忙着呢。\n");

	if( arg=="up" )
	{
		if( ma->query("hoster")==me->query("id") )
		{
			if( me->query_temp("riden") )  return notify_fail(YEL"你已经骑在马上了。\n"NOR);
                        ma->set_leader(me);
	   		me->set_temp("riden",1);
	   		message_vision(YEL"$N飞身上马，马儿一声嘶鸣举起前腿就想撒蹄儿跑。\n"NOR,me); 
		
		}
		else
			message_vision(RED"$N飞身上马，但是被马掀了下来，重重地摔在地上。\n"NOR,me); 
        me->start_busy(3);

		return 1;
	}
	if(arg=="down")
	{
		if( ma->query("hoster")!=me->query("id") || !me->query_temp("riden") )
			return notify_fail("你又没有骑在马上，下什么马？\n");
		me->delete_temp("riden");
		ma->set_leader(me);
		message_vision(YEL"$N单手一按，跳下马来。\n"NOR,me); 
		return 1;
	}

	return notify_fail(YEL"骑马( ride up ), 下马( ride down ).\n"NOR);
}

