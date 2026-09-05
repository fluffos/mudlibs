// might.c 力大无穷

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return  HIY "力大无穷" NOR; }

int perform(object me, string skill)
{
        int count;
        int extra;
		int add_p=0;
        if(me->query("age")<18)
                return notify_fail("你还未成年，不能使用特殊技能。\n");
        if (me->query("qi") < 300)
                return notify_fail("你的体力不支，无法竭力提升自己的攻击力。\n");
		  if (me->query("jingli")<200)
				 return notify_fail("你的精力不足，无法提升自己的攻击力。\n");  
		  if (me->query("neili")<200)
				 return notify_fail("你的内力不足，无法提升自己的攻击力。\n");  

        if (me->query_temp("special_skill/might", 1))
                return notify_fail("你已经竭力提升你自己的攻击力了。\n");
        if (!me->query("jiali"))
                return notify_fail("你没有加力，这样没法提高自己的攻击力。\n");
        message_vision(HIC "$N大吼一声，将内力灌注于双臂，顿时觉得充满了力量。\n" NOR, me);
        count=(int)me->query("jiali")/2;
        if (count<=150) extra=count;
        else if (count<=300) extra=150+(count-150)/2;
        else if (count<=450) extra=225+(count-300)/3;
        else if (count<=600) extra=275+(count-450)/4;
        else extra=312+(count-600)/5;
		switch(me->query("special_level/might"))
		{
			case 2:
				if (me->query("special_skill/greedy"))
				{
					if (me->query("special_level/greedy")>2)
					{
						add_p=8;
					}
					else
					{
						add_p=5;
					}
				}
			break;
			case 3:
				if (me->query("special_skill/greedy"))
				{
					if (me->query("special_level/greedy")>2)
					{
						add_p=16;
					}
					else
					{
						add_p=10;
					}
				}
			break;
			case 4:
	//			if (me->query("special_skill/spirituality")&&me->query("special_skill/greedy"))
				if (me->query("special_skill/greedy"))
				{
					if (me->query("special_level/greedy")>2)
					{
						add_p=26;
					}
					else
					{
						add_p=20;
					}
				}
				/*else
				{
					if (me->query("special_skill/greedy"))
					{
						if (me->query("special_level/greedy")>2)
						{
							add_p=16;
						}
						else
						{
							add_p=10;
						}
					}
				}*/
			break;
			default:
//				bt_count=33;
//				js_count=66;
			break;
		}      
		extra+=(int)extra*add_p/100;
		me->receive_damage("qi", 100 + random(100));
		me->add("neili",-200);
		me->add("jingli",-200);
        me->set_temp("special_skill/might", 1);
        me->add_temp("apply/damage", extra);
        me->set_temp("active_force_buffer/special.might/name", HIY "力大无穷" NOR );                                  //buff名称
        me->set_temp("active_force_buffer/special.might/effect1", "伤害+"+extra+"点");       //效果描述1 
        return 1;
}
