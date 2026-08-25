// Taniwha, util routine for "membership"
int check_isin(mapping map,object ob)
{
    mixed list;
    int i;
    list = map["race"];
    if(pointerp(list) && member_array(ob->query_race(),list) != -1) return 1;
    if(stringp(list) && (string)list == (string)ob->query_race()) return 1;
    list = map["guild"];
    if(pointerp(list) && member_array(ob->query_guild(),list) != -1) return 1;
    if(stringp(list) && (string)list == (string)ob->query_guild()) return 1;
    list = map["group"];
    if(pointerp(list) && member_array(ob->query_group_name(),list) != -1) return 1;
    if(stringp(list) && (string)list == (string)ob->query_group_name()) return 1;
    list = map["player"];
    if(pointerp(list) && member_array(ob->query_name(),list) != -1) return 1;
    if(stringp(list) && (string)list == (string)ob->query_name()) return 1;
    list = map["deity"];
    if(pointerp(list) && member_array(ob->query_deity_name(),list) != -1) return 1;
    if(stringp(list) && (string)list == (string)ob->query_deity_name()) return 1;
    list = map["alignment"];
    if(pointerp(list) && member_array(ob->query_align_name(),list) != -1) return 1;
    if(stringp(list) && (string)list == (string)ob->query_align_name()) return 1;
    list = map["ethics"];
    if(pointerp(list) && member_array(ob->query_ethical_name(),list) != -1) return 1;
    if(stringp(list) && (string)list == (string)ob->query_ethical_name()) return 1;
    list = map["property"];
    if(pointerp(list))for(i = 0; i < sizeof(list); i++)
        {
            if(stringp(list[i])&& ob->query_property(list[i])) return 1;
        }
    if(stringp(list) && ob->query_property(list)) return 1;
    return 0;
}


