/*
 * /std/poison_effect.c
 *
 * This object is the standard poison effect. It will harm people who are
 * poisoned.
 */

/*
 * Example of simple poison effect:
 *
 * inherit "/std/poison_effect";
 * #include <poison_types.h>
 *
 * create_poison_effect()
 * {
 *     set_interval(20);
 *     set_time(500);
 *     set_damage( ({ POISON_FATIGUE, 100, POISON_HP, 30 }) );
 *     set_strength(20);
 *     set_poison_type("spider");
 * }
 *
 * Note that you can make your own poison effects too.  Notes on which
 * functions can be redefined are with the functions below.  All kinds of
 * effects can be created.
 *
 * Usage: from the poisoning object, when the poison should be started,
 *        execute the following code fragment.
 *
 * poison = clone_object("our_poison");
 * poison->move(living_we_want_to_poison);
 * poison->start_poison();
 */

/*
 * The poison is autoloading in nature. If you want to add you own variables
 * to the autoloadstring, please define the functions:
 *
 * string query_poison_recover() { return my_args; }
 *
 * void   init_poison_recover(string my_args) { my_recovery_code; }
 */
#pragma save_binary
#pragma strict_types

inherit "/std/object";

#include <macros.h>
#include <poison_types.h>
#include <ss_types.h>
#include <stdproperties.h>

/*
 * Global variables
 */
float  p_time;   /* The poison lasts for 'p_time' hearbeats		*/
float  interval; /* The poison damages you every 'interval' seconds	*/
int    strength; /* The strength of the poison, to match for cure       */
int    silent;   /* 0 - poisonee gets messages                          */
                 /* 1 - poisonee will not cough but get damage messages */
                 /* 2 - poisonee will not get any messages              */
int    recovery; /* if set to 1 this is a recovery after you quit       */
int    *damage;  /* The damage the poison can do                        */
int    a_dam;    /* The id of the damage_player alarm                   */
int    a_time;   /* The id of the time_out alarm                        */
string type;     /* The type of the poison, to match for cure           */
object poisonee; /* The victim that is being poisoned                   */

/*
 * Function name: create_poison_effect
 * Description  : The normal create for the poison_effect. Redefine this
 *                function if you want to create your own poison.
 */
public void
create_poison_effect()
{
}

/*
 * Function name: create_object
 * Description  : This function defines the object. There are several things
 *                we want to define so we define it for you.
 */
public nomask void
create_object()
{
    ::create_object();

    ustaw_nazwe( ({ "trucizna", "trucizne", "truciznie", "trucizne",
        "trucizna", "truciznie" }), ({ "trucizny", "trucizn", "truciznom",
        "trucizny", "truciznami", "truciznach" }), PL_ZENSKI);
        
    set_long("Oto trucizna.\n");

    set_no_show();

    add_prop(OBJ_I_WEIGHT, 0);
    add_prop(OBJ_I_VOLUME, 0);
    add_prop(OBJ_I_VALUE, 0);

    /* Set up a default poison in case it isn't done by the creator. */
    p_time = 500.0;
    interval = 30.0;
    strength = 50;
    poisonee = 0;
    silent = 0;
    type = "standard";
    damage = ({ POISON_FATIGUE, 40, POISON_HP, 30, POISON_MANA, 20,
	POISON_STAT, SS_CON });

    create_poison_effect();
}

/*
 * Function name: set_poison_type
 * Description  : This sets the type of poison, for use with antidotes.
 * Artuments    : t - the type of the poison
 */
public void
set_poison_type(string t)
{
    type = t;
}

/*
 * Function name: query_poison_type
 * Description  : This returns the type of poison, for use with antidotes.
 * Returns      : string - the type of the poison
 */
public string
query_poison_type()
{
    return type;
}

/*
 * Function name: set_strength
 * Description  : This sets the strength of the poison to overcome player
 *                resistance.
 * Arguments    : t - the strength of the poison
 */
public void 
set_strength(int t) 
{ 
    strength = t; 
}

/*
 * Function name: query_strength
 * Description  : This returns the strength of the poison.
 * Returns      : int - the strength
 */
public int 
query_strength() 
{ 
    return strength; 
}

/*
 * Function name: set_silent
 * Description  : This sets whether the poison should be 'silent'. If it is
 *                silent, the poisonee will not cough or make other sounds.
 * Arguments    : t - silent or not (1 = silent, default = 0, not silent)
 */
public void
set_silent(int t)
{
    silent = t;
}

/*
 * Function name: query_silent
 * Description  : This returns whether the poison is silent.
 * Returns      : 0 - the poisonee will get all messages
 *                1 - the poisonee will nog cough etc but get other messages
 *                2 - the poisonee will get no messages at all
 */
