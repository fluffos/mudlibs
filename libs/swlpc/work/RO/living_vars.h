
string race;		/* if 0, human. */
nosave int time_to_heal;	/* Count down variable. */
int money;		/* Amount of money on player. */
array death_hook = [];
/* How about 1 flags int and using & and some #ifdefs? */
int is_npc, brief;	/* Flags. */
int ghost;		/* Used for monsters that can leave a ghost. */

/* probably write out level now! */
int level, wiz_level;	/* Level of monster. */
nosave int base_armour; /* Basic (ie skin) armour class of monster. */
nosave array armour = [];	/* What armour they have */
nosave array prots = [];	/* What protections they have */
string dam_type; /* Done when creature has no weapon */
int hit_point;		/* Number of hit points of monster. */
int max_hp;
int action, reaction;
array body_locations; 
array body_hps; 
array body_damage;
array disable;		/* disablities */
int bleeding;		/* are we bleeding? */
/* these should all be in one array I reckon */
string msgin, msgout;	/* Messages when entering or leaving a room. */

nosave object attacker_ob;	/* Name of player attacking us. */
int weapon_class;	/* How good weapon. Used to calculate damage. */
nosave object name_of_weapon;	/* To see if we are wielding a weapon. */
nosave int local_weight; /* weight of items */
string cap_name;	/* Capital version of "name". */
int sp;			/* Current spell points. */
int is_invis;		/* True when player is invisible */
int wimpy;		/* Automatically run when low on HP */
string current_room;	/* Name of current room. */
string prev_room;	/* Name of previous room. */
string gender;      /* monsters should have genders too */
nosave int fatigue_points;
/* YES! Move_hooks IS meant to be nosave! */
nosave array move_hooks = []; /* object/function pairs to be called in move_player */
array allies;			/* array of my friends :-) */

/*
 * The following would be required in any saved unique.
 * To this, I'd like to add `expiry_time' or some such,
 * for purges (but I'll leave it for now).
 */

string name;			/* Name of object. */

