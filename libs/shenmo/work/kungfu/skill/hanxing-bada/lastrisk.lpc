// hanxing-fada/lastrisk.c

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int i,s;
        string msg;
        object *ob;
        object weapon;
        s = me->query_skill("hanxing-bada", 1);
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("孤注一掷只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "throwing")
           return notify_fail("你必须先有暗器。\n");

        if( s < 60)
                return notify_fail("你的寒星八打修为太浅。\n");
        msg = CYN "$N孤注一掷，发出所有暗器攻向$n!";
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);         
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(2);
        ob = all_inventory(me);         
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( (string)ob[i]->query("equipped")!="wielded" ) continue;
        ob[i]->unequip();
                  ob[i]->move(environment(me));}
       
        return 1;
}

