//获得经验的机会，设为n则为原来的1/n
int get_exp_chance=4;
//战斗方式最大可以达到的潜能
int MaxCombatPot = 6000;

void learn_from_combat(object me,object victim,string type,int dp,int ap,mapping my,mapping your,string attack_skill)
{
    int damage = me->query_temp("apply/damage");
    int y_hp;
    
    if (victim->query("antirobot/deactivity") >= 4) 
    {
        //不fullme，奖励减少
        get_exp_chance = get_exp_chance * victim->query("antirobot/deactivity") * victim->query("antirobot/deactivity");
    }
    else
    {
        get_exp_chance = 4;
    }
    
    if(type == "dodge")
    {
        if( dp < ap && (!userp(victim) || !userp(me))
            &&	random(your["jing"]*100/your["max_jing"] + your["int"]) > 50 )
        {
            if ( random(get_exp_chance) == 1 )
                your["combat_exp"] += (random(your["int"]/5)+1);
            victim->improve_skill("dodge", 1);
        }
        
        // This is for NPC only. NPC have chance to get exp when fail to hit.
        //if( (ap < dp) && random(ExpTopChance) >= expchance && !userp(me) )
        //iszt@pkuxkx, 2007-03-13, added !xytaskd
        if( (ap < dp) && !userp(me) && my["id"][0..5] != "menggu")
        {
            if ( random(get_exp_chance) == 1 )
                if( random(my["int"]) > 15 ) 
                    my["combat_exp"] += 1;
            me->improve_skill(attack_skill, random(my["int"]));
        }
    }
    else if(type == "parry")
    {
        if( dp < ap && (!userp(victim) || !userp(me))
            &&	random(your["jing"]*100/your["max_jing"] + your["int"]) > 50 ) {
            if ( random(get_exp_chance) == 1 )
                your["combat_exp"] += (random(your["int"])+1);
            victim->improve_skill("parry", (random(your["int"])+1));
        }
    }
    else if(type == "hit")
    {

        if( (!userp(me) || !userp(victim)))
        {
            //				if( (ap < dp) && random(ExpTopChance) >= expchance
            if( (ap < dp) && (random(my["jing"]*100/my["max_jing"] + my["int"]) > 30) )
            {
                if ( random(get_exp_chance) == 1 )
                {
                    my["combat_exp"] += (random(my["int"]/5)+1);
                    if( my["potential"] - my["learned_points"] < MaxCombatPot )
                        my["potential"] += (random(my["int"]/5)+1);
                    me->improve_skill(attack_skill, (random(my["int"]/5)+1));
                }
            }
            y_hp=your["max_qi"] + your["qi"];
            if(floatp(y_hp)) y_hp=to_int(y_hp);
            if( random(y_hp) < damage )
            {
                if ( random(get_exp_chance) == 1 )
                {
                    your["combat_exp"] += (random(your["int"]/5)+1);
                    if( your["potential"] - your["learned_points"] < MaxCombatPot )
                        your["potential"] += (random(your["int"]/5)+1);
                }
            }
        }
    }
    
    if ( floatp(your["combat_exp"]) && !intp(your["combat_exp"]) )
    	your["combat_exp"]=to_int(your["combat_exp"]);
    
    if ( floatp(my["combat_exp"]) && !intp(my["combat_exp"]) )
    	my["combat_exp"]=to_int(my["combat_exp"]);
}