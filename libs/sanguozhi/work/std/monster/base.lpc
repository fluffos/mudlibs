// Updated by stefan on 10 Jan 1997
// modified by fire on March 14, 1998
/* Do not remove the headers from this file! see /USAGE for more info. */
// Things which are common to all combat modules
#include <combat.h>
#include <sanguo.h>

inherit LIVING;
inherit M_DAMAGE_SOURCE;
inherit __DIR__ "base/wield";
inherit __DIR__ "base/target";
inherit __DIR__ "base/death";
inherit __DIR__ "base/results";
inherit __DIR__ "base/behaviors";
inherit __DIR__ "base/hit_points";
#ifdef COMBAT_USES_HEARTBEATS
inherit __DIR__ "base/heart_beat";
#else
inherit __DIR__ "base/non_heart_beat";
#endif
#ifdef USE_BODYSLOTS
inherit __DIR__ "base/bodyslots";
#endif
void remove() {
#ifndef COMBAT_USES_HEARTBEATS
    non_heart_beat::remove();
#endif
    m_damage_source::remove();
    living::remove();
}
void dispatch_opponent() {
    class combat_result * res = ({ new(class combat_result, 
                                           special : RES_FATAL |
RES_NO_RESISTANCE,
                                           kind : weapon_type) });
    
    res = negotiate_result(res);
    print_result(res);
    query_target()->do_damage(res);
}
class combat_result * take_a_swing(object);
void check_condition(int);
void attack() {
    object target;
    mixed tmp;
    class combat_result * result;
    
    if (tmp = check_condition(1)) {
        if (tmp[<1] == '\n')
            write(tmp);
        else
            simple_action(tmp + //" so $p blows are ineffective.\n"
                                "因此，$p这一击毫无成效。\n");
        return;
    }
    if (query_ghost() || !(target = get_target())) {
        attacking = 0;
        return;
    }
    if (target->query_asleep()) {
        /* Our target is unconscious.  We get to have our way with them
         * *evil grin*
         */
        target_is_asleep();
        return;
    }
    result = take_a_swing(target);
    if (!result) return;
    
    result = negotiate_result(result);
    print_result(result);
    target->hit_living(result);
}
string diagnose() {
    
    return M_OUT->fight_result(this_object());
}
int query_ghost()
{
    return hit_points::query_ghost();
}
