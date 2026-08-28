inherit "obj/skill/obj/maneuver";

create_skill()
{
	set_skill_name("brawlers punch");
	set_train_difficulty(8); 
	set_base_percent(15);
	add_base_stat("str",40);  // Total of Base Stats is 100
	add_base_stat("siz",30);
	add_base_stat("agi",30);
	set_parent_skill("martial_arts_hard");
	set_weapon_types(({"martial_arts"}));
	set_damage(0);
	set_defense(0);
	set_protection(0);
	set_fatique(0);
	set_offense(1);
	set_speed(1);
}

/* Legality check returns 0 if this combination of attacker, weapon and target is somehow illegal.
	It returns 1 if it is legal */

int legality_check(object attacker, object weapon, object target)
{
    return ::legality_check(attacker, weapon, target);
}

void do_combat_msg(object attacker, object target)
{
  if(random(5)||!attacker||!target)
    return;
  if(target->query_is_unconscious())
    {
      tell_room(environment(attacker),
		attacker->query_cap_name()+" laughs at unconscious "+
		target->query_cap_name()+".\n",
		({target,attacker}));
      tell_object(attacker,
		  "You laugh at unconscious "+target->query_cap_name()+".\n");
      tell_object(target,
		  "You hear evil laughter from far far away.\n");
      return;
    }

  tell_room(environment(attacker),
	    attacker->query_cap_name()+" circles around "+
	    target->query_cap_name()+" looking for an opening.\n",
	    ({attacker, target}));
  tell_object(attacker,
	      "You circle around "+target->query_cap_name()+
	      " looking for a place to hit.\n");
  tell_object(target,
	      attacker->query_cap_name()+" circles around you waiting for your last mistake.\n");
}

void do_maneuver_msg(object target, object attacker, object weapon,
  string location, int offres, int defres, int dmgres, int hitres)
{
    string msg, offmsg, dmgmsg, dodmsg, hitmsg ;

    /* Location: Where the attack will land if it hits.
       Offres: How well the attacker performed his attack (-120 to 120)
       Defres: How well the target performed his dodge (-120 to 120)
       Dmgres: How much the attack will cause damage if attack hits. (1 or up)
       Hitres: Attack will hit if this is positive.
       */
    location=handle_location(location,target);
    switch (offres)
      {
      case -120..-100:
	offmsg="a sloppy";
	break;
      case -99..-50:
	offmsg="poorly aimed";
	break;
      case -49..0:
	offmsg="misplaced";
	break;
      case 1..25:
	offmsg="an adequate";
	break;
      case 26..60:
	offmsg="well aimed";
	break;
      case 61..80:
	offmsg="quick";
	break;
      case 81..95:
	offmsg="lightning fast";
	break;
      case 96..100:
	offmsg="perfect";
	break;
      case 101..120:
	offmsg="god guided";
	break;
      }
    switch (dmgres)
      {
      case 1..3:
	dmgmsg="weak";
	break;
      case 4..8:
	dmgmsg="average";
	break;
      case 9..20:
	dmgmsg="strong";
	break;
      case 21..50:
	dmgmsg="a bone shattering";
	break;
      case 51..100:
	dmgmsg="deadly";
	break;
      default:
	dmgmsg="a stone shattering";
	break;
      }
    switch (defres)
      {
      case -120..-100:
	dodmsg="clumsily steps in front of the punch";
	break;
      case -99..-50:
	dodmsg="stupidly just stands there";
	break;
      case -49..0:
	dodmsg="manages to move an inch away";
	break;
      case 1..20:
	dodmsg="ducks below the blow";
	break;
      case 21..60:
	dodmsg="tries to avoid the blow by stepping backwards";
	break;
      case 61..80:
	dodmsg="takes a quick step to side";
	break;
      case 81..100:
	dodmsg="who moves like quicksilver and to avoid the blow";
	break;
      default:
	dodmsg="who is suddenly behind "+attacker->query_cap_name()+"'s back";
	break;
      }
    if(hitres<1)
      {
	hitmsg="and avoids being hit.";
	tell_object(target,
		    attacker->query_cap_name()+" throws a "+offmsg+" "+dmgmsg+" punch "+
		    "at your "+location+" but you easily avoid it.\n");
	tell_object(attacker,
		    "You try to punch "+target->query_cap_name()+" but "+
		    target->query_pronoun()+" is too quick for you!\n");
      }
    else
      {
	hitmsg="but is hit by "+attacker->query_cap_name()+"'s attack!";
	tell_object(target,
		    attacker->query_cap_name()+" throws a "+dmgmsg+" punch at your "+
		    location+"!\n");
	tell_object(attacker,
		    "You throw "+dmgmsg+" punch at "+target->query_cap_name()+
		    "'s "+location+"!\n");
      }
    tell_room(environment(attacker),
	      attacker->query_cap_name()+" throws a "+offmsg+" "+dmgmsg+" punch towards "+
	      target->query_cap_name()+"'s "+location+" who "+dodmsg+" "+hitmsg+"\n",
	      ({attacker, target}));
}


