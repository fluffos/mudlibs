#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

void remove_effect(object me, int improve);

string* valid_weapon() 
{
    return ({ "all" });
}

int perform(object me, object target)
{
      string msg;                                   
      int improve;
      mapping skills;
	  int i;
      if( !target ) target = offensive_target(me);
      skills = me->query_skills();
	    for(i=0; i<sizeof(skills); i++)
		if(load_object(SKILL_D(keys(skills)[i]))->valid_enable("dodge")
			&& keys(skills)[i] != "luoxuan-jiuying")
			return notify_fail("你身上还有其他杂乱的轻功，这样无法施展「旋字诀」。\n");
      if( (int)me->query_skill("luoxuan-jiuying",1) < 120 )
                return notify_fail("你的螺旋九影不够娴熟，不会使用「旋字诀」！\n");
      
      if( (int)me->query_skill("jiuyin-shengong",1) < 120 )
                return notify_fail("你的九阴神功等级不够，不能使用「旋字诀」！\n");  
      if( (int)me->query_dex() < 30 )
                return notify_fail("你的身法太低，不能使用「旋字诀」！\n");
      
      if( (int)me->query_skill("dodge",1) < 120 )
                return notify_fail("你的基本轻功太差，身体笨拙，不能使用「旋字诀」！\n");
      
      if( (int)me->query("neili") < 400 )
      return notify_fail("你的内力太少了，无法使用出「旋字诀」！\n");   
    
        if (me->query_skill_mapped("dodge") != "luoxuan-jiuying")
                return notify_fail("你现在激发的轻功无法使用「旋字诀」绝技。\n");                                                                                 
      if( me->query_temp("xuan")   )
      return notify_fail("你正在使用螺旋九影的「旋字诀」！\n");
       
     msg = HIW"$N默念九阴歌诀，身形现出淡淡光晕，速度不断提升，整个人渐渐只剩下虚影。\n"NOR;
      
      message_vision(msg, me, target); 
      improve = (int)me->query_dex() * 2;
      me->add_temp("apply/dodge", improve);
      me->set_temp("xuan",1);  
      me->add("neili", -(500-(int)me->query_skill("luoxuan-jiuying",1)/10));
      
      if ( !me->query_temp("active_buffer/family") )
        me->set_temp("active_buffer/family","公共武学");
      me->set_temp("active_buffer/luoxuan-jiuying.xuan/name", "旋字诀");                      //buff名称
      me->set_temp("active_buffer/luoxuan-jiuying.xuan/last_time", time() + me->query_skill("luoxuan-jiuying")*2/3 );          //持续时间
      me->set_temp("active_buffer/luoxuan-jiuying.xuan/effect1", "轻功技能+"+improve+"级");     //效果描述1
            
      call_out("remove_effect",me->query_skill("luoxuan-jiuying")*2/3,me,improve);
      return 1;
}

void remove_effect(object me, int improve)
{
        if (!me) return;
      me->add_temp("apply/dodge", - improve);
      me->delete_temp("xuan");
      me->delete_temp("active_buffer/luoxuan-jiuying.xuan");
      if ( sizeof(me->query_temp("active_buffer"))==1 )
        me->delete_temp("active_buffer");
      tell_object(me, HIR"你散去「旋字诀」的功效，整个人懒洋洋的。\n"NOR);
      tell_room(environment(me), HIW + me->name()+"周身的光晕消失，散去了「旋字诀」。\n" NOR,  ({ me }));
    
}
