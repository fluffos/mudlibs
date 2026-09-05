//zuida 八仙醉打
//test by yhzzyahoo1

#include <ansi.h>

inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
 int time;
 time=time();
if(time-me->query_temp("time_lingwu")<10) return notify_fail(HIG"刚领悟，又来？休息一下吧？\n"NOR);
//    if(target!=me) return notify_fail("领悟不需要对象!\n");
  if(me->is_busy()) return notify_fail("你正忙着呢!\n");
  if(!me->is_fighting()) return notify_fail("只有战斗中才能领悟绝招!\n");
 if(me->query("jingli")<50) return notify_fail("你的精力太少，无法领悟!\n");
 if(me->query_skill("zui-quan",1)>1600) return notify_fail("你的醉拳等级已经太高了，无法领悟了!\n");
me->add("jingli",-10);
call_out("upgrade",9,me);
write(HIY"你开始在战斗中用心领悟醉拳的拳法。\n"NOR);
me->set_temp("time_lingwu",time());
return 1;
}
int upgrade(object me)
{
    if (!me) return 1;
    if(!me->is_fighting()) return 1;
if( random(2000)>=1999 && 
    !me->query("zuiquanpf") && 
    me->query_skill("zui-quan",1)>100 &&
    me->query("age")>=18 )
{
	switch(random(11))
		{
		 case 0:
		case 1:
			 if ((!me->query("party_bonus/zuiquanpf")) // 聚会抽奖抽中清醉拳mark的，手动给一个标记，允许其有概率抽中lhzj... by lordstar 20180312
				 &&(me->query("combat_exp")>100000000||me->query("idleapply")||me->query("xiantian/int/map")>2))
			 {
				switch(random(4))
				 {
					case 0:
						 write(HIR"你在战斗中冥思苦想之后,"+BNK"终于悟出醉生梦死这一招!\n"NOR);
						me->set("zuiquanpf",2);

					break;
					case 1:
						  write(HIR"你在战斗中冥思苦想之后,"+BNK"终于悟出醉笑红尘这一招!\n"NOR);
							me->set("zuiquanpf",3);

					break;

					case 2:
						 write(HIR"你在战斗中冥思苦想之后,"+BNK"终于悟出杀气纵横这一招!\n"NOR);
						me->set("zuiquanpf",4);
					break;

					case 3:
						write(HIR"你在战斗中冥思苦想之后,"+BNK"终于悟出醉拳中的必杀之技:醉卧沙场!\n"NOR);
						me->set("zuiquanpf",5);
					break;
				 }
			 }
			 else
			{
			if(me->query("gender")=="男性")
			  write(HIR"你在战斗中冥思苦想之后,"+BNK"终于悟出罗汉醉酒这一招!\n"NOR);
			else
			  write(HIR"你在战斗中冥思苦想之后,"+BNK"终于悟出贵妃醉酒这一招!\n"NOR);
			me->set("zuiquanpf",1);
			}
		break;
		case 3:
		case 4:
		case 5:
		  write(HIR"你在战斗中冥思苦想之后,"+BNK"终于悟出醉生梦死这一招!\n"NOR);
		me->set("zuiquanpf",2);
		break;
		case 6:
		case 7:
		  write(HIR"你在战斗中冥思苦想之后,"+BNK"终于悟出醉笑红尘这一招!\n"NOR);
		me->set("zuiquanpf",3);
		break;
		case 8:
		case 9:
		  write(HIR"你在战斗中冥思苦想之后,"+BNK"终于悟出杀气纵横这一招!\n"NOR);
		me->set("zuiquanpf",4);
		break;
		case 10:
		case 2:
		  write(HIR"你在战斗中冥思苦想之后,"+BNK"终于悟出醉拳中的必杀之技:醉卧沙场!\n"NOR);
		me->set("zuiquanpf",5);
		break;
		}
	return 1;
}
write(HIY"你在战斗中用心领悟了醉拳中的道理，"+MAG"觉得有所收获!\n"NOR);
me->improve_skill("zui-quan",3*random(me->query("dex")));
if(me->query_condition("wannianzui")>0)
{
	write(HIB"凭借万年醉的酒力，你领悟到醉拳更深一层境界...\n"NOR);
	me->improve_skill("zui-quan",random(me->query("dex"))*(1+me->query_skill("zui-quan",1)/150));
}
 return 1;
}

