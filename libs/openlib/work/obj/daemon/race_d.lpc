/*  -*- LPC -*-  */
// Orig by Tim -- This is a sloppy hack, not intended to be actually used,
// but it never got any further than this.
//
#include <weapon.h>

mapping raceinfo;  // keyed by race names, values are mixed*

void
create()
{
  raceinfo = ([ ]);
  call_out("setup", 2);
}

mixed*
load_arrays(string text)
{
  string* arr1 = ({});
  string* arr2 = ({});
  foreach(string set in explode(text, ","))
  {
    string type, loc;

    if( sscanf(set, "%s:%s", type, loc) != 2 )
      continue;
    
    while(type[0] == ' ') type = type[1..];
    while(loc[<1] == ' ') loc = loc[0..<2];
      
    arr1 += ({ type });
    arr2 += ({ loc });
  }
  return ({ arr1, arr2 });
}

mixed*
query_raceinfo(string race)
{
  return raceinfo[race];
}

void
setup()
{
  string race, tmp;
  mixed* arr;
  int hands, weight, strength, agility;
  int* base_ac = allocate(2);
  string *hitverbs_act,
         *hitverbs_pas,
         *missverbs_act,
         *missverbs_pas,
         *weapon_names = ({}),
         *armour_types,
         *armour_locs;

  string text = read_file("/adm/etc/human.cfg");
  text = implode(filter(explode(text, "\n"), (: $1[0] != '#' :)), "");

  sscanf(text, "%*srace=%s;%*s", race);
  sscanf(text, "%*shands=%d;%*s", hands);
  sscanf(text, "%*sweight=%d;%*s", weight);
  sscanf(text, "%*sstrength=%d;%*s", strength);
  sscanf(text, "%*sagility=%d;%*s", agility);
  sscanf(text, "%*schance_to_hit_mod=%d;%*s", base_ac[0]);
  sscanf(text, "%*sdamage_mod=%d;%*s", base_ac[1]);

  if( sscanf(text, "%*sarmour_info=%s;%*s", tmp) > 0 )
  {
    arr = load_arrays(tmp);
    armour_types = arr[0];
    armour_locs = arr[1];
  }

  if( sscanf(text, "%*shitverbs=%s;%*s", tmp) > 0 )
  {
    arr = load_arrays(tmp);
    hitverbs_act = arr[0];
    hitverbs_pas = arr[1];
  }

  if( sscanf(text, "%*smissverbs=%s;%*s", tmp) > 0 )
  {
    arr = load_arrays(tmp);
    missverbs_act = arr[0];
    missverbs_pas = arr[1];
  }

  if( sscanf(text, "%*sweapon_names=%s;%*s", tmp) > 0 )
    foreach(string name in explode(tmp, ","))
    {
      while(name[0] == ' ') name = name[1..];
      while(name[<1] == ' ') name = name[0..<2];
      weapon_names += ({ name });			 
    }

  raceinfo[race] = ({ race,
		      hands,
		      weight,
		      strength,
		      agility,
		      armour_types,
		      armour_locs,
		      base_ac,
		      (:
		       // $1 = hand_pair 
		       // $2 = wep_skill
		       // $3 = strength (stat)
		       // $4 = agility (stat)
		       // $5 = combat (skill)
		       // $6 = unarmed  (skill)
		       // $7 = wep_skill (skill)
		       ({ 2916473 / (3 * (26 - $3) + (26 - $4) + 2 *
				     (1001 - ($2 ? $7  : 0)) + 
				     (1001 - ($2 ? $5 : 0))) - 949,
			  ($2 && $2 == "unarmed" ? 5 + $6 / 10 : 0),
			  7 * $3 + 21 * $4 + ($2 ? 2 * $5 + $7 : 0) + 136,
			  ($2 && $2 == "unarmed" ? 0 :
			   $3 * 10 + $4 * 20 + $5 * 10) +
			     ($2 != "unarmed" && $2 ? $7 * 10 : 0),
			  $(hitverbs_act),
			  $(hitverbs_pas),
			  $(missverbs_act),
			  $(missverbs_pas),
			  $(weapon_names),
			  WEAPON_FISTS,
			  this_object(),
			  $1 /* hand_pair */
			  }) :)
		      });
//  tell_object(find_player("tim"), sprintf("%O", evaluate(raceinfo["human"][7],
//							 0,
//							 0,
//							 10,
//							 12,
//							 6,
//							 8,
//							 9)));
}  
			 
  
#if 0
// Later to read from file...
void
setup()
{
  raceinfo["human"] =
    ({ 140,  // base wt.
       2, // hands
       ({"helm","ring","ring","bracers","body2","legs2","boots",
	 "amulet","cloak"}), // armour types
       ({"on the head","on the left hand","on the right hand",
	 "on the arms","about the body","on the legs",
	 "on the feet","around the neck","around the neck"}), // locations
       (: ({
	 2916473 /
	   (3 * (26 - $3) + (26 - $4) + 2 * (1001 - ($2 ? $7  : 0)) + 
	    (1001 - ($2 ? $5 : 0))) - 949,
	 // That was the damage bonus.  Worked to balance (somewhat) 
	 // skills and the like.  Ask for an explination of why it 
	 // is the way it is.  Casper
	 ($2 && $2 == "unarmed" ? 5 + $6 / 10 : 0),
	 // damage range needed ONLY for unarmed combat.
	 // May need balancing.
	 7 * $3 + 21 * $4 + ($2 ? 2 * $5 + $7 : 0) + 136,
	 // base to_hit
	 // Again, ask for an explination of why it is the way it 
	 // is.  Casper
	 ($2 && $2 == "unarmed" ? 0 :
	  $3 * 10 + 
	  $4 * 20 + 
	  $5 * 10) +
	    ($2 != "unarmed" && $2 ? $7 * 10 : 0),
	 //parry modifier.  Nill for unarmed combat (how DO you
	 //parry with hands?) otherwize 2% per point of agil & 1%
	 //per point of $3 + 1% per combat * weapon skill.
	 ({"punch","sock","chop","jab"}),
	 ({"punches","socks","chops","jabs"}),
	 ({"miss","swing above", "jab beside", "swing short of"}),
	 ({"misses","swings above", "jabs beside", "swings short of"}),
	 ({"fists","balled hand", "hand", "fist"}),
	 WEAPON_FISTS,
	 this_object(),
	 0
	 })
     }
     });
}
#endif
