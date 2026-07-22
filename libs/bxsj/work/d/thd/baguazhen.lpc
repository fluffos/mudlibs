#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HBBLU"阵中"NOR);
        setup();
}

void init()
{
     object me = this_player();
     object env = me->query("lastroom");
     me->move(env);
     me->start_busy(1);
     switch(random(8)) {
       case 0: //休
         me->start_busy(10);
         message_vision(HIR"$N踏入“休”门，只觉得脚步缓慢，无力可施。\n"NOR, me);
        break;
       case 1: //生
         if (env->query("th_buzhen")) {
         env->set("long", env->query("org_desc"));
         env->set("exits", env->query("org_exits"));
         env->delete("org_desc");
         env->delete("org_exits");
         env->delete("th_buzhen");
         env->delete("th_pozhen");
         env->delete("th_zhen_owner");
         }
         message_vision(HIG"$N踏入“生”门，破解了这个阵法！\n"NOR, me);
        break;
       case 2: //伤
         me->set_temp("last_damage_from", "受到八卦阵中机关攻击而");
         me->receive_wound("qi",100+random(100));
         message_vision(HIY"$N踏入“伤”门，阵中机关突然发动，$N立时受了点伤！\n"NOR, me);
        break;
       case 3: //杜
         me->set("neili",0);
         message_vision(HIB"$N踏入“杜”门，只觉得阻力重重，耗尽了内力方才退回原位。\n"NOR, me);
        break;
       case 4: //景
         me->set_temp("last_damage_from", "受到八卦阵中幻影迷了心志");
         me->receive_wound("jing",100+random(100));
         message_vision(HIM"$N踏入“景”门，陡然眼前出现幻影，头脑晕眩，不知不觉的回到了原地。\n"NOR, me);
        break;
       case 5: //死
         message_vision(HBRED"$N踏入“死”门，突然弓失长矛，火药土块全都漫天射来！\n"NOR, me);
         if (random(me->query_dex()) > 3) {
            message_vision(HBRED"$N闪避不及，当场送命！\n"NOR, me);
            me->set_temp("last_damage_from", "踏入八卦阵中“死”门而");
            me->die();
         } else {
            message_vision(HBRED"$N拼命抵抗，虽然逃出生天，元气已经是大损！\n"NOR, me);
            me->add("max_neili", -2-random(4));
         }
        break;
       case 6: //惊
         me->set_temp("last_damage_from", "受到八卦阵中可怖情况吓");
         me->add("jingli",-100-random(100));
         message_vision(HIW"$N踏入“惊”门，倒抽了一口冷气，全身颤抖，面白如纸，急忙退回！\n"NOR, me);
        break;
       case 7: //开
         message_vision(HIC"$N踏入“开”门，不知道为何绕了一圈又走回了原地。\n"NOR, me);
        break;
     }
}

