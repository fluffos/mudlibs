/*
 * A standard object that adds resistance to its carrier
 */
 
#pragma save_binary
#pragma strict_types

inherit "/std/object";

#include <macros.h>
#include <ss_types.h>
#include <stdproperties.h>

//	Prototypes
public void stop_res();

//	Global variables
mixed	Res_Type;	/* The type of resistance */
int	Alarm_Id,	/* The alarm id of the alarm to end the effect */
        Strength;	/* How strong it will be */
float   Time;	/* How long time it will be in effect, if 0.0 always. */

/*
 * Function name: create_resistance
 * Description:   Create the resistance
 */
void
create_resistance()
{
    set_name("Resistance_Object");
    add_prop(OBJ_M_NO_DROP, "Poloz co?\n");
    add_prop(OBJ_I_WEIGHT, 0);
    add_prop(OBJ_I_VOLUME, 0);
    add_prop(OBJ_I_VALUE, 0);
    set_no_show();
}

/*
 * Function name: create_object
 * Description:   The standard create
 */
nomask void
create_object()
{
    Strength = 5;
    Res_Type = MAGIC_I_RES_MAGIC;
    Time = 0.0;
    create_resistance();
}

/*
 * Function name: enter_env
 * Description:   Called each time this object enters another environment
 * Arguments:     to   - The object this object enters
 *		  from - The object this object leaves
 */
void
enter_env(object to, object from)
{
    if (objectp(to) && living(to))
    {
        to->add_magic_effect(this_object());
        if (Time && (!Alarm_Id || !sizeof(get_alarm(Alarm_Id))))
            Alarm_Id = set_alarm(Time, 0.0, stop_res);
    }

    ::enter_env(to, from);
}

/*
 * Function name: leave_env
 * Description:   Called when this object is moved from another object
 * Arguments:     from - The object this object is moved from
 *		  to   - The object to which this object is being moved
 */
void
leave_env(object from, object to)
{
    if (objectp(from) && living(from))
      	from->remove_magic_effect(this_object());
    
    ::leave_env(from, to);
}

/*
 * Function name: stop_res
 * Description:   If the resistance is time dependent this function will
 *		  called when it's time to remove this resistance
 */
public void
stop_res()
{
    object ob;

    if (objectp(ob = environment(this_object())) && living(ob))
	tell_object(ob, "Czujesz sie mniej odporn" + ob->koncowka("y", "a")
	    + ".\n");

    remove_alarm(Alarm_Id);
    remove_object();
}

/*
 * Function name: set_res_type
 * Description:   Set the type of resistance of this object
 */
void set_res_type(string str) { Res_Type = str; }

/*
 * Function name: query_res_type
 * Description:   Returns what type of resistance this object helps
 */
string query_res_type() { return Res_Type; }

/*
 * Function name: set_strength
 * Description:   Set how strong this resistance is
 */
void set_strength(int i) { Strength = i; }

/*
 * Function name: query_strength
 * Description:   Query how strong this resistance is
 */
int query_strength() { return Strength; }

/*
 * Function name: set_time
 * Description:   How long this will hold
 */
void set_time(int i) { Time = itof(i); }

/*
 * Function name: query_time
 * Description:   How long will we be resistive
 */
int query_time() { return ftoi(Time); }

/*
 * Function name: stat_object
 * Description:   Called when wizard stats the object
 * Returns:       A string describing the object.
 */
public string
stat_object()
{
    mixed   a_info;
    string  desc = ::stat_object();

    desc += "Resistance: " + Res_Type + "\n"
         +  "Strength:   " + Strength + "\n"
         +  "Time:       " + ftoa(Time) + "\n";

    if (Alarm_Id && sizeof(a_info = get_alarm(Alarm_Id)))
        desc += "Time left:  " + ftoa(a_info[2]) + "\n";

    return desc;
}

/*
 * Function name: query_magic_protection
 * Description:   the resistance effect
 * Arguments:     prop - the resistance property
 *                what - the protected object
 * Returns:       an array of integer with the resistance:
 *                ({ strength, additive })
 *                Strength is always less or equal 40, and
 *                the resistance effect is always additive
 */
public mixed
query_magic_protection(string prop, object what)
{
    if ((what == environment(this_object())) && (prop == Res_Type))
        return ({ Strength, 1 });

    return 0;
}

/*
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
