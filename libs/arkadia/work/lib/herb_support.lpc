/*
 * Support for herbs that is used for potions as well.
 *
 * /Nick
 */
#pragma strict_types

#include <macros.h>
#include <stdproperties.h>
#include <ss_types.h>
#include <herb.h>
#include <composite.h>
#include <language.h>

#define KONC this_player()->koncowka

/*
 * Variables
 */
string poison_file;
mixed *effects,*poison_damage;

/* 
 * Function name: do_tmp_stat
 * Description:   This function is called from the effects if the herb is
 *                stat-affecting. One stat is randomly increased
 *                temporarily, lasting as long as strength * 10. If strength is
 *                negative, the stat is decreased instead.
 * Arguments:     stat     - The number of the stat
 *		  strength - How strong the herb is - time effect will last
 */
void
do_tmp_stat(int stat, int strength)
{
    string konc;
    
    konc = this_player()->koncowka("y", "a");
    
    if (strength > 0)
    {
     	this_player()->add_tmp_stat(stat, random(3) + 1,
		strength / 2 + random(strength));
    	if (stat == SS_STR) write("Czujesz sie silniejsz" + konc +
    	    ".\n");
    	else if (stat == SS_DEX) write("Czujesz sie zreczniejsz" + 
    	    konc + ".\n");
    	else if (stat == SS_CON) write("Czujesz sie bardziej wytrzymal" +
    	    konc + ".\n");
    	else if (stat == SS_INT) write("Czujesz sie bardziej inteligentn" +
    	    konc + ".\n");
    	else if (stat == SS_WIS) write("Czujesz sie bardziej madr" +
    	    konc + ".\n");
    	else if (stat == SS_DIS) write("Czujesz sie bardziej odwazn" +
    	    konc + ".\n");
    	    
        return ;
    }

    if (strength < 0)
    {
        strength = -strength;
    	this_player()->add_tmp_stat(stat, -(random(3) + 1), strength / 2 +
		random(strength));
    	if (stat == SS_STR) write("Czujesz sie oslabion" + konc + ".\n");
    	else if (stat == SS_DEX) write("Czujesz sie bardziej niezdarn" +
    	    konc + ".\n");
    	else if (stat == SS_CON) write("Czujesz sie mniej wytrzymal" +
    	    konc + ".\n");
    	else if (stat == SS_INT) write("Czujesz sie mniej inteligentn" +
    	    konc + ".\n");
    	else if (stat == SS_WIS) write("Czujesz sie mniej madr" +
    	    konc + ".\n");
    	else if (stat == SS_DIS) write("Czujesz sie mniej odwazn" +
    	    konc + ".\n");
    	    
        return;
    }
}

/*
 * Function name: add_resistance
 * Description:   This function is called from the herb-effects, and adds some
 *                resistance in the player. Max strength is 40.
 *                The resistance added is an additive resistance.
 *                (See /doc/man/general/spells for more info on resistance)
 * Arguments:     res_type - The resistance type
 *		  strength - How strong the herb is
 */
void
add_resistance(mixed res_type, int strength)
{
    object res_obj;
    res_obj = clone_object(RESISTANCE_FILE);
    if (strength > 40)
	strength = 40;
    res_obj->set_strength(strength);
    res_obj->set_time(5 * (40 - strength / 2) + 5 * random(strength));
    res_obj->set_res_type(res_type);
    res_obj->move(this_player());
    write("Czujesz sie bardziej odporn" + this_player()->koncowka("y", "a") +
        ".\n");
}

/*
 * Function name: special_effect
 * Description:   Redefine this when you have done set_effect(HERB_SPECIAL);
 *                to do the effect of your herb.
 */
void
special_effect()
{
    write("Nie czujesz zadnego efektu.\n");
}

