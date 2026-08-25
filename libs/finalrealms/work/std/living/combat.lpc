/* Ok, this time it's this code I will walk through...
 * Baldrick, april '94
 * Removed the deathstuff and pu tit in death.c.
 * looks a lot better that way.
 * Added change of alignment in attack_ob, removed from death.c
 * Hope it will work, Baldrick, june '96
 */

inherit "/std/unarmed_combat";

/* Hmm, are we using these now ? */
int *weapon_attack_out, *attack_out;                //dk

nosave object attackee;
nosave object *attacker_list,
*call_outed,
protector;

nosave object concentrate;
nosave int dodging;


#define DIV_NUM 6
#include "money.h"

void set_weapon_attack_out(int mess, object *held_ob) { }

int query_dodging() { return dodging; }
int query_my_att_level() { return (int)this_object()->query_level(); }
int set_concentrate(object ob)
{
    if ( member_array(ob, attacker_list) == -1 ) return 0;
    concentrate = ob;
    return 1;
}
object query_concentrate() { return concentrate; }
int query_concentrate_valid() { return 0; }

// Radix, added for unprotect add_action
int remove_protector(object ob) { return(protector = 0); }
object set_protector(object ob) { return (protector = ob); }
object query_protector() { return protector; }

int query_fighting()
{
    int i;

    attacker_list -= ({0});
    call_outed -= ({0});
    for (i=0;i<sizeof(attacker_list);i++)
    {
	if (interactive(attacker_list[i]))
	    return 4;
	if (attacker_list[i]->query_aggressive())
	    return 1;
	else
	    return 2; 
    }

    for (i=0;i<sizeof(call_outed);i++)
    {
	if (interactive(call_outed[i]))
	    return 4;
	if (call_outed[i]->query_aggressive())
	    return 1;
	else
	    return 2; 
    }
    return 0;
}

int query_protect_valid(object attacker, object protectee)
{
    int base_roll;

    // Wonderflug, dec 95, can't protect while berserk
    if ( this_object()->query_property("flipped") )
	return 0;

    base_roll = random(100);   /* this to be replaced by a guild obj call */
    if ( member_array( attacker, attacker_list ) == -1 )
	base_roll -= 20;

    return ( base_roll >= 30 );
}

void actual_death();

void create() 
{
    attacker_list = ({ });
    call_outed = ({ });
    concentrate = 0;
    unarmed_combat::create();
}

void combat_commands() 
{
    add_action("do_protect", "protect");
    add_action("do_unprotect","unprotect");
    unarmed_combat_commands();
}

object query_attackee() { return attackee; }

