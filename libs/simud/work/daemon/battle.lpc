/**
 * Battle daemon. Used for getting all sorts of nifty combat calculations
 */
#include <const/battconst.h>
#include <dice.h>

// which hit/evade percentage pairs to use
#define  USE_MELEE   1
#define  USE_MISSILE   2
#define  USE_MAGIC   3
#define  USE_MENTAL   4

/// \todo Document this file.

/** Returns an array containing objects wielded by who. If type is
 * declared (either as a single string or as an array of strings), the
 * function will only return those weapons of the appropriate type (sword,
 * axe, etc...)
 */
varargs object *query_wielded_weapons(object who, mixed type) {
  object item, *list;
  if (!who)
    return 0;
  list = all_inventory(who);
  foreach (item: list)
    if (!item->query_weapon() || !item->query_held())
      list -= ({ item });
  if (type)
    foreach (item: list)
      if (stringp(type) && item->query_weapon_type() != type)
        list -= ({ item });
      else if (pointerp(type) &&
               member(type,item->query_weapon_type()) == -1)
        list -= ({ item });
  if( sizeof(list) == 0 ) return 0;
  return list;
}

/** This is like query_wielded_weapons(), except that it does
 * it for armour.
 */
varargs object *query_worn_armour(object who, mixed type) {
  object item, *list;
  if (!who)
    return 0;
  list = all_inventory(who);
  foreach (item: list)
    if (!item->query_worn())
      list -= ({ item });
  if (type)
    foreach (item: list)
      if (stringp(type) && item->query_armour_type() != type)
        list -= ({ item });
      else if (pointerp(type) &&
               member(type,item->query_armour_type()) == -1)
        list -= ({ item });
  if( sizeof(list) == 0 ) return 0;
  return list;
}

/// Convert a single wc value into an amount of damage.
int wc_to_damage(int wc) {
  int total_dmg;
  int i;

  if (wc <= 0)
    return 0;

  // New, newer formula using a dice roll system, meant to balance combat a bit.
  total_dmg = 0;
  for( i=0;i<wc;i++ ) {
     total_dmg += random( 6 ) + 1;
  }
  return total_dmg;

}

// This function should be obsolete, and replaced by calc_dmg_by_rules() below.
/// Takes a wc mapping and converts it into actual points of damage.
#if 0
varargs int calc_damage(mixed wc) {
  int total = 0, x;
  if (intp(wc))
    return wc_to_damage(wc);
  else if (mappingp(wc))
    foreach (x : m_values(wc))
      total += wc_to_damage(x);
  return total;
}
#endif

/// Returns target's hit% of type (melee, missile, magic, mental)
varargs int hit_percent(object target, int type, string skill) {
  float x = 0.0;

  switch (type) {
    case USE_MELEE: if (!skill) skill = "combat.weapon.unarmed";
                    x = target->query_skill(skill);
                    break;
    case USE_MISSILE: if (!skill) skill = "combat.weapon.bow";
                      x = target->query_skill(skill);
                      break;
    case USE_MAGIC: if (!skill) skill = "magic.spellcraft";
                    x = target->query_skill(skill);
                    break;
    case USE_MENTAL: x = target->query_skill("magic.concentration");
                     break;
  }

  return (int)(x / 2.0);
}

/// Returns target's hit% of type (melee, missile, magic, mental)
int evade_percent(object target, int type) {
  float x = 0.0;
  if( !target )   // This is quite possible if the target was destructed.
    return 0;

  switch (type) {
    case USE_MISSILE:
    case USE_MELEE: x = target->query_skill("combat.dodge");
                    break;
    case USE_MAGIC: x = (target->query_skill("combat.dodge") +
                         target->query_skill("magic.spellcraft")) / 2.0;
                    break;
    case USE_MENTAL: x = target->query_skill("magic.concentration");
                     break;
  }

  return (int)(x / 2.0);
}

/** This function is called by the various execute_xxx functions to
 * determine whether or not an attack is worth considering for reactions,
 * damage and whatnot.
 */
int attack_hits( object actor, object target, int type, string skill ) {
  int hitp = hit_percent(actor, type, "combat.weapon."+skill);
  int evadep = evade_percent(target, type);
  int chance = 75 + hitp - evadep;
  return (random(100) <= chance);
}

/** This function is designed to make it more convenient to build battle
 * actions. It takes six parameters, but all but the first one are optional.
 */
varargs mixed *make_action( mixed target, int readiness_req, int stance, string ob_name, mixed param ) {
   if( !objectp(target) ) target = -1;
   if( readiness_req == 0 ) readiness_req = 1000;
   if( stance == 0 ) stance = ST_STANDING;
   if( !ob_name ) ob_name = load_name(previous_object());
   return ({ readiness_req,
      ob_name,
      target,
      stance,
      param });
}

