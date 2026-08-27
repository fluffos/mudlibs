//QC: Luky
// 1.戰鬥訊息過長喔, 而且訊息後面的'。'不需要, 請重新整理一下訊息
// 2. if 和 else 敘述請排列整齊. { 和 } 位置要相對應喔


#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N運勁於臂，一招「 "HIG" 一氣動山河 "NOR" 」手中$w以雷霆萬鈞之勢朝$n猛劈而去。",
        "damage":             15,
        "dodge" :               10,
        "attact_type":  "bar",  // 設定技能的攻擊種類
                                // 種類有 生物(bio) 獸性(bar)
                                // 魔法(wit)心靈(sou)科技(tec)
        "damage_type":  "劈傷",
        ]),

        ([
        "action": "$N一聲清嘯，「 "HIG" 江水黃山繞 "NOR"」$w一抖，身形繞著$n急轉而起，突然$w數招直朝$n招呼而去。",
        "damage":               17,
        "dodge":                12,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "刺傷",
        ]),
        ([
        "action": "$N左手一甩，「 "HIG"一笑撼陰陽 "NOR"」，口中狂狂鬼笑，直看的$n目瞪口呆，豈料$N忽然身形一閃，一匕斜斜殺向$n。",
        "damage":                16,
        "dodge" :               -10,
        "parry" :                10,
        "attact_type":  "bar",
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N忽然丹氣大盛，「 "HIG" 丹氣威震天 "NOR" 」，四周白煙邈邈，一匕挾以雄厚內勁殺向$n，直教$n無法閃躲。",
        "damage":               20,
        "dodge" :               -20,
        "parry" :                 -10,
        "attact_type":  "bar",
        "damage_type":  "內傷",
        ]),

        ([
        "action": "$N臉色忽現狂殺之氣，「 "HIG" 浴血九千里 "NOR" 」一式狂斬而出 ，一道殺氣以破竹之勢斬向$n。",
        "damage":               19,
        "dodge" :                20,
        "parry" :                -20,
        "attact_type":  "bar",
        "damage_type":  "斬傷",
        ]),

        ([
        "action": "$N忽然狀若白癡，「 "HIG" 瘋心破日月 "NOR"」，數招慢匕以不可能的方位斬向$n！",
        "damage":               15,
        "dodge" :                10,
        "parry" :                -20,
        "attact_type":  "bar",
        "damage_type":  "扎傷",
        ]),

        ([
        "action": "$N勁透匕背，「 "HIG" 狂舞匕斷心 "NOR"」， 將$w使得密不透風，直朝$n衝撞而去! ",
        "damage":               17,
        "dodge" :                10,
        "parry" :                 10,
        "attact_type":  "bar",
        "damage_type":  "劃傷",
        ]),

        ([
        "action": "$N急運內勁使手中$w發出高溫，「"HIG" 傲氣咄如焰 "NOR"」朝$n急殺而去! 。",
        "damage":               18,
        "dodge" :                20,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "燒傷",
        ]),

        ([
        "action": "$N使出「 "HIG" 疾風如影隨 "NOR" 」，勁透全身，遊走$n身邊，緊握手中$w朝$n以八卦方位急扎。",
        "damage":               20,
        "dodge" :               -10,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "扎傷",
        ]),

       ([
        "action": "$N使出「 "HIG" 振翅狂風捲 "NOR" 」，勁透手臂，運起內息使身旁捲起狂風，使地上飛沙走石，趁此良機，$w向$n狠砍而去。",
        "damage":               19,
        "dodge" :               -10,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "砍傷",
        ]),

});

