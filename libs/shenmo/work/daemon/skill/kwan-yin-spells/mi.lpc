 //mimicat@fy4
#include <ansi.h> 
inherit F_SSERVER;
string *gifts=({ "qi","jing","jingli" });
string *gifts1=({"eff_qi","eff_jing","neili"});  

int perform(object me, object target)
{
        int extra,i;
        

        extra=me->query_skill("kwan-yin-spells",1);
        if(extra<120) return notify_fail("你的观音六字明咒的等级还不够高深。\n");
        
        if( !target )
                return notify_fail("你要用真言为谁疗伤？\n");
        //if( !userp(target) )
        //        return notify_fail("你要用真言为谁疗伤？\n");

                
        if( me==target)
                return notify_fail("真言法术不能用在自己身上。\n"); 
        if( (int)me->query("neili") < 1200 )
                return notify_fail("你的法力不够。\n");
        
        message_vision(HIC "$N面呈无限虔诚憧憬之色。双手合十祈愿，低声对$n念道：“咪” \n\n"NOR
        HIM"一轮神圣的光彩笼罩在$N周围，$N面现普度众生的慈悲之色，法力源源 
不绝流入$n体内。 \n"NOR,me, target );
        
        for( i = 0; i < sizeof(gifts); i++ )
        {
                target->set(gifts[i],target->query("max_"+gifts[i]));
                target->set("eff_"+gifts[i],target->query("max_"+gifts[i]));
        }
        for( i = 0; i < sizeof(gifts1); i++ )
        {
                target->set(gifts1[i],target->query("max_"+gifts1[i]));
        }
 
   //     target->clear_condition();
        message_vision(HIR"$n感到体内生机勃勃，而$N的面色却渐渐枯萎。。。\n"NOR,me,target);
        me->unconcious();
        me->set("neili",0);
        //me->set("force",0);
   //me->set("atman",0);
        return 1;
}      
