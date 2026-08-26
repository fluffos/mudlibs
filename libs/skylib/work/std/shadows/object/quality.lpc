  /* This is the guts of the quality code.
     These are the things we must affect:
     Weapon Damage
     Object Value
     Object Condition
     And a couple thingies for looks.
  */

#define THING player
#define ENCHANT_SCALE 12.5
#define DAMAGE_SCALE 12.5
#define COND_SCALE 10.0
#define VALUE_SCALE 10.0

inherit "/std/effect_shadow";

void set_quality( int i ) { set_arg( i ); }

int query_quality() { return arg(); }

string quality()
{
  switch( arg() )
  {
  case -10..-9: return "extremely poor";
  case -8..-7: return "very poor";
  case -6: return "quite poor";
  case -5: return "poor";
  case -4..-3: return "well below average";
  case -2: return "below average";
  case -1: return "slighty below average";
  case 0: return "average";
  case 1: return "slightly above average";
  case 2: return "above average";
  case 3: return "well above average";
  case 4: return "high";
  case 5: return "quite high";
  case 6: return "extremely high";
  case 7: return "exquisite";
  case 8: return "masterful";
  case 9: return "unbelievably high";
  case 10: return "impossibly high";
  default:
    if (arg()>0)
      return "Divinely Inspired"; else return "Utterly Ludicrous";
  }
}

int modify_damage( int damage, string attack_name )
{
  mixed bing;
  int new_damage = to_int( damage*exp(to_float(arg())/DAMAGE_SCALE));
  if ((bing = query_shadowing(this_object())) &&
      (function_exists("modify_damage", bing)))
    bing->modify_damage( new_damage, attack_name );
  else
    return new_damage;
}

int query_value()
{
  mixed bing;
  if (bing = query_shadowing(this_object()))
    return to_int( (bing->query_value())*exp(to_float(arg())/VALUE_SCALE));
  else
    return 0;
}

int adjust_cond( int i )
{
  mixed bing;
  if (bing = query_shadowing(this_object()))
    if (i < 0)
      return bing->adjust_cond( to_int(i*exp(to_float(arg())/-COND_SCALE)));
    else
      return bing->adjust_cond(i);
  else
    return 0;
}

void do_damage( string dtype, int i )
{
  mixed bing;
  if (bing = query_shadowing(this_object()))
    bing->do_damage( dtype, to_int(i*exp(to_float(arg())/-COND_SCALE)));
}

/**
 * This function is necessary to make sure that damage done in combat is
 * reduced or increased as appropriate for the quality level.
 * @param i This is the damage to be inflicted, which is adjusted.
 * @param type This is the type of damage inflicted.
 */
void hit_weapon( int i, string type )
{
  mixed bing;
  if ((bing = query_shadowing(this_object()))
    && (function_exists("hit_weapon", bing)))
    bing->hit_weapon( to_int(i*exp(to_float(arg())/-COND_SCALE)), type );
}

int query_max_enchant()
{
  mixed bing;
  int real_max;
  float quality_effect = exp(to_float(arg())/ENCHANT_SCALE);
  real_max = (bing = query_shadowing(this_object()))?
    bing->query_max_enchant():0;
  return (to_int(quality_effect*real_max) >= 100)?100:
    to_int(quality_effect*real_max);
}

mixed stats()
{
  mixed bing;
  mixed *stuff = ({ });
  if (bing = query_shadowing(this_object()))
    stuff += bing->stats();
  stuff += ({ ({ "Quality", quality() + "(" + query_quality() + ")" }) });
  return stuff;
}
