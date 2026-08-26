
/*
// Program: /std/living/attack.c
// Written mostly by Buddha@TMI
// Originally based on the attack.c found in the mudlib.n,
// many structural similarites may remain.
// It is is a part of the TMI distribution mudlib.
// Please retain this header if you use this file.
// Much work was done in December of 1991.
// revised 2-16-92 by Buddha
// revised again 3-1-92 by Buddha
// Rewritten to remove the LOC, and to update it for mudlib 0.9, by
// Mobydick@TMI-2, 9-21-92
// Added some stuff to make monsters remember and attack old opponents.
// Mobydick, 2-3-93.
// Added receive_damage() and receive_healing() systems, Watcher 3-27-93
*/
 

// Basic structure:
// The function kill_ob is used to initiate combat. The kill command calls
// it in any monster or player entering combat, as do the combat spells and
// other nastiness. It also turns on a monster's heartbeat if that is
// necessary.
// The heart_beat calls the continue_attack function. This function checks
// to see if the monster is dead and if so, starts the death sequence. It
// then checks the list of current opponents and removes any that are dead
// or otherwise out of the MUD. Opponents that have left the room are moved
// onto the "will_kill" list. It then checks to see if spellcasting or
// other activity has blocked the attack. If not, it calls execute_attack
// which does the actual attack against the first attacker on the list.
// The functions continue_attack and execute_attack are defined seperately
// in each body.

#include <config.h>
#include <stats.h>
#include <mudlib.h>

inherit SECURE_OBJECT ;
 
// Prototypes for things that come in through the body object.

varargs mixed set(string prop, mixed arg, mixed security) ;
nosave object *attackers, target, *will_attack; // wombled by buddha
nosave int any_attack ;
mixed link_data(string what);
 
nosave string qs ;
private nosave int heal_time ;

// These variables are used in execute_attack() but are declared here to get
// around the limit on number of variables declared in the function. Kludge.

nosave string *vb, *vb2 ;
nosave int dmin, dmax, damage ;
nosave string weapontype ;
nosave int skill_improve_prob ;

void run_away();
int kill_ob (object victim) ;
void set_verbs(string *verbs) ;
void set_verbs2 (string *verbs) ;
string *get_verb() ;
void cease_all_attacks();
void continue_attack() ;

// This function handles the damage calls from battle. It only accepts
// positive damage calls. receive_healing() should be used for healing.
 
int receive_damage(int damage) {
   int dam;

   set ("last_attacker", previous_object()) ;
   if(damage <= 0 || link_data("dead") || query("hit_points") < 0 ||
      query("linkdead"))  return 0;
 
/*
This stuff is commented out because damage may come from non-living
objects or from spell commands - it's hard to know for sure what
object is the one that you want to attack.

   if(!attackers || member_array(this_player(), attackers) == -1)
      kill_ob(this_player());

*/
 
   dam = query("hit_points") - damage;
   if(dam < 0)  dam = -1;
 
   set("hit_points", dam);
 
return 1; }
 
// This function handles the healing calls from spells. It only accepts
// positive healing calls.  receive_damage() should be used for damage.
 
int receive_healing(int healing) {
   int heal;
 
   if(healing <= 0 || link_data("dead") || query("hit_points") < 0)
	return 0;

   heal = query("hit_points") + healing ;
   if(heal > query("max_hp"))  heal = query("max_hp");
 
   set("hit_points", heal);

return 1; }
 

// This function updates the object's AC. It got moved out of the
// player object so monsters could have it too.

int calc_armor_class() {

        mapping armor ;
        int ac ;
        string *types ;
        int i ;

        armor = query("armor") ;
        if (!armor) {
//  The dude is butt-naked.
                set ("armor_class", 0) ;
                return 0 ;
        }
        ac = 0 ;
        types = keys(armor) ;
        for (i=0;i<sizeof(types);i++) {
                ac = ac + armor[types[i]] ;
        }
        set ("armor_class", ac) ;
        return ac ;
}
// This function is used to prevent a player from attacking for a time.
// Called by the wield command, the various spells, other places. Anything
// a players does that should interfere with his combat should call this.

void block_attack (int t) {

	int i ;

// If we're not in combat, then don't bother.
	if (!any_attack) return ;
#ifdef BLOCK_ATTACK
	i = query("stop_attack") ;
	set ("stop_attack",i+t/2) ;
#endif
}

// This is called in the heart_beat to decrease the blocking time.

void unblock_attack() {

	int i ;

	i = query("stop_attack")-1 ;
	if (i>-1) set ("stop_attack",i) ;
}

// This function returns 1 if the player has stop_attack set and 0 if not.
// It's probably a pretty stupid thing to use, since you should just query
// stop_attack directly, but it's here if you want it.

int player_busy() {
	return query("stop_attack") ;
}

// This function is used to initialize various values.

void init_attack() {
   attackers = ({});
}

// This function returns the object at the top of the attackers list.

object query_attacker() {
	if(!attackers || !sizeof(attackers))  return 0;
	return attackers[0] ;
}

// Remove dead or nonexisting objects out of the list of attackers.
// Return true if there is still an attack going.

/*
// This is the 'kill' command. If the victim is not attacked yet,
// then it is entered first into the list of victims. If it is already
// in the list, then it is moved to the first entry.
*/
int kill_ob (object victim) {
   int i;
 
   if(query("linkdead"))  return 0;

#ifdef NO_PKILL
    if (userp(this_object()) && userp(victim)) {
        if (query("no_attack") || victim->query("no_attack"))
            return 2;
    }
// no_attack for users added by Blue, 941022.
#endif
 
   if (!attackers) {
	init_attack() ;
	attackers = ({ victim }) + attackers;
	any_attack = 1;
	set_heart_beat(1) ;
      victim->kill_ob(this_object());
      return 1;
    }
 
   i = member_array(victim, attackers);
 
   if (i > -1) {
         return 0;
    }
   attackers = ({ victim }) + attackers;
   any_attack = 1;
   victim->kill_ob(this_object());
	set_heart_beat(1) ;
   return 1;
}

