// yitiantulong.c 倚天屠龙功之[倚天屠龙]。
// by yfeng 2000.1.27

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int		ap,dp,damage,improve;
	string msg;
	object weapon = me->query_temp("weapon");
	object weapon1;
	int cost = me->query_skill("yitian-tulong", 1);
	
	if( !target ) target = offensive_target(me);
	if( !target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("「倚天屠龙」只能对战斗中的对手使用。\n");
	if(!living(target))
		return notify_fail("对付不能动的人也要用「倚天屠龙」？\n");
	if(!weapon || weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，如何使得「倚天屠龙」？\n");
        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"你已经在默运流云水袖神功了。\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("你已经在运同归剑了。\n");
      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
      if( me->query_temp("jingang")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");

        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运护体神功中了。\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");
       if(me->query_temp("wdpowerup") )
       return notify_fail("你现在正在使用「五毒神功」的绝技。\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("你正在使用五毒追魂钩之「乱披风」\n"); 

       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技。\n"); 

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("你已经在掌刀的运功中。\n");

	if(me->query_temp("yttl/yttl"))
		return notify_fail("你刚使用完「倚天屠龙」，歇会再说吧。\n");
	if( (int)me->query_skill("yitian-tulong", 1) < 120 )
		return notify_fail("你的倚天屠龙功不够娴熟，不会使用「倚天屠龙」。\n");
	if( me->query("neili") <= 400+cost*3 )
		return notify_fail("你的内力不够！\n");
	if( me->query("jing") <= 120+cost*2 )
		return notify_fail("你的精不够！\n");
	if( me->query("max_neili") < 1200)
		return notify_fail("你的内力修为不够，无法使用「倚天屠龙」。\n");
	if(me->query("jing")<100+cost)
		return notify_fail("你现在精神不好，无法使用「倚天屠龙」。\n");
	if(me->query_temp("combat_yield"))
		return notify_fail("你不出剑，何以使得「倚天屠龙」？\n");
	if (me->query_skill_mapped("sword") != "yitian-tulong")
		return notify_fail("你现在无法使用「倚天屠龙」。\n");
	if (me->query_skill_mapped("dodge") != "tiyunzong")
        return notify_fail("你必须使用「梯云纵」绝技作为轻身术，方可使出「倚天屠龙」。\n");   
    if( (int)me->query_skill("tiyunzong",1) < 120 )
    	return notify_fail("你的梯云纵不够娴熟，无法使用「倚天屠龙」！\n");
    if( (int)me->query_dex() < 28 )
    	return notify_fail("你的身法太低，不能使用「倚天屠龙」！\n");
    if( (int)me->query_skill("dodge",1) < 120 )
    	return notify_fail("你的基本轻功太差，身体笨拙，不能使用「倚天屠龙」！\n");
    if( me->query_temp("zong")   )
      return notify_fail("你正在使用「梯云纵」！\n");
	if(userp(me))
	{
		if( (int)me->query_skill("taiji-shengong", 1) < 140 )
			return notify_fail("你的内功修为不够，无法使用「倚天屠龙」。\n");
		if( me->query_skill_mapped("force") != "taiji-shengong")
			return notify_fail("你所用的内功无法摧动「倚天屠龙」的运行！\n");
	}
	message_vision(HIW"\n$N吸一口气，猛地里双脚一撑，提身而起。身形纵起丈余，跟着使出「梯云纵」绝技，右脚在空中凭空一撑，左脚紧跟着在右脚上一借力，又纵起两丈！\n"NOR,me);
	improve = (int)me->query_dex() * 2;
	me->add_temp("apply/dodge", improve);
	me->add_temp("apply/attack",improve/2);
    me->set_temp("zong",1); 
    me->set_temp("yttl/yttl",1); 
    me->receive_damage("neili", (350+(int)me->query_skill("tiyunzong",1)/10));    
	call_out("remove_effect",30+random(30),me,improve);
	ap = me->query_skill("sword")*me->query_skill("force")*me->query_skill("dodge")/10+me->query("combat_exp");
    dp = target->query_skill("parry")*target->query_skill("force")*target->query_skill("dodge")/10+target->query("combat_exp");
    damage=me->query_skill("yitian-tulong",1)+me->query_skill("taiji-shengong",1)+me->query_skill("tiyunzong",1);
    weapon1=target->query_temp("weapon");
    if(ap*2/3+random(ap/3)>dp/2+random(dp/2))
    {
    	me->start_busy(1);
        target->start_busy(3);            
		msg=HIC"\n只见$N手中$w"+HIC"看准$n，嗤嗤嗤几声，剑光闪过，隐约呈现一个「武」字。\n";
		msg+=HIR"$n眼前一花，已看不出$N的招式，";
		if(weapon1)
			msg+="慌忙间将手中"+weapon1->name()+HIR"挥舞开来，护住自己的前心。\n\n";
		else 
			msg+="身形左闪右避，渐感不支。\n\n";
		msg+=HIC"$N一个字写完，身子便要落下。只见$P左手挥出，$w"+HIC"在握，倏地一翻，\n";
		if(weapon1)
			msg+=HIC"只听「当」的一声，$w"+HIC"在$n的"+weapon1->name()+HIC"上一点，支住身子的重量，";
		else
			msg+=HIC"只听「噗」的一声，$w"+HIC"正好刺进$n的左肩，同时止住下坠的身形，";
		msg+="借力而起，右手跟着又写了个「林」字！\n这两个字的一笔一划，包含的阴阳刚柔、精神气势，龙飞凤舞，笔力雄健，虽是一剑一掌，却有如快剑长戟，森然相同。 \n";
		msg+=HIR"$n再也抵挡不住$N的攻势，「砰」的一声，这一掌正中$n胸口，$n的身子却象断了线的风筝一般，向后倒飞出去。\n"NOR;
		msg=replace_string(msg,"$w",weapon->name());
		message_vision(msg,me,target);
		target->receive_damage("qi",damage*(1+random(3)));
		me->receive_damage("neili",cost*2);
	    COMBAT_D->report_status(target);
		msg=HIC"\n$N两个字写罢，跟着又写「至」字，「尊」字。越写越快，但见剑光闪烁，或如灵蛇盘腾，或如猛兽屹立\n，飘风骤雨惊飒飒，落花飞雪何茫茫。恍恍如闻鬼神惊，时时只见龙蛇走。须臾间二十四字一齐写毕。\n";
		if(ap*2/3+random(ap/3)>dp/2+random(dp/2))
		{
	    	msg+=HIR"这二十四字一气呵成，二十四招一气贯通，$n步法越来越混乱，左支右拙，身上已不知中了多少剑。\n"NOR;
			target->receive_wound("qi",100+damage);
			me->receive_damage("neili",100+cost);
			message_vision(msg,me,target);
			COMBAT_D->report_status(target);
			message_vision(HIW"\n$N写到「锋」字的最后一笔，"+weapon->name()+HIW"在地面上一荡，翻身落下，轻轻巧巧地站定。\n"NOR,me,target);
	    	return 1;
		}
		message_vision(msg,me,target);
		message_vision(CYN"怎奈$N看得真切，早已退出你的招数之外！\n"NOR,target);
		me->start_busy(2);
		return 1;
	}
	message_vision(CYN"$n一惊非同小可，不及思索，一阵快攻，逼得$N的招式无法使出！\n"NOR,me,target);
	me->start_busy(3);
	return 1;			
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dodge", - improve);
      me->add_temp("apply/attack", - improve/2);
      me->delete_temp("zong");
      me->delete_temp("yttl/yttl");
      
}
