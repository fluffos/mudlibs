varargs int do_gongji(object me, string lb)
{
    mapping action;
    int damage, damage_bonus;
    object weapon = me->query_temp("weapon");

    me->reset_action();
    action = me->query("actions");
    if( !mapp(action) ) {
        me->reset_action();
        action = me->query("action");
        if( !mapp(action) ) {
            return 0;
        }
    }

            if (weapon) damage = weapon->query("weapon_prop/damage");
            damage += me->query_temp("apply/damage");
            damage = (damage + random(damage)) / 2;
            if( action["damage"] )
                damage += action["damage"] * damage / 100;
            damage_bonus = me->query_str();

