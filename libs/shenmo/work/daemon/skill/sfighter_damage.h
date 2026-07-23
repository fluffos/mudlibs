
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int mylvl,tlvl,i,j,k;
        string msg,msgcol;
        object tweapon,target;
        target=victim;
        mylvl=me->query_skill("power",1);
        tlvl=target->query_skill("power",1);
        tweapon=target->query_temp("weapon");         
        i=mylvl+me->query_skill("unarmed",1)/2;
        j=target->query_skill("parry",1)*2+target->query_skill("dodge",1);

        if(mylvl>300 && me->query_skill_mapped("force")=="power"){ 
        if( random(i) > (tlvl+j)/9 ) {
                damage_bonus=damage_bonus+damage_bonus*stage(mylvl)/10;
                if (damage_bonus>3000)    damage_bonus=3000;
                victim->receive_wound("kee", damage_bonus/10);
                if (!target->is_busy())  target->start_busy(1);
                msgcol=level_description(stage(mylvl));
                switch(random(2)) {
                        case 0: msg=HIW"$n"HIW"被$N"HIW"的"NOR+msgcol+HIW"一震，气血翻腾不休！\n"NOR;
                        case 1: msg=HIW"$N"HIW"劲力一吐，"NOR+msgcol+HIW"气劲激射而出,击中$n"HIW"的$l！\n"NOR;
                }
                return msg;
            }
         }
}

