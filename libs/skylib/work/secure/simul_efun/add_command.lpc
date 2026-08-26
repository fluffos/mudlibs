/*
 * A simul_efun for add_command to make life slightly easier.
 */
/**
 * Contains some simul_efuns.
 * @author Pinkfish
 */
/**
 * A simul_efun for add_command.  This allows you to call add_command without
 * having to go this_player()->add_command.  This will only work on non-living
 * objects.
 *
 * @param verb the verb to add
 * @param pattern the pattern associated with the verb
 * @param func the function to call on success
 *
 * @see /global/player/new_parse->add_command()
 * @see help add_command_conversion
 */
varargs void add_command( string verb, string pattern, function func ) {
    if( TP )
        TP->add_command( verb, PO, pattern, func );
} /* add_command() */

/**
 * An interface to add_succeeded_mess.  This is added to make life easier,
 * you do not need to call this_player()->add_succeeded_mess() if you are
 * writing add_command code in a non-living object.
 *
 * @param mess the message to print
 * @param indir the indirect objects the message is for
 * @see /global/player/new_parse->add_succeeded_mess()
 */
void add_succeeded_mess( mixed mess, object *indir ) {
    if( TP )
        TP->add_succeeded_mess( PO, mess, indir );
} /* add_succeeded_mess() */

/**
 * An interface to add_succeeded.  This is added to make life easier,
 * you do not need to call this_player()->add_succeeded() if you are
 * writing add_command code in a non-living object.
 *
 * @param ob the object to add as succeeded
 * @see /global/player/new_parse->add_succeeded()
 */
void add_succeeded( object ob ) {
    if( TP )
        TP->add_succeeded(ob);
} /* add_succeeded() */

/**
 * An interface to add_failed_mess.  This is added to make life easier,
 * you do not need to call this_player()->add_failed_mess() if you are
 * writing add_command code in a non-living object.
 *
 * @param mess the message to print
 * @param indir the indirect objects the message is for
 *
 * @see /global/player/new_parse->add_failed_mess()
 */
void add_failed_mess( mixed mess, object *indir ) {
    if( TP )
        TP->add_failed_mess( PO, mess, indir );
} /* add_failed_mess() */
