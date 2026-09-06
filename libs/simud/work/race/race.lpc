#include <const/raceconst.h>

struct body_part {
   string name;
   int size, vitality;
};

/** Every living creature is (or at least, should be) assigned to a race object.
 * Races aren't necessarily just things like human/elf/dwarf (although they are
 * used for that), but they can also cover species differences.
 *
 * Races keep track of a lot of that information that "just seems obvious", like
 * whether a creature has hands (as opposed to paws or claws), or whether it has
 * some body parts at all, such as a third pair of limbs (insects, some
 * mutant giants) and a tail.
 *
 * This object consists primarily of a long series of queries and sets -- one
 * pair for each available body part. There is one special set, for bp_map,
 * that takes a mapping instead of a boolean value, and maps from body-part
 * type to body part name. The values for body-part type are the constants found
 * in const.h.
 *
 * This file is a little difficult to document well. The usage is probably
 * best demonstrated by looking at other files found in this (/race/) directory,
 * and copying their examples. human.c was particularly written with an eye
 * toward acting as a template.
 *
 * ---
 *
 * I have taken over playing with races as Acius hasn't touched it since
 * he wrote it initially, and since I'm the one working with the whole
 * combat/armour/ai/food thing anyway.
 *
 * I have added size and different food/water costs (per hour) to the mix
 * now, and have also filled out the list of body parts (removing some
 * useless parts - like knees - and adding ones that got forgotten on the
 * first pass - secondary hands, etc...).
 *
 * More documentation is probably forthcoming if I get around to
 * explaining how things work. Chances are that I need to write this
 * outside of the source anyhow... shrug. -- Al [8.8.02]
 */

/** Names of the body parts, with their bitflags as keys.
 *
 * I have extended this mapping to also include data on the size of the
 * body part (that is to say it's relative chance of being hit by a
 * randomly placed blow in combat) as well as an indicator of how vital
 * the part is to basic life functions (0 = normal, + = more vital,
 * - = less vital, vitality modifies wc of blows taken).
 *
 * Note: The bp_vitality has been ignored in the combat calculations,
 * because no bp_vitality was ever being set,
 * so keeping it isn't making a lot of sense atm. However, because somebody
 * made it a !#%^@ wide mapping, it's nigh impossible to get rid of.
 * Somebody should clean this up eventually.
 */
protected mapping bp_map = ([ ]);

/// An integer holding up to 32 bit flags, boolean values for body parts possessed.
int bp_flags;

/** The race's default body size, used for determining what equipment may
 * be used. Humans are size 20. It is possible to use items of up to 8
 * sizes different than yourself in either direction (ie, humans can use
 * eq ranging from size 12 to 28).
 */
int size;

/** Normal food lost per game hour. This should increase with size. Humans
 * lose 4 food per hour. Kittens should lose only 1. Dragons would need to
 * eat more to fuel their gigantic bodies and probably lose 10 food per
 * hour.
 */
int food_cost;

/// Normal water lost per game hour. Similar to food_cost.
int water_cost;

int hp_per_con;
int min_hp;

int mana_per_emp;
int mana_per_int;
int min_mana;

int end_per_con;
int end_per_will;
int min_end;

int query_size() { if (!size) size = 20; return size; }
int query_food_cost() { if (!food_cost) food_cost = size/5; return food_cost; }
int query_water_cost() { if (!water_cost) water_cost = size/5; return water_cost; }

int query_hp_per_con() { if (!hp_per_con) hp_per_con = 5; return hp_per_con; }
int query_min_hp() { if (!min_hp) min_hp = 25; return min_hp; }
int query_mana_per_emp() { return mana_per_emp; }
int query_mana_per_int() { return mana_per_int; }
int query_min_mana() { if (!min_mana) min_mana = 10; return min_mana; }
int query_end_per_con() { return end_per_con; }
int query_end_per_will() { return end_per_will; }
int query_end_per_wil() { return this_object()->query_end_per_will(); }
int query_min_end() { if (!min_end) min_end = 10; return min_end; }

void set_size(int x) { size = x; }
void set_food_cost(int x) { food_cost = x; }
void set_water_cost(int x) { water_cost = x; }

void set_hp_per_con(int x) { hp_per_con = x; }
void set_min_hp(int x) { min_hp = x; }
void set_mana_per_emp(int x) { mana_per_emp = x; }
void set_mana_per_int(int x) { mana_per_int = x; }
void set_min_mana(int x) { min_mana = x; }
void set_end_per_con(int x) { end_per_con = x; }
void set_end_per_will(int x) { end_per_will = x; }
void set_min_end(int x) { min_end = x; }

