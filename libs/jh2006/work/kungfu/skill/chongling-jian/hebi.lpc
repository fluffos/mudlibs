// chongling-jian perform hebi 双剑合璧
// Modify by Looklove 2001.4.6 fix 要求fanliangyi-dao的bug

#include <ansi.h>
#define ME  "你现在不能使用双剑合璧。\n"
#define TAR  "对方现在不能使用双剑合璧。\n"

int check_fight(object me, object target, int amount);
private int remove_effect(object me, object target, int amount);

int perform(object me, object target)
{
        object *enemy;
        int i,j,k,amount;
        object wep1, wep2;
        wep1 = me->query_temp("weapon");

        if( !target || target == me) return notify_fail("你要和谁双剑合璧？\n");

        if (me->query_temp("hebi")) return notify_fail(ME);
        if (target->query_temp("hebi")) return notify_fail(TAR);
        if (me->query("jingli") < 200) return notify_fail(ME);
        if (target->query("jingli") < 200) return notify_fail(TAR);
        if (me->query("neili") < 1000) return notify_fail(ME);
        if (target->query("neili") < 1000) return notify_fail(TAR);
        if (!me->is_fighting()) return notify_fail("双剑合璧只能在战斗中使用。\n");
        if (me->is_fighting(target)) return notify_fail("你正在和对方打架，使用双剑合璧干什么？\n");
        if (me->query("gender") == target->query("gender")) return notify_fail("你们是同性，还合壁什么啊？\n");
        if( (int)me->query_skill("chongling-jian", 1) < 140 ) return notify_fail(ME);
        if( (int)me->query_skill("zixia-gong", 1) < 140 ) return notify_fail(ME);
        if( me->query_temp("leidong")) return notify_fail("你正在使用雷动九天！\n");
        if( target->query_temp("leidong")) return notify_fail("对方正在使用雷动九天！\n");
        if (!wep1 || wep1->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "chongling-jian")
                return notify_fail(ME);
        
        enemy = me->query_enemy();
        k = sizeof(enemy);
        while (k--)
        if (target->is_fighting(enemy[k])) break;
        if (k<0) return notify_fail(target->name()+"并没有和你的对手在交战。\n");

        if( (int)target->query_skill("chongling-jian", 1) < 140 )
                return notify_fail(TAR);
        if( (int)target->query_skill("zixia-gong", 1) < 140 )
                return notify_fail(TAR);
        wep2 = target->query_temp("weapon");
        if (target->is_busy() || !wep2 || wep2->query("skill_type") != "sword"
        || target->query_skill_mapped("sword") != "chongling-jian")
                return notify_fail(TAR);
        message_vision(HIY "\n只见他二人在半空中轻身飘开，俱是嘴角含笑，姿态神情，便似裹在一团和煦的春\n"+
                           "\n风之中。不知不觉之间，都回想到从前的情景，出剑转慢，眉梢眼角，一招一式，\n"+
                           "\n优雅如仙，你不由看的呆了......\n" NOR, me, target);
        me->set_temp("hebi", 1);
        target->set_temp("hebi", 1);
        me->receive_damage("jingli", 100);
        target->receive_damage("jingli", 100);
        me->receive_damage("neili", 300);
        target->receive_damage("neili", 300);
        me->start_busy(1);
        target->start_busy(1);
        i = (int)me->query_skill("chongling-jian", 1);
        j = (int)target->query_skill("chongling-jian", 1);
        amount = ((i + j)/10 + (int)me->query_per() + (int)target->query_per())/5;
        if( amount > 20 ) amount = 20;
        me->add_temp("apply/dexerity", amount);
        me->add_temp("apply/strength", amount);
        target->add_temp("apply/dexerity", amount);
        target->add_temp("apply/strength", amount);
        enemy[k]->start_busy(amount/3);
        check_fight(me, target, amount);
        return 1;
}

int check_fight(object me, object target, int amount)
{  
        object wep1, wep2;
        if(!me && !target) return 0;
        if(!me && target){
           target->add_temp("apply/dexerity", -amount);
           target->add_temp("apply/strength", -amount);
           target->delete_temp("hebi");
           return 0;
        }
        if( me && !target){
           me->add_temp("apply/dexerity", -amount);
           me->add_temp("apply/strength", -amount);
           me->delete_temp("hebi");
	   return 0;
        }
        wep1 = me->query_temp("weapon");
        wep2 = target->query_temp("weapon");
        if(!me->is_fighting()
         || !living(me)
         || me->is_ghost()
         || !wep1
         || !target->is_fighting()
         || !living(target)
         || target->is_ghost() 
         || !wep2
         || me->query_skill_mapped("sword") != "chongling-jian" 
         || target->query_skill_mapped("sword") != "chongling-jian"
         || environment(me) != environment(target))
              remove_effect(me, target, amount);
        else {
              call_out("check_fight", 1, me, target, amount);
        }
        return 1;
}

private int remove_effect(object me, object target, int amount)
{
        if(living(me)
         && !me->is_ghost()
         && living(target)
         && !target->is_ghost())
           message_vision(HIY "\n$N和$n双剑合璧用完，灵犀互通，相视一笑，各自收招。\n" NOR, me, target);

        me->add_temp("apply/dexerity", -amount);
        me->add_temp("apply/strength", -amount);
        target->add_temp("apply/dexerity", -amount);
        target->add_temp("apply/strength", -amount);
        me->delete_temp("hebi");
        target->delete_temp("hebi");
        return 0;
}