void attack() 
{
    int i, dam, his_att_lvl, olav, att_level;
    string his_name;
    object *obs,ob,*ww;

    if (!attacker_list)
	attacker_list = ({ });

    while (i<sizeof(attacker_list)) {
	if (!attacker_list[i])       //dw have they died unexpecedaly? 
	    attacker_list = delete(attacker_list,i,1);
	else
	    //dw    I will put all the ones not in the correct environ in a new list.

	if (environment(attacker_list[i]) != environment(this_object())) {
	    write("You are hunting "+attacker_list[i]->short()+"\n");
	    if (!call_outed)
		call_outed = ({ attacker_list[i] });
	    else
		call_outed += ({ attacker_list[i] });
	    attacker_list = delete(attacker_list,i,1);
	} else
	    i++;
    }

    //dw check the not correct environ list to see if any one has come back.  
    i = 0;
    while (i<sizeof(call_outed))
	if (!call_outed[i])
	    call_outed = delete(call_outed,i,1);
	else if (environment(this_object()) == environment(call_outed[i])) {
	    attacker_list += ({ call_outed[i] });
	    call_outed = delete(call_outed,i,1);
	} else
	    i++;
	//dw not hitting anyone... do spell effects anyway... 
    if (!sizeof(attacker_list)) {
	attackee = 0;
	return;
    }
    //dw choose a random person from the attacker list; they're in correct env.
    if ( concentrate )
    {
	if ( member_array( concentrate, attacker_list ) == -1 )
	{
	    attackee = attacker_list[random(sizeof(attacker_list))];
	    concentrate = 0;
	}
	else
	{
	    attackee = concentrate;
	    if ( !this_object()->query_concentrate_valid(
		concentrate, attacker_list) )
		concentrate = 0;
	}
    }
    else
	attackee = attacker_list[random(sizeof(attacker_list))];

    //dw Check to see if they are being protected.

    if (protector && member_array(protector, attacker_list) != -1) {
	tell_object(this_object(), protector->query_cap_name()+
	  " turns against you and starts fighting you.\n");
	tell_object(protector, "You start fighting "+
	  this_object()->query_cap_name()+" and stop protecting "+
	  this_object()->query_objective()+".\n");
	say(protector->query_cap_name()+" turns against "+
	  this_object()->query_cap_name()+" and starts attacking him.\n",
	  ({ protector, this_object() }));
	/* This has been missing far too long, Wonderflug */
	protector = 0;
    }
    if ((ob = (object)attackee->query_protector()) &&
      environment(ob) == environment(attackee) &&
      ob->query_protect_valid(this_object(), attackee) )
    {
	if (!ob->query_dead())
	{
	    tell_object(attackee, ob->query_cap_name()+
	      " valiantly protects you.\n");
	    tell_object(ob,"You valiantly protect "+attackee->query_cap_name()+".\n");
	    say(ob->query_cap_name()+" valiantly protects "+
	      attackee->query_cap_name()+".\n", ({ attackee, ob }));
	    attackee = ob;
	}
    }
    his_att_lvl = maxi(({ (int)attackee->query_level(), 1 }) );

    his_name = (string)attackee->query_name();

    attackee->attack_by(this_object());


    // Attack code below by Aragorn.

    ww = (object *)this_object()->query_weapons_wielded();
    if (!sizeof(ww))
	// Radix added this_object()-> for shadows
	dam = this_object()->unarmed_attack(attackee,this_object()); // Bare hands?
    else
	for(olav=0;olav<sizeof(ww);olav++)
	    dam += (int)ww[olav]->weapon_attack(attackee,this_object());


	// Here endeth the code by Aragorn

    if (!attackee) 
    {
	tell_object(this_object(),"You killed "+his_name+"\n");
	say(this_object()->query_cap_name()+" killed "+his_name+"\n");
    }

    // Fix by Aragorn
    att_level = (int)this_object()->query_level();
    att_level = att_level?att_level:1;
    ++att_level;
    this_object()->adjust_xp(dam*(his_att_lvl/att_level));
    event(environment(this_object()), "fight_in_progress", attackee);

}

void attack_by(object ob) 
{
    if (ob == this_object())
	return ;
    if(this_object()->query_hidden())
	return;
    if (!attacker_list)
	attacker_list = ({ });
    if (!sizeof(attacker_list)) 
    {
	dodging = (int)this_object()->query_level();
    }
    if (member_array(ob, attacker_list) == -1 &&
      member_array(ob, call_outed) == -1) 
    {
	tell_object(this_object(), "You are attacked by " + 
	  ob->query_short() + ".\n");

	attacker_list += ({ ob });
    }
    set_heart_beat(1);
}

/* Hmm, this is called by the attacker, object ob is the victim */
void attack_ob(object ob) 
{
    int align;

    if (ob == this_object())
	return;

    if (ob->query_dead())
	return;

    /*
     * Should use the one used by death.c before.
     */

    /*
      align = ob->query_align() * ob->query_level();

      if (align > 100) 
	align = 100;
      if (align < -100)
	align = -100;
    */
    // not good to attack evil, multiplying by level gave numbers too big
    // probably should be LAWFULL to attack evil... Anirudh
    align = ob->query_align();

    if (align > 0) align = 0;
    if (align < -100) align = -100;

    if (!attacker_list)
	attacker_list = ({ });
    if (!sizeof(attacker_list)) 
    {
	/* This will be changed later.. */
	dodging = (int)this_object()->query_level();
    }
    if (member_array(ob, attacker_list) == -1 &&
      member_array(ob, call_outed) == -1) 
    {
	attacker_list += ({ ob });
	this_object()->adjust_align(-align); 
    }
    if (ob)
	ob->attack_by(this_object());
}

void check_stop_fight(object ob) 
{
    int i;
    if ((i=member_array(ob,call_outed)) != -1)
	call_outed = delete(call_outed,i,1);
}

