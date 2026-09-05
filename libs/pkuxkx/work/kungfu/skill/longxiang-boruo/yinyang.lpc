// yinyang.c
// code by hunthu
#include <ansi.h>

int exert(object me, object target)
{
     int exp,exp1; 
     string gen,gen1;
     mapping fam;
	fam=me->query("family");
        gen=me->query("gender");
         gen1=target->query("gender");
 
        if( !target )
	return notify_fail("你要降伏谁？\n");
        if (!living(target))
        return notify_fail("看清楚，是不是活着。\n");
	if(target == me)
	return notify_fail("你有病啊，自己降伏自己？！\n");
        if (me->is_busy())
        return notify_fail("你正忙着呢。\n");
      	if( me->is_fighting() || target->is_fighting())
	return notify_fail("战斗中无法使用此法！\n");
      if ((int)me->query_skill("longxiang-boruo",1)<100)
        return notify_fail("你的龙象般若功修为尚浅，无法支持此法。\n");
        if (me->query_skill("huanxi-chan",1)<90)
        return notify_fail("你的欢喜禅修为太低了。\n");
          

        if( (int)me->query("max_neili") < 1000 )
	return notify_fail("你的内力修为尚浅，当心反为人所算。\n");
        if ((int)me->query("neili")<500)
         return notify_fail("你当前内力几乎已经用尽了，无法再施展此法！\n");   
	if ( fam["family_name"] != "大轮寺")
         return notify_fail("你不是大轮寺的弟子，如何能参欢喜禅。\n");
        if (gen== "无性")
        return notify_fail("你不男不女的瞎折腾什么?\n");
         if (gen1== "无性")
         return notify_fail("看清楚点，他是个太监。\n");
          if (gen==gen1)
          return notify_fail("你是同性恋啊，变态！\n");
            exp= (int)me->query("comat_exp");
          exp1=(int)target->query("combat_exp");
     if (me->query("combat_exp",1)>target->query("combat_exp",1))
          return notify_fail("和这样差劲的家伙双修的话，小心功力大损！\n");
          if ((int)target->query("max_neili")< 100)
          return notify_fail("和这样内力差劲的家伙双修的话，小心自己内力大损！\n");
         switch (gen){
                case "男性":
                 tell_object(me,HIY"你凝神聚气，脑中存想欢喜禅意，对"+target->name()+"运起「阴阳大法」。\n"NOR);
                 message_vision(HIY"$N面含微笑，口中呢喃低吟法咒，双眼半睁半闭，莹然生光，直视$n双眼。\n"NOR,me,target);
                    switch (random(3)){
                              case 0:
                              message_vision(HIY"$N慢慢走到$n旁边。\n"NOR,me,target);
                              break;
                              case 1:
                             message_vision(HIY"$N用低沉轻柔的声音在$n耳旁说道：“这位"+RANK_D->query_respect(target)+"看来太劳累了，不如就睡了吧，就睡了吧。”\n"NOR,me,target);
                              break;
                              case 2:
                              message_vision(CYN"$N用低沉柔和的声音在$n耳旁说道：“这位"+RANK_D->query_respect(target)+"慈眉善目，与我佛极是有缘，不如让"+RANK_D->query_self(me)+"今天点化于你如何？\n"NOR,me,target);
                               break;
                                }
                            switch (random(4)){
                              case 0:
                             message_vision(HIY"$n耳中听到$N低讼法咒，只觉阵阵天旋地转，身子一晃，险些摔到。\n"NOR,me,target);
                              break;
                             case 1:
                           message_vision(HIY"$n精神恍惚，眼神迷离，满脸涨得通红，呼吸渐渐急促起来。\n"NOR,me,target);
                             break;
                             case 2:
                          message_vision(HIY"$n和$N眼神一对，不由全身一震，一道热流自腹中腾地升起，刹时全身燥热无比。\n"NOR,me,target);
                            break;
                             case 3:
                            message_vision(HIY"$n全身酸软乏力，眼皮沉重，似乎渐渐不能控制自己的意志了。\n"NOR,me,target);
                             break;
                             }
               break;
default:
              tell_object(me,HIY"你凝神聚气，脑中存想欢喜禅意，对"+target->name()+"运起「阴阳大法」。\n"NOR);
             message_vision(HIY"$N媚眼如丝，珠唇轻启，口中低唱法咒，慢慢靠近$n，一对勾魂双瞳扫向$n。\n"NOR,me,target);
             switch (random(3)){
                case 0:
                message_vision(HIY"$N莲步轻移，凑到$n跟前。\n"NOR,me,target);
                break;
                 case 1:
               message_vision(HIY"$N用低沉轻柔的声音在$n耳旁说道：“这位"+RANK_D->query_respect(target)+"看来太劳累了，不如就睡了吧，就睡了吧。”\n"NOR,me,target);
                break;
                 case 2:
               message_vision(HIY"$N用低沉柔和的声音在$n耳旁说道：“这位"+RANK_D->query_respect(target)+"慈眉善目，与我佛极是有缘，不如让"+RANK_D->query_self(me)+"今天点化于你如何？\n"NOR,me,target);
                 break;     
                   }
            switch (random(3)){
                 	case 0:
                       message_vision(HIY"$n鼻中香风阵阵，熏人欲醉，而$N千娇百媚，只觉血脉奋张，不由自主地干笑了几声。\n"NOR,me,target);
                      break; 
                      case 1:
                      message_vision(HIY"$n胸中欲火如焚，无可抑制，眼中射出兽性地光芒，喉中“呵呵”发出几声似人似兽地声音。\n"NOR,me,target);
                      break; 
                      case 2:
                       message_vision(HIY"$n莫名其妙地只觉无比兴奋，不由得手舞足蹈，呵呵地傻笑了几声。\n"NOR,me,target);
                       break;
                         }
                  }
exp=(int)me->query_skill("huanxi-chan",1)/5;
  if (random(me->query("combat_exp",1))>target->query("combat_exp",1)/5*2)
                          {
                            message_vision(HIG"$n脸上春意盎然，如痴如醉，鼻中低哼着扑入$N怀中。\n"NOR,me,target);
                            me->start_busy(5);
                            me->add("qi",me->query_skill("huanxi_chan",1)*2);
                            me->add("jingli",me->query_skill("huanxi_chan",1)*2);
       me->add("combat_exp",me->query_skill("huanxi-chan",1)/5);
                            me->add("neili",-200); 
                            target->add("max_neili",-20);
                            target->add("eff_jingli",-20);
                           if (me->query("potential") > me->query("max_pot")){
                            me->add("potential", me->query_skill("huanxi-chan",1)/10+1);   
                            return 1;
                            }
                           me->add("potential", random(me->query_skill("huanxi-chan",1))/5+1);
                            return 1;
                         } 
                        if (gen1=="女性")
                        message_vision(HIR"$n蓦然醒觉，只感全身透出层冷汗，脸颊通红，不由得柳眉倒竖，对着$N怒叱“淫僧该死！”\n"NOR,me,target);
                        else 
                        message_vision(HIR"$n一声大叫，猛然惊觉，头脑犹自迷迷糊糊，不由得怒吼“淫尼采阳补阴，伤天害理！”\n"NOR,me,target);
//                       target->kill_ob(me);
                        me->start_busy(7); 
                        return 1;   
        
                        }