/// Used by objedit.
string race_info() {
   return "bp_flags\nbp_map\nsize\nfood_cost\nwater_cost\nhp_per_con\nmin_hp\nmana_per_emp\nmana_per_int\nmin_mana\nend_per_con\nend_per_will\nmin_end";
}

/// Sets the entire body-parts flag set at once.
void set_bp_flags( int flags ) {
   if( intp(flags) ) bp_flags = flags;
}

/// Query the current body-part flags.
int query_bp_flags() {
   return bp_flags;
}

void add_bp( int bp, string name, int size, int vitality ) {
   bp_map[bp] = (<body_part> name:name, size:size, vitality:vitality);
}

/// Set the name of the body part \a bp to \a name. Use BP_XXXX constants for \a bp.
void set_bp_name( int bp, string name ) {
   if (!member(bp_map,bp))
     bp_map += ([ bp: (<body_part> name: name) ]);
   else
     bp_map[bp]->name = name;
}
/// \return The name of the body part given by \a bp. Use BP_XXXX constants for \a bp.
string query_bp_name( int bp ) {
   if( !intp(bp) || !bp_map[bp] ) {
      debug("invalid body part = "+bp);
      return "INVALID BODY PART";
   }
   return bp_map[bp]->name;
}

/// Set the size of body part \a bp to \a size.
void set_bp_size( int bp, int size ) {
   if( !bp_map[bp] ) return;
   bp_map[bp]->size = size;
}
/// \return The size of body part \a bp.
int query_bp_size( int bp ) {
   if( !bp_map[bp] ) return 0;
   return bp_map[bp]->size;
}

/// Set the vitality of body part \a bp to \a vitality. Never used.
void set_bp_vitality( int bp, int vitality ) {
   if( !bp_map[bp] ) return;
   bp_map[bp]->vitality = vitality;
}

/// \return The vitality of body part \a bp. Never used.
int query_bp_vitality( int bp ) {
   if( !bp_map[bp] ) return 0;
   return bp_map[bp]->vitality;
}

/// Set the body parts mapping directly.
void set_bp_map( mapping m ) {
   if( !mappingp(m) )
      raise_error( "set_bp_map called with non-mapping as parameter..." );
   //debug("Setting bp_map! Trying to find why /race/beast loses its, see... (size="+sizeof(m)+")");
   bp_map = m;
}

/// Query the entire body parts mapping.
mapping query_bp_map() {
   return copy(bp_map);
}

/// \return A random body part (weighted by size)
int query_random_bp() {
   int total = 0, x;
   int *list;

   if( !mappingp(bp_map) || !sizeof(list = m_indices(bp_map)) ) {
      debug("Whoa... "+object_name()+" does not have any body parts...","combat");
      return 0;
   }
   foreach ( x : list ) {
      if (bp_flags&x && bp_map[x]->size)
         total += bp_map[x]->size;
      else
         list -= ({ x });
   }
   total = random(total);
   while (sizeof(list)) {
      if (total > 0) {
         total -= bp_map[list[0]]->size;
         // debug("dropping "+query_bp_name(list[0])+", total = "+total,"combat");
         list -= ({ list[0] });
      } else {
         debug("weighted random random says: "+query_bp_name(list[0]),"combat");
         return list[0];
      }
   }

   // safety net ignores all of my math if something goes wrong ;)
   x = 0;
   while ( !(x & bp_flags) )
      x = m_indices(bp_map)[random(sizeof(bp_map))];
   debug("Oops! completely random says: "+query_bp_name(x),"combat");
   return x;
}

/// Sets (to true) on or more body part flags.
void set_bp_flag( int flag ) {
   bp_flags |= flag;
}

/// Clears (to false) one or more body part flags.
void clear_bp_flag( int flag ) {
   bp_flags &= (0xFFFFFFFF - flag);
}

/// Returns the racial maximum for any given stat
int query_stat_max( string stat ) {
   return 20; // override this for special races, eh? :)
}

////// Stuff below this point will be cleaned up later...

/*****
/// Used for changing whether or not this race object has this body part.
void set_has_head(int x) {
   if(x)
      set_bp_flag(BP_HEAD);
   else
      clear_bp_flag(BP_HEAD);
}

/// \return True if this race has this body part, false otherwise.
int query_has_head() {
   return (query_bp_flags() & BP_HEAD) > 0;
}
*****/

void create() {
   // The objedit default settings are for a simple humanoid.
   hp_per_con = 5;
   min_hp = 25;
   mana_per_emp = 2;
   mana_per_int = 1;
   min_mana = 5;
   end_per_con = 2;
   end_per_will = 1;
   min_end = 5;
//   bp_map = m_allocate(0,3);
   set_bp_flags( BT_HUMANOID );
}
