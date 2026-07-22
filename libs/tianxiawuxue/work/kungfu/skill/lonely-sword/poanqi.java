// poanqi.c 破箭式

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{

        object *ob,weapon,target;
        int i, skill, damage;
        string msg;

        if(me->query("family/master_id") != "feng qingyang")
            return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lonely-sword",1);

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

        if( skill < 80)
      return notify_fail("你的独孤九剑等级不够, 不能使用「破箭式」！\n");

        if( me->query("neili") < 500 )
            return notify_fail("你的内力不够，无法运用「破箭式」！\n");

        if( environment(me)->query("no_fight") )
            return notify_fail("在这里不能攻击他人。\n");


        me->add("neili", -250);
        me->receive_damage("qi", 10);
        me->start_busy(1);
        message_vision(
 HIC"$N清啸一声，手中长剑轻转，剑势变幻，化出光芒千道，一式独孤九剑
「破箭式」，剑尖向四面八方疾速点出！\n"NOR,me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++)
        {
           if( !living(ob[i]) || ob[i]==me ) continue;
           damage=skill-((int)ob[i]->query_skill("dodge")/10);
           if(damage>0)
           {
              ob[i]->receive_damage("jing", damage);
              ob[i]->receive_wound("qi", damage*2);
              ob[i]->add("eff_qi", -damage/2);
              switch (random(5))
              {
                  case 1:
message_vision(HIC"$N手中剑尖破空，正刺在$n的咽喉！\n"NOR,me,ob[i]);
                        break;
                  case 2:
message_vision(HIC"只见$N右手剑尖一点，$n胸口鲜血喷涌而出！\n"NOR,me,ob[i]);
                        break;
                  case 3:
message_vision(HIC"$N手中剑光闪处，在$n手腕就是一个透明窟窿！\n"NOR,me,ob[i]);
                        break;
                  case 4:
message_vision(HIC"$N手中剑尖斜挑，轻轻插进$n的小腹！\n"NOR,me,ob[i]);
                        break;
                  default:
message_vision(HIC"你看见$N手中剑光一闪，正扎在$n左臂肩井穴上！\n"NOR,me,ob[i]);
                        break;
              }
              tell_object(ob[i], 
HIC"你觉得眼前一点寒星直奔而来，顿觉一阵刺痛难忍，眼前发黑..\n"NOR);
           }
           if(userp(ob[i])) ob[i]->fight_ob(me);
           else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
        }

        return 1;
}

