#include "unarmed_combat.h"

nosave int ovr_num,ovr_type;
nosave string *custom_attacks;
object attacker,defender;
nosave string *bits;


/*
    Unarmed Combat for FR by Sojan
    Currently unlobotomised/castrated by Baldrick :)

    On my way... Baldrick. June '94

    Totalled, Taniwha, 1997
    Now much simpler format and much faster messages (I hope)
    
    No cutsey change styles, but thats easy to add, main
    advantage is the default to what the race does and
    hits on valid body parts.
    	
 */


int unarmed_attack(object def, object att);
void write_message(int damage, string result, object att, object defdr);
void apply_damage(int hps, object att);
mixed *workout_attack(string unarmed_type);
string *valid_attacks();

void create()
{
  ovr_num=0;
  ovr_type=0;
}
string *add_attack(string *strs)
{
  if(custom_attacks)
 	custom_attacks += ({ strs });
  else custom_attacks = strs;		
}

string *set_attacks(string *strs)
{   
   custom_attacks = strs;
}   
/*
	generate "bits hit" based on damage compared to max.
	The most important "bits" are first in the bist array
	so we just index into the array backwards using damage
*/
string bithit(int maxd,int dam)
{
	int n;
     string *m;
	object *ob;
	if(!pointerp(bits))
	{
	   ob = TO->query_race_ob();
	   if(ob) bits = ob->query_bits();
	}
	if(!pointerp(bits)) return "somewhere";
	   
	if(dam > maxd || dam < 0) dam = maxd;
	/* break messages up into major and less important bits 
	   based on how hard we hit 
	*/
	/* How many classes of bits do we have ? */   
	n = sizeof(bits);
	/* we did damage belonging to this class */
	n = (maxd*dam)/n;
	/* so pick one and return it */
	n = sizeof(bits);
	/* swap array end for end, earlier "bits" are the most important */
    n = n/3;
    n = (n-1)-random(n);
    n = n *3;
    return (string)bits[n];
}

int unarmed_attack(object def, object att)
{
  mixed  att_val;
  attacker = att;
  defender = def;
  att_val=workout_attack("");
  if(att_val[0]=="hit")
    apply_damage((int)att_val[1], att);
  write_message((int)att_val[1], att_val[0], att, def);
  return att_val[1];
} /* unarmed_attack */

mixed *workout_attack(string unarmed_type)
{
  string happen;
  int  tmproll,result, achit, defenderac, damage_done, THAC0;

  // Taniwha 1995, LUCK factor
  tmproll = random(200);
  if( tmproll < defender->query_cha() )
    return ({ "fumble", 0});

  THAC0=(int)attacker->query_thac0();
  /* This is the way it is done everywhere else.. */
  achit = ((THAC0 - (int)attacker->query_tohit_bonus()) - tmproll);
  defenderac = (int)defender->query_total_ac();

  result = (achit - defenderac);

  if (result < 1)
  {
      happen = "hit";
        damage_done=roll(BDEFNUM, BDEFTYPE);
      // Taniwha 1995, critical hit, luck based
      if( random(200) < attacker->query_cha() ) damage_done *= 2;
  }
  else
  {
      happen = "miss";
      damage_done = 0;
  }

  return ({ happen, damage_done });
} /* workout_attack */


/* This needs the attacker's object too.. */
void apply_damage(int hps, object att)
{
  if(hps<0) hps=0;
  /* taniwha, was attacker here, God knows ;) who that was */
  defender->adjust_hp(-hps, att);
  return;
}


// Muchly simplied system, taniwha


void write_message(int damage, string result, object att, object defdr)
{
  string *vatts;
  string tmp,an,bn,dn;
  int i,maxd;
  
  vatts = valid_attacks();
  
  dn = defdr->query_cap_name();
  an = att->query_cap_name();
  
  
  
  switch(result)
  {
  case "hit":
 	maxd = ovr_num * ovr_type;
  	bn = bithit(maxd,damage);   	
  	i=random(sizeof(vatts)/3)*3;
 	tmp = vatts[i];
  	tmp = replace_string(tmp,"AN",an);
  	tmp = replace_string(tmp,"DN",dn);
  	tmp = replace_string(tmp,"BN",bn);
  	tell_room(ENV(att),tmp+".\n", ({att, defdr}));
	tmp = vatts[i+1];
  	tmp = replace_string(tmp,"AN",an);
  	tmp = replace_string(tmp,"DN",dn);
  	tmp = replace_string(tmp,"BN",bn);    
  	tell_object(att, tmp+" causing "+damage+" hp's damage.\n");
  	tmp = vatts[i+2];
  	tmp = replace_string(tmp,"AN",an);
  	tmp = replace_string(tmp,"DN",dn);
  	tmp = replace_string(tmp,"BN",bn);
  	tell_object(defdr, tmp+" doing "+damage+" hp's damage.\n");
	break;
   default:
  case "miss":
   case "fumble":
  	tell_room(ENV(att),an+" misses "+dn+".\n",({att, defdr}));
  	tell_object(att,"You miss "+dn+".\n");
  	tell_object(defdr,an+" missed you.\n");
  	break;
  }		  		
}
/* returns triplets of messages
   room
   hitter
   target 
  
   AN is replaced with attacker name
   DN is replaced with defender name
   BN is replaced with the name of a selected body part 
*/
string *valid_attacks()
{
	object race_ob;
	/* O.K. if this has been set, use it */
	if(custom_attacks) return custom_attacks;
	/* Else scrounge round the race object */
	race_ob = TO->query_race_ob();
	if(race_ob)
	{
	   custom_attacks = race_ob->valid_attacks();
	   if(custom_attacks) return custom_attacks;
	}   
	else /* else Never Happen */
	{
	   custom_attacks = ({ "AN kisses DN on the BP",
		       "You kiss DN",
		       "DN kissed you"});
        }
        return custom_attacks;		       		
}
void set_damage_dice(int numdie, int dietype)
{
  if(numdie>0 && dietype>0)
  {
    ovr_num=numdie;
    ovr_type=dietype;
  }
  return;
}
