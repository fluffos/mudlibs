// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Things which are common to all combat modules

#include <combat.h>

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
    class combat_result array res = ({ new(class combat_result, 
                                           special : RES_FATAL | RES_NO_RESISTANCE,
                                           kind : weapon_type) });
    
    res = negotiate_result(res);
    print_result(res);
    query_target()->do_damage(res);
}

class combat_result array take_a_swing(object);
void check_condition(int);

void attack() {
    object target;
    mixed tmp;
    class combat_result array result;
    
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
    string ret;
    
    if (query_ghost())
        return //"$N $vare dead.  Other than that, things are going well for $n.\n";
               "$N死掉了。除开这，$n到还不错。\n";
    if (query_asleep())
        ret = //"$N $vare asleep.\n";
              "$N正在睡眠中。\n";  
    else if (query_stunned())
        ret = //"$N $vare stunned.\n";
              "$N晕倒了。\n";  
    else
        ret = "";

    switch (query_hp() * 100 / query_max_hp()) {
    case 0..10:
        return ret + //"$N $vare about to die.\n";
                     "$N已经奄奄一息了。\n";   
    case 11..25:
        return ret + //"$N $vare in very bad shape.\n";
                     "$N受了相当重的伤，只怕有生命危险。\n";   
    case 26..50:
        return ret + //"$N $vare badly wounded.\n";
                     "$N已经伤痕累累，正在勉力支撑着不倒。\n";   
    case 51..75:
        return ret + //"$N $vare wounded.\n";
                     "$N受了几处伤，看起来状况不太好。\n";   
    case 76..85:
        return ret + //"$N $vare lightly wounded.\n";
                     "$N看起来可能受了些轻伤。\n";   
    case 86..95:
        return ret + //"$N $vare a bit hurt, but nothing serious.\n";
                     "$N似乎受了点轻伤，不过从表面看不出来。\n";   
    case 96..99:
        return ret + //"$N $vare a bit roughed up.\n";
                     "$N似乎有些疲惫，但仍然十分有活力。\n";   
    case 100:
        return ret + //"$N $vare in perfect health.\n";
                     "$N气色很好，毫发无伤。\n";
    default:
        error("query_hp() out of bounds\n");
    }
}

int query_ghost()
{
    return hit_points::query_ghost();
}
