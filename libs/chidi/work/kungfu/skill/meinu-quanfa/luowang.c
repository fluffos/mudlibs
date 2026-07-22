// modify by xiha for jhfy@xssx3
// luowang.c ÷

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("Ç£ÖÆ¹¥»÷Ö»ÄÜ¶ÔÕ½¶·ÖÐµÄ¶ÔÊÖÊ¹ÓÃ¡£\n");

        if( (int)me->query_skill("force") < 100 )
                return notify_fail("ÄãµÄÄÚ¹¦ÐÞÎª²»¹»»ðºò£¬Ê¹ÓÃ²»ÁË¡¸ÌìÂÞµØÍøÊÆ¡¹¡£\n");
        
        if( me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("ÄãËùÓÃµÄÄÚ¹¦ÓëÃÀÅ®È­µÄÆøÂ·Ïàã££¡\n");

        if( me->query("neili") <= 300 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¡\n");

        if( me->query("jingli") <= 200 )
                return notify_fail("ÄãµÄ¾«Á¦²»¹»£¡\n");
                
        if( (int)me->query_skill("cuff") < 120 )
                return notify_fail("ÄãµÄÃÀÅ®È­²»¹»æµÊì£¬²»»áÊ¹ÓÃ¡¸ÌìÂÞµØÍøÊÆ¡¹¡£\n");

        if( target->is_busy() ) 
                return notify_fail(target->name() + "Ä¿Ç°Õý×Ô¹Ë²»Ï¾£¬·Åµ¨¹¥»÷°É¢¦\n");

        msg = CYN "$NÊ¹³ö´òÃÀÅ®È­¡¸ÌìÂÞµØÍøÊÆ¡¹£¬Ë«È­ÎèÆðÌìÂÞµØÍø£¬½«$nÍÌÃ»£¡\n";
        me->add("neili", -80);
        me->add("jingli", -20);

        if( ((random(me->query("combat_exp")/10000) * (int)me->query_skill("meinu-quan") ) > 
        (((int)target->query("combat_exp")/5000) * ((int)target->query_skill("parry")/2 + (int)target->query_skill("dodge")/2))/4) ) {

                msg += "½á¹û$p±»$P¹¥ÁË¸öÊÖÃ¦½ÅÂÒ£¬Ò»Ê±ÎÞ·¨»¹ÕÐ½ø¹¥£¡\n" NOR;
                target->start_busy( (int)me->query_skill("tianluo-diwang") /(30+random(10)));
        } else {
                msg += "¿ÉÊÇ$p¿´ÆÆÁË$PµÄÆóÍ¼£¬²¢Ã»ÓÐÉÏµ±¡£\n" NOR;
                me->start_busy(1+random(3));
        }
        message_vision(msg, me, target);

        return 1;
}

