#include <object.h>
#include <saveload.h>

/** This file is based very loosely on Acius' hunger_ob. See
 * /obj/hunger.c for original comments.
 *
 * This particular object handles all food-related buffing effects.
 *
 * At present, only basic stat increase-type bonuses work, but others
 * will be forthcoming.
 */

/**
 * buffmap = ([ "food item": buffstruct ])
 */
struct Buff {
	int		time;	// how many food ticks before this effect ends
	mapping	aff;	// ([ "str": +1, "dex": -1, etc... ])
};
mapping buffmap;

mapping query_buffmap() {
	if( !mappingp(buffmap) )
		buffmap = ([]);
	return copy(buffmap);
}
string * query_bufflist() {
	return m_indices( query_buffmap() );
}
void set_buffmap(mapping map) { buffmap = map; }

void on_move() {
	if (!environment()->query_is_living())
		destruct(this_object());
}

/// \return This object's name, "hunger_ob"
string query_name() { return "foodbuff_ob"; }

/// \return this_object() if \a str is "hunger_ob", false (0) otherwise.
object id(string str) {
	if( str == "foodbuff_ob" ) return this_object();
	else return 0;
}

/// \return True, indicating that this object has stat bonus information.
int query_use_bonuses() { return 1; }


/// \return The actual bonus of any given type stored in the mapping
int calc_bonus(string type) {
	string buff, stat;
	int val, bonus = 0, penalty = 0;
	foreach( buff : query_bufflist() ) {
		struct Buff data = buffmap[buff];
		foreach( stat, val : data->aff ) {
			if( stat == type ) {
				if ( val > bonus )
					bonus = val;
				if ( val < penalty )
					penalty = val;
			}
		}
	}
	return bonus + penalty;
}

/// Add an affect to the named buff (creating it if needed)
void add_affect(string buff, string stat, int amt) {
	struct Buff data;
	if( !mappingp(buffmap) )
		buffmap = ([]);
	if( member(buffmap, buff) )
		data = buffmap[buff];
	else
		data = (<Buff> aff: ([]) );
	data->aff[stat] = amt;
	buffmap[buff] = data;
}

/// \return Mapping of all affects of an individual buff source
mapping query_affects(string buff) {
	if( !mappingp(buffmap) )
		buffmap = ([]);
	if( member(buffmap, buff) )
		return buffmap[buff]->aff;
	else
		return ([]);
}

/// \return One affect of a given buff source
int query_affect(string buff, string stat) {
	return query_affects(buff)[stat];
}

/// Returns number of ticks remaining in a given buff
int query_time(string buff) {
	if( !mappingp(buffmap) )
		buffmap = ([]);
	if( member(buffmap, buff) )
		return buffmap[buff]->time;
	else
		return -1;
}

/// Set the time remaining on a given buff
int set_time(string buff, int time) {
	if( !mappingp(buffmap) )
		buffmap = ([]);
	return buffmap[buff]->time = time;
}
/// Allow for manual tweakage of time on a given buff
int add_time(string buff, int time) {
	return set_time(buff, query_time(buff) + time);
}

/// \return The number of points of strength to add
int query_str_bonus() { return calc_bonus("str"); }
/// \return The number of points of dexterity to add
int query_dex_bonus() { return calc_bonus("dex"); }
/// \return The number of points of constitution to add
int query_con_bonus() { return calc_bonus("con"); }
/// \return The number of points of speed to add
int query_spd_bonus() { return calc_bonus("spd"); }
/// \return The number of points of intelligence to add
int query_int_bonus() { return calc_bonus("int"); }
/// \return The number of points of empathy to add
int query_emp_bonus() { return calc_bonus("emp"); }
/// \return The number of points of charisma to add
int query_cha_bonus() { return calc_bonus("cha"); }
/// \return The number of points of will to add
int query_wil_bonus() { return calc_bonus("wil"); }

/// Debit timers on all different effects.
void on_tick() {
	int keepme = 0;
	string buff;
   if( !environment(this_object())->query_is_living() )
      destruct(this_object());
	// cycle through all entries and reduce them, report messages when they
	// wear off completely
	foreach( buff : query_bufflist() ) {
		struct Buff data = buffmap[buff];
		data->time--;
		if( data->time < 1 ) {
			// remember, buff is obj->query_speific()
			msg_object(environment(),"~[030You feel the effects of "+buff+" that you ate fade.~CDEF");
			buffmap -= ([ buff ]);
			// update their stats ;)
			environment()->recalc();
		} else
			keepme = 1;
	}
	
	// if we're all out of buffs, get rid of this stupid thing, eh?
	if( !keepme ) {
		destruct(this_object());
	}
}
