//saozhou.c 扫帚
//海洋II（云起云落）
//星星lywin 2000/6/15

#include <ansi.h>
inherit ITEM;
//任务特殊命令
void init()
{
	add_action("do_saoxue", "saoxue");
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

int do_saoxue()
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
        if ((me->query("qi") < 100 ))
        {
          tell_object(me,"你的身体状态太差，不能扫雪！\n");
          return 1;
        }
        else
//检查是否是所要求的任务地点
	if (environment(me)->query("short") !=me->query_temp("lingjiujob"))
        {
          tell_object(me,"不是叫你到这里来扫雪的吧！\n");
          return 1;
        }
        else
//是否接了任务
        if (!me->query_temp("lingjiu/saoxue"))
        {
          tell_object(me,"没叫你扫雪的吧！\n");
          return 1;
        }
        else
//高经验玩家必须有限制，防止机器人
	if (environment(me)->query("short") ==me->query_temp("lingjiujob"))
        {
        if (random(30)>28 && !environment(me)->query("no_fight")
        && me->query("combat_exp") >800000)
        {
          tell_object(me,"忽然，附近出来一个江湖客，想对你不利！\n");
                obj=new(__DIR__"jianghuke"); 
	        obj->do_copy(me,maxpot,1);
	        obj->set("title",HIY"江湖客"NOR);
             obj->set("usename",me->query("name"));
	        obj->move(environment(me));
                obj->kill_ob(me);
          return 1;
        }
//上面为出现，杀手叫杀代码。

        message_vision(HIC"$N拿起大扫帚开始在地上扫了起来。\n"NOR,me);
//任务，玩家所需的jing,qi和时间
        me->add("jing",-me->query("max_jing")/20);
        me->add("qi",-me->query("max_qi")/20);
        me->start_busy(8);   
//减上限，可以对机器的速度做一些控制
       call_out("destroying", 8, me);
	   	return 1;
      	}
}

void destroying(object me)
{   
//任务结束，加上成功标记,并去除任务道具。
        if (!me) return;
        message_vision(HIG"雪倒是扫完了，可惜大扫帚却坏了。\n"NOR,me); 
        me->set_temp("lingjiuok",1);
        destruct(this_object());
}
