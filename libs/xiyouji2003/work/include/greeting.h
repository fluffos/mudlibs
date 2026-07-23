// Created by waiwai@2003/01/18
// 闲来无聊写个破玩意吧。：P

#include "ansi.h"

void greeting(object who)
{
	object me = this_object();
	string str,wizmsg;
	object weapon = me->query_temp("weapon");

	if(!visible (who)) return;
	if(me->is_fighting()) return;

	if( !wizardp(who) ) {
	if(who->query("office_number") > 0 && who->query("degree")) {
	if (weapon)
		str = "$N举起手中的"+weapon->query("name")+HIG"向$n行礼：";
		else
		str = "$N躬身向$n行礼：";
	 str = HIG+str + "属下参见朝廷 "+who->query("degree")+HIG" 大人！\n"NOR;

	message_vision (str,me,who);
	}
	} else
	if (weapon) {
	if( !who->query("env/invisibility") ) {
	if( wiz_level(who) == wiz_level("(created)") ) { 
	  str = "$N举起手中的"+weapon->query("name")+HIR"向$n行礼：";
	 str = HIR+str +HIR+" 小的参见西游记创世大神！\n"NOR;
	} else
	if( wiz_level(who) == wiz_level("(admin)") ) {
	  str = "$N举起手中的"+weapon->query("name")+HIY"向$n行礼：";
	 str = HIY+str +HIY+" 小的参见西游记主管天神！\n"NOR;
	} else 
	if(wiz_level(who) == wiz_level("(arch)") ) {
	 str = "$N举起手中的"+weapon->query("name")+HIM"向$n行礼：";
	 str = HIM+ str +" 小的参见西游记神界大神！\n"NOR;
	} else
	if(wiz_level(who) == wiz_level("(wizard)") ) {
	 str = "$N举起手中的"+weapon->query("name")+NOR WHT"向$n行礼：";
	 str = WHT+ str +" 小的参见西游记神界仙人！\n"NOR;
	} else
	if(wiz_level(who) < wiz_level("(apprentice)") ) {
	 str = "$N举起手中的"+weapon->query("name")+NOR WHT"向$n行礼：";
	 str = WHT+ str +" 小的参见西游记神界散仙！\n"NOR;
	} else
	if(wiz_level(who) < wiz_level("(immortal)") ) {
	 str = "$N举起手中的"+weapon->query("name")+NOR WHT"向$n行礼：";
	 str = WHT+ str +" 小的参见西游记神界灵官！\n"NOR;
	} else {
	 str = "$N举起手中的"+weapon->query("name")+NOR WHT"向$n行礼：";
	 str = WHT+ str +" 小的参见西游记荣誉之神！\n"NOR;
	} 

	message_vision (str,me,who);
	}
	} else if( !who->query("env/invisibility") ) {
	if( wiz_level(who) == wiz_level("(created)") ) {
	  str = "$N躬身向$n行礼：";
	 str = HIR+str +HIR+" 小的参见西游记创世大神！\n"NOR;
	} else
	if( wiz_level(who) == wiz_level("(admin)") ) {
		str = "$N躬身向$n行礼：";
	 str = HIY+str +HIY+" 小的参见西游记主管天神！\n"NOR;
	} else 
	if(wiz_level(who) == wiz_level("(arch)") ) {
	 str = "$N躬身向$n行礼：";
	 str = HIM+ str +" 小的参见西游记神界大神！\n"NOR;
	} else 
	if(wiz_level(who) == wiz_level("(wizard)") ) {
	 str = "$N躬身向$n行礼：";
	 str = WHT+ str +" 小的参见西游记神界仙人！\n"NOR;
	} else 
	if(wiz_level(who) == wiz_level("(apprentice)") ) {
	 str = "$N躬身向$n行礼：";
	 str = WHT+ str +" 小的参见西游记神界散仙！\n"NOR;
	} else 
	if(wiz_level(who) == wiz_level("(immortal)") ) {
	 str = "$N躬身向$n行礼：";
	 str = WHT+ str +" 小的参见西游记神界灵官！\n"NOR;
	} else {
	 str = "$N躬身向$n行礼：";
	 str = WHT+ str +" 小的参见西游记荣誉之神！\n"NOR;
	}

	message_vision (str,me,who);
	}
}

void greeting2(object who)
{
  object me = this_object();

  if (! visible (who))  return;
  if (me->is_fighting()) return;

  if (who->query("quest/reward") > 0)  {
    string str;
    str = HIG"$N向$n一躬："+RANK_D->query_respect(who)+
          "仙体祥云笼罩，请速去拜见吾王太宗！\n"NOR;
    message_vision (str,me,who);
  }
}
