/*
 * /std/messenger.c
 *
 * Base Messenger Object
 * ---------------------
 * This was taken from the hobbit messengers in the Frogmorton, but has
 * a long history of creators. The purpose of this new version is to
 * standardize messaging in the Realms.
 *
 * To create a messenger of your own, simply inherit from this object
 * and define the hooks to customize the messages. The hooks can be
 * found in the messaging library. 
 */

inherit "/std/creature";
inherit "/std/combat/unarmed";
inherit "/std/act/action";
inherit "/lib/messenger";

/*
 * Function:    create_messenger
 * Description: Override this function to define your own messenger
 */
public void
create_messenger()
{
} 

/*
 * Function:    create_creature
 * Description: This nomask function calls init_messenger, which in turn calls
 *              create_messenger(). Define any overrides in create_messenger.
 */
public nomask void 
create_creature()
{
    init_messenger();
}

/*
 * Function name: appraise_object
 * Description:   This function is called when someon tries to appraise this
 *                object.
 * Arguments:    num - use this number instead of skill if given.
 */
public void 
appraise_object(int num)
{
    ::appraise_object(num);

    appraise_messenger(num);
}
