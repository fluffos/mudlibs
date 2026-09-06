/**
 * \c #include \c <bonus.h> to use this object.
 *
 * Armour, weapons, magical items and similar may all be capable of conferring
 * bonuses to a player's stats. You may hard-code these bonuses into your source
 * code if you wish, but a simpler way to handle them is to simply inherit this
 * file and allow them to be modified with the object editor. Bonuses are
 * always temporary; they are removed from the player's stats as soon as
 * the bonus-giving object is discarded or removed.
 *
 * \todo We still need to provide a mechanism so that an object can decide
 * under what conditions bonuses are conferred; for weapons, the bonuses
 * should only be conferred if the weapon is wielded. For magic items, etc.
 * they may be conferred always.
 * This file will need a rewrite after we have completely
 * decided what all our bonuses will be.
 */
/// Inheritable component for defining bonuses

/// A mapping of all the bonuses
mapping bonus = ([ ]);

/**
 * @name Sets
 * Functions for setting bonus values.
 */
//@{
/// Sets the bonus for strength. This forces a recalculation of bonuses when it is called.
void set_str_bonus(int x) { bonus["str"] = x; if( environment(this_object()) ) environment( this_object() )->recalc(); }

/// Sets the bonus for dexterity. This forces a recalculation of bonuses when it is called.
void set_dex_bonus(int x) { bonus["dex"] = x; if( environment(this_object()) ) environment( this_object() )->recalc(); }

/// Sets the bonus for constitution. This forces a recalculation of bonuses when it is called.
void set_con_bonus(int x) { bonus["con"] = x; if( environment(this_object()) ) environment( this_object() )->recalc(); }

/// Sets the bonus for speed. This forces a recalculation of bonuses when it is called.
void set_spd_bonus(int x) { bonus["spd"] = x; if( environment(this_object()) ) environment( this_object() )->recalc(); }

/// Sets the bonus for will. This forces a recalculation of bonuses when it is called.
void set_wil_bonus(int x) { bonus["wil"] = x; if( environment(this_object()) ) environment( this_object() )->recalc(); }

/// Sets the bonus for intelligence. This forces a recalculation of bonuses when it is called.
void set_int_bonus(int x) { bonus["int"] = x; if( environment(this_object()) ) environment( this_object() )->recalc(); }

/// Sets the bonus for empathy. This forces a recalculation of bonuses when it is called.
void set_emp_bonus(int x) { bonus["emp"] = x; if( environment(this_object()) ) environment( this_object() )->recalc(); }

/// Sets the bonus for charisma. This forces a recalculation of bonuses when it is called.
void set_cha_bonus(int x) { bonus["cha"] = x; if( environment(this_object()) ) environment( this_object() )->recalc(); }
//@}

/**
 * @name Queries
 * Functions to query bonus values and settings. If you don't recognize an
 * abbreviation, check the matching set_ function.
 */
//@{
int query_str_bonus() { return bonus["str"]; }
int query_dex_bonus() { return bonus["dex"]; }
int query_con_bonus() { return bonus["con"]; }
int query_spd_bonus() { return bonus["spd"]; }
int query_wil_bonus() { return bonus["wil"]; }
int query_int_bonus() { return bonus["int"]; }
int query_emp_bonus() { return bonus["emp"]; }
int query_cha_bonus() { return bonus["cha"]; }

/** \return True, indicating that bonuses defined in this object should
 * be applied to any living holding it. This function may be overridden
 * in classes which inherit it (such as weapons or armour), so that
 * bonuses may be conditional on the object being worn/wielded, paired
 * with another object, etc.
 */
query_use_bonuses() { return 1; }
//@}

/// Query the mapping of bonuses on this object
mapping query_bonuses() {
   return bonus;
}

/** Set all the bonuses in a single function call.
 * \param m A mapping of the form ([ "type": (int) amount ])
 */
void set_bonuses(mapping m) {
   if( mappingp(m) )
      bonus = m;
}

/**
 * Returns a \\n separated list of variables for which this file
 * contains queries and sets. You may call this function to find
 * out if an object inherits this one.
 */
string bonus_info() { return "str_bonus\ndex_bonus\ncon_bonus\nspd_bonus\nwil_bonus\nint_bonus\nemp_bonus\ncha_bonus\nbonuses"; }