public int
query_silent()
{
    return silent;
}

/*
 * Function name: set_time
 * Description  : This sets the length of time the poison will last,
 *                in seconds.
 * Arguments    : t - the time the poison lasts
 */
public void 
set_time(int t) 
{ 
    p_time = itof(t);
}

/*
 * Function name: query_time
 * Description  : This returns the remaining time the poison will last, 
 *                in seconds.
 * Returns      : int - the time the poison lasts
 */
public int 
query_time() 
{ 
    return ftoi(p_time);
}

/*
 * Function name: set_interval
 * Description  : This sets the average interval between damage being
 *                applied, in seconds.
 * Arguments    : i - the interval
 */
public void 
set_interval(int i) 
{
    interval = itof(i);
}

/*
 * Function name: query_interval
 * Description  : This returns the average interval between damage
 *                applications, in seconds.
 * Returns      : int - the interval
 */
public int 
query_interval(int i) 
{
    return ftoi(interval);
}

/*
 * Function name: query_recovery
 * Description  : This returns whether the poison is being recovered or
 *                whether it is a first time poisoning.
 * Returns      : 1 - the poison is recovered after someone quit
 *                0 - this is a first time poisoning.
 */
public int
query_recovery()
{
    return recovery;
}

/*
 * Function name: set_damage
 * Description  : This function sets the maximum damage done by the poison
 *                Damage is an array of type and amount (or stat in the
 *                case of POISON_STAT)
 * Arguments    : *d - the damage types
 */
public void 
set_damage(int *d) 
{
    if (!sizeof(d))
    {
	log_file("BAD_POIS_DAM", "In " + file_name(this_object()) +
	    " called by " + file_name(previous_object()) + "\n");
	return;
    }

    damage = d;
}

/*
 * Function name: add_damage
 * Description  : This adds an extra damage type.
 * Arguments    : *d - the damage types to add
 */
public void
add_damage(int *d)
{
    damage += d;
}

/*
 * Function name: query_damage
 * Description  : This function returns the damage array of the poison
 * Returns      : int * - the damage types
 */
public int *
query_damage() 
{
    return damage;
}

/*
 * Function name: timeout
 * Description  : This is called when the poison duration has expired.
 *                It simply removes itself.
 */
public void
timeout()
{
    if (silent < 2)
    {
	tell_object(poisonee, "Czujesz sie znacznie lepiej.\n");
    }

    remove_alarm(a_dam);
    
    remove_object();
//    set_alarm(1.0, 0.0, remove_object);
}

/*
 * Function name: kill_player
 * Description  : The player has died, so we kill him! 8-)
 */
public void
kill_player()
{
    remove_alarm(a_time);
    a_time = 0;
    tell_object(poisonee, "Umarl" + poisonee->koncowka("es", "as") + ".\n");
    poisonee->do_die(this_object());
    remove_object();
}

/*
 * Function name: tell_damage_player
 * Description  : The player has been hurt; tell him how.  A string
 *                is passed, which must sound reasonable in the 
 *                sentences "You feel xxxx." and "You feel much xxxx."
 *		  *UWAGA*
 *		  Funkcja juz nie jest uzywana - wszystkie komunikaty
 *		  o obrazeniach zostaly przeniesione do damage_player().
 * Arguments    : phit - the damage level
 *                str  - the string to tell the player.
 */
public void
tell_damage_player(int phit, string str)
{
    if (silent > 1)
    {
	return;
    }

    if (phit > 90)
    {
	tell_object(poisonee, "You feel so much " + str + 
	    ", you wish you were dead.\n");
	return;
    }

    if (phit > 75)
    {
	tell_object(poisonee, "You feel much " + str + ".\n");
	return;
    }

    tell_object(poisonee, "You feel " + str + ".\n");
    return;
}

/*
 * Function name: special_damage
 * Description  : This function is called for any non-standard values
 *                of the poison.  This function should be redefined when
 *                subclassing to get a different damage type.
 * Arguments    : damage - the complete damage array.
 *                i      - the position of the unknown argument type.
 * Returns      : int - the updated i position.
 */
public int
special_damage(int *damage, int i)
{
    return i + 2;  /* by default just ignore the damage, skipping the next
		    argument */
}


/*
 * Function name: damage_player
 * Description:   This function actually carries out the damage on the
 *                player.  It then sets a new damage_player set_alarm.
 *                This function provides stat reduction, hp damage, fatiguing,
 *                and mana reduction. special_damage may be redefined to
 *                provide other types of damage.
 */
