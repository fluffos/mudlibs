// force.c



inherit SKILL;



mixed hit_ob(object me, object victim, int damage_bonus, int factor)

{

        int damage;



        me->add("force", - factor );

        damage = (int)me->query("force")/20 + factor

                - (int)victim->query("force")/25;



        if( damage < 0 ) {

                if( !me->query_temp("weapon")

                &&      random(victim->query_skill("force")) > me->query_skill("force")/2 ) {

                        damage = - damage;

                        me->receive_damage( "qi", damage * 2 );

                        me->receive_wound( "qi", damage );

                        if( damage < 10 ) return "$n天魔金身一振，竟能抵挡住$N的猛烈攻击。\n";

                        else if( damage < 20 ) return "$n运起天魔金身，浑身肌肉膨胀逾倍，隐隐透出金光，把$N的攻击震开了。\n";

                        else if( damage < 40 ) return "$n天魔金身发挥强猛的暴震力，把$N震开五六步。\n";

                        else return "$n将天魔金身提升到极尽，浑身金光暴现，将$N震飞出几丈之外。\n";

                }

                if( damage_bonus + damage < 0 ) return - damage_bonus;

                return damage;

        }



        damage -= victim->query_temp("apply/armor_vs_force");

        if( damage_bonus + damage < 0 ) return - damage_bonus;

        if( random(me->query_skill("force")) < damage )

                return damage;

}

