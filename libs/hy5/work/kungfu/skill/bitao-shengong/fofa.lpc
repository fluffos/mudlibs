// onlyu.c by greenwc
#include <ansi.h>

inherit F_SSERVER;

int exert(object me)
{
        int ap,dp,damage,success,skill;
object target;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁使用佛光？\n");

        if((int)me->query("neili") < 500)
                return notify_fail("你的内力不够！\n");

        if((int)me->query("jing") < 200 )
                return notify_fail("你无法集中精力！\n");


      if( !target ) target = offensive_target(me);
   	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
		
		        if((int)me->query_skill("buddhism",1) < 100)
                return notify_fail("你的禅宗心法还不够。。。\n");

        if((int)me->query_skill("bitao-shengong",1) < 100)
                return notify_fail("你的碧涛心法还不够。。。\n"); 

        me->add("neili", -200);

        if( random(me->query("max_neili")) < 100 ) {
                write("你试着哼了几声，但怎么也找不着调！\n");
                return 1;
        }
skill=(int)me->query_skill("bitao-shengong",1);
        ap = (int)me->query_skill("bitao-shengong");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = (int)target->query("combat_exp");
            success=0;
           damage=100+((int)me->query_skill("buddhism",1)+random((int)me->query_skill("bitao-shengong",1)/5));
            message_vision(HIY"\n$N忽然跳出战圈，向$n念道："NOR,me,target);
        message_vision(HIY"\n$N语音清脆，越念越是冲和安静，全身隐隐发出圣洁的光辉。"NOR,me,target);
            message_vision(HIC"\n身從無相中受生。猶如幻出諸形象。幻人心識本來無。罪福皆空無所住。"NOR,me,target);
            if (random(ap+dp) > dp )
{            
                   success += 1;
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
if (userp(target) && damage > target->query("jing",1)/2) damage=target->query("jing",1)/2;
            target->receive_wound("jing",damage/3,me);
            target->receive_damage("jing",damage*2/3,me);
}
            message_vision(HIG"\n起諸善法本是幻，造諸惡業亦是幻。身如聚沫心如風，幻出無根無實性。"NOR,me,target);  
          if (random(ap+dp) > dp )
{            success += 1;

                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
            damage=damage+100;
            if (userp(target) && damage > target->query("jing",1)) damage=target->query("jing",1)/2;
            target->receive_wound("jing",damage/3,me);
            target->receive_damage("jing",damage*2/3,me);
}
            message_vision(HIR"\n假借四大以為身，心本無生因境有，前境若無心亦無，罪福如幻起亦滅。"NOR,me,target);
                       if (random(ap+dp) > dp )
{           success += 1;
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage*2,me);
}

if (skill > 200)
{	
            message_vision(HIW"\n見身無實是佛身，了心如幻是佛幻，了得身心本性空，斯人與佛何殊別。"NOR,me,target);
                        if (random(ap+dp) > dp )
{            success += 1;
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage*2,me);
}
            message_vision(RED"\n佛不見身知是佛，若實有知別無佛，智者能知罪性空，坦然不怖於生死。"NOR,me,target);
                        if (random(ap+dp) > dp )
{           success += 1;
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage*2,me);
}
            message_vision(GRN"\n一切众生性清淨，從本無生無可滅，即此身心是幻生，幻化之中無罪福。"NOR,me,target);
                       if (random(ap+dp) > dp )
{            success += 1;
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;
if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage,me);
            target->receive_damage("qi",damage*2,me);
}
}

if (skill > 250)
{	
            message_vision(YEL"\n法本法無法，無法法亦法，今付無法時，法法何曾法。"NOR,me,target);
                       if (random(ap+dp) > dp )
{           success += 1;
                 message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;
 target->add("neili",-damage*3);
 if ((int)target->query("neili")<=0) target->set("neili",0);
 	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage/3,me);
            target->receive_damage("qi",damage*2/3,me);
}

}

if (skill > 300)
{	
            message_vision(HIB"\n諸行無常，是生滅法，生滅滅已，寂滅為樂。"NOR,me,target);
                        if (random(ap+dp) > dp )
{           success += 1;
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;
target->add("neili",-damage*3);
 if ((int)target->query("neili")<=0) target->set("neili",0);
 	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage/3,me);
            target->receive_damage("qi",damage*2/3,me);
}
}

if (skill > 350)
{	
       message_vision(WHT"\n凡俗諸猛熾，何能致火爇，請尊三昧火，闍維金色身。"NOR,me,target);
                        if (random(ap+dp) > dp )
{           success += 1;
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;
target->add("neili",-damage*3);
 if ((int)target->query("neili")<=0) target->set("neili",0);
 	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage/3,me);
            target->receive_damage("qi",damage*2/3,me);
}
}

if (skill > 400 || !userp(me))
{	
            message_vision(BLU"\n菩提道上来，随缘现镜台。妙有续慧命，真空无尘埃。"NOR,me,target);
                        if (random(ap+dp) > dp )
{           success += 1;
                message_vision(
                 "\n $n突然脸色苍白，似乎体力不支，竟呕出一口血来…",
                 me, target );
damage=damage+100;
target->start_busy(3);
target->add("neili",-damage*3);
 if ((int)target->query("neili")<=0) target->set("neili",0);
  	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
            target->receive_wound("qi",damage/3,me);
            target->receive_damage("qi",damage*2/3,me);
}

      }    
            if (success=0) message_vision(HIW"\n$n哼了一声：我命不由天 ！\n"NOR,me,target);
           else if (success > 5) message_vision(HIB"\n$n被烦的头痛欲裂，根本没有再战的力量了\n"NOR,me,target);
            else message_vision(HIB"\n$n拍了拍头，尽量想让自己保持清醒\n"NOR,me,target);
            

        me->start_busy(2+random(2));
        return 3+random(5);
}
