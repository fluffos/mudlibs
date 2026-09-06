/** Armour is currently very broken... with the change of ac to a mapping.
 * Don't bother messing with it for a while, I'll fix it some time after
 * this headache of mine goes away.
 */

#include <const.h>
#include <item.h>
#include <desc.h>
#include <saveload.h>
#include <bonus.h>
#include <battle.h>

int *ac, worn, *requirements, cursed;
int condition, enchanted, max_condition;
int *bp_options;
string armour_type;

string armour_info() {
  return "armour_type\nedged_ac\npiercing_ac\nblunt_ac\nfire_ac\nice_ac\n"+
         "elec_ac\npoison_ac\nacid_ac\nmental_ac\nrad_ac\nholy_ac\n"+
         "unholy_ac\nplasma_ac\nshadow_ac\ndisease_ac\nworn\n"+
         "level_req\nstr_req\ndex_req\ncon_req\nwis_req\nint_req\n"+
         "will_req\nskill_req\ncursed\ncondition\nmax_condition\nenchanted";
}

/****************************** Queries ****************************/

int query_armour() { return 1; }

/** \return Non-zero if this piece of armour has been worn. The integer
 * designates which bodypart(s) the armour is worn on.
 */
int query_worn() {
  if (!environment(this_object())->query_living())
    worn = 0;
  return worn;
}

int query_ac(int x) {
  if (x >= DAM_TYPES || x < 0)
    return 0;
  if (pointerp(ac))
    return ac[x];
  else
    return 0;
}

int query_max_condition() {
  int x, f;
  if (!max_condition) {
    for (f = 0; f < DAM_TYPES; f++)
      x += query_ac(f);
    max_condition = x*75;
    switch (this_object()->query_material()) {
      case "cloth": max_condition = 7 * max_condition / 10; break;
      case "wood": max_condition = 8 * max_condition / 10; break;
      case "copper":
      case "silver":
      case "gold":  max_condition = 9 * max_condition / 10; break;
      // iron is default
      case "stone":
      case "steel": max_condition = 11 * max_condition / 10; break;
      case "diamond": max_condition = 12 * max_condition / 10; break;
    }
  }
  return max_condition;
}

int query_condition() {
  if (!condition)
    condition = query_max_condition();
  return condition;
}

int query_broken() {
  if (query_condition() == -1)
    return 1;
}

int query_enchanted() { return enchanted; }
string query_distant() {
  if (query_broken())
    return ::query_distant() + " (broken)";
  else
    return ::query_distant();
}

query_edged_ac()    { return query_ac(DAM_EDGED); }
query_piercing_ac() { return query_ac(DAM_PIERCING); }
query_blunt_ac()    { return query_ac(DAM_BLUNT); }
query_fire_ac()     { return query_ac(DAM_FIRE); }
query_ice_ac()      { return query_ac(DAM_ICE); }
query_elec_ac()     { return query_ac(DAM_ELEC); }
query_poison_ac()   { return query_ac(DAM_POISON); }
query_acid_ac()     { return query_ac(DAM_ACID); }
query_mental_ac()   { return query_ac(DAM_MENTAL); }
query_rad_ac()      { return query_ac(DAM_RADIATION); }
query_holy_ac()     { return query_ac(DAM_HOLY); }
query_unholy_ac()   { return query_ac(DAM_UNHOLY); }
query_plasma_ac()   { return query_ac(DAM_PLASMA); }
query_shadow_ac()   { return query_ac(DAM_SHADOW); }
query_disease_ac()  { return query_ac(DAM_DISEASE); }

query_armour_type() { return armour_type; }
query_cursed() { return cursed; }       // returns level of curse

query_req(int req)  {
  if (pointerp(requirements))
    return requirements[req];
  else
    return 0;
}
query_level_req()   { return query_req(REQ_LEVEL); }
query_str_req()     { return query_req(REQ_STR); }
query_dex_req()     { return query_req(REQ_DEX); }
query_con_req()     { return query_req(REQ_CON); }
query_wis_req()     { return query_req(REQ_WIS); }
query_int_req()     { return query_req(REQ_INT); }
query_will_req()    { return query_req(REQ_WILL); }
query_skill_req()   { return query_req(REQ_SKILL); }