/* 
 * Function: do_herb_effects
 * Description: In this function the effect(s) of the herb are resolved.
 *              To define a standard effect, do 
 *              set_effect(herb_type, str, strength); in create_herb(),
 *              where herb_type is one of the herb-types in /sys/herb_types.h,
 *              str is a string for the affect type, and strength is an
 *              integer for the strength of the effect.
 *              Read /doc/man/general/herbs for more information.
 *              One effect per herb should be the norm, but adding one or
 *              two is ok, as long as they don't make the herb too good.
 */
nomask int
do_herb_effects()
{
    int strength, res, i, n, a;
    string type;
    object poison, tp, to, *inv;

    seteuid(getuid());
    tp = this_player();
    to = this_object();
    i = 0;
    while (i < sizeof(effects))
    	switch(effects[i])
        {
      	    case HERB_HEALING:
		type = lower_case(effects[i + 1]);
		strength = effects[i + 2];
		res = 100 - tp->query_magic_res(MAGIC_I_RES_POISON);
		if (!type || type == "hp")
	  	{
	    	    if (strength < 0) 
	      	    { 
			tp->reduce_hit_point(res * random(-strength) / 100);
			if (tp->query_hp() <= 0)
			{
			    write("To chyba nie byl najlepszy pomysl...\n");
		  	    tp->do_die(to);
		  	    this_object()->remove_object();
			}
			write("Czujesz sie gorzej.\n");
	      	    }
	    	    else if (strength > 0)
		    {
	      		tp->heal_hp(strength);
			write("Czujesz sie lepiej.\n");
		    }
	    	    else
			write("Nie czujesz zadnego efektu.\n");
	  	}
		else if (type == "mana")
	  	{
	    	    if (strength < 0)
		    {
	      	        tp->set_mana(tp->query_mana() - res *
				random(-strength) / 100);
			write("Czujesz sie bardziej zmeczon" +
			    tp->koncowka("y", "a") + " mentalnie.\n");
	    	    }
		    else if (strength > 0)
		    {
	      		tp->set_mana(tp->query_mana() + strength);
	    		write("Czujesz sie mniej zmeczon" + 
	    		    tp->koncowka("y", "a") + " mentalnie.\n");
		    }
		    else
			write("Nie czujesz zadnego efektu.\n");
	  	}
		else if (type == "fatigue")
	  	{
	    	    if (strength < 0)
		    {
	     		tp->set_fatigue(tp->query_fatigue() - res * 
			   random(-strength) / 100);
			write("Czujesz sie bardziej zmeczon" +
			    tp->koncowka("y", "a") + ".\n");
		    }
		    else
		    if (strength > 0)
		    {
			write("Czujesz sie mniej zmeczon" +
			    tp->koncowka("y", "a") + ".\n");
	      		tp->set_fatigue(tp->query_fatigue() + strength);
		    }
		    else
			write("Nie czujesz zadnego efektu.\n");
	  	}
		else
		    write("Nie czujesz zadnego efektu.\n");
		i += 3;
		break;
	    case HERB_ENHANCING:
		type = lower_case(effects[i + 1]);
		strength = effects[i + 2];
		res = 0; //(!!!)
		if (!strength || ((strength < 0) && (res > random(100))))
		    write("Nie czujesz zadnego efektu.\n");
		else
		switch(type)
	  	{
	  	    case "dex":
	    		do_tmp_stat(SS_DEX, strength);
	   		break;
	 	    case "str":
	    		do_tmp_stat(SS_STR, strength);
	    		break;
		    case "con":
	    		do_tmp_stat(SS_CON, strength);
	    		break;
		    case "int":
	    		do_tmp_stat(SS_INT, strength);
	    		break;
		    case "wis":
	    		do_tmp_stat(SS_WIS, strength);
	    		break;
		    case "dis":
	    		do_tmp_stat(SS_DIS, strength);
	    		break;
		    case "acid":
	    		add_resistance(MAGIC_I_RES_ACID, strength);
	    		break;
		    case "cold":
	    		add_resistance(MAGIC_I_RES_COLD, strength);
	    		break;
	 	    case "electr":
	    		add_resistance(MAGIC_I_RES_ELECTRICITY, strength);
	    		break;
		    case "fire":
	    		add_resistance(MAGIC_I_RES_FIRE, strength);
	    		break;
		    case "magic":
	    		add_resistance(MAGIC_I_RES_MAGIC, strength);
	    		break;
		    case "poison":
	    		add_resistance(MAGIC_I_RES_POISON, strength);
	    		break;
	 	    default:
	    		write("You don't feel any effect.\n");
	    		break;
	  	}
		i += 3;
		break;
	    case HERB_POISONING:
		type = lower_case(effects[i + 1]);
		strength = effects[i + 2];
		if (poison_file)
	  	{
	 	    poison = clone_object(poison_file);
		    if (!poison)
	  	    {
		        write("Nie czujesz zadnego efektu.\n");
		        break;
	 	    }
	    	    if (strength)
	      		poison->set_strength(strength);
		    if (type)
	      		poison->set_poison_type(type);
		    if (poison_damage)
		        poison->set_damage(poison_damage);
	 	    poison->move(tp);
	 	    poison->start_poison();
	  	}
		else 
	  	{
	 	    poison = clone_object(POISON_FILE);
	 	    poison->set_strength(strength);
		    poison->set_poison_type(type);
		    if (poison_damage)
		        poison->set_damage(poison_damage);
		    poison->move(tp);
		    poison->start_poison();
	  	}
		i += 3;
		break;
	    case HERB_CURING:
		type = lower_case(effects[i + 1]);
		strength = effects[i + 2];
		inv = all_inventory(tp);
		n = 0;
		a = 0;
		while(n < sizeof(inv))
		{
	 	    if (function_exists("cure_poison", inv[n]) == POISON_FILE)
       			if (inv[n]->cure_poison(({type}), strength))
			{
			    a++;
			    strength /= 2;
			}
	    	    n++;
	  	}
		if (a <= 0)
		    write("Nie czujesz zadnego efektu.\n");
		i += 3;
		break;
   	    case HERB_SPECIAL:
		special_effect();
		i += 3;
		break;
   	    default:
		write("Nie czujesz zadnego efektu.\n");
		i+=3;
		break;
        }

    return 1;
}

