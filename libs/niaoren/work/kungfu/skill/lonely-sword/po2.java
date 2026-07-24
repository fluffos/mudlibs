// poanqi.c 破箭式

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{

        object *ob,weapon,target;
        int i, skill, damage;
        string msg;

        if(me->query("family/master_id") != "feng qingyang")
            return notify_fail("你不是風清揚的弟子，不能使用絕招！\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lonely-sword",1);

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不對。\n");

        if( skill < 80)
      return notify_fail("你的獨孤九劍等級不夠, 不能使用「破箭式」！\n");

        if( me->query("neili") < 500 )
            return notify_fail("你的內力不夠，無法運用「破箭式」！\n");

        if( environment(me)->query("no_fight") )
            return notify_fail("在這里不能攻擊他人。\n");


        me->add("neili", -250);
        me->receive_damage("qi", 10);
        me->start_busy(1);
        message_vision(
 HIC"$N清嘯一聲，手中長劍輕轉，劍勢變幻，化出光芒千道，一式獨孤九劍
「破箭式」，劍尖向四面八方疾速點出！\n"NOR,me);
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
message_vision(HIC"$N手中劍尖破空，正刺在$n的咽喉！\n"NOR,me,ob[i]);
                        break;
                  case 2:
message_vision(HIC"只見$N右手劍尖一點，$n胸口鮮血噴涌而出！\n"NOR,me,ob[i]);
                        break;
                  case 3:
message_vision(HIC"$N手中劍光閃處，在$n手腕就是一個透明窟窿！\n"NOR,me,ob[i]);
                        break;
                  case 4:
message_vision(HIC"$N手中劍尖斜挑，輕輕插進$n的小腹！\n"NOR,me,ob[i]);
                        break;
                  default:
message_vision(HIC"你看見$N手中劍光一閃，正扎在$n左臂肩井穴上！\n"NOR,me,ob[i]);
                        break;
              }
              tell_object(ob[i], 
HIC"你覺得眼前一點寒星直奔而來，頓覺一陣刺痛難忍，眼前發黑..\n"NOR);
           }
           if(userp(ob[i])) ob[i]->fight_ob(me);
           else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
        }

        return 1;
}