public nomask void
damage_player()
{
    int i;
    int s;
    int stat;
    int pdam;   /* We keep track of the percent damage with this var.  */
    int res;
    int dam;

    /*
     * Get resistance as a percent, since we use it more than once.
     */
    res = 100 - poisonee->query_magic_res(MAGIC_I_RES_POISON);
    res = MAX(res, 0);

    i = 0;
    s = sizeof(damage);
    while(i < s)
    {
	switch (damage[i++]) 
	{
	case POISON_HP:
	    if (random(poisonee->query_stat(SS_CON)) > strength) 
		i++;
	    else
	    {
		dam = (res * random(damage[i++])) / 100;
		if (!(pdam = poisonee->query_hp()))
		    pdam = 1;
		pdam = 100 * dam / pdam;
		poisonee->reduce_hit_point(dam);
		if (!silent)
		{
		    if (pdam < 75)
			tell_object(poisonee, "Czujesz sie gorzej.\n");
		    else if (pdam < 90)
			tell_object(poisonee, "Czujesz sie o wiele gorzej.\n");
		    else
			tell_object(poisonee, "Czujesz sie tak zle, ze masz "+
			    "ochote juz umrzec.\n"); 
		}
		if (poisonee->query_hp() <= 0)
		kill_player();
	    }
	break;

	case POISON_MANA:
	    if (random(poisonee->query_stat(SS_CON)) > strength) 
		i++;
	    else
	    {
		dam  = (res * random(damage[i++])) / 100;
		if (!(pdam = poisonee->query_mana()))
		    pdam = 1;
		pdam = 100 * dam / pdam;
		poisonee->add_mana(-dam);
		if (!silent)
		{
		    if (pdam < 75)
			tell_object(poisonee, "Czujesz sie bardziej zmeczon" +
			    poisonee->koncowka("y", "a") + " mentalnie.\n");
		    else if (pdam < 90)
			tell_object(poisonee, "Czujesz sie o wiele bardziej "+
			    "zmeczon" + poisonee->koncowka("y", "a") +
			    " mentalnie.\n");
		    else
			tell_object(poisonee, "Czujesz tak wielke "+
			    "zmeczenie mentalne, ze masz ochote juz umrzec.\n");
		}
	    }
	break;

	case POISON_FATIGUE:
	    if (random(poisonee->query_stat(SS_CON)) > strength) 
		i++;
	    else
	    {
		dam  = (res * random(damage[i++])) / 100;
		if (!(pdam = poisonee->query_fatigue()))
		    pdam = 1;
		pdam = 100 * dam / pdam;
		poisonee->add_fatigue(-dam);
		if (!silent)
		{
		    if (pdam < 75)
			tell_object(poisonee, "Czujesz sie bardziej zmeczon" +
			    poisonee->koncowka("y", "a") + ".\n");
		    else if (pdam < 90)
			tell_object(poisonee, "Czujesz sie o wiele bardziej "+
			    "zmeczon" + poisonee->koncowka("y", "a") +
			    ".\n");
		    else
			tell_object(poisonee, "Czujesz tak wielke "+
			    "zmeczenie fizyczne, ze masz ochote juz umrzec.\n");
		}
	    }
	break;

	case POISON_STAT:
	    if ((random(poisonee->query_stat(SS_CON)) > strength)||
		(random(100)>=res)) 
		i++;
	    else 
		poisonee->add_tmp_stat(damage[i++], - 1, ftoi(p_time * rnd()));
	break;

        case POISON_USER_DEF:
	default:
	    i = special_damage(damage, i - 1);
	break;
	}
    }

    /*
     * Lets make the player emit random pitiful sounds if the poison is
     * not silent. 8)
     */
    if ((random(3)) && (!silent))
    {
/*	poisonee->command( ({"choke", "cough", "puke", "shiver", "moan",
	    "groan"})[random(6)]);
*/
        poisonee->command( ({ "zblednij", "zakrztus sie" })[random(2)]);
    }
  
    a_dam = set_alarm((interval / 2.0) + (rnd() * interval), 0.0,
		      damage_player);
}

/*
 * Function name: no_drop
 * Description  : Give correct fail message when a player tries to drop it.
 *                We do this to keep poisons invisible.
 * Returns      : string - the fail message.
 */
public string
no_drop()
{
    return capitalize(query_verb()) + " co?\n";
}

/*
 * Function name: start_poison
 * Description:   This function simply starts the poison working.  Until 
 *                the poison is acivated, it is a simple object.  Once
 *                activated, the poison will disappear after 'time'
 *                seconds.
 */