// This is a default heart_beat for living objects. There's a player heart_beat
// in user.c and a monster heart_beat in monster.c, both of which should
// override this one.

void heart_beat() {
	unblock_attack() ;
	continue_attack() ;
}

// Continue_attack is called from heart_beat in monster.c and user.c.
// here is where we can try to see if we're dead or in combat.

// Call this to erase the list of opponents to attack. This will NOT stop
// them from attacking you again...  ;)

void cease_all_attacks() {
   attackers = ({});
   any_attack = 0;
}

// Call this function to remove a specific user from the attack array.
 
int remove_attacker(object obj) {
   if(member_array(obj, attackers) != -1)  attackers -= ({ obj });
return 1; }
 
// This function returns the current target if there is one. The "current
// target" could be in another room, or dead, and not cleaned out of the
// list yet, so be reasonably careful with this.

object query_current_attacker() {
   if(sizeof(attackers) == 0)
      return 0;
   else
      return attackers[0];
}

// This function returns the whole attackers list. Same caveat as above.

object *query_attackers() {
	if (sizeof(attackers)==0) {
		return 0 ;
	} else {
		return attackers ;
	}
}


// This lets a wimpy player or monster run away. Buddha got this part
// working for the case of rooms with no exits. (Bad sign for the wimp.)


void run_away() {

	int wimpy ;
	string direction ;
	mapping womble ;

   womble = environment(this_object())->query("exits") ;
   if (!womble) return;
   direction = this_player()->query("wimpydir") ;
   if (!direction || !womble[direction]) {
   	direction = keys(womble)[random(sizeof(womble))] ;
   }
   write ("You flee to the "+direction+"!\n") ;
   this_player()->force_me("go "+direction) ;
   return ;
}

// This function restores spell points and hit points to the player and
// deals with his blood-alcohol level.
// Drunkenness is handled as follows: 0 indicates sobriety. Positive
// numbers indicate drunkenness, and diminish over time. When the player
// reaches drunkenness of 1, we then set his drunkenness to -6, where
// the negative number means hangover rather than drunkenness, and we
// begin counting up until we reach 0, at which time he's sober again.

void heal_up() {

	int hp, sp, maxh, maxs ;
	int time, dr, rate ;

// If he's a ghost we want to skip this entirely.
	if (query("ghost")) return ;
	heal_time = heal_time + 1 ;
	time = query("time_to_heal") ;
// If the healing rate wasn't set, then it's one hp/sp each 10 heartbeats.
	if (time==0) time = 10 ;
// Check to see if it's time to improve hits and spells.
	if (heal_time>time) {
		hp = query("hit_points") ;
		sp = query("spell_points") ;
		maxh = query("max_hp") ;
		maxs = query("max_sp") ;
		heal_time = 0 ;
// The drunkenness comes commented out. If you add the drunkenness stuff,
// put this back in.
/*
		dr = query("drunk") ;
		switch (dr) {
			case -1 : { write ("Your headache clears up.\n") ; break; } 
			case 1 : { write ("Suddenly you have a massive headache.\n") ; break ; }
			case 6 : { write ("Your head is clearing.\n") ; break ;}
			case 11 : { write ("You feel drunk.\n") ; break ; }
			case 16 : { write ("The room stops spinning.\n") ; break ; }
			case 21 : { write ("You can see straight again.\n") ; break ; }
		}
// If the player's drunk is 1, we send him into hangover land.
		if (dr==1) dr=-6 ;
// Dry him out, or fix his hangover, as needed.
		if (dr>0) set ("drunk", dr-1) ;
		if (dr<0) set ("drunk", dr+1) ;
*/
		if (hp==maxh && sp==maxs) return ;
// If drunkenness, put this line back in, and have sp and hp increase by
// rate instead of by 1.
// You could also put rate in but have it affected by things other than
// alcohol, perhaps by food, by rest, or by magic spells.

// Eodon noticed that being drunken won't do any good
// since you'll het dr = -6 and get -6/5+1 = 0 for healing
// Leto 02/27/95
//		rate = dr/5+1 ;
		if (hp<maxh) {
			set ("hit_points", hp+1) ;
		} else {
			set("hit_points", maxh) ;
		}
		if (sp<maxs) {
			set ("spell_points", sp+1) ;
		} else {
			set ("spell_points", maxs) ;
		}
	}
}

// The set_verbs function stores the list of verbs to be used when a player
// or monster makes an attack, and conjugates the verbs by adding an "s" to
// the end of each. You can use set_verbs2, below, to override this
// conjugation if you need to.

void set_verbs(string *verbs) {

        int i ;
        string w1, w2 ;

        vb = verbs ;
        vb2 = allocate(sizeof(vb)) ;
        for (i=0;i<sizeof(verbs);i++) {
                if (sscanf(verbs[i],"%s %s",w1,w2)==2) {
                        vb2[i]=w1+"s "+w2 ;
                } else {
                        vb2[i]=verbs[i]+"s" ;
                }
        }
}

// This function is used to set the conjugated forms of the verbs. Use
// this when one of the attack verbs is irregular: there are some monster
// examples that do it.

void set_verbs2 (string *verbs) {
        vb2 = verbs ;
}

// The get_verb function returns a random verb from the list of verbs.
// It returns bboth forms of the verb in a 2-element array.

string *get_verb() {

        int i ;

        i = random(sizeof(vb)) ;
        return ({ vb[i], vb2[i] }) ;
}
