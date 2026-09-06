/*
 * Priest sample bottle & potion.
 * Dark elves can drink blood, others will just spit it on the ground.
 * Only priests can see, what kind of blood / what kind of potion this is,
 * others will just see "bottle of blood" or "green potion" etc.
 *
 * 4/19/1997 First version by Chopin 
 * 1/02/1998 Baccata: Added id 'empty bottle'
 * 5/10/98 Chopin: Bottles can now be of different sizes
 */

#include <drink.h>
#include <guild.h>
#include <player_defs.h>
#include <room_defs.h>

string its_race;
int its_level;
string pot_name, pot_color;
closure effect_fun;
closure smash_funs;

int bottle_status;
status property_of_hob;

#define SAMPLE_BOTTLE 0
#define POTION 1
#define DISTILLATION 2

#define SMALL_BOTTLE 1
#define MEDIUM_BOTTLE 2
#define LARGE_BOTTLE 3

string query_dist_race() { return its_race; }
int query_dist_level() { return its_level; }
status is_priest_bottle() { return 1; }
status is_priest_potion() { return bottle_status == POTION; }
status is_property_of_hob() { return property_of_hob; }
string query_pot_name() { return pot_name; }

void set_hob() { property_of_hob = 1; }

// prototypes:
string my_query_short(int mode, object who);
string my_query_long(int mode, object who);


void
create_drink()
{
    // let's make it a sample bottle
    set_name("small crystal bottle");
    set_id( ({"crystal bottle","sample_bottle","empty bottle"}));
    set_short(#'my_query_short);
    set_long(#'my_query_long);
    set_container_value(10);
    set_full(0);
    set_max_full(SMALL_BOTTLE);
    // shop can set this to something else too (3?)
    set_soft(1);
    set_keep_short(1);
    its_race = "";
    its_level = 0;
    bottle_status = SAMPLE_BOTTLE;
    smash_funs = 0;
    effect_fun = 0;
}


string
my_query_short(int mode, object who)
{
    int i;

    if(!objectp(who))
	who = this_player();

    switch(bottle_status) {
    case POTION:
	if(who->query_guild() == GN_PRIEST)
	    return sprintf("A potion of %s", pot_name);
	return capitalize(pot_color) + " potion";

    case DISTILLATION:
	if(who->query_guild() == GN_PRIEST)
	    return sprintf("A distillation of %s's blood",its_race);
	return "A bottle of blood";

    default:
	i = query_max_full();
	if(i>=LARGE_BOTTLE) return "A large crystal bottle";
	if(i>=MEDIUM_BOTTLE) return "A crystal bottle";
	return "A small crystal bottle";
    }
}

string
my_query_long(int mode, object who)
{
    int i;

    i = query_max_full();
    if(i>=LARGE_BOTTLE) return "It's a large iridescent crystal bottle.";
    if(i>=MEDIUM_BOTTLE) return "It's an iridescent crystal bottle.";
    return "It's a small iridescent crystal bottle.";
}



void
fill_with_blood(string race, int level)
{
    int i;

    i = query_full();
    its_race = race;
    its_level = (i * its_level + level) / (i+1);
    bottle_status = DISTILLATION;
    set_id( ({"sample", "distillation", race + "_sample"}) );
    set_liquid("blood");
    set_cost(10);
    set_full(i + 1);
}

void
set_color(string s) {
    pot_color = s;
    set_liquid(pot_color + " liquid glowing with a holy aura");
}

void
make_potion(string name, string color, int lvl, string mess,
  int str, closure drink_cl, closure smash_cl)
{
    int i;

    i = query_full();
    bottle_status = POTION;
    its_level = (i * its_level + lvl) / (i + 1);
    effect_fun = drink_cl;
    smash_funs = smash_cl;
    pot_name = name;
    set_drinker_mess(mess);
    set_drinking_mess(0);
    set_color(color);
    set_full(i+1);
    set_no_heal(1);
    set_strength(str);
    set_cost(10+its_level); // value of one gulp

    // these are set again, when a player takes the potion
    set_name(pot_color + " potion");
    set_id("potion");
    set_short(#'my_query_short);
}

void
init_drink()
{
    object me;

    me = this_player();
    switch(bottle_status) {
    case POTION:
	if(me->query_guild() == GN_PRIEST) 
	    set_id(({"potion", "potion of "+pot_name, pot_color+" potion"}));
	else 
	    set_id(({"potion", pot_color+" potion"}));
	break;

    case DISTILLATION:
	if(me->query_race() == "dark elf") 
	{
	    set_drinker_mess("Ahh.. Slurp slurp *burp*");
	    set_drinking_mess(" drinks a bottle of blood with great pleasure.");
	    set_no_heal(0); // let's heal the player
	    set_strength(10);
	}
	else 
	{
	    set_drinker_mess("You take a good sip from the bottle, but \
immediately throw it all up.");
	    set_drinking_mess(" tries to drink some blood, but throws it \
all up.");
	    set_no_heal(1);
	    set_strength(1);
	}
	break;

    default:
	// No need to do anything, if it's an empty sample bottle
    }
    // all kinds of bottles can be smashed, not just potions
    add_action("break_bottle", "smash");
}

string query_name(int mode, object who)
{
    if (invis_level && (!intp(mode) || mode < invis_level))
	return "something";
    if(!who) who = this_player();

    switch(bottle_status) {
    case POTION:
	if(who && who->query_guild() == GN_PRIEST)
	    return "potion of " + pot_name;

    default:
    }
    return id_name;
}



void
extra_drink()
{
    switch(bottle_status) {
    case POTION:
	if(!to_object(effect_fun)) {
	    this_player()->tell_me("** Potion is corrupted **");
	} else
	    funcall(effect_fun, its_level);
    }

    if(query_full()<=0) {
	bottle_status = SAMPLE_BOTTLE;
	// it can be used as a sample bottle again
	set_name("small crystal bottle");
	set_id( ({"crystal bottle", "sample_bottle", "empty bottle"}) );
	set_short(#'my_query_short);
	its_race = "";
	its_level = 0;
	smash_funs = 0;
	effect_fun = 0;
    }
}

status
break_bottle(string str) {
    mixed x;

    if(!id(str))
	return notify_fail("Smash what?\n"),0;

    switch(bottle_status) {
    case POTION:
	if(environment(this_player())->query(NO_PK)) return
	    notify_fail("Harming other players is not allowed here.\n"),0;
	x = smash_funs + ({ ({ this_object(), its_level}) }); // nice, isn't it :P

	if (this_player()->set(PLR_COMBAT_QUEUE, x) == 1)
	    funcall(x[0],this_player(),&(x[2]));
	break;

    case SAMPLE_BOTTLE:
	environment(this_player())->tell_here(
	  ":%<me.capname>% smash%<me.ending_s>% an empty bottle on the ground, \
leaving nothing but small shards.",0,0,0,this_player(),0,0);
	destruct(this_object());
	break;

    default:
	return notify_fail("It's not much use to smash it on the ground...\n"),0;
    }
    return 1;
}