public void
start_poison()
{
    poisonee = environment(this_object());

    /* Find out who owns us */
    if (!living(poisonee))
    {
	 /* If they aren't living, we punt. */
	 remove_object();
	 return;
    }

    if (silent < 2)
    {
	tell_object(poisonee, "Zostal" + poisonee->koncowka("es", "as") +
	    " zatrut" + poisonee->koncowka("y", "a") + "!\n");
    }

    add_prop(OBJ_I_NO_DROP, no_drop);
    add_prop(OBJ_I_NO_GIVE, "Daj co komu?\n");

    if (interval)
    {
        a_dam = set_alarm((interval / 2.0) + (rnd() * interval), 0.0,
			  damage_player);
    }

    a_time = set_alarm(p_time, 0.0, timeout);
}

/*
 * Function name: cure_poison
 * Description  : Check success in removing poison, then remove it, if
 *                successful.  An array of curable poison types is passed
 *                in.
 * Arguments    : cure_type - the types that can be cured
 *                success   - the 'strength' of the cure
 * Returns      : 1/0 (success/fail)
 */
public int
cure_poison(string *cure_type, int success)
{
    int index = -1;
    int size = sizeof(cure_type);

    while(++index < size)
    {
        if (((cure_type[index] == "all") &&
	     ((success / 2) > strength)) ||
            ((member_array(type, cure_type) != -1) &&
	     (success > strength)))
	{
	    remove_alarm(a_time);
            a_time = 0;
	    timeout();
	    return 1;
	}
    }
    return 0;
}

/*
 * Function name: remove_object
 * Description  : This function is called when the object is removed.
 */
void
remove_object()
{
    if (a_time)
    {
        remove_alarm(a_time);
    }

    ::remove_object();
}

/*
 * Function name: query_poison_recover
 * Description  : To add more information to the recover string, you should
 *                mask this function to return that information. Do not
 *                make a call to ::query_poison_recover!
 * Returns      : string - the extra recover string.
 */
public string
query_poison_recover()
{
    return "-";
}

/*
 * Function name: query_auto_load
 * Description:   Used to reload the poison into the player if it hasn't
 *                expired when he quits. When you want to add more information
 *                to the recover string, mask query_poison_recover().
 */
public nomask string
query_auto_load()
{
    float time_left = 0.0;
    string dam_string = "";
    int i;
    mixed arr;

    for (i = 0; i < sizeof(damage); i++)
    {
	dam_string += "," + damage[i];
    }

    if (sizeof(arr = get_alarm(a_time)))
        time_left = arr[2];

    return MASTER + ":" +
	ftoi(time_left) + "," +
	ftoi(interval) + "," +
	type + "," +
	strength + "," +
	silent +
	dam_string + "#USER#" +
	query_poison_recover();
}

/*
 * Function name: init_posion_recover
 * Description  : To add more information to the recover string, you should
 *                mask this function to process that information after you
 *                have added it with query_poison_recover().
 * Arguments    : string arg - the extra recover string.
 */
public void
init_poison_recover(string arg)
{
}

/*
 * Function name: init_arg
 * Description  : Parses the data from the saved object.
 * Arguments    : arg - the arguments to init
 */
public nomask void
init_arg(string arg)
{
    int i;
    string *arglist;
    int dam;
    string s1, s2;

    /* Set that this is a recovery after someone quit */
    recovery = 1;

    sscanf(arg, "%s#USER#%s", s1, s2);

    arglist = explode(s1, ",");

    sscanf(arglist[0], "%f", p_time);
    sscanf(arglist[1], "%f", interval);
    type = arglist[2];
    sscanf(arglist[3], "%d", strength);
    sscanf(arglist[4], "%d", silent);
    damage = ({ });

    if (silent < 2)
    {
	write("Czujesz sie smiertelnie chor" + 
	    this_player()->koncowka("y", "a") + ".\n");
    }

    for (i = 5; i < sizeof(arglist); i++)
    {
	sscanf(arglist[i], "%d", dam);
	damage += ({ dam });
    }

    init_poison_recover(s2);

    set_alarm(1.0, 0.0, start_poison);
}

/*
 * Function name: stat_object
 * Description  : Called when wizard stats the object
 * Returns      : A string describing the object.
 */
public string
stat_object()
{
    float time_left = 0.0;
    mixed arr;

    if (a_time &&
	sizeof(arr = get_alarm(a_time)))
    {
        time_left = arr[2];
    }

    return ::stat_object() +
	"Time      : " + ftoa(p_time) + "\n" +
	"Time left : " + ftoa(time_left) + "\n" +
        "Interval  : " + ftoa(interval) + "\n" +
        "Strength  : " + strength + "\n" +
        "Type      : " + type + "\n" +
        "Silent    : " + silent + "\n";
}