/** \return True, if conditions are legal for this_player() to attack
 * \a victim. This checks to see that the two parties are next to each
 * other, that both are alive, that victim != this_player(), and similar.
 * If any condition fails, false is returned.
 */
int check_legal_melee( object victim, string verb ) {
   string err = 0;

   if( !victim->query_is_living() )
      err = "the enemy is already dead";
   if( this_player() == victim )
      err = "you are not allowed to attack yourself";
   if( environment(this_player()) != environment(victim) )
      err = "the enemy is no longer nearby";
//   if( !this_player()->query_adjacent(victim->query_x(), victim->query_y()) )
//      err = "you are not standing close enough";

   if( err )
      msg("You cannot " + verb + " because " + err + "." );
   else
      return 1;
   return 0;
}

/// for sorting armour by layers - called in execute_melee
int armour_sort(object a, object b) {
  return a->query_layer() > b->query_layer();
}

/** Executes a melee attack and returns the result. Returns zero if
 * no hit-points were lost. It is assumed that this_player() is the one
 * attacking.
 *
 * The result is something like this:
 *
 * ({ string class, int damage, string message, (optional) int bp,
 *    (optional) object armour })
 *
 * The 'class' is one of a set of standardized strings. The list
 * of meaningful strings is found in battconst.h. The "damage"
 * is the damage dealt as a percent of the target's hitpoints. The
 * message describes the target's reaction (I think?) and is provided
 * for those too lazy to integrate the reaction into their descriptions.
 *
 * \warning The docs in battconst.h claim that the 'damage' amount
 * may also be a mapping. I don't know what that would mean, but may
 * have something to do with multiple types of damage.
 */
mixed execute_melee( object weapon, mapping wc, object target, int speed,
                     int flag ) {
   mixed result;
   string weapon_type, reaction, str;
   int damage = 0, crit = 0;
   int bp;

   if (!weapon || weapon->query_is_living())
     weapon_type = "unarmed";
   else if (weapon->query_armour_type() == "shield")
     weapon_type = "shield";
   else
     weapon_type = weapon->query_weapon_type();

   if (!weapon_type)
     weapon_type = "unarmed";

   // Check if the weapon has it's own hit function
   if (weapon) {
      result = weapon->on_attack(target);
      if (result)
        return result;
   }

   // Check if the attack misses...
   if (!(flag & ATT_NO_MISS) &&
       !attack_hits(this_player(), target, USE_MELEE, weapon_type)) {
      reaction = target->query_form_object()->on_miss(target,this_player(),wc);
      if (reaction && target->query_readiness() >= reaction->query_readiness_requirement()) {
        result = reaction->on_miss(this_player(), weapon, wc, target, speed, flag);
        if (pointerp(result) && sizeof(result) == RESULT_SIZE) {
          switch (result[RESULT_TYPE]) {
            case "counter": this_player()->take_damage(result[RESULT_MOD]);
                            break;
          }
          return ({"miss",0,result[RESULT_MSG],0});
        }
      }
      return ({"miss",0,"",0});      // Return an utter miss
   }

   // special case for targetting plants ;)
   if( target->query_has_aspect( C_PLANT ) ) {
      foreach( str : m_indices(wc) )
         damage += target->add_damage( -wc_to_damage(wc[str]) / 10 );
      return ({"hit",damage,""});
   }

   // Check results from reactions
   reaction = target->query_form_object()->on_attack(target,this_player(),wc);
   if( reaction ) {
     if (target->query_readiness() >= reaction->query_readiness_requirement()) {
       result = reaction->on_attack(this_player(), weapon, wc, target, speed, flag);
       if ( pointerp(result) && sizeof(result) == RESULT_SIZE ) {
         switch (result[RESULT_TYPE]) {
           case "immune":  wc = ([]); break;
           case "dodge":
           case "parry":
           case "block":
             // perform the modification
             wc = result[RESULT_MOD];
           // target gets a practice of speed for every attack avoided
          target->practice_stat("spd");
             break;
           case "counter":
             this_player()->take_damage(result[RESULT_MOD]);
           // target gets a practice of will power for every counter
           target->practice_stat("wil");
             break;
         }
       }
     }
   }

   // attacker practices weapon skill and will power with every action
   this_player()->practice_skill("combat.weapon."+weapon_type);
   this_player()->practice_stat("wil");
   // target practices speed with every attack (in addition to the extra
   // practice for avoiding an attack if that is the case)
   target->practice_stat("spd");

   // get body part attacked
   bp = target->query_race_object()->query_random_bp();

   if (!result)
     result = ({"hit",0,"",0});

   if (wc) {
     int wc_total = 0;
     object obj, *armour = ({});

     // Finds the highest wc type, and increases it by 1 if there is a critical.
     if (random(125) < this_player()->query_skill("combat.technique.critical")) {
       string highest_wc; int value = 0;
       foreach(str: m_indices(wc)) {
         if (wc[str] > value) {
           value = wc[str];
           highest_wc = str;
         }
       }
       wc[highest_wc]++;
     }

     if (this_player()->query_is_player())
       target->set_env_var("cause_of_death","was killed by "+this_player()->query_cap_name()+".");
   else
       target->set_env_var("cause_of_death","was killed by "+this_player()->query_distant()+".");
     damage = target->take_damage_percent(wc, bp);

     foreach (str: m_indices(wc))
        wc_total += wc[str];

     // TODO: Consider materials and wc types involved when damaging eq
     foreach (obj: all_inventory(target))
        if (obj->query_worn() && obj->query_body_parts()&bp)
           armour += ({obj});
     if (sizeof(armour)) {
        obj = sort_array(armour, "armour_sort")[0];
        obj->add_condition(-wc_total);
     } else
        obj = 0;
     if (weapon_type != "unarmed")
     {
        if (random(1000) < wc_total) {
           weapon->add_condition(-1);
        }
     }

     if (damage == 0)
       crit = 0;

     if (crit)
       this_player()->practice_skill("combat.technique.critical");

     return ({result[RESULT_TYPE],damage,
              (crit ? "~CBRTCritical Hit! ~[060" : "")
                 + result[RESULT_MSG], bp, obj });
   } else
     return ({result[RESULT_TYPE],0,result[RESULT_MSG],0});
}

