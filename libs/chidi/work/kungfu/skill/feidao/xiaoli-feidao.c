// counterattack.c

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{              int weapon;
	string msg;
	if( !target ) target = offensive_target(me);
       if (!objectp(weapon = me->query_temp("weapon"))
               || (string)weapon->query("skill_type") != "throwing")
                        return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[31mĞ¡Àî·Éµ¶[37mÖ»ÄÜ¶ÔÕ½¶·ÖĞµÄ¶ÔÊÖÊ¹ÓÃ¡£\n");
	if((int) me->query_skill("feidao",1) <= 300000)
		return notify_fail("ÄãµÄ·Éµ¶¾ø¼¼»¹²»¹»¾«´¿£¬²»ÄÜ·¢³öĞ¡Àî·Éµ¶¡£\n");

	message_vision(RED"$NÄ¿²»×ª¾¦µØ¶¢×Å$n£¬×¼±¸·¢³öÖÂÃüÒ»»÷¡£\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me,target :), 1);
	me->start_busy(5);
	return 1;
}
void kill_him(object me, object target)
{
	string msg;
	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target))
	{
msg = HIY "$NÊ¹³ö·Éµ¶¾ø¼¼ÖĞÀıÎŞĞé·¢µÄ" + HIR "Ğ¡Àî·Éµ¶" +HIY "£¬$nÖ»¾õµÃÑÛÇ°Ò»»¨£¬ÑÊºíÒÑ±»¶Ô´©¶ø¹ı£¡£¡£¡" ;
msg +=  "\nÒ»¹ÉÑª¼ıÅçÓ¿¶ø³ö£®£®$nµÄÑÛ¾¦ËÀÓã°ãµÄÍ»ÁË³öÀ´£®£®\n" NOR;

	message_vision(msg, me, target);
		//target->die();
	}
	return ;
}
