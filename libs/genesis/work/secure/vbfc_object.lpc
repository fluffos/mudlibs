/*
 * /secure/vbfc_object.c
 *
 * This object is a very empty object, used when executing VBFC. This is
 * to ensure that VBFC is never executed with privileges.
 *
 * NOTE that this object may NEVER get #pragma resident.
 */

#pragma no_clone
#pragma no_inherit
#pragma save_binary
#pragma strict_types

/*
 * Function name: create
 * Description  : This function is called when the object is created. It
 *                resets the euid of this object.
 */
nomask void
create()
{
    seteuid(0);
}

/*
 * Function name: ob_pointer
 * Description  : This function returns the objectpointer to this object.
 * Returns      : object - the objectpointer to this object.
 */
nomask object
ob_pointer()
{
    return this_object();
}
