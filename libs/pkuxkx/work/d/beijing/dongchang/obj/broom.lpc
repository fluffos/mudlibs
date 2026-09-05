//broom.c 扫帚
//相关npc文件 /d/beijing/dongchang/npc/xiaoguizi.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("大扫帚", ({"sao zhou", "zhou"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("no_drop", 1);
		set("no_put",1);
		set("long", "这是一把大扫帚，你可以用它来扫地（saodi）。\n");
		set("value", 0);
	}
	setup();
}

void init()
{
	add_action("do_saodi", "saodi");
}

int do_saodi()
{
				int level, i;
				string *sk;
        object obj, broom;
        object me = this_player();
        broom = this_object();

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
          tell_object(me,"你的精力不能集中，不可以扫地！\n");
          return 1;
        }
        else
        if ((me->query("qi") < 100 ))
        {
          tell_object(me,"你的身体状态太差，不能扫地！\n");
          return 1;
        }
        else
        	
//检查是否是所要求的任务地点
	if (file_name(environment(me)) != broom->query("target_place"))
        {
          tell_object(me, "好像不是叫你到这里来扫地的吧！\n");
          return 1;
        }
        else
//是否接了任务
        if (!me->query_temp("saodi/sao"))
        {
          tell_object(me, "你并没有接到扫地的任务啊！\n");
          return 1;
        }
        else
//高经验玩家必须有限制，防止机器人
	if (file_name(environment(me)) == broom->query("target_place"))
        {
        if (random(9) > 5 && me->query("combat_exp") > 800000)
        {
          tell_object(me,"忽然，附近出来一个刺客，想对你不利！\n");
          obj=new(CLASS_D("lingjiu") + "/jianghuke"); 
          if(!objectp(obj)) 
							tell_object(me, "BUG，请通知巫师。\n");
	        level = obj->do_copy(me,0,1);
	        level = (level * 3) / 4;

	        sk = keys(obj->query_skills());
	        for(i = 0; i < sizeof(sk); i++)
	        obj->set_skill(sk[i], level);
//	        FAMILY_NPC->family_skill(obj, "random", level, random(2));
	        
	        obj->set("title", COLOR_D->random_color(0,0) + "江湖刺客"NOR);
	        obj->move(environment(me));
          obj->kill_ob(me);
          return 1;
        }
//上面为出现杀手叫杀代码。

        message_vision(HIC"$N拿起大扫帚开始在地上扫了起来。\n"NOR,me);
        
//任务，玩家所需的jing,qi和时间
        me->receive_damage("jing", me->query("max_jing")/20);
        me->receive_damage("qi", me->query("max_qi")/20);
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
        message_vision(HIG"你终于扫完了地，随手将大扫帚扔在了一边。\n"NOR,me); 
        me->set_temp("saodi/ok", 1);
        destruct(this_object());
}
