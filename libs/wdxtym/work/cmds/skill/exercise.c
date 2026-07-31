// exercise.c
#pragma save_binary
#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;
int exercising(object me);
int halt_exercise(object me);

int main(object me, string arg)
{
      
	int exercise_cost;
	mapping map_temp;
	object where;
	seteuid(getuid());
	where = environment(me);
	map_temp = me->query_skill_map();  
	if ((int)me->query_skill("force",1)<10)
		return notify_fail("你还是先学些呼吸吐呐的技巧！\n");
	if (sizeof(map_temp)!=0)
	{
		if(undefinedp(map_temp["force"]))
		{
			return notify_fail("你需要先装备(enable)内功心法吧！！！\n");
		}
		else if((int)me->query_skill(map_temp["force"])<10)
		{
			return notify_fail("你装备的内功心法级别太低了！！！\n");
		}
	}
	else
	{
	     return notify_fail("你需要先装备(enable)内功心法吧！！！\n");
	}
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");
	if( environment(me)->query("no_dazuo") )
		return notify_fail("这里是是非之地，不可久留，别练功了，快走吧！\n");
	if( me->is_fighting() )
		return notify_fail("战斗中不能练内功，会走火入魔。\n");
	if( !arg || !sscanf(arg, "%d", exercise_cost))
	{
		me->set_temp("pending/auto_dazuo",1);
		exercise_cost = me->query("max_neili")/3;
		if (exercise_cost > me->query("qi") / 2) exercise_cost = me->query("qi") / 2;
		if (exercise_cost < 10 ) exercise_cost = 10;
	}
	if (exercise_cost < 10)
		return notify_fail("你的内功还没有达到那个境界！\n");
	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");
	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 60 )
		return notify_fail("你现在精不够，无法控制内息的流动！\n");
	write(HIR"你坐下来开始运行"+HIY"【"+to_chinese(map_temp["force"])+"】"+NOR+"\n"+NOR+"一股"+HIW"内息("+exercise_cost+")"+NOR+"开始在体内流动......"+NOR+"\n");	
	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
	message("vision",me->name()+"盘膝坐下，开始修炼内力。\n",environment(me),({me}));
	tell_object(me,ZJEXIT"northwest:"RED"站起来"NOR":halt\n");
	me->set_temp("dazuo/step", 1);
	me->start_busy(bind((: call_other, __FILE__, "exercising" :), me),
		       bind((: call_other, __FILE__, "halt_exercise" :), me));
	return 1;
}

void auto_dazuo(object me, int exercise_cost)
{
	if(!me||!me->query_temp("pending/auto_dazuo"))
		return;
	if(me->is_busy())
		call_out("auto_dazuo",1,me,exercise_cost);
	else if( (int)me->query("qi") < exercise_cost )
	{
		if (SKILL_D("force/recover")->exert(me, me)&&me->query_skill("force")>120)
		{
			if( (int)me->query("qi") < exercise_cost)
			{
				tell_object(me,"气血不足，休息中。。。\n");
				call_out("auto_dazuo",10,me,exercise_cost);
			}
			else
			{
				call_out("auto_dazuo",1,me,exercise_cost);
			}
		}
		else
		{
			tell_object(me,"气血不足，休息中。。。\n");
			call_out("auto_dazuo",10,me,exercise_cost);
		}
	}
	else
	{
		tell_object(me,"托管中，继续打坐。。。。。。\n");
		tell_object(me,ZJFORCECMD("dazuo "+exercise_cost));
	}
}

