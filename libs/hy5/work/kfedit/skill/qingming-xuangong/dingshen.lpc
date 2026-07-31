// dingshen.c 定身法

#include <ansi.h>

inherit F_SSERVER;

string get_name(string str)
{
        str="定身法";
        return str;
}

string get_help(string str)                
{
        str="指令：ｃａｓｔ　ｄｉｎｇｓｈｅｎ　ｏｎ　＜攻击对象＞\n"
        +"条件：基本法术>=100\n"
        +"孙悟空的定身法，使对方不能动弹。";
        return str;
}

void free(object target);

int exert(object me)
{
        string msg;
        int success, ap, dp, howlong;
object target;

    string msg1;
    string msg2;
    string msg3;
    string msg4;
    int damage,i;
    i=random(3);

        if( !target ) target = offensive_target(me);

        if((int)me->query_skill("taoism",1) < 100)
                return notify_fail("你还没学会定身法。。。\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你想把谁定住？\n");


           if( !target 
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail(WHT"只能对战斗中的对手使用。\n"NOR);

        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("你无法集中精力！\n");

        me->add("neili", -500);
        me->receive_damage("jing", 10);

        msg = HIC
"$N口中念了句咒文，朝$n一指，大喝一声：定！\n" 
NOR;

        success = 1;
        ap = me->query_skill("taoism");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

        ap = (int)me->query("max_neili");
        dp = (int)target->query("max_neili");
        if( random(ap + dp) < dp ) success = 0;
//here we compared max_mana.

        ap = (int)me->query("neili");
        dp = (int)target->query("neili");
        if( random(ap + dp) < dp ) success = 0;
//here we compare current mana. this is important. you need recover to try again.

        howlong = 0;        
        if(success == 1 ){
                msg +=  HIR "结果$n手足僵硬，果然动弹不得！\n" NOR;
                target->start_busy(7);

//a typical level is 100+100 ->enabled 150, so will "ding" about 1 minute in the best case.
        }           
        else {
                msg +=  HIR "结果$n被吓了一跳！\n" NOR; 
        } 

        message_vision(msg, me, target);

        

        if (success == 0) {
                me->start_busy(3);
                return 1+random(2);
}

if ((int)me->query_skill("qingming-xuangong",1)> 200)
{
        msg1=HIY"$N双手各捻个法诀，再并拢向外一推，大喝道："+HIC"“般若波罗密，风火雷电……打！！” 刹那间，风起云涌，浓云密布，一道闪电自天空中疾闪而下向$n劈去！！！\n";
        msg2=HIR"“轰”的一声打了个正着，"+target->query("name")+"被电得象烟熏猪头一样黑！\n"NOR;
        msg3=RED"你只觉得全身发麻，眼前金星乱冒。。。。\n"NOR;
    message_vision(msg1, me, target);
    ap = me->query_skill("taoism");
    dp = target->query("dodge");
    if( random(ap + dp) > dp) 
    {
       damage = (int)me->query("max_jing") / 10 + random((int)me->query("eff_jing") / 5);
       damage -= (int)target->query("max_jing") / 20 + random((int)target->query("eff_jing") / 20);
       damage=100+damage;
       if (!userp(me) && damage >23000) damage=23000;
       if (damage <100) damage=100;
       if( damage > 0 ) 
       {
           target->receive_damage("qi", damage,me);
           target->receive_wound("qi", damage/2,me);
           tell_room(environment(me),msg2,target);
           tell_object(target,msg3);
           
       }
       else
       {
           msg = "$N的「火识神通」好象没有造成任何伤害！\n";
           me->receive_damage("jing", 10);
       }
    } 
    else
    msg = "但是$n巧妙地躲开了。\n";
    message_vision(msg, me, target);

    if( damage > 0 ) COMBAT_D->report_status(target);	
	
}	 
 
if ((int)me->query_skill("qingming-xuangong",1)> 250)
{
        msg1=HIC"$N身形一转散作七处同时口中念道：“天地无相，万剑归宗，浩天正气，神剑伏魔！！”只见空中出现万点金光向$n射去。。。\n"NOR;

        msg2=RED"只听“嗤嗤”声响不绝，金光射入"+target->query("name")+RED"身体。"+
        target->query("name")+RED"变成了千窗百孔的大筛子！！！\n";
        msg3=RED"你只觉的遍体生风，浑身剧痛。\n"NOR;
    message_vision(msg1, me, target);
    ap = me->query_skill("taoism");
    dp = target->query("dodge");
    if( random(ap + dp) > dp) 
    {
       damage = (int)me->query_skill("qingming-xuangong",1) + random((int)me->query_skill("taoism",1));
          damage=100+damage;
       if (!userp(me) && damage >23000) damage=23000;
       if (damage <100) damage=100;

       if( damage > 0 ) 
       {
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage/2);
           tell_room(environment(me),msg2,target);
           tell_object(target,msg3);
           
       }
       else
       {
           msg = "$N的「火识神通」好象没有造成任何伤害！\n";
           me->receive_damage("jing", 10);
       }
    } 
    else
    msg = "但是$n巧妙地躲开了。\n";
    message_vision(msg, me, target);

    if( damage > 0 ) COMBAT_D->report_status(target);	
	
}	     

if ((int)me->query_skill("qingming-xuangong",1)> 300)
{
        msg1=HIB"$N双手环抱胸前，口中喃喃念道：“天地无极，乾坤借法！！” 突然大喝一声：“中！！”双掌并力将一巨大的金色光球推向$n！\n";
        msg2="“砰”！"+target->query("name")+HIB"身子向后一仰，连退了几步………\n";
        msg3="“砰”！你胸口如遭锤击，两眼一黑，险些昏了过去！\n"NOR;
    message_vision(msg1, me, target);
    ap = me->query_skill("taoism");
    dp = target->query("dodge");
    if( random(ap + dp) > dp) 
    {
       damage = (int)me->query_skill("qingming-xuangong",1) + random((int)me->query_skill("taoism",1));
          damage=500+damage;
       if (!userp(me) && damage >23000) damage=23000;
       if (damage <100) damage=100;

       if( damage > 0 ) 
       {
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage/2);
           tell_room(environment(me),msg2,target);
           tell_object(target,msg3);
           
       }
       else
       {
           msg = "$N的「火识神通」好象没有造成任何伤害！\n";
           me->receive_damage("jing", 10);
       }
    } 
    else
    msg = "但是$n巧妙地躲开了。\n";
    message_vision(msg, me, target);

    if( damage > 0 ) COMBAT_D->report_status(target);	
	
}	  