/*
 * Function name: set_effect
 * Description:	  Give the herb or potion an effect (see herb.h)
 * Arguments:	  herb_type   - What type of effect
 *		  affect_type - And what exactly do we affect?
 *		  strength    - The strength
 */
void
set_effect(int herb_type, string affect_type, int strength)
{
    effects = ({ herb_type, affect_type, strength });
}

/*
 * Function name: add_effect
 * Description:   Adds one more effect to a herb or potion
 * Arguments:	  herb_type   - What type of effect
 *                affect_type - And what exactly do we affect?
 *                strength    - The strength
 */
void
add_effect(int herb_type, string affect_type, int strength)
{
    effects += ({ herb_type, affect_type, strength });
}

/*
 * Function name: clear_effect
 * Description:   Remove all earlier set effects
 */
void
clear_effect()
{
    effects = ({});
}

/*
 * Function name: query_effect
 * Description:   Get the effect array
 * Returns:	  The array
 */
mixed *
query_effect() { return effects; }

/*
 * Function name: set_poison_file
 * Description:   Set the file name of poison to use instead of standard
 * Arguments:     str - The file name
 */
void
set_poison_file(string str) { poison_file = str; }

/*
 * Function name: query_poison_file
 * Description:   Query the poison file (if any)
 * Returns:       The file name if set
 */
string
query_poison_file() { return poison_file; }

/*
 * Function name: set_poison_damage
 * Description:   Set the array to be sent to set_damage in the poison
 * Arguments:     damage - The damage array
 */
void
set_poison_damage(mixed *damage) { poison_damage = damage; }

/*
 * Function name: query_poison_damage
 * Description:   Query the poison damage array (if any)
 * Returns:       The damage array
 */
mixed *
query_poison_damage() { return poison_damage; }