int *query_bp_options() {
   if( bp_options ) return bp_options;
   else
   switch( armour_type ) {
      case "gloves"      : return ({ BP_LHAND | BP_RHAND });
      case "ring"        : return ({ BP_LHAND, BP_RHAND });
      case "breastplate" : return ({ BP_CHEST });
      case "armour"      : return ({ BP_CHEST | BP_STOMACH | BP_BACK });
      case "shield"      : return ({ BP_LARM, BP_RARM, BP_LARM2, BP_RARM2 });
      case "boots"       : return ({ BP_LFOOT | BP_LCALF | BP_RFOOT | BP_RCALF });
      case "cloak"       : return ({ BP_NECK });
      default            : return ({ });
   }
}

/** Returns the number of basic requirements the player does NOT meet in
 * order to wear this armour. Returns 0 if the player may wear
 * the armour. Returns -1 if player is not a valid object.
 * \param player The player for whom you are doing a stat check
 * against this armour.
 * \param silent (Optional) If true, no message will be printed
 * to the player if they cannot wear the armour. Otherwise,
 * The player is told the reason that they can't wear the armour.
 */
varargs int query_requirements(object player, int silent) {
  int fail = 0;
  if( !player ) return -1;
  if (player->query_level() < query_req(REQ_LEVEL)) {
    if( !silent ) msg("You are not experienced enough to wear this piece of armour.");
    fail++;
  }
  if (player->query_strength() < query_req(REQ_STR)) {
    if( !silent ) msg("You are not strong enough to wear this piece of armour.");
    fail++;
  }
  if (player->query_dexterity() < query_req(REQ_DEX)) {
    if( !silent ) msg("You are not dexterous enough to wear this piece of armour.");
    fail++;
  }
  if (player->query_constitution() < query_req(REQ_CON)) {
    if( !silent ) msg("You do not have the physical endurance to wear this piece of armour.");
    fail++;
  }
  if (player->query_wisdom() < query_req(REQ_WIS)) {
    if( !silent ) msg("You are not wise enough to wear this piece of armour.");
    fail++;
  }
  if (player->query_intelligence() < query_req(REQ_INT)) {
    if( !silent ) msg("You are not intelligent enough to wear this piece of armour.");
    fail++;
  }
  if (player->query_will() < query_req(REQ_WILL)) {
    if( !silent ) msg("You do not have the mental strength to wear this piece of armour.");
    fail++;
  }
  if (player->query_skill("combat.armour."+armour_type) < query_req(REQ_SKILL)) {
    if( !silent ) msg("Your skill with armour is not sufficient to wear this piece of armour.");
    fail++;
  }
  return fail;
}

/******************************* Sets *******************************/

set_ac(int *x) {
  int f;
  if (sizeof(x) == DAM_TYPES) {
    ac = copy(x);
    write("set_ac ( ");
    for (f = 0; f< DAM_TYPES; f++)
      write(x[f]+" ");
    write(")\n");
  } else
    write("set_ac got "+x+" values instead of "+DAM_TYPES+"\n");
 max_condition = 0;
}

set_one_ac(int which, int what) {
  int f,*z;
  z = allocate(DAM_TYPES);
  for (f = 0; f < DAM_TYPES; f++) {
    if (f == which) z[f] = what;
    else z[f] = query_ac(f);
  }
  set_ac(z);
  max_condition = 0;
}

set_edged_ac(int x)	{ set_one_ac(DAM_EDGED, x); }
set_piercing_ac(int x)  { set_one_ac(DAM_PIERCING, x); }
set_blunt_ac(int x)     { set_one_ac(DAM_BLUNT, x); }
set_fire_ac(int x)      { set_one_ac(DAM_FIRE, x); }
set_ice_ac(int x)       { set_one_ac(DAM_ICE, x); }
set_elec_ac(int x)      { set_one_ac(DAM_ELEC, x); }
set_poison_ac(int x)    { set_one_ac(DAM_POISON, x); }
set_acid_ac(int x)      { set_one_ac(DAM_ACID, x); }
set_mental_ac(int x)    { set_one_ac(DAM_MENTAL, x); }
set_rad_ac(int x)       { set_one_ac(DAM_RADIATION, x); }
set_holy_ac(int x)      { set_one_ac(DAM_HOLY, x); }
set_unholy_ac(int x)    { set_one_ac(DAM_UNHOLY, x); }
set_plasma_ac(int x)    { set_one_ac(DAM_PLASMA, x); }
set_shadow_ac(int x)    { set_one_ac(DAM_SHADOW, x); }
set_disease_ac(int x)   { set_one_ac(DAM_DISEASE, x); }

