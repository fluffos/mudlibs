/**
 * XP handler - hands out command xp based on the time the
 * command was last used and the cost of the command.
 * @author Sandoz
 */

#define GAP_TIME 100

/** @ignore yes */
void create() {
} /* create() */

/** @ignore yes */
void dest_me() {
    destruct(TO);
} /* dest_me() */

/**
 * This function will give out xp to the player, based on the
 * amount of gps used, the last time the command was used by
 * the player and if the command was successful or not.
 *
 * @param person the player using the command
 * @param amount the amount of gps used
 * @param success wether or not the command was successful
 * @param cmd the name of the command, if this is 0,
 * previous_object() will be used.
 */
varargs void handle_xp( object person, int amount, int success, string cmd ) {
    string from;
    int tmp;

    if( !person || !objectp(person) || !interactive(person) || amount < 1 )
        return;

    from = ( stringp(cmd) ? cmd : base_name(PO) );

    if( success )
        tmp = amount;
    tmp += roll_MdN( 6, amount / 4 );

    if( !person->query_property(from) ) {
        tmp += ( success ? 3 : 1 ) * amount;
        tmp += roll_MdN( 4, amount / 2 );
    }

    person->add_property( from, 1, GAP_TIME );
    person->adjust_xp( tmp );

} /* handle_xp() */