int stop_fight(object ob) 
{
    int i;
    if ((i=member_array(ob,call_outed)) != -1) {
	tell_object(this_object(),"You stop hunting "+call_outed[i]->short(0)+
	  ".\n");
	call_outed = delete(call_outed, i, 1);
    }
    if ((i=member_array(ob,attacker_list)) != -1)
	attacker_list = delete(attacker_list,i,1);
}

mixed *query_attacker_list()
{
    attacker_list -= ({0});
    return attacker_list;
}

mixed *query_call_outed()
{
    call_outed -= ({0});
    return call_outed;
}

/** added by Raskolnikov Oct 96 **/
mixed *remove_call_outed()
{
    call_outed = ({ });
    return call_outed;
}

/** added by Raskolnikov Oct 96 **/
mixed *reset_attacker_list()
{
    attacker_list = ({ });
    return attacker_list;
}


//dw   Sets up protection matrixes.
int do_protect(string str) 
{
    object *obs, *ok; int i;
    if (!str) 
    {
	notify_fail("Syntax: protect <objects>\n");
	return 0;
    }
    obs = find_match(str, environment(this_object()));
    if (!sizeof(obs)) 
    {
	notify_fail("Protect what?\n");
	return 0;
    }
    //dk added member_array to this next line:
    if (member_array(this_object(), obs))
	//dk I changed this next line from this_player() to this_object():
	obs -= ({ this_object() });
    ok = ({ });
    for (i=0; i<sizeof(obs); i++)
	if (obs[i]->set_protector(this_object()))
	    ok += ({ obs[i] });
    if (!sizeof(ok)) 
    {
	notify_fail(query_multiple_short(obs)+
	  (sizeof(obs)==1?" doesnt":" don't")+" want your protection.\n");
	return 0;
    }
    if (sizeof(obs) != sizeof(ok))
	write("You fail to protect "+query_multiple_short(obs - ok)+".\n");

    write("You protect "+query_multiple_short(ok)+".\n");
    say(this_object()->query_cap_name()+" protects "+query_multiple_short(ok)+
      ".\n", ok);
    for (i=0; i<sizeof(ok); i++)
	tell_object(ok[i], this_object()->query_cap_name()+" protects "+
	  query_multiple_short(({ "you" }) + (ok - ok[i..i]))+".\n");
    return 1;
}
// Added by Radix, missing too long...
int do_unprotect(string str)
{
    object tmp;
    if(!str)
    {
	notify_fail("Syntax: unprotect <object>\n");
	return(0);
    }
    tmp = find_living(str);
    if(!tmp)
    {
	notify_fail("Unprotect what?\n");
	return(0);
    }
    if(tmp->query_protector() != this_object())
    {
	write("You are not protecting "+tmp->query_cap_name()+".\n");
	return(1);
    }
    tmp->remove_protector(this_object());
    if(environment(tmp) == environment(this_object()))
    {
	tell_object(tmp,this_object()->query_cap_name()+" withdraws and "
	  "no longer protects you.\n");
	tell_room(environment(),this_object()->query_cap_name()+" stops "
	  "protecting "+tmp->query_cap_name()+".\n", ({tmp, this_object() }));
    }
    write("You withdraw and stop protecting "+tmp->query_cap_name()+".\n");
    return(1);
}

mixed stats() 
{
    int i; object ob; mixed *ret;
    if (ob=this_object()->query_held_ob(0) && ob->query_weapon())
	ret += ({ ({ "Weapon", ob->short() }) }) + (mixed)ob->weapon_stats();
    if (ob=this_object()->query_held_ob(1) && ob->query_weapon())
	ret += ({ ({ "Secondary weapon", ob->short() }) });
    for (i=0; i<sizeof(attack_out); i+=7) 
	ret += ({ ({ "If",    attack_out[i], }), 
	  ({ "Rate",  attack_out[i+1], }), 
	  ({ "Attack", attack_out[i+2], }), 
	  ({ "Tohit", attack_out[i+3], }), 
	  ({ "Number of damage dice", attack_out[i+4], }), 
	  ({ "Die size", attack_out[i+5], }), 
	  ({ "Addend", attack_out[i+6], }), 
	}); 
    return ret;
}
