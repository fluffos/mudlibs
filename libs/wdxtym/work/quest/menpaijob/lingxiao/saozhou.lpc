//yaochu.c 药锄
//海洋II（云起云落）
//星星lywin 2000/6/15

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_wayao", "saoxue");
}

void create()
{
	set_name("大扫帚", ({"sao zhou", "saozhou"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_put",1);
		set("long", "这是一把大扫帚，你可以用它来扫雪（saoxue）。\n");
		set("value", 0);
	}
	setup();
}

int do_wayao()
{
int maxpot;
        object obj;
        object me=this_player();


//&& !environment(me)->query("no_fight")

        if (me->is_busy())
        {
          tell_object(me,"等你忙完了，再扫吧，！\n");
          return 1;
        }
	if( me->is_fighting() )
        {
          tell_object(me,"等打完了，再扫吧，！\n");
          return 1;
        }

        if ((me->query("jing") < 100))
        {  
          tell_object(me,"你的精力不能集中，不可以扫雪！\n");
          return 1;
        }
       else
        if ((me->query("neili") < 100 ))
        {
          tell_object(me,"你的身体状态太差，不能做工！\n");
          return 1;
        }
        else
        if ((me->query("qi") < 100 ))
        {
          tell_object(me,"你的身体状态太差，不能扫雪！\n");
          return 1;
        }
        else
	if (environment(me)->query("short") !=me->query_temp("lingxiaojob"))
        {
          tell_object(me,"不是叫你到这里来扫雪的吧！\n");
          return 1;
        }
        else
	if (!me->query_temp("lingxiao"))
        {
          tell_object(me,"没叫你扫雪的吧！\n");
          return 1;
        }
        else
	if (environment(me)->query("short") ==me->query_temp("lingxiaojob"))
        {
        if (random(30)>28 && !environment(me)->query("no_fight")
        && me->query("combat_exp") >800000)
        {
          tell_object(me,"忽然，附近出来一个江湖客，想对你不利！\n");
                obj=new(__DIR__"mengbing"); 
	        obj->do_copy(me,maxpot,1);
	        obj->set("title",HIY"江湖客"NOR);
	        obj->move(environment(me));
                obj->kill_ob(me);
                obj->set("dex",100);
                me->start_busy(2);
          return 1;
        }
        message_vision(HIC"$N拿起大扫帚开始在地上扫了起来。\n"NOR,me);
        me->add("jing",-me->query("max_jing")/20);
        me->add("qi",-me->query("max_qi")/20);
        me->add("eff_jing",-me->query("max_jing")/20);
        me->add("eff_qi",-me->query("max_qi")/20);
        me->add("neili",-me->query("neili")/20);
        me->start_busy(10);   
        me->apply_condition("lingxiao_busy",4);
       call_out("destroying", 0, me);                       
      	}
}

void destroying(object me)
{   
        message_vision(HIG"雪倒是扫完了，可惜大扫帚却坏了。\n"NOR,me); 
        me->set_temp("lingxiaook",1);
        destruct(this_object());
}