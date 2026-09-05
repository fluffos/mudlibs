/*
 *  A more polite version of destruct. It gives the object the option of
 *  destructing itself first, and possibly performing some kind of special
 *  house-cleaning.
 *
 *  Bastian 07/29/95
 */

#pragma strict_types
#pragma save_types

nomask void
destruct ( mixed ob ) {
    object caller;

    if ( stringp(ob) ) ob = find_object(ob);
    if ( (caller = previous_object()) == ob )
        efun::destruct(ob);
    catch(ob->remove_object(caller));
    if ( ob )
        efun::destruct(ob);
}
