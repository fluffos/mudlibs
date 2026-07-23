#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    string msg;
      switch(random(5)){
      case 0 : 
              msg = HIM"$N两眼通红，喉中不断的发出野兽般的低吼。\n"NOR;
              me->add_busy(5);
              me->add("jingli", -300);
              break;
      case 1 : 
              msg = HIM"$N只觉燥热难当，舌头不停的舔吻着自己的双唇。\n"NOR;
              me->add_busy(5);
              me->add("jingli", -400);
              break;
      case 2 : 
              msg = HIM"$N双手交叉抚摩着自己的双臂急躁的嘶叫：不行了...不行了...我要死了。\n"NOR;
              me->add_busy(5);
              me->add("jingli", -500);
              break;
      case 3 : 
              msg = HIM"$N色迷迷的看着人们，嘴里不停的叫唤着：亲亲我的小宝贝儿。\n"NOR;
              me->add_busy(5);
              me->add("jingli", -600);
              break;
      case 4 : 
              msg = HIM"$N将自己的衣服不停的撕扯，指甲在胸口划出了一道道的血痕。\n"NOR;
              me->add_busy(5);
              me->add("jingli", -700);
              break;
      }
      message_vision(msg, me);      
      me->apply_condition("yysan_poison", duration - 1);
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

