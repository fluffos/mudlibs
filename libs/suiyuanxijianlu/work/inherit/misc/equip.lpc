// equip.c

inherit ITEM;
inherit F_EQUIP;

void setup()
{
        if( !query("armor_prop/dodge") && (weight() >= 3000) )
                set("armor_prop/dodge", - weight() / 3000 );
        if( !query("weapon_prop/dodge") && (weight() >= 3000) )
                set("weapon_prop/dodge", - weight() / 3000 );
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (! mapp(query_temp("daub")))
                return;

        return COMBAT_D->hit_with_poison(me, victim, this_object());
}

mixed valid_damage(object me, object victim, int damage_bonus)
{
        if (! mapp(query_temp("daub")))
                return;

        if (me->query_temp("weapon"))
                // the attacker has weapon, so he won't be poison by my cloth
                return;

        return COMBAT_D->hit_poison(me, victim, this_object());
}