set_bp_options( int *x ) {
   bp_options = x;
}

set_worn(int x) {
   object owner;

   owner = environment(this_object());
   if( owner && !owner->query_living() ) owner = 0;

   if( owner )
      owner->remove_bp_armour( worn );
   worn = x;
   if( owner )
      owner->add_bp_armour(worn);
}

set_condition(int x) { condition = x; }
set_max_condition(int x) { max_condition = x; }
add_condition(int x) {
  condition += x;
  if (condition <= 0)
    if (enchanted) // enchanted weapons cannot be broken
      condition = 1;
    else
      condition = -1;
  if (query_broken() && worn) {
    msg("Your armour ("+this_object()->query_distant()+") has broken!");
    set_worn( 0 );
  }
}

// for sanity reasons, curse levels should be 0..50, an item of curse
// level > 50 should prolly be set level 100 to denote that the curse is
// unremovable... ick... don't do that very often, ok?
set_cursed(int x) {
  if (x >= 0)
    cursed = x;
}

set_enchanted(int x) {
  if (x == 0 || x == 1)
    enchanted = x;
}

set_armour_type(string x) {
   armour_type = x;
   bp_options = 0;
}

set_req(int req,int level) {
  requirements[req] = level;
}

set_level_req(int x)    { requirements[REQ_LEVEL] = x; }
set_str_req(int x)      { requirements[REQ_STR] = x; }
set_dex_req(int x)      { requirements[REQ_DEX] = x; }
set_con_req(int x)      { requirements[REQ_CON] = x; }
set_wis_req(int x)      { requirements[REQ_WIS] = x; }
set_int_req(int x)      { requirements[REQ_INT] = x; }
set_will_req(int x)     { requirements[REQ_WILL] = x; }
set_skill_req(int x)    { requirements[REQ_SKILL] = x; }


/****************************** Other *******************************/

create() {
  ac = allocate(DAM_TYPES);
  requirements = allocate(REQ_TYPES);
  this_object()->set_type("armour");
}

on_drop() {
  remove_armour();
  if (worn)
    return MOVE_SILENCE_FLAG; // No message
  return 0;  // Normal behavior
}

on_give() {
  remove_armour();
  if (worn)
    return MOVE_SILENCE_FLAG;
  return 0;
}

int wear_armour() {
   int i, wear_location;
   object owner = environment(this_object());

   if( !owner ) return 0;
   if( worn ) {
      msg("You are already wearing that!");
      return 0;
   }
   wear_location = 0;

   if( !owner->query_living() )
      return 0;

   // Find out if they have a body part free capable of
   // wearing this armour type.
   foreach( i : query_bp_options() )
      if( !owner->query_bp_armour(i) && i == owner->query_has_bp(i) ) wear_location = i;

   if( !wear_location ) {
      msg( "You already have too much stuff on. Nowhere to put this." );
      return 0;
   }

   if( query_broken() ) {
      msg("It's broken. You will need to repair it before you can wear it.");
      return 0;
   }
   // returns true if base reqs not met, so false means they can wear it
   if( query_requirements(this_player()) == 0 ) {
      // returns true if do_wear() has been defined, so false means we need
      // to manually wear the item for them
      if( this_object()->do_wear() == 0 ) {
         set_target(this_object());
         owner->msg_local("~Name ~verbwear ~targ.");
         set_worn( wear_location );
      }
   }
   owner->recalc();
   return 1;
}

int remove_armour() {
  object owner = environment(this_object());
  if (!worn)
    return 0;
  if (!owner->query_living())
    return 0;
  // returns true if do_remove() has been defined, so false means we have
  // to do this our selves as well
  if (this_object()->do_remove() == 0) {
    if (cursed) {
      msg_object(owner,"You can't remove your armour! The very fastenings seem to tighten when you tug at them.");
      return 0;
    } else {
      set_target(this_object());
      owner->msg_local("~Name ~verbremove ~targ.");
      set_worn(0);
    }
  }
  owner->recalc();
  return 1;
}

void move( mixed param ) {
   object old_env;

   old_env = environment(this_object());
   ::move(param);
   if( old_env && old_env->query_living() ) old_env->recalc();
}
