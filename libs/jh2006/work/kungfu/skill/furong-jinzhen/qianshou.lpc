// qianshou.c 千手
// By lius 99/8
#include <ansi.h>

inherit	F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
void remove_effect(object target,object	me);

string *xue_name1 =({
"劳宫穴","膻中穴","曲池穴","关元穴","至阳穴","中极穴","承浆穴","肩井穴"});
string *xue_name2 = ({
"百汇穴","幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴"});
string *xue_name3 = ({
"清灵穴","命门穴","风府穴","大雅穴","灵台穴","悬枢穴","气海穴","天突穴"});
 
 int perform(object me,	object target)
{      object weapon = me->query_temp("weapon");
	int p,i,j,z;
	string name1,name2,name3;
	weapon = me->query_temp("weapon");
	name1 =	xue_name1[random(sizeof(xue_name1))];
	name2 =	xue_name2[random(sizeof(xue_name2))];
	name3 =	xue_name1[random(sizeof(xue_name3))];
	if( !target) target = offensive_target(me);
	if( !target || !me->is_fighting(target)	|| !living(target)
		    || environment(target)!=environment(me))
	   return notify_fail("没有战斗，何需消耗如此巨大的内力幻化千手？\n"); 
	if (! present("furong jinzhen",me ))
	   return notify_fail("没有金针，即使幻化千手又有何用?!\n");
	if(!weapon || weapon->query("skill_type") != "throwing"	)
	   return notify_fail("你手中既无暗器，幻化千手也是无用！\n");
	if( (int)me->query_skill("yinyun-ziqi",1) < 150	)
	   return notify_fail("你的氤氲紫气修为不足，无法幻化千手！\n");
	if( (int)me->query_skill("furong-jinzhen",1) < 150 )
	   return notify_fail("你的芙蓉金针等级不够，无法领悟如此高深的武技！\n");
	if( (int)me->query_skill("force", 1) < 150 )
	   return notify_fail("你的基本内功修为不足，还不能意到气随！\n");
	if( (int)me->query_skill("throwing", 1)	< 150 )
	   return notify_fail("你的基本暗器修为不足，不能驾御如此复杂的手法！\n");
	if (me->query_skill_mapped("throwing") != "furong-jinzhen")
	   return notify_fail("不激发芙蓉金针如何使用千手绝技？！\n");
	if (me->query_skill_mapped("parry") != "furong-jinzhen")
	   return notify_fail("不激发芙蓉金针如何使用千手绝技？！\n");
	if( (int)me->query("neili") < 600 )
	   return notify_fail("你的真气不足，不能使用千手绝技！\n");
	if( (int)me->query("max_neili") < 1200 )
	   return notify_fail("你的内力不足，不能使用千手绝技！\n");
	if( (int)me->query("jingli") < 300 )
	   return notify_fail("你的精力不足，不能使用千手绝技！\n");
	if(target->query_temp("qianshou"))
	   return notify_fail("对方已经被金针封住各处大穴，无需再多费手脚了！\n");

i=me->query_skill("furong-jinzhen",1)+me->query_skill("throwing",1)+me->query_skill("force",1);
j=target->query_skill("parry",1)+target->query_skill("dodge",1)+me->query_skill("force",1);
	p = random(i/3);
	z = (i -j)/3;
	if ( z < 3 ) z = 3;
	if ( z > 12 ) z	=12;
      
       message_vision(HIR"\n突然$N一声清啸，手臂连抡，整条手臂象风车般旋转起来，
如同幻化出千万条手臂，已分不出哪是真哪是影！！\n"NOR,me,target);
	 
	 me->add("neili", -500);
	 me->add("jingli", -50);
      if ( random(z) > 10 && me->query_skill("throwing", 1) > 200 && me->query_skill("furong-jinzhen", 1) > 200	){ 
      tell_object(me, MAG"你见一击奏效，压力骤减，当下不再顾虑，着着抢先！！\n"NOR);
      tell_object(target, MAG"激斗中，你突觉"RED+name1+MAG"、"RED+name2+MAG"和"RED+name3+MAG"同时一麻，一身功力顿散，四肢也开始麻木，刹时万念俱灰！！\n"NOR);
	 target->receive_damage("qi", i/3+p);
	 me->start_busy(3);
	 target->start_busy(5);
	 target->set_temp("qianshou", 1);
	 target->set_temp("apply/strength", -(target->query("str", 1)/3));    
	 target->set_temp("apply/dexerity", -(target->query("dex", 1)/3));  
	 target->set_temp("apply/intelligence",	-(target->query("int", 1)/3));	  
	 target->set_temp("apply/constitution",	-(target->query("con", 1)/3));	
	 target->apply_condition("no_perform", i/26);
	 target->start_call_out((:call_other,__FILE__,"remove_effect",target:),i/6); 
	 return	1; }
	 if (random((int)me->query("combat_exp",1)) > (int)target->query("combat_exp",1)/2 && random(i)	> j/3)
       {  if ( random(z) > 5 &&	(int)me->query_skill("throwing", 1) > 180 && (int)me->query_skill("furong-jinzhen", 1) > 180 ){
	tell_object(me,	HIB"你见"+target->name()+"双眉突然深深一蹙，满脸痛楚，显是吃亏不少，顿时精神大振！\n"NOR);
	tell_object(target, HIB"酣战中，你突觉"RED+name1+HIB"和"RED+name2+HIB"同时一麻，血脉顿时为之一塞，你连忙凝神聚气，
气行周天，虽已无碍，却也是弄的额上见汗，知是吃亏不少。\n"NOR);
	     target->receive_damage("qi", i/3+p);	     
	    me->start_busy(3);
	    target->start_busy(3);
	    return 1; }
       else
       switch(random(2)) {
	  case "0":
	   tell_object(me, HIM"你三针连发，不想对方竟只是微微一缓，又纵身扑上，心里暗自迷惑。\n"NOR);
	   tell_object(target, HIM"酣战中，你微觉"RED+name1+HIM"一麻，知是金针所伤，忙凝气冲关，虽伤处还有些疼痛，却已无大碍。\n"NOR);
	   target->receive_damage("qi",	i/3);		 
	  me->start_busy(2);
	  target->start_busy(1);
	  break;
	  case "1":		  {	  
	   me->start_busy(3);
	   me->add("neili", -(100+random(50)));	
	   me->add("jingli", -100);		
	   message_vision(BLU"只见$p身形飘忽，诡异无比的避开了$N所发的数道夺命金光。\n"NOR,me, target);
	    break;}
	 return	1;}
	return 1;}
}

void remove_effect(object target,object	me)
{
      me = this_player();
      if(!target) return;
      target->delete_temp("apply/strength");	
      target->delete_temp("apply/dexerity");  
      target->delete_temp("apply/intelligence");    
      target->delete_temp("apply/constitution");  
      target->clear_condition("no_perform");
      target->delete_temp("qianshou");
      message_vision(WHT"只见$p长吸一口气，“噗噗”从身上逼出三枚金针，抑郁之气顿消。\n"NOR,target);
      tell_object(me,WHT"你顿觉阻塞之苦全消，功行百脉，舒畅无比。\n"NOR);
}