if ((int)me->query_skill("qingming-xuangong",1)> 500)
{
       msg =  HIY "$N口中念了句咒文，半空走出一位容貌秀雅的电母，双手各持一枚铜镜。铜镜相转，忽的闪出一道金光射向$n！\n" NOR;
        message_combatd(msg, me,target);		
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = (int)me->query_skill("qingming-xuangong");  //以基本内功和九阳神功的高低，取决杀伤力的大小！
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("taoism", 1)*8);
       if (!userp(me) && damage >23000) damage=23000;
       if (damage <100) damage=100;

if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage);
}
		msg=HIC "结果「嗤」地一声，金光从$n身上透体而过，\n拖出一条长长的血箭，直射到两三丈外的地下！\n" NOR;
}
else
{
		msg="结果嗤！地一声$n闻到了一股焦味。还好只烧掉了几根头发。\n" NOR; 
}
message_combatd(msg, me,target);	
	
}	  

if ((int)me->query_skill("qingming-xuangong",1)> 700)
{
       msg =  HIW "$N口中念了句咒文，半空走出位尖头鹰鼻的雷公，左手执斧，右手提锥。斧锥相击，在$n的头顶炸起一片响雷！\n" NOR;
        message_combatd(msg, me,target);		
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = (int)me->query_skill("qingming-xuangong");  //以基本内功和九阳神功的高低，取决杀伤力的大小！
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("taoism", 1)*8);
       if (!userp(me) && damage >23000) damage=23000;
       if (damage <100) damage=100;

if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage);
}
		msg=HIW "结果$n被雷声震得眼冒金星，心神不定，差点跌倒在地！\n" NOR;
}
else
{
		msg="谁知$n毫无反应，就象聋子似的。\n" NOR; 
}
message_combatd(msg, me,target);	
	
}	  
       
         me->start_busy(3);        
        return 3+random(5);
}



