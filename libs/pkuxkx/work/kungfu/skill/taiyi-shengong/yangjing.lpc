// yangjing.c
// 太乙神功exert 养精，效果是提高在线时最大精神
// 2009.8.17 finished by zgbl

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int count;
	  if ((int)me->query("family"))
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

	  if (me->query("family") || me->query("chushi/last_family"))
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

	    if (me->query("betrayer") > 0)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

	    if (me->query_skill("hunyuan-yiqi",1) > 0)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
//有门派或者有过门派都无法使用，纯百姓技能

        if( me->is_fighting() )
                return notify_fail("战斗中修心养精？找死吗？\n");

        if ((int)me->query_skill("taiyi-shengong", 1) < 200)
                return notify_fail("你的太乙神功修为还不够。\n");

        if( (int)me->query("jingli") < 1500 )
                return notify_fail("你的精力不够。\n");

		if( (int)me->query("neili") < 1000 )
                return notify_fail("你的内力不够。\n");

		if( (int)me->query_temp("yangjing") )
                return notify_fail("你已经调理过精神了。\n");

        write( HIC "你眼观鼻鼻观心，内心进入一片空明，开始调养精神。\n" NOR);
        message("vision",
                HIC + me->name() + HIC "养管鼻鼻观心，开始闭目养神\n" NOR,
                environment(me), me);

		    count =(me->query_skill("force"))*5/2;   
        
        me->add_temp("apply/max_jing", count);
        me->set("max_jing",me->query_max_jing() );
        me->set("eff_jing",me->query("jing")+count);
		    me->set("jing",me->query("jing")+count);
        me->set_temp("yangjing", 1); 
        me->add("neili", -500);
		    me->add("jingli", -1000);
        me->set_temp("active_force_buffer/taiyi-shengong.yangjing/name", "养精");                          //buff名称
        me->set_temp("active_force_buffer/taiyi-shengong.yangjing/effect1", "最大精神+"+count+"点");       //效果描述1   
        return 1;
//提高数值为有效内功*2.5，使用消耗1000精力500内力
}

void remove_effect(object me, int count)
{
        me->delete_temp("yangjing", 1);

        me->set("max_jing",me->query("max_jing")-count);
              if(me->query("eff_jing")>count)                    
                       me->set("eff_jing",me->query("eff_jing")-count);
              else
                      me->set("eff_jing",10);
              if(me->query("jing")>count)
                      me->set("jing",me->query("jing")-count);
              else
                      me->set("jing",10); 
        tell_object(me, "你空明的心境渐渐消失，感觉精神没有那么充裕了。\n");
}