int exert(object me, object target, string arg)
{
        int c,damage,sk,i;
        string msg;
        object weapon;
        weapon=me->query_temp("weapon");
        if(!weapon) return notify_fail("使用『嘆天神匕』必須手中要有匕首。\n");
        if(weapon->query("skill_type")!="dagger") return notify_fail("使用『嘆天神匕』手中必須要有匕首。\n");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("dagger")!="sigh_dagger")
                        return notify_fail("你並沒有在運行『嘆天神匕』。\n");
                me->map_skill("dagger");
                me->reset_action();
                write("你逆行『嘆天神匕』心訣，終止了『嘆天神匕』的運行。\n");
                return 1;
        }
        if(me->query_skill("dagger")<50||me->query_skill("sky-dagger")<60) return notify_fail("你的匕首基礎不夠無法使用『嘆天神匕』。\n");
        				//..sky-dagger是?
        if(me->query("ap")<60|| me->query("hp")<60) return notify_fail("你的身體狀況無法使用『嘆天神匕』。\n");

        //第二次exert
        if(me->query_skill_mapped("dagger")=="sigh_dagger")
        {
          if( !target ) target = offensive_target(me);
          if(!target)   return notify_fail("你正在運行嘆天神匕心訣。\n");
          // 攻擊性的要特別注意要加下面兩行.
           if(!me->can_fight(target))
                return me->can_fight(target);
             c = target->query_armor();
          if(me->query_skill("sigh_dagger")>40)
          {
            if(me->query("ap")>60)
            {
             i=me->query_skill("sigh_dagger");
             if(i>90) i+=10;
             if(random(i)>30) // 這裡建議 random(i)>30改為 random(i)>random(50) 否則skill<31時永遠不會成功
             {
              damage = random(me->query_skill("sigh_dagger"))*3+ random(me->query("str"))*6/5;
              //me->query("str") 最好改用 me->query_str()
              damage = damage/2 + random(damage) + me->query_damage();
              //me->query_damage()不要直接用定數, 請放在第一行damage=.. 裡讓第二行使用damage=damage/2+random(damage);
              // 附註: query_damage() 裡面已經有計算 me->query_str()*2了. 請考慮是否刪除第一行的me->query_str();
              damage -= random(target->query_armor());
              //防禦力已經用c取得了, 這裡改用 damage=damage-c/2-random(c);
 msg = HIW "\n$N忽現大智之色，看破世間一切凡憂，『天地一驚』忽然大現霞光，"+weapon->query("name")+"化為極明之匕向四周狂劈 !!\n\n" NOR;
              msg += HIR "$n一聲慘叫，全身盡數浸入霞光之內，全身無數個灼傷，既深且大，看來不死也剩半條命。\n\n" NOR;
               
              damage = COMBAT_D->Merits_damage(me,target,damage,"sou");
              target->receive_damage("hp",damage,me);
              COMBAT_D->report_status(target);
              me->receive_daemage("ap",20);
              target->start_busy(2);
              me->start_busy(3);
             }
             else {
     msg = HIW "\n$N忽現大智之色，看破世間一切凡憂，『天地一驚』忽然大放霞光，"+weapon->query("name")+"化為極明之匕向四周狂劈 !!\n\n" NOR;
              msg += HIB "只見$n力把心神，盡全力與霞光抗衡，竟與霞光同流， 而避過殺身之劫。\n" NOR ;
              me->receive_daemage("ap",70);
              target->start_busy(2);
              me->start_busy(2);
             }
           if(!me->is_fighting(target)) me->kill_ob(target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           message_vision(msg, me, target);
           return 1;
            }
            else {
             tell_object(me,"你的體力無法負荷這嘆天神匕的巨大消耗。\n");
            }
          }
          else {
            tell_object(me,"你的『嘆天神匕』未到火候，無法使用『天地一驚』\。\n");
          }
        }
        if(me->query_skill_mapped("dagger")=="sigh_dagger") return notify_fail("你正在使用『嘆天神匕』。\n");
        me->map_skill("dagger", "sigh_dagger");
        me->reset_action();
        message_vision("\n"HIW" $N大步一跨，凝望手中匕首，霸氣十足，運起『嘆天神匕』的基本心訣 !! \n"NOR,me);
        me->receive_damage("ap",20); 
        me->start_busy(1);
        //嚴重錯誤. 這個寫法已經不能用了. 請改用 me->skill_active的寫法. 參考/daemon/skill/bagi_fist.c
        //me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
        return 1;
}

void delay(object me,int cost)
{
        object weapon;
        if(!me) return;
        weapon=me->query_temp("weapon");
        if(!weapon)
        {
                me->map_skill("dagger");
                me->reset_action();
                return;
        }
        if(weapon->query("skill_type")!="dagger")
        {
                me->map_skill("dagger");
                me->reset_action();
                return;
        }
        if(me->query_skill_mapped("dagger")!="sigh_dagger")
        {
         return;
        }
        if(me->query("ap")<20)
        {
                me->map_skill("dagger");
                me->reset_action();
                message_vision("\n"HIW"$N的內息錯亂，無法在運行『嘆天神匕』心訣。\n"NOR,me);
                return ;
        }
        if( me->is_fighting() ) me->receive_damage("ap",20);
        // 嚴重錯誤. 這個寫法已經不能用了. 請改用 me->skill_active的寫法. 參考/daemon/skill/bagi_fist.c
        //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