int exercising(object me)
{
	int finish;
	int neili_temp,skill_temp_point;
	int exercise_cost = (int)me->query_temp("exercise_cost");
	mapping map_temp;
	object where=environment(me);
	map_temp = me->query_skill_map();  
      if (!interactive(me)) return 0;
	if (exercise_cost < 1)
		return 0;
	if (! me->query_temp("dazuo/step"))
		me->set_temp("dazuo/step", 1);

	if (! living(me))
	{
		me->set_temp("pending/exercise", 0);
		me->delete_temp("dazuo/step");
		return 0;
	}
	finish = 0;

	switch (me->query_temp("dazuo/step"))
      {
      case 1:
		write(YEL"一股热流出现在"+HIR"『百会穴』"+NOR+YEL"你开始运转小周天......"+NOR"\n");
      	break; 
      case 2:
		write(YEL"热流流进"+HIW"『印堂穴』"+NOR+YEL"，又缓缓的开始流动......"+NOR"\n");
      	break;
      case 3:
		write(YEL"热流流进"+HIG"『檀中穴』"+NOR+YEL"，打着旋着又缓缓的流动......"+NOR"\n");
      	break;
      case 4:
		write(YEL"你努力控制暖流缓缓流回"+HIR"『百会穴』"+YEL+"，顿时身体一震。"+NOR"\n");
      	break;
 	default:
		finish = 1;
		break;
	}

	if(!finish)
	{
		me->add_temp("dazuo/step", 1);
		return 1;
	}
	neili_temp=((int)me->query_skill(map_temp["force"]))/5+random(9)+exercise_cost;  //内功等级/5+随即系数+用气=实际效果
	skill_temp_point=random(8)+8; 
	if(where->query("xuanbing"))
 		me->add("qi", (int)exercise_cost/3);
	if(where->query("hanyuchuang"))
		me->add("qi", (int)exercise_cost/2);   
	me->add("qi", -exercise_cost);
	me->set_temp("pending/exercise", 0);
	tell_object(me,"你慢慢睁开眼睛，深深吸了口气，站了起来。\n"
			+HIW"你感觉内功又精进了：\n"
			+HIR"【内力】"NOR" "+HIG"+"+neili_temp+NOR+HIR	+"  【"+to_chinese(map_temp["force"])+"】"NOR" "HIG"exp +"+skill_temp_point+NOR"\n");
	me->improve_skill(map_temp["force"],skill_temp_point);
	me->add("neili", neili_temp);
	if(me->query_temp("pending/auto_dazuo"))
		call_out("auto_dazuo",1,me,exercise_cost);
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else
	{
/*
if ( me->query_neili_limit()-100 > (me->query_skill("force", 1) + me->query_skill("force")/5) * 10)
     neili_limit1=me->query_neili_limit()-100;
else neili_limit1=(me->query_skill("force", 1) + me->query_skill("force")/5) * 10;
*/
		if ((int)me->query("max_neili") >= me->query_neili_limit() )
		{
			write("你的内力修为似乎已经达到了瓶颈。\n");
			me->set("neili", (int)me->query("max_neili")*2);
			return 0;
		} 
		else if ((int)me->query_skill("linji-zhuang",1) == 100 &&(int)me->query("max_neili") == 500)
		{
			me->add("max_neili", 100);
			me->set("neili", (int)me->query("max_neili"));
			write("你只觉丹田处一股热流涌向全身，有着说不出来舒服得感觉。不知不觉中你已经练成了临济十二庄的天字庄。\n");
			return 0;
		}
		else if ((int)me->query_skill("linji-zhuang",1) == 300 &&(int)me->query("max_neili") == 1000)
		{
			me->add("max_neili", 200);
			me->set("neili", (int)me->query("max_neili"));
			write("你只觉你的内息游遍了你全身，仿佛容入了天地之间，你已经融会贯通了临济十二庄的地字庄，已经可以(yun tiandi)了。\n");
			return 0;
		}
		else
		{
			me->add("max_neili", 3);
			me->set("neili", (int)me->query("max_neili"));
			write(""WHT"﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎﹎"NOR"\n");
			write(HIR"恭喜:"+NOR+"你的"+HIG"【内力上限】"+NOR+"增加了！"NOR"\n");
			write(""WHT"﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊"NOR"\n");
			return 0;
		}
	}
}
int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->delete_temp("dazuo/step");
	me->set_temp("pending/exercise", 0);
	message_vision("$N将内息压回丹田，缓缓睁开了眼睛！\n", me);
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : exercise [<耗费「气」的量> 必须多于 10]
运气练功，控制体内的气在各经脉间流动，藉以训练人体肌肉骨骼的耐
力、爆发力，并且用内力的形式将能量储备下来。
HELP
	);
	return 1;
}
