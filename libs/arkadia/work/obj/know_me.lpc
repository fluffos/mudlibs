/*
 * /obj/know_me.c
 *
 * On request from Lars, this object if cloned autoloads with a wizard
 * and sets the LIVE_I_ALWAYSKNOWN property. Thereby always showing
 * the wizard on everyones who list.
 */

#pragma save_binary
#pragma strict_types

inherit "/std/object";

#include <macros.h>
#include <stdproperties.h>

/*
 * Function name: create_object
 * Description  : Constructor. Called to create the object when it is cloned.
 */
void
create_object()
{
    ustaw_nazwe( ({ "kolczyk", "kolczyka", "kolczykowi", "kolczyk", 
        "kolczykiem", "kolczyku" }), ({ "kolczyki", "kolczykow", 
        "kolczykom", "kolczyki", "kolczykami", "kolczykach" }), 
        PL_MESKI_NOS_NZYW);
        
    dodaj_przym("maly", "mali");
    dodaj_przym("metalowy", "metalowi");
    
    remove_prop(OBJ_I_VALUE);
    remove_prop(OBJ_I_VOLUME);
    remove_prop(OBJ_I_WEIGHT);
}

/*
 * Function name: enter_env
 * Description  : This function is called whenever this object enters a new
 *                environment. We add the LIVE_I_ALWAYSKNOWN property to
 *                the environment if the environment is a wizard.
 * Arguments    : object inv  - the environment this object is entering.
 *                object from - the possible place this object came from.
 */
void
enter_env(object inv, object from)
{
    ::enter_env(inv, from);

    if (inv->query_wiz_level())
    {
	inv->add_prop(LIVE_I_ALWAYSKNOWN, 1);
    }
}

/*
 * Function name: leave_env
 * Description  : This function is called whenever this object leaves its
 *                environment. We remove the LIVE_I_ALWAYSKNOWN property
 *                from the environment if the environment is a wizard. Note
 *                that this function is also called when this object is
 *                destructed.
 * Arguments    : object inv - the environment this object is leaving.
 *                object to  - the possible new destination of this object.
 */
void
leave_env(object inv, object to)
{
    ::leave_env(inv, to);

    if (inv->query_wiz_level())
    {
	inv->remove_prop(LIVE_I_ALWAYSKNOWN);
    }
}

/*
 * Function name: query_auto_load
 * Description  : Return the filename of this module to allow it to be
 *                autoloadable.
 * Returns      : string - the filename of this module.
 */
string
query_auto_load()
{
    return MASTER;
}