// calc_dmg_by_rules()
// modifies dmg done by stance, armour absorbtion, and natural armour absorbtion, and adds it up, returns it.
// is really a replacement for the older function calc_damage that used to be called from living.
// wc: weapon class mapping
// bp: body part struck
// *inven_data: array of inventory data for the target_object
// target_object: pointer to target object

int calc_dmg_by_rules( mapping wc, int bp, object *inven_data, object target_object ) {
   object inv;
   mixed foo;
   //float dmg_mod;
   float total;
   mapping temp_dmg = ([]);

   temp_dmg = copy( wc );

   // Calculates the dmg for each dmg type in the wc mapping first off, so we have actual numbers to work
   // from.
   foreach( foo: wc ) {
      temp_dmg[foo] = wc_to_damage( wc[foo] );
      debug( "WC["+wc[foo]+"] = "+temp_dmg[foo]+" hp", "combat");
   }
   // debug( "DMG ORIG> " + as_lpc(temp_dmg, 1), "combat" );

   //dmg_mod = 1.00;
   // Temporarily dropped. Causes difficulties, and yields little actual effect in most combat
   // situations.
   /*
   // modify dmg first by what stance the target is in
   switch( target_object->query_stance() ) {
      case ST_FALLING:    dmg_mod = 1.30; break;
      case ST_LYING:    dmg_mod = 1.25; break;
      case ST_JUMPING:    dmg_mod = 1.20; break;
      case ST_SITTING:    dmg_mod = 1.50; break;
      case ST_CROUCHING: dmg_mod = 1.05; break;
      case ST_FLYING:    dmg_mod = 0.95; break;
   }
   */
   foreach( foo: temp_dmg ) {
//      temp_dmg[foo] *= dmg_mod;
      foreach (inv : inven_data )
         temp_dmg[foo] -= inv->on_damage(foo, to_int(temp_dmg[foo]));
      if (temp_dmg[foo] <= 0)
         temp_dmg -= ([ foo ]);
   }

   // apply armour absorbtion for corresponding armour piece to the body part hit
   foreach( inv : inven_data ) {
      if( inv->query_worn() && inv->query_body_parts()&bp ) {
         foreach( foo: temp_dmg ) {
            // Bug in -=, eh? WEIRDness.
            temp_dmg[foo] = temp_dmg[foo] - temp_dmg[foo] * (inv->query_ac(foo) / 100.0);
         }
      }
   }

   // apply natural(racial) armour ac absorbtion
   foreach( foo: temp_dmg ) {
      if (target_object->query_real_ac()) // real ac may be 0
         temp_dmg[foo] = temp_dmg[foo] - temp_dmg[foo] * (target_object->query_real_ac() / 100.0);
   }

   total = 0.00;

   // adds up the total dmg after modifications
   foreach( foo: temp_dmg ) {
      total += temp_dmg[foo];
   }
   debug( "DMG MOD> " + as_lpc(temp_dmg, 1), "combat" );

   return (int)total;
}
