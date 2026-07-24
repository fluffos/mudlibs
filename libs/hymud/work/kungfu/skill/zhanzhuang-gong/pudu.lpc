#include <ansi.h>


#include <combat.h>


inherit F_SSERVER;

string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                        HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                        HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                        BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                        NOR, BOLD,BLINK });
                        
        if( str && stringp(str) ) 
        {
                i = sizeof(color);
                while( i-- ) 
                {
                        str = replace_string(str, color[i], "");
                };
                return str;
         }
}



int exert(object me)
{
        string msg,spells_skill,name;
        int ap,dp,ap1,dp1,pp,i,j,p;
        object weapon,*inv;
 object target;
        if( !target ) target = offensive_target(me);

        if( (int)me->query_skill("buddhism",1) < 100)
                return notify_fail("你的禅宗心法不够，还不能[普渡慈航]。。。\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这门绝学只能对战斗中的对手使用。\n");
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你想点化谁？\n");  
   
           if( !target 
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail(WHT"「普渡慈航」只能对战斗中的对手使用。\n"NOR);
   
        if (!me->is_fighting() && (userp(target)))
                return notify_fail("天下本无事，何必自扰之？\n");
   
        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("jing") < 200 )
                return notify_fail("你无法集中精力！\n");

        me->add("neili", -200);
        me->receive_damage("jing",100);
        if ( me->query_skill("buddhism",1)< 100) 
                return notify_fail("你还没有学会[普渡慈航]......\n");  
                if( me->is_busy() )
                return notify_fail("你现在正忙着呢，哪有空运功？\n");
        
        me->start_busy(2);
        spells_skill = target->query_skill_mapped("buddhism");
        ap = me->query_skill("buddhism") + me->query("str");
        dp = target->query_skill("buddhism",1) + target->query("str");
        ap1= me->query("str");
        dp1= target->query("str");
                        pp = me->query_skill("buddhism",1);
        if ((string)me->query("bonze/class") =="bonze" )
                pp = me->query_skill("buddhism",1)*2;
        
        weapon=target->query_temp("weapon");
        inv=all_inventory(me);
        i=sizeof(inv);
//        me->delete_temp("condition/carrying_ok");
        j=0;

       if( !present(target, environment(me)) )
                return notify_fail("这次还是得饶人处且饶人吧。\n");
            
        if( random(ap+dp) > dp)
        {
                if( random(ap1)>random(dp1) ) 
                { 
                        msg = HIC"$N双手合十，两眼微闭，口中轻诵，全身都拢罩在一片霞光之中。但听$N念道：\n"NOR;          
                        switch (random(3))
                        {
                        case 0:
                        { 
                                msg += HIC"
    若恶兽围绕，利牙爪可怖，念彼观音力，疾走无边方。\n
    蟒蛇及螟蝎，气毒烟火然，念彼观音力，寻声自回去。\n
    云雷鼓掣电，降雹澍大雨，念彼观音力，应时得消散......\n"NOR; break;}
      
                        case 1:
                        {
                                msg += HIC"
    众生被困厄，无量苦遍身，
    观音妙智力，能救世间苦......\n"NOR; break; }
                        case 2:
                        { 
                                msg += HIC"
    若有无量百千万亿众生，受诸苦恼，
    闻是观世音菩萨，一心称名，观世音菩萨即时观其音声，皆得解脱。
    若有持是观世音菩萨名者。设入大火，火不能烧，由是菩萨威神力故。
    若为大水所漂，称其名号，即得浅处......\n"NOR; break; }
    
                        }             
                if ( random(3)==0 )
                {                 
                		if ( userp(target) && pp > target->query("jing",1)/3) pp=target->query("jing",1)/3;    
                        target->receive_damage("jing", pp*2,me);  
                        target->receive_wound("jing", pp*2,me);
                        target->receive_wound("qi", pp*2,me);
                        target->add("neili",-800);
                        target->add("neili",-pp*3,me);
                        target->start_busy(5);
                        if (target->query("neili")<0) target->set("neili",0);
                }
                         else 
                {
                	if ( userp(target) && pp > target->query("jing",1)/3) pp=target->query("jing",1)/3; 
                        target->receive_damage("jing", pp*3/2,me);  
                        target->receive_wound("jing", pp,me);
                                                target->receive_wound("qi", pp*2,me);
                        target->add("neili",-500);
                        target->add("neili",-pp*2);
                        target->start_busy(3);
                        if (target->query("neili")<0) target->set("neili",0);
                }
                      
                msg += HIR"不知不觉中$n竟然已泪流满面，喃喃地念到：罢了，罢了......\n"NOR;
               
                if(objectp(weapon) && (  random(10)>7 ) )
                {
                        weapon->unequip();
                        target->start_busy(8);
                        //weapon->move(environment(target));  
                        msg+="$n丢下手中的"+weapon->query("name")+"，叹道：“"+RANK_D->query_self(me)+"今日始闻大道，愿意依归我佛！\n"NOR;
                
                }
                message_vision(msg,me,target);         
                COMBAT_D->report_sen_status(target);
        }
    
        else
        {
                msg = HIW"$N厉声喝道：放下屠刀，立地成佛！放下屠刀，立地成佛！！放下屠刀，立地成佛！！！\n"NOR;
                if (random(ap1+ap1)>random(dp1)) 
                {
                        msg += HIW"只见$n精神恍惚，身体摇摇欲坠！\n"NOR;
                        message_vision(msg,me,target);         
                        COMBAT_D->report_sen_status(target);
                        if ( userp(target) && pp > target->query("jing",1)/3) pp=target->query("jing",1)/3; 
                        target->receive_damage("jing", pp,me);  
                        target->receive_wound("jing", pp/2,me);
                                                target->receive_wound("qi", pp*2,me);
                        target->start_busy(3);
                        target->add("neili",-100);
                        target->add("neili",-pp);
                        if (target->query("neili")<0) target->set("neili",0);
                }
   
                else {
                        if (spells_skill) {
                                msg += HIW"$n默运"+CHINESE_D->chinese(spells_skill)+HIW"，一声大喝：何人在此装神弄鬼！\n"NOR;                             
                                message_vision(msg,me,target);         
                                        me->start_busy(2+random(3));
                        } 
                }
        } 
   
        
  
        return 1+random(4);
        }
   
        message_vision(HIR"$n哈哈大笑：“我命由我不由人，要你这"+RANK_D->query_rude(me)+"来唠叨些什么!\n"NOR,me,target);     
         
        return 3+random(4);     
}