int do_aggressive_check(object ob, int aggressive,object me,int minplayer,mapping hated,mapping loved)
{
   /* mixed *list; */
   /* int level; */
    if(!ob) return 0;
    if ( ob->query_invis() )  
        return 0;
    if(!ob->query_alive()) 
        return 0;
    // Taniwha, why I did this. Race/guild/group/player
    if(mappingp(loved))
    {
        if(check_isin(loved,ob)) 
        {
            aggressive = 0;
        }
    }
    if(mappingp(hated))
    {
        if(check_isin(hated,ob)) 
        {
            if(aggressive == 5) aggressive = 2;
            else aggressive = 1;
        }
    }
    if(ob->query_level() < minplayer) return 0; /* bypass weaklings */
    switch( aggressive )
    {
    case 0:
        return 0;
    case 1:
        if ( !interactive(ob) ) 
            return 0;
        if(random(ob->query_cha()) > 16) return 0; // Friends
        /* fall through */
    case 2:
   if( ob->query_hide_shadow() ) return 0;
            return 1;
        break;
    case 3:
        if ( !interactive(ob) ) 
            return 0;
        /* fall through */
    case 4:
        return 1; // Attack all.
    case 5:
        return 0; // Hack for set hated, if it's a hated race, it shifts the mode to 2
    default:
        return 1;
    }  /* switch( aggressive ) */
}
string expand_string(object me,string in_str, object on, object attacker)
{
    string *str, ret;
    int i, j, add_dollar;
    int k,l;


    object liv, *obs, ob,*attacker_list;

    str = explode(in_str, "$");
    ret = "";

    // Fix by Wonderflug, only parse every SECOND argument, just tack on the 
    // others.
    for (i=0; i<sizeof(str); i++)
        if ( !( i % 2) )
            ret += str[i];
        else
            switch (str[i][0])
        {
        case 'm' :
            ob = me;
            break;
        case 'l' :
            if (!ob)
            {
                if (!liv)
                {
                    obs = all_inventory(environment(me));
                    k = sizeof(obs);
                    l = random(k);
                    for(j = 0; j < k; j++)
                    {
                        if(living(obs[l]) && obs[l] != me)
                        {
                            liv = obs[l];
                            break;
                        }
                        l++;
                        l %= k;
                    }
                }
                if (!liv)  /* No one here to see us blow up anyway ;) */
                    ob = me;
                ob = liv;
            }
            if (!ob)
            {
                attacker_list = me->query_attacker_list();
                if(!sizeof(attacker_list))
                    break;
                if (!attacker)
                    attacker = attacker_list[random(sizeof(attacker_list))];
                ob = attacker;
            }
        case 'o' :
            if (!ob)
            {
                if(!on)
                {
                    obs = all_inventory(environment(me));
                    k = sizeof(obs);
                    l = random(k);
                    ob = me; /* should all else fail */
                    for(j = 0; j < k; j++)
                    {
                        if ( obs[l] != me)
                        {
                            on = obs[l];
                            break;
                        }
                        l++;
                        l %= k;
                    }
                }
                else
                    ob = on;
            } /* if (!ob) */
            switch (str[i][1..1000])
            {
            case "name" :
                ret += (string)ob->query_name();
                add_dollar = 0;
                break;
            case "cname" :
                ret += (string)ob->query_cap_name();
                add_dollar = 0;
                break;
            case "gender" :
                ret += (string)ob->query_gender_string();
                add_dollar = 0;
                break;
            case "poss" :
                ret += (string)ob->query_possessive();
                add_dollar = 0;
                break;
            case "obj" :
                ret += (string)ob->query_objective();
                add_dollar = 0;
                break;
            case "gtitle" :
                ret += (string)ob->query_gender_title();
                add_dollar = 0;
                break;
            case "pronoun" :
                ret += (string)ob->query_pronoun();
                add_dollar = 0;
                break;
            case "race":
                ret += (string)ob->query_race();
                add_dollar =0;
                break;
            case "guild":
                ret += (string)ob->query_guild_name();
                add_dollar =0;
                break;
            case "group":
                ret += (string)ob->query_group_name();
                add_dollar =0;
                break;
            case "clan":
                ret += (string)ob->query_race_group_name();
                add_dollar =0;
                break;

            default :
                if (add_dollar)
                    ret += "$";
                ret += str[i];
                add_dollar = 1;
                break;
            } /* switch str[i][1.. */

            ob = 0;
            break;

        default :
            if (add_dollar)
                ret += "$";
            ret += str[i];
            add_dollar = 1;
            ob = 0;
            break;
        }

    if (ret[strlen(ret)-1] == '$')
        ret = ret[0..strlen(ret)-2];
    if(!stringp(ret))
        return "looks confused for a moment, pauses, and continues ";
    return ret;
}

void spell_heart_beat(object me,object *attacker_list,mixed attack_spells)
{
    int i;
    int k, silent;
    string spell_target;
    i = random(sizeof(attack_spells)/3);
    i *= 3;
    if (random(100) > attack_spells[i] ) return;

    /* Check that we can cast a spell */
    if ( attack_spells[i+2][2] == 4 && me->check_props("noguild") )
        return;
    if ( me->check_props("nocast") ) return;

    /* Find a target */
    if (attack_spells[i+2][2] == 1)
    {
        spell_target = "";
        for (k=0;k<(sizeof(attacker_list)-1);k++)
            spell_target += attacker_list[k]->query_name()+",";
        spell_target += attacker_list[sizeof(attacker_list)-1]->query_name();
    }
    else if ( attack_spells[i+2][2] == 2 )
        spell_target = "all";
    else if ( attack_spells[i+2][2] == 3 )
        spell_target = me->query_name();
    else spell_target =
        attacker_list[random(sizeof(attacker_list))]->query_name();

    if (sizeof(attack_spells[i+2]) > 3) 
        silent = attack_spells[i+2][3];
    else 
        silent = 0;

    call_other(attack_spells[i+2][0], attack_spells[i+2][1],
      spell_target, me, silent);
    /* end of the attack spell thingie */
}